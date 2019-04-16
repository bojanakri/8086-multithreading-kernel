#ifndef _PCB_h_
#define _PCB_h_

typedef unsigned long StackSize;
typedef unsigned int Time; // time, x 55ms
typedef int ID;
typedef enum State{NEW, READY, RUNNING, BLOCKED, FINISHED};

class Thread;
class PCBList;
class PCBListTime;

class PCB{
	public:
		StackSize stackSize;
		Time timeSlice;
		Thread* myThread;

		unsigned int sp;
		unsigned int bp;
		unsigned int ss;

		unsigned int *stack;

		State state;
		PCBList* blockedPCB;

		static PCB* runningPCB;
		static PCB* idlePCB;
		static PCBListTime* sleepingThreads;

		PCB(StackSize stackSize_, Time timeSlice_, Thread* myThread_);
		void createStack();
		static void wrapper();
		~PCB();

};


#endif
