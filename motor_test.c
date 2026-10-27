/*
ENGR 10 motor test - spins each motor port one at a time, forward then backward.
Set test_port to the port you want (1-10), or 0 to run every port.

HOW TO USE:
  1. Put the robot on a box/stand so the wheels are OFF the ground. Battery charged and switched on.
  2. Download the program, then open Robot > Debugger Windows > Debug Stream to see which port is running.
  3. Watch each motor. Port 1 and port 10 plug straight into the Cortex.
     Ports 2-9 need a Motor Controller 29 between the motor and the Cortex.

If a motor doesn't move when its port is running:
  - check the cable is pushed all the way in (and the Motor Controller 29 for ports 2-9)
  - swap it to another port to see if it's the motor or the port
  - check the battery and that the Cortex is on
*/

int test_port = 1;     // port to test (1-10), or 0 to test all ports
int test_speed = 60;   // motor power, -127 to 127
int run_time = 1500;   // ms each direction

task main(){
	clearDebugStream();
	writeDebugStreamLine("Motor test starting in 3 s - wheels OFF the ground!");
	delay(3000);

	for(int p = 0; p < 10; p++){
		if(test_port != 0 && p != test_port - 1) continue;

		writeDebugStreamLine("PORT %d: forward", p + 1);
		motor[(tMotor)p] = test_speed;
		delay(run_time);
		motor[(tMotor)p] = 0;
		delay(300);

		writeDebugStreamLine("PORT %d: backward", p + 1);
		motor[(tMotor)p] = -test_speed;
		delay(run_time);
		motor[(tMotor)p] = 0;
		delay(700);
	}

	writeDebugStreamLine("MOTOR TEST DONE");
}
