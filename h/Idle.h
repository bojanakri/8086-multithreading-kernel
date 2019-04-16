#ifndef _idle_h_
#define _idle_h_

class Thread;

#include "Thread.h"

class Idle:public Thread{
	public:
		Idle();
		void startIdle();
		void run();
};


#endif