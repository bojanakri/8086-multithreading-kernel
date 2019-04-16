#ifndef _ivtentry_h_
#define _ivtentry_h_

typedef unsigned char IVTNo;
typedef void interrupt (*FPointer) (...);

class KernelEv;

class IVTEntry{
	public:
		FPointer oldRoutine;
		FPointer newRoutine;
		KernelEv* myEvent;
		IVTNo ivtNo;
		static IVTEntry* entries[256];

		IVTEntry(IVTNo ivtNo_, FPointer newRoutine_);
		~IVTEntry();
};


#endif
