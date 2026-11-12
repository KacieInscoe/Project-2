import serial
import time
import json
import os
PORT = '/dev/cu.usbmodem64E833605B782'
BAUD = 9600
DESKTOP_PATH = os.path.expanduser('~/Desktop')
LOG_FILE = os.path.join(DESKTOP_PATH, 'distance_log.json')
def main():
    ser = serial.Serial(PORT, BAUD, timeout=1)
    time.sleep(2)
    readings = []
    danger_start = None
    print("Running... Press Ctrl+C to stop.\n")
    try:
        while True:
            if ser.in_waiting > 0:
                line = ser.readline().decode('utf-8', errors='ignore').strip()
                try:
                    dist = float(line)
                    readings.append(dist)
                    if dist < 15:
                        if danger_start is None:
                            danger_start = time.time()
                        elif time.time() - danger_start >= 3.0:
                            print("--> ALERT: Too close for 3 seconds!")
                            danger_start = time.time()
                    else:
                        danger_start = None
                    print(f"Distance: {dist:.1f} cm | Readings: {len(readings)}")
                except ValueError:
                    pass
    except KeyboardInterrupt:
        print("\nStopping...")
        summary = {
            "total_samples": len(readings),
            "avg_cm": round(sum(readings) / len(readings), 2) if readings else 0
        }
        with open(LOG_FILE, 'w') as f:
            json.dump(summary, f, indent=4)
        ser.close()
        print(f"Saved successfully to your Desktop as 'distance_log.json'. Done!")
if __name__ == "__main__":
    main()