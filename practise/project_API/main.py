import requests

api_key = "e3e0a0a855824b928f190351250806"
base = "http://api.weatherapi.com/v1"

def fetch_weather(city):
    curr_url = f"{base}/current.json?key={api_key}&q={city}"
    curr = requests.get(curr_url).json()

    # Forecast endpoint (note: should be 'forecast.json', not 'current.json')
    fc_url = f"{base}/forecast.json?key={api_key}&q={city}&days=2"
    fc = requests.get(fc_url).json()

    return curr, fc

def process_data(curr, fc):
    c = curr["current"]
    forecast_day = fc["forecast"]["forecastday"][0]["day"]
    wind = c("wind_kph")
    temp = c["temp_c"]
    min_temp = forecast_day["mintemp_c"]
    max_temp = forecast_day["maxtemp_c"]
    humidity = c["humidity"]
    it_is_raining = forecast_day.get("daily_chance_of_rain", 0) > 0
    feels_like = forecast_day.get("feelslike_c")
    uv = c["uv"]

    warnings, advice = [], []

    if temp > 30:
        warnings.append("Warning! Extremely hot!")
        advice.append("Don't forget to cover your head, drink plenty of water, and use SPF.")
    if it_is_raining:
        warnings.append("It is raining outside.")
        advice.append("Don't forget your umbrella!")
    if uv >= 8:
        warnings.append("High UV!")
        advice.append("Wear your sunglasses.")

    return {
        "current_temp": temp,
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

# Example usage
if __name__ == "__main__":
    city = "Kyiv"
    current, forecast = fetch_weather(city)
    weather_info = process_data(current, forecast)
    print(weather_info)

