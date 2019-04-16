#ifndef _kernelev_h_
#define _kernelev_h_

class PCB;
typedef unsigned char IVTNo;

class KernelEv{
	private:
		IVTNo ivtNo;
		PCB* owner;
		int value;

	public:
		KernelEv(IVTNo ivtNo_);
		~KernelEv();
		void wait();
		void signal();
};

#endif