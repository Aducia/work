import requests

city = "Brovary"
api_key = "e3e0a0a855824b928f190351250806"
base = "http://api.weatherapi.com/v1"

def fetch_weather(city, days=5):
    fc_url = f"{base}/forecast.json?key={api_key}&q={city}&days={days}"
    fc_2 = requests.get(fc_url).json()
    return fc_2

forecast_2 = fetch_weather(city)

def process_data(fc_2):
    forecasts_2 = []

    c_2 = fc_2["current"]
    forecast_list_2 = fc_2["forecast"]["forecastday"]

    for day_data_2 in forecast_list_2:
        date_2 = day_data_2["date"]
        forecast_day_2 = day_data_2["day"]

        wind_2 = c_2["wind_kph"]
        temp_2 = forecast_day_2["temp_c"]
        min_temp_2 = forecast_day_2["mintemp_c"]
        max_temp_2 = forecast_day_2["maxtemp_c"]
        humidity_2 = c_2["humidity"]
        it_is_raining_2 = forecast_2.get("daily_chance_of_rain", 0) > 0
        feels_like_2 = forecast_day_2.get("feelslike_c", c["temp_c"])
        feels_like_2 = temp_2  # Forecast doesn't provide feels_like, so we use avgtemp
        uv_2 = c_2["uv"]

        warnings_2, advice_2 = [], []

        if temp_2 > 30:
            warnings_2.append("Warning! Extremely hot.")
            advice_2.append("Cover your head, drink plenty of water, and wear SPF.")
        if it_is_raining_2:
            warnings_2.append("Chance of rain.")
            advice_2.append("Take an umbrella.")
        if uv_2 >= 8:
            warnings_2.append("High UV expected.")
            advice_2.append("Wear sunglasses and sunscreen.")

        forecasts_2.append({
            "date": date_2,
            "avg_temp": temp_2,
            "min_temp": min_temp_2,
            "max_temp": max_temp_2,
            "humidity": humidity_2,
            "uv": uv_2,
            "it_is_raining": it_is_raining_2,
            "feels_like": feels_like_2,
            "wind": wind_2,
            "warnings": warnings_2,
            "advice": advice_2
        })

    return forecasts_2
    five_day_weather_2 = process_data(forecast_2)

    if __name__ == "__main__":
        print(day_weather)
