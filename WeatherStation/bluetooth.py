import random
import sys
import os
import serial
import glob
import time


ser = serial.Serial(
    port='COM4',
    baudrate=9600,
    parity=serial.PARITY_NONE,
    stopbits=serial.STOPBITS_ONE,
    bytesize=serial.EIGHTBITS,
    timeout=0)

print("connected to: " + ser.portstr)

#this will store the line
seq = []
param = []
count = 1
count1 = 0
temp = 0
baro = 0
humid = 0
while True:
    for c in ser.read():
        seq.append(chr(c)) #convert from ANSII
        joined_seq = ''.join(str(v) for v in seq) #Make a string from array
        if chr(c) == '*':
            count += 1
            count1 += 1
            seq = []
            break
        elif count1 == 1 and chr(c) == '\n':
            count += 1
            count1 += 1
            seq = []
            break
        elif count1 == 2  and chr(c)== '\n':
                print("Line " + str(count) + ': ' + "Weather Data")
                count += 1
                print("Line " + str(count) + ': ' "Temperature is (degrees) : " + joined_seq)
                count += 1
                count1 += 1
                seq=[]
                break

        elif count1 == 3 and chr(c)== '\n':
                print('\n'+"Line " + str(count) + ': ' + "Barometric Pressure is (kPA) : " + joined_seq )
                count += 1
                count1 += 1
                seq=[]
                break

        elif count1 == 4 and chr(c)== '\n':
                print('\n'+ "Line " + str(count) + ': ' + "Humidiity is (%) : " + joined_seq)
                count1 = 0
                count += 1
                seq=[]
                break

        elif chr(c) == '}' or chr(c) == '?':
            count += 1
            seq = []
            break
        if chr(c) == '\n' and count1 == 0:
            print('\n'+"Line " + str(count) + ': ' + joined_seq)
            seq = []
            count += 1
            break


ser.close()