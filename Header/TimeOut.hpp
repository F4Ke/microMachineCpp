
#ifndef __TIMEOUT_HPP_
#define __TIMEOUT_HPP_

#include <iostream>
#include <ctime>

enum typeMod { RUN = 1, THINK = 2 };

class timer {
	private:
		unsigned long begTime;
		typeMod etypeMod;
	
	public:
		void start() {
			begTime = clock();
		}

		unsigned long elapsedTimeSecond() {
			return ((unsigned long) clock() - begTime) / CLOCKS_PER_SEC;
		}

		unsigned long elapsedTimeMillisecond() {
			return ((unsigned long) clock() - begTime) / (CLOCKS_PER_SEC *1000);
		}

		void setTimerMod(typeMod emod)
		{
			this->etypeMod = emod;
		}

		bool isTimeout(unsigned long seconds) 
		{
			if (etypeMod == RUN)
				return seconds >= elapsedTimeSecond();
			if (etypeMod == THINK)
				return seconds >= elapsedTimeMillisecond();
			else
				return false;
		}
};

class TimeOut
{
public:
	TimeOut();
	~TimeOut();
	void startRun();
	void startThink();
//	void setMod(int mod); // 1 = RUN, 2 = THINK
	bool isTimeoutRUN();
	bool isTimeoutTHINK();

private:
	unsigned long timeSecondsRunTotal;// = 60s;
	unsigned long timeMilissecondsToThink;// = 15ms;

	int IndexMod;

	timer tRUN;
	timer tTHINK;

	

};

#endif