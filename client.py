import socket

data_len = 12;

s = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
s.connect(('mta-sa.ru', 8081))
str = (b'h'*data_len) + b'\x00'
s.send(str)

upper = s.recv(len(str)-1)
print(upper)
s.close()
