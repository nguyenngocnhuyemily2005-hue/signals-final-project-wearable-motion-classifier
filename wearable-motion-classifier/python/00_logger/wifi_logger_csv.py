import socket
import csv
import time

ESP_IP = "10.47.188.173"
PORT = 80

sock = socket.socket(socket.AF_INET, socket.SOCK_STREAM)

sock.connect((ESP_IP, PORT))

print("CONNECTED TO ESP32")

filename = "data/raw/walking_01.csv"

start_time = time.time()

with open(filename, mode="w", newline="") as file:

    writer = csv.writer(file)

    writer.writerow(["timestamp", "FB", "LR", "UD"])

    while True:

        data = sock.recv(1024).decode().strip()

        if data:

            try:

                fb, lr, ud = data.split(",")

                timestamp = round(time.time() - start_time, 3)

                writer.writerow([timestamp, fb, lr, ud])

                file.flush()

                print(timestamp, fb, lr, ud)

            except:

                print("BAD PACKET:", data)