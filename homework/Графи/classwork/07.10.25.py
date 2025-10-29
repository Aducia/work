import base64
import json
import hmac
import hashlib
import time

def base64url_decode(data):
    padding = '=' * (-len(data) % 4)
    return base64.urlsafe_b64decode(data + padding)

def verify_jwt(token, secret):
    try:
        header_b64, payload_b64, signature_b64 = token.split('.')
        
        # Обчислюємо очікуваний підпис
        signing_input = f"{header_b64}.{payload_b64}".encode()
        expected_signature = hmac.new(secret.encode(), signing_input, hashlib.sha256).digest()
        expected_signature_b64 = base64.urlsafe_b64encode(expected_signature).rstrip(b'=')

        # Перевіряємо підпис
        if expected_signature_b64 != signature_b64.encode():
            print("❌ Невірний підпис")
            return False

        # Перевіряємо час дії токена (exp)
        payload = json.loads(base64url_decode(payload_b64))
        if "exp" in payload and time.time() > payload["exp"]:
            print("❌ Токен прострочений")
            return False

        print (f"✅ Токен валідний\nДані: {payload}")
        return True

    except Exception as e:
        return False
    

# 🔹 приклад використання
token = "eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJleHAiOjE3NTk4Mjc2MDAsInN1YiI6IjEyMzQ1Njc4OTAiLCJuYW1lIjoiSm9obiBEb2UiLCJhZG1pbiI6dHJ1ZSwiaWF0IjoxNTE2MjM5MDIyfQ.6eCHD_JMHYRM8VvYW4jHDP3PRGL7WTBsL-sKCDyL0ng"
secret = "a-string-secret-at-least-256-bits-long"

print(verify_jwt(token, secret))
