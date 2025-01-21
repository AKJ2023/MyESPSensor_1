import serial
import struct
from time import sleep
import sys

def C(val):
    return struct.pack('!H', val)

import glob

def list_serial_ports():
    """ Lists serial port names

        :raises EnvironmentError:
            On unsupported or unknown platforms
        :returns:
            A list of the serial ports available on the system
    """
    if sys.platform.startswith('darwin'):
        return glob.glob('/dev/tty.*')

if __name__ == "__main__":
    list_serial_ports()
exit()

ser = serial.Serial(port='/dev/tty.PL2303-00002006', baudrate=9600)

sleep(2)

ser.write(C(0xaa00))

sleep(1)
ser.write(C(0xaa36))

sleep(1)
ser.write(C(0xaa11))

sleep(1)