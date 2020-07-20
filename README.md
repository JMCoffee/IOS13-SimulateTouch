# IOS13-SimulateTouch
iOS 11.0 - 13.6 system-level touch simulation iOS13模拟点击

Jailbroken device required

## Description
This library enables you to simulate touch events on iOS 11.0 - 13.6 with just one line of code! All the source code will be released later.

## Features
1. Multitouch supported (no other library you can find supports multi touching).
2. Programmable. Control scripts can be programmed with all the programming languages you desire.
3. Instant controlling supported. The ios device can be controlled with no latency from other devices/computers.
4. System-level touch simulation (will not inject to any process).

## Installation
1. Open Cydia - Sources - Edit - Add - http://47.114.83.227 ("http" instead of "https"!!! Please double check this.)
2. Install ***"ZJXTouchSimulation"*** tweak
3. Done

## Code Example
`Python Version`
```Python
import socket
import time

# event types
TOUCH_UP = 0
TOUCH_DOWN = 1
TOUCH_MOVE = 2
SET_SCREEN_SIZE = 9

# you can copy and paste this method to your code
def formatSocketData(type, index, x, y):
    return '{}{:02d}{:05d}{:05d}'.format(type, index, int(x*10), int(y*10))

s = socket.socket()
s.connect(("127.0.0.1", 6000))  # connect to the tweak
s.send(("1"+formatSocketData(SET_SCREEN_SIZE, 0, 2732, 2048)).encode())  # tell the tweak that the screen size is 2732x2048 (your screen size might differ). This should be send to the tweak every time you kill the SpringBoard (just send once)
time.sleep(1)  # sleep for 1 sec to get setting size process finished
s.send(("1"+formatSocketData(TOUCH_DOWN, 7, 300, 400)).encode())  # tell the tweak to touch 300x400 on the screen
# IMPORTANT: NOTE the "1" at the head of the data. This indicates the event count and CANNOT BE IGNORED.
s.close()
```

Actually the touch is performed by only one line: 
```Python 
s.send(("1"+formatSocketData(TOUCH_DOWN, 7, 300, 400)).encode()) 
```
Neat and easy. 

Perform Touch Move
```Python
s.send(("1"+formatSocketData(TOUCH_MOVE, 7, 800, 400)).encode())  # tell the tweak to move our finger "7" to (800, 400)
```

Perform Touch Up
```Python
s.send(("1"+formatSocketData(TOUCH_UP, 7, 800, 400)).encode())  # tell the tweak to touch up our finger "7" at (800, 400)
```

Combining them
```Python
s.send(("1"+formatSocketData(TOUCH_DOWN, 7, 300, 400)).encode())
time.sleep(1)
s.send(("1"+formatSocketData(TOUCH_MOVE, 7, 800, 400)).encode())
time.sleep(1)
s.send(("1"+formatSocketData(TOUCH_UP, 7, 800, 400)).encode())
```

First the finger touches (300, 400), and then it moves to (800, 400), and then "leaves" the screen. All the touch events are performed with no latency.

## Usage
1. After installation, the tweak will start listening at port 6000.
2. Use socket to send touch data field to the tweak

data field should always be decimal digits, specified below
![alt text](https://raw.githubusercontent.com/xuan32546/IOS13-SimulateTouch/master/img/event-data-digit.png)

`Event Count`(1 digit): Specify the count of the single events. If you have multiple events to send at the same time, just increase the event count and append events to the data.

`Type`(1 digit): Specify the type of the single event. 

Supported event type:


 | Event   | Flag | Description  |
|:--------:|:-------------:|:------------:|
| Touch Up      | 0      | Specify the event as a touch-up event |
| Touch Down    | 1      | Specify the event as a touch-down event |
| Touch Move    | 2      | Specify the event as a touch-move event (move the finger) |
| Set Size      | 9      | Set screen size (required!! Will be explained below) |

`Touch Index`(2 digits): Apple supports multitouch, so you have to specify the finger index when posting touching events. The range of finger index is 1-20 (0 is reserved, don't use 0 as finger index). 

`x Coordinate`(5 digits): The x coordinate of the place you want to touch. The first 4 digit is for integer part while the last one is for the decimal part. For example, if you want to touch (123.4, 2432.1) on the screen, you should fill "01234" for this.

`y Coordinate`(5 digits): The y coordinate of the place you want to touch. The first 4 digit is for integer part while the last one is for the decimal part. For example, if you want to touch (123.4, 2432.1) on the screen, you should fill "24321" for this.

## Contact
Mail 1: jiz176@pitt.edu
Mail 2: 1023675508@qq.com
