import socket

data_len = 12
url = "127.0.0.1"
port = 8081

s = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
s.connect((url, port))
str = (b'h'*data_len) + b'\x00'
s.send(str)

upper = s.recv(len(str)-1)
print(upper)
s.close()

