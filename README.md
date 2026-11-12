# Arduino Distance Tracker

This is a project that measures distance using an ultrasonic sensor, lights up LEDs based on proximity, and logs data to a computer using Python.

## Hardware Setup
- Arduino Uno
- HC-SR04 Ultrasonic Sensor (Trig: D9, Echo: D10)
- Red LED (D1) - Too close (< 15 cm)
- Yellow LED (D2) - Warning (15 - 30 cm)
- Green LED (D3) - Safe (> 30 cm)

## Files
- `proximity_sensor.ino` - Arduino code
- `distence.py` - Python script to read serial data and save logs
- `distance_log.json` - Output summary saved to Desktop

## How to Run
1. Upload `proximity_sensor.ino` to the Arduino.
2. Install pyserial: `pip install pyserial`
3. Update `PORT` in `distence.py` to match your USB port.
4. Run `python distence.py` and press Ctrl+C to stop and save.
