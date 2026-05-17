import socket

ESP_IP = "10.47.188.173"
PORT = 80

sock = socket.socket(socket.AF_INET, socket.SOCK_STREAM)

sock.connect((ESP_IP, PORT))

print("CONNECTED TO ESP32")

while True:

    data = sock.recv(1024).decode().strip()

    if data:

        print(data)