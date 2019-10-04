#! /usr/bin/env python3
# Tutorial: stackoverflow.com/questions/20892133/storing-string-from-arduino-to-text-file-using-python
# lots of trial and error
# make sure you install pyserial

import serial
from datetime import datetime

serial_port = "/dev/ttyACM0"
baud_rate = 9600
write_to_file_path = "output.txt"

ser = serial.Serial(serial_port, baud_rate)

while True:
    line = ser.readline()
    line = line.decode("utf-8")
    dateTimeObj = datetime.now()
    print(dateTimeObj.strftime("%d-%b-%Y (%H:%M:%S.%f)"))
    print(line)

    output_file = open(write_to_file_path, "a+")
    output_file.write(dateTimeObj.strftime("%d-%b-%Y (%H:%M:%S.%f)\t"))
    output_file.write(line)
    output_file.close()
