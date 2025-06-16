import sys
import datetime

class Formatter:
    def format(self, message):
        raise NotImplementedError("Must implement format method")

class TimeFormatter(Formatter):
    def __init__(self, fmt="%Y-%m-%d %H:%M:%S"):
        self.fmt = fmt

    def format(self, message):
        now = datetime.datetime.now().strftime(self.fmt)
        return f"[{now}] {message}"

class Handler:
    def handle(self, formatted_message):
        raise NotImplementedError("Must implement handle method")

class StreamHandler(Handler):
    def __init__(self, stream=sys.stderr):
        self.stream = stream

    def handle(self, formatted_message):  # fixed typo
        print(formatted_message, file=self.stream)

class Logger:
    def __init__(self, formatter: Formatter):
        self.formatter = formatter
        self.handlers = []

    def add_handler(self, handler: Handler):  # fixed indentation and syntax
        self.handlers.append(handler)

    def log(self, message):
        formatted = self.formatter.format(message)
        for handler in self.handlers:
            handler.handle(formatted)

def main():
    formatter = TimeFormatter("%Y-%m-%d %H:%M:%S")  # fixed typo
    logger = Logger(formatter)

    stderr_handler = StreamHandler(sys.stderr)
    logger.add_handler(stderr_handler)

    logger.log("message for logging")
    logger.log("another message")  # fixed typo

if __name__ == "__main__":
    main()

