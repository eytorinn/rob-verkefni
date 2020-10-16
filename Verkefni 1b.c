#pragma config(Sensor, dgtl1,  rightEncoder,        sensorQuadEncoder)
#pragma config(Sensor, dgtl3,  leftEncoder,         sensorQuadEncoder)
#pragma config(Motor,  port2,           rightMotor,    tmotorVex269, openLoop, reversed)
#pragma config(Motor,  port3,           leftMotor,     tmotorVex269, openLoop)

#define BASEDIST = 1250;
const int BASEDIST = 1250;

void reset(){
	SensorValue[rightEncoder] = 0;
	SensorValue[leftEncoder] = 0;
}

void on(int dist, int dir){

	while(abs(SensorValue[rightEncoder]) < dist)
	{
		if(abs(SensorValue[rightEncoder]) == abs(SensorValue[leftEncoder]))

			// Move Forward
			motor[rightMotor] = 80*dir;		    // Right Motor is run at power level 80
			motor[leftMotor]  = 80*dir;		    // Left Motor is run at power level 80
		}
		else if(abs(SensorValue[rightEncoder]) > abs(SensorValue[leftEncoder]))
		{
			// Turn slightly right
			motor[rightMotor] = 60*dir;		    // Right Motor is run at power level 60
			motor[leftMotor]  = 80*dir;		    // Left Motor is run at power level 80
		}
		else
		{
			// Turn slightly left
			motor[rightMotor] = 80*dir;		    // Right Motor is run at power level 80
			motor[leftMotor]  = 60*dir;		    // Left Motor is run at power level 60
		}
	}
}

task main()
{
	for(int i=1; i++){

		on(BASEDIST*i,1);
		reset();
		on(BASEDIST*i,-1);
		reset();
	}

}  //Veit natturulega ekki alveg hvort thetta virki, get ekki testad :(
