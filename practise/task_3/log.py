import sys
import datetime

class Logger:
    def __init__(self, out_stream, time_format):
        self.out_stream = out_stream
        self.time_format = time_format

    def log(self, message):
        current_time = datetime.datetime.now().strftime(self.time_format)
        print("[%s] %s" % (current_time, message), file=self.out_stream)

def main():
    out_stream = sys.stderr
    time_formatter = '%Y-%m-%d %H:%M:%S'
    logger = Logger(out_stream, time_formatter)

    logger.log("Text message")
    logger.log("Another message for logging")
    
    return 0

if __name__ == "__main__":
    sys.exit(main())

