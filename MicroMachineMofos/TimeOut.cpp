
#include "TimeOut.hpp"


TimeOut::TimeOut()
{
	timeSecondsRunTotal =3;
	timeMilissecondsToThink = 15;

	tRUN.setTimerMod((typeMod)1);
	tTHINK.setTimerMod((typeMod)2);
}

TimeOut::~TimeOut()
{
}

void TimeOut::startRun()
{
	this->tRUN.start();

	while(true) {
		if(tRUN.elapsedTimeSecond() >= timeSecondsRunTotal) {
			break;
		}
		else {
			// do other things
		}
	}
	// Kill Run
}

void TimeOut::startThink()
{
	this->tTHINK.start();

	while(true) {
		if(tTHINK.elapsedTimeMillisecond() >= timeMilissecondsToThink) {
			break;
		}
		else {
			// do other things
		}
	}
	// Kill Think
}
//
//void TimeOut::setMod(int index)
//{
//	this->IndexMod = index;
//}

bool TimeOut::isTimeoutRUN() 
{
	return (this->tRUN.isTimeout(this->timeSecondsRunTotal));
}

bool TimeOut::isTimeoutTHINK() 
{
	return (this->tTHINK.isTimeout(this->timeMilissecondsToThink));
}
