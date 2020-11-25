#pragma config(Sensor, dgtl1,  Stop,           sensorTouch)
#pragma config(Sensor, dgtl9,  leftEncoder,    sensorQuadEncoder)
#pragma config(Sensor, dgtl7, rightEncoder,   sensorQuadEncoder)
#pragma config(Motor,  port2,           rightMotor,    , openLoop)
#pragma config(Motor,  port3,           leftMotor,     , openLoop, reversed)



void Forward(int tickingGoal);
void Turn(float r, bool clockwise);


task main()
{
	SensorValue[leftEncoder] = 0;
	int distance= 50; // i CM
	int drivecm = (distance/33) * 360;

	wait1Msec(1000);
	Forward(drivecm);
	Turn(1, true);
	Forward(drivecm);
	Turn(1, false);
	Forward(drivecm);
	Turn(1, false);
	Forward(drivecm);
}



void Forward(int tickingGoal)
{
	SensorValue[leftEncoder] = 0;
	SensorValue[rightEncoder] = 0;

	while(abs(SensorValue[leftEncoder]) < tickingGoal)
	{
		motor[rightMotor] = 63;
		motor[leftMotor]  = 63;
	}
	motor[rightMotor] = 0;
	motor[leftMotor] = 0;
}


void Turn(float r, bool clockwise)
{
  SensorValue[rightEncoder] = 0;    // Clear the encoders
  SensorValue[leftEncoder]  = 0;


  if(clockwise == true)
  {
	  while(SensorValue[rightEncoder] < (r * 90) && SensorValue[leftEncoder] > (-1 * r * 90))
	  {
	    motor[rightMotor] = 63;         // Run the right motor forward at half speed
	    motor[leftMotor]  = -63;        // Run the left motor backward at half speed
	  }
	}
	else if (clockwise == false)
	{
		while(SensorValue[rightEncoder] > (-1 * r * 90) && SensorValue[leftEncoder] < (r * 90))
	  {
	    motor[rightMotor] = 63;         // Run the right motor forward at half speed
	    motor[leftMotor]  = -63;        // Run the left motor backward at half speed
	  }
	}
  motor[rightMotor] = 0;            /* Stop both motors!  This is important so that each function          */
  motor[leftMotor]  = 0;            /* can act independantly as a "chunk" of code, without any loose ends. */

	while(1 == 1){
		if(vexRT[Btn7R] == 1)
			{
				StopAllTasks();

				wait1Msec(10);
			}
			if(SensorValue[Stop] == 1)
			{
				StopAllTasks();

				wait1Msec(10);
			}
		}
}
