import pytchat
import serial

# video_id = "jfKfPfyJRdk" # LoFi Hiphop Radio (the BEST!)
video_id = 'r2He0N9dosg'

port_name = '/dev/ttyACM0' # Port for Servo controlling Arduino

# We get commands of the following:
commands_list = ["left", "right", "stop"]

# Global variable
chat = pytchat.create(video_id)
ser = serial.Serial(port_name, 115200)

def send_command(cmd):
    ''' Sends command to the microprocessor (driver) '''
    if cmd == "left":
        ser.write(b'left')
    elif cmd == "right":
        ser.write(b'right')
    elif cmd == "stop":
        ser.write(b'stop')
    else:
        ser.write(cmd)
    
    print('Command sent: ' + cmd)

def main():
    try:
        while chat.is_alive():
            for c in chat.get().sync_items():
                # print(f"{c.datetime} [{c.author.name}]- {c.message}")
                # Parse the string
                msg = c.message
                for cmd in commands_list:
                    if cmd in msg:
                        # Apply command control (send command)
                        send_command(cmd)
                        continue # Go for next loop
            # End of Loop
    except Exception as e:
        # TODO: Parse error logs
        print(e)
        print(f"Exception occured with the payload: {c.message}")
        exit()

if __name__ == "__main__":
    print("********Started YouTube Server********")
    print("======================================")
    main()

# How it Works
# Get's the client ID: client .get https://github.com/taizan-hokuto/pytchat/blob/master/pytchat/util/__init__.py