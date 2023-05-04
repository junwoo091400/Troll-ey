## Materials
1. Servo: [Turnigy MX-95E](https://hobbyking.com/en_us/turnigytm-mx-95e-digital-micro-servo-0-8kg-0-09sec-4-1g.html?___store=en_us)
2. Arduino Pro Micro

## Instructions
1. Connect the Servo to Arduino's Vcc, GND, and Pin 2
2. Flash the `servo_controller` script to Arduino using the [IDE](https://support.arduino.cc/hc/en-us/articles/360019833020-Download-and-install-Arduino-IDE)
3. Modify the `youtube_chat_servo_control.py` to have the `video_id` variable have the ID of the livestream you want to take comments from
4. Start the script: `python3 youtube_chat_servo_control.py`

### Testing the Functionality
To test the movement directly, you could open a Serial Monitor in Arduino IDE and send the commands "left", "right", and "stop" manually. Or, you can directly send the message on the live stream chat.

## Notes from livestream try-out
I have tried this with a [live stream](https://www.youtube.com/live/r2He0N9dosg), and observed the following:

1. The lag is high! Roughly 15 ~ 20 seconds from the moment user types the command, until the movement of servo is shown on screen.
   1. **Livestream message parsing delay, 2 sec**: From user typing the command ~ Getting it parsed and sent to Arduino
   2. **Servo actuation delay, 1 sec**: From receiving the command (Arduino) ~ Servo actually moving
   3. **Live stream delay, 12 ~ 17 sec**: From the Sservo actually moving ~ That being shown in the livestream
2. The Servo is sometimes not working, probably due to the connection with jumper wires
3. Somewhere during the 8 hours long livestream, the parser script exited itself. Pretty sure the `chat.is_alive()` logic returned `False` once, and it came out of the loop.

Therefore, immediate things to improve are:
1. Livestream delay: We need to reduce it down to ~10 seconds. Zoom calls achieve sub-second delay, how can we achieve that?
2. Make the parser more robust: Don't have it quit the program after one hickup in the livestream & Parse lower and upper case commands

## Reference
1. https://smartbuilds.io/building-a-package-delivery-robot-controlled-by-youtube-live-chat/
2. https://github.com/EbenKouao/twitch-chat-websocket-python
3. https://github.com/EbenKouao/arduino-wheel-robot/blob/main/arduino-wheel-robot-code/arduino-wheel-robot-code.ino
4. https://www.delftstack.com/howto/cpp/cpp-last-character-of-string/
5. https://stackoverflow.com/questions/32391036/how-to-get-last-character-of-string-in-c