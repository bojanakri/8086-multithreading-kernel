#include "thread.h"
#include "Schedule.h"
#include "PCB.h"
#include "List.h"


Thread::Thread(StackSize stackSize, Time timeSlice){
	myPCB = new PCB(stackSize ,timeSlice, this);
}

Thread::~Thread(){
	delete myPCB;
}

void Thread::start(){
	myPCB->createStack();
	myPCB->state = READY;
	Scheduler::put(myPCB);
}

void Thread::waitToComplete(){
	if (myPCB->state != FINISHED && myPCB->state != NEW && myPCB != PCB::runningPCB){
		PCB::runningPCB->state = BLOCKED;
		myPCB->blockedPCB->insert(PCB::runningPCB);
		dispatch();
	}
}
#ifndef BCC_BLOCK_IGNORE
void Thread::sleep(Time timeToSleep){
	asm pushf
	asm cli
	if (timeToSleep > 0){
		PCB::runningPCB->state = BLOCKED;
		PCB::sleepingThreads->insert(PCB::runningPCB, timeToSleep);
		dispatch();
	}
	asm popf
}
#endif
