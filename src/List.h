#ifndef _List_h_
#define _List_h_


class PCB;

class PCBList{
	private:
		struct Elem{
			PCB* pcb;
			Elem* next;
			Elem(PCB* pcb_):pcb(pcb_){
				next=0;
			}
		};

		Elem* first;
		Elem* last;
	public:
		PCBList();
		~PCBList();

		void insert(PCB* pcb);
		PCB* removeFirst();
		PCB* remove(PCB* pcb);
};


class PCBListTime{
	private:
		struct Elem{
			PCB* pcb;
			Elem* next;
			int time;
			Elem(PCB* pcb_, int t):pcb(pcb_){
				time=t;
				next=0;
			}
		};

		Elem* first;
		Elem* last;
	public:
		PCBListTime();
		~PCBListTime();

		void insert(PCB* pcb, int time);
		PCB* removeFirst();
		PCB* remove(PCB* pcb);
		void update();
};

#endif
