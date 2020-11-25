#pragma config(Sensor, dgtl1,  Stop,           sensorTouch)
#pragma config(Motor,  port2,           leftMotor,     tmotorVex393_MC29, openLoop, reversed)
#pragma config(Motor,  port3,           rightMotor,    tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port6,           clawMotor,     tmotorVex269_MC29, openLoop, reversed)
#pragma config(Motor,  port7,           armMotor,      tmotorVex393_MC29, openLoop, reversed)


task main ()
{

	while(1 == 1)
	{
		motor[leftMotor]  = (vexRT[Ch2] - vexRT[Ch1])/2;
		motor[rightMotor] = (vexRT[Ch2] + vexRT[Ch1])/2;


		if(vexRT[Btn5U] == 1)
		{
			motor[armMotor] = 127;
		}
		else if(vexRT[Btn5D] == 1)
		{
			motor[armMotor] = -127;
		}
		else
		{
			motor[armMotor] = 0;
		}


		if(vexRT[Btn6U] == 1)
		{
			motor[clawMotor] = 127;
		}
		else if(vexRT[Btn6D] == 1)
		{
			motor[clawMotor] = -127;
		}
		else
		{
			motor[clawMotor] = 0;
		}

		if(vexRT[Btn7R] == 1)
		{
			stopAllTasks();

			wait1Msec(10);
		}
		if(SensorValue[Stop] == 1)
		{
			stopAllTasks();

			wait1Msec(10);
		}

	}
}
