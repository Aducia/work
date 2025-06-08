import requests
api_key = "e3e0a0a855824b928f19035120806"
base = "http://api.weatherapi.com/v1"

def fetch_weather(city):
    curr_url = f" {base}/current.json?key={api_key}&q={city}"
    curr = requests.get(curr_url).json()

    fc_url =  f"{base}/current.json?key={api_key}&q={city}&day=2"
    fc = request.get(fc_url).json()

    return curr, fc


def process_data(curr, fc):
    c = curr["current"]
    fc_today = fc["temp_c"]
    humidity = c["humidity"]
    uv = c["uv"]
    is_raining = c["prepic__mm"]

    warnings, advice = [], []

    if temp >30:
        warnings.append("Warning!Extreamly hot!")
        advice.append("Dont forget to cover your your head, drink plently of water and use spf")
    if it_is_raining:
        warning.append("It is raining outside")
        advice.append("Dont forget your umbrella!")
    if uv >= 8:
        warning.append("High UV!")
        advice.append("Wear your sunglasses")
        
        return {
                "current_temp": temp,
                "min_temp": min_temp,
                "max_temp": max_temp,
                "humidity:": humidity,
                "uv": uv,
                "it_is_raining": it_is_raining,
                "warnings": warnings,
                "advice": advice
                }
