// File: event.h
#ifndef _event_h_
#define _event_h_

#include "KernelEv.h";
#include "IVTEntry.h"

typedef unsigned char IVTNo;
class KernelEv;
class Event {
	public:
 		Event (IVTNo ivtNo);
 		~Event ();
 		void wait ();
	protected: 

 		friend class KernelEv;
 		void signal(); // can call KernelEv
	private:
		KernelEv* myImpl;
};


#define PREPAREENTRY(num, callold)\
	void interrupt interruptHandler(...);\
	IVTEntry ivtEntry(num, interruptHandler);\
	void interrupt interruptHandler(...){\
		if (ivtEntry.myEvent != 0)\
			ivtEntry.myEvent->signal();\
		if (callold != 0)\
			ivtEntry.oldRoutine();\
	}



#endif 