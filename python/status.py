from gpiozero import *

# Need to start daemon: sudo pigpiod
# To stop daemon: sudo killall pigpiod
# https://gpiozero.readthedocs.io/en/stable/index.html

print(pi_info())
print("{0:board}".format(pi_info()))
print("{0:headers}".format(pi_info()))
