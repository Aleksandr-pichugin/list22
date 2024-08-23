#include<iostream>

using namespace std;



	class Node {
	public:
		int data;
		Node* Pprev, * Pnext;

	public:
		Node(int data) {
			this->data = data;
			this->Pprev = this->Pnext = NULL;
		}
	};
	class LinkedList {
	public:
		Node* head, * tail;

	public:
		LinkedList() {
			head = tail = NULL;
		}
		~LinkedList() {
			while (head != NULL)
				pop_front();
		}
		Node* push_front(int data) {
			Node* Newptr = new Node(data);
			Newptr->Pnext = head;
			if (head != NULL)
				head->Pprev = Newptr;
			if (tail == NULL)
				tail = Newptr;
			head = Newptr;

			return Newptr;
		}
		Node* push_back(int data) {
			Node* Newptr = new Node(data);
			Newptr->Pprev = tail;
			if (tail != NULL)
				tail->Pnext = Newptr;
			if (head == NULL)
				head = Newptr;
			tail = Newptr;

			return Newptr;
		}
		void pop_front() {
			if (head == NULL) return;

			Node* Nevptr = head->Pnext;
			if (Nevptr != NULL)
				Nevptr->Pprev = NULL;
			else
				tail = Nevptr;

			delete head;
			head = Nevptr;
		}
		void pop_back() {
			if (tail == NULL) return;

			Node* Nevptr = tail->Pnext;
			if (Nevptr != NULL)
				Nevptr->Pnext = NULL;
			else
				head = NULL;

			delete tail;
			tail = Nevptr;
		}
		Node* getAt(int index) {
			Node* Nevptr = head;
			int n = 0;

			while (n != index) {
				if (Nevptr == NULL)
					return NULL;
				Nevptr = Nevptr->Pnext;
				n++;
			}
			return Nevptr;
		}

		Node* operator[] (int index) {
			return getAt(index);
		}
		Node* insert(int index, int data) {
			Node* right = getAt(index);
			if (right == NULL)
				return push_back(data);

			Node* left = right->Pprev;
			if (left == NULL)
				return push_front(data);

			Node* Nevptr = new Node(data);

			Nevptr->Pprev = left;
			Nevptr->Pnext = right;
			left->Pnext = Nevptr;
			right->Pprev = Nevptr;

			return Nevptr;
		}
		void erase(int index) {
			Node* Nevptr = getAt(index);
			if (Nevptr == NULL)
				return;

			if (Nevptr->Pprev == NULL) {
				pop_front();
				return;
			}
			if (Nevptr->Pnext == NULL) {
				pop_back();
				return;
			}
			Node* left = Nevptr->Pprev;
			Node* right = Nevptr->Pnext;
			left->Pnext = right;
			right->Pprev = left;

			delete Nevptr;
		}
	};

		void main()
	{
		setlocale(LC_ALL, "");

		LinkedList lst;
		lst.push_back(1);
		lst.push_back(2);
		lst.push_back(3); 
		lst.push_back(5);

		cout << lst[1]->data << endl;
		cout << lst[0]->data << endl;
		cout << lst[2]->data << endl;

		lst.insert(2, -5);
		lst.insert(20, -10);

		lst.erase(3);
		

		for (Node* Nevptr = lst.head; Nevptr != NULL; Nevptr = Nevptr = Nevptr->Pnext)
			cout << Nevptr->data<<" ";
		cout << endl;

		for (Node* Nevptr = lst.tail; Nevptr != NULL; Nevptr = Nevptr = Nevptr->Pprev)
			cout << Nevptr->data<<" ";
		cout << endl;
}