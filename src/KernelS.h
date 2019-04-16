#ifndef _KERNELS_H_
#define _KERNELS_H_
#include "Semaphor.h"
#include "List.h"
#include "PCB.h"
#include "Schedule.h"
class KernelSem{
public:
	KernelSem(int _val, Semaphore* _mySemaphore);
	~KernelSem();
	void signal();
	int wait(int toBlock);
	int getVal() const;
private:
	int val;
	PCBList* blocked;
	Semaphore* mySemaphore;
};



#endif
