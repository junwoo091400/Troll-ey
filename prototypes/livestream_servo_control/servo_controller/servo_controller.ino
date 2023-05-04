#include <Servo.h>

const int8_t SERVO_PIN = 2;
Servo serv;

const int left_servo_cmd = 2000;
const int right_servo_cmd = 1000;
const int stop_servo_cmd = 1500;

void sendServoCommand(String cmd) {
  // Serial.print("Processing command: ");
  // Serial.print(cmd);
  // Serial.println(cmd.length());

  // for (int i=0; i<cmd.length(); ++i) {
  //   Serial.print(cmd[i], HEX);
  // }

  // Serial.print("End: ");
  // Serial.println(*cmd.end(), HEX);

  if (cmd == "left") {
    serv.write(left_servo_cmd);
    Serial.println("Left serv written");
  } else if (cmd == "right") {
    serv.write(right_servo_cmd);
    Serial.println("Right serv written");
  } else if (cmd == "stop") {
    serv.write(stop_servo_cmd);
    Serial.println("Stop serv written");
  } else {
    Serial.println("Invalid command");
  }
}

void setup() {
  Serial.begin(115200);// setup Serial Monitor to display information
  serv.attach(SERVO_PIN);
}

void loop() {
  //Recieve Serial commands to control the Robot
  if (Serial.available() > 0) {
    String data = Serial.readString();
    Serial.print("Command Recieved: ");
    Serial.println(data);
    // Serial.println(data.length());

    // Sanitize the data
    if (data.charAt(data.length()-1) == '\n') {
      // Cut away the trailing \n
      data = data.substring(0, data.length()-1);
      // Serial.println("Trailing newline cut");
    }

    // Line feed
    // if (*data.end() == '\r') {
    //   // Cut away the trailing \n
    //   data = data.substring(0, data.length()-1);
    //   Serial.println("Trailing linefeed cut");
    // }

    // Process data
    sendServoCommand(data);
  }
}