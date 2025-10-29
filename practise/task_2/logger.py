import datetime
import sys
def log(message):
        current_time = datetime.datetime.now()
        current_time_str = current_time.strftime("%Y-%m-%d %H:%M:%S")
        print("[%s] %s" % (current_time_str, message), file=sys.stderr)
def main():
    log("Text message")
    return 0

#if __name__ == "__main__":
#    sys.exit(main())
log("abc")
