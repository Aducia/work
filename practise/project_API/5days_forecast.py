import requests

city = "Brovary"
api_key = "e3e0a0a855824b928f190351250806"
base = "http://api.weatherapi.com/v1"

def fetch_weather(city, days=5):
    fc_url = f"{base}/forecast.json?key={api_key}&q={city}&days={days}"
    fc = requests.get(fc_url).json()
    return fc

def process_weather(fc):
    forecasts = []

    for day_data in fc["forecast"]["forecastday"]:
        date = day_data["date"]
        forecast_day = day_data["day"]

        temp = forecast_day["avgtemp_c"]
        min_temp = forecast_day["mintemp_c"]
        max_temp = forecast_day["maxtemp_c"]
        humidity = forecast_day["avghumidity"]
        wind = forecast_day["maxwind_kph"]
        it_is_raining = int(forecast_day.get("daily_chance_of_rain", 0)) > 0
        uv = forecast_day["uv"]
        feels_like = temp  # Approximate

        warnings, advice = [], []

        if temp > 30:
            warnings.append("Warning! Extremely hot.")
            advice.append("Cover your head, drink plenty of water, and wear SPF.")
        if it_is_raining:
            warnings.append("Chance of rain.")
            advice.append("Take an umbrella.")
        if uv >= 8:
            warnings.append("High UV expected.")
            advice.append("Wear sunglasses and sunscreen.")

        forecasts.append({
            "date": date,
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
        })

    return forecasts

if __name__ == "__main__":
    forecast = fetch_weather(city)
    five_day_weather = process_weather(forecast)
    for day_weather in five_day_weather:
        print(day_weather)

