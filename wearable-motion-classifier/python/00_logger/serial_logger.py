import serial
import csv
import time

# =========================
# CONFIGURATION
# =========================

SERIAL_PORT = 'COM8'
BAUD_RATE = 115200

OUTPUT_FILE = '../../data/raw/walking_01.csv'

# =========================
# SERIAL CONNECTION
# =========================

ser = serial.Serial(
    SERIAL_PORT,
    BAUD_RATE
)

time.sleep(2)

print("Collecting data...")
print(f"Saving to: {OUTPUT_FILE}")

# =========================
# CSV WRITER
# =========================

with open(OUTPUT_FILE, mode='w', newline='') as file:

    writer = csv.writer(file)

    writer.writerow([
        'timestamp',
        'ax',
        'ay',
        'az',
        'gx',
        'gy',
        'gz'
    ])

    try:

        while True:

            line = ser.readline().decode('utf-8').strip()

            print(line)

            data = line.split(',')

            if len(data) == 7:
                writer.writerow(data)

    except KeyboardInterrupt:

        print("\nData collection stopped.")

        ser.close()