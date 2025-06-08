import requests

city = "Brovary"
api_key = "e3e0a0a855824b928f190351250806"
base = "http://api.weatherapi.com/v1"

def fetch_weather(city):
    # Forecast for 2 days (today and tomorrow)
    fc_url = f"{base}/forecast.json?key={api_key}&q={city}&days=2"
    fc = requests.get(fc_url).json()
    return fc

def process_tomorrow_weather(fc):
    # Get forecast for tomorrow
    forecast_day = fc["forecast"]["forecastday"][1]["day"]

    temp = forecast_day["avgtemp_c"]
    min_temp = forecast_day["mintemp_c"]
    max_temp = forecast_day["maxtemp_c"]
    humidity = forecast_day["avghumidity"]
    wind = forecast_day["maxwind_kph"]
    it_is_raining = forecast_day.get("daily_chance_of_rain", 0) > 0
    uv = forecast_day["uv"]
    feels_like = temp  # Approximation, as there's no feels-like for forecast in API

    warnings, advice = [], []

    if temp > 30:
        warnings.append("Warning! Extremely hot tomorrow!")
        advice.append("Cover your head, drink plenty of water, and wear SPF.")
    if it_is_raining:
        warnings.append("Chance of rain tomorrow.")
        advice.append("Take an umbrella.")
    if uv >= 8:
        warnings.append("High UV expected tomorrow!")
        advice.append("Wear sunglasses and sunscreen.")

    return {
        "avg_temp": temp,
        "min_temp": min_temp,
        "max_temp": max_temp,
        "humidity": humidity,
        "uv": uv,
        "it_is_raining": it_is_raining,
        "feels_like": feels_like,
        "wind": wind,
        "warnings": warnings,
        "advice": advice
    }

# Main execution
if __name__ == "__main__":
    forecast = fetch_weather(city)
    tomorrow_weather = process_tomorrow_weather(forecast)
    print(tomorrow_weather)

