from flask import Flask
from flask_ask import Ask, statement
import serial
import time
ser = serial.Serial('/dev/ttyACM1')
app = Flask(__name__)
ask = Ask(app, '/')


@ask.launch
def start_skill():
    welcome_message = 'OK, OK!'
    ser.write(b'1')
    return statement(welcome_message)



@app.route('/')
def homepage():
    return "Hi, there"


if __name__ == '__main__':
    app.run(port=5000, debug=True)