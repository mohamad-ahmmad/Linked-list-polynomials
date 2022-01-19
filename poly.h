#pragma once
#include <iostream>
#include<string>
#include<cmath>
#include <fstream>

using namespace std;
using std::istream;
class NODE {
private:
	int pow, coeff;

public:
	NODE* next;
	NODE() {
		pow = 0;
		coeff = 0;
		next = NULL;
	}
	NODE(int pow, int coeff) {
		this->pow = pow;
		this->coeff = coeff;
		next = NULL;
	}
	int getpow() {
		return pow;
	}
	void setpow(int powe) {
		pow = powe;
	}
	int getcoeff() {
		return coeff;
	}
	void setcoeff(int coeff) {
		this->coeff = coeff;
	}


};

class Poly {
private :
	NODE* head;
	NODE* tail;
public:
	
	Poly() {
		head = NULL;
		tail = NULL;
		next = NULL;
	}
	
	Poly(int Coeff_arr[], int Pow_arr[],int size) {
		
		for (int i = 0; i < size; i++) {
			add_node(creat_node(Coeff_arr[i], Pow_arr[i]));
			
		}
		tail_setter();

	}
	~Poly() {}
	void setpoly(int Coeff_arr[], int Pow_arr[], int size) {
		for (int i = 0; i < size; i++) {
			add_node(creat_node(Coeff_arr[i], Pow_arr[i]));

		}
		tail_setter();

	}
	void tail_setter()
	{
		NODE* ptr;
		ptr = head;
		while (ptr->next !=NULL) {
			ptr = ptr->next;
		}
		tail = ptr;
	}
	NODE * creat_node(int coeff, int pow){
		NODE* n=new NODE;
		n->setcoeff(coeff);
		n->setpow( pow);
	
		n->next = NULL;
		return n;
       
	}
	double eval(double x) {
		NODE* ptr;
		ptr = head;
		double sum=0;
		while (ptr != NULL) {
			sum = sum + ptr->getcoeff() * pow(x,ptr->getpow());
			ptr = ptr->next;
		}
		return sum;
	}
	void add_node(NODE* n) {
		NODE* p1, * p2;
	
		if (head == NULL) {

			head = n;
			tail = n;
			return;
		}
		if (head->getpow() == n->getpow()) {
			head->setcoeff(head->getcoeff() + n->getcoeff());
			return;
		}
		if (head->getpow() > n->getpow()) {
		
			p1 = head;
			head = n;
			n->next = p1;
			return;
		}
		p1 = p2 = head;
		while (p2 != NULL) {
			if(p2->getpow() == n->getpow()) {
				p2->setcoeff(n->getcoeff() + p2->getcoeff());
				return;
			}
			if (n->getpow() < p2->getpow()) {
			
				n->next = p2;
				p1->next = n;
				return;
			}

			else {
				p1 = p2;
				p2 = p2->next;
			}
		}
		if (p1->getpow() == n->getpow()) {
			p1->setcoeff(n->getcoeff() + p1->getcoeff());
			return;
		}
		n->next = p2;
		p1->next = n;

	}
	NODE* tail_get() {
		return tail;
	}
	void merge(Poly *p) {
		NODE* ptr1;
		ptr1 = p->head;
		while ((ptr1 != NULL)) {
		    add_node(creat_node(ptr1->getcoeff(), ptr1->getpow()));
		 ptr1 = ptr1->next;	
		}

		p->delete_poly();

	}
	void delete_node(int pow) {
		NODE* ptr1;
		NODE* ptr2;
		ptr2 = head;
		ptr1 = head;
		if ((ptr2 == head) &&(head->next==NULL)&& (ptr2->getpow() == pow)) {
			this->delete_poly();
			
			return;
		}
		while (ptr2 != NULL) {
			
			if ((ptr2 == tail)&&(ptr2->getpow()==pow)) {
				tail = ptr1;
				ptr1->next = NULL;
				delete ptr2;
				return;
			}
			if ((ptr2 == head) && (ptr2->getpow()==pow)) {
				head = head->next;
				delete ptr2;
				return;
			}
			if (ptr2->getpow()==pow) {
				ptr1->next = ptr2->next;
				
				delete ptr2;
				return;
			}
		
			ptr1 = ptr2;
			ptr2 = ptr2->next;
		}
		cout << "The Power not found.";
		cout << endl;

	}
	void delete_poly() {
		NODE* ptr;
		ptr = head;
		if (ptr == NULL) {
			cout << "No Polynomial to delete";
			cout << endl;
			return;
		}
		while (head != NULL) {
			ptr = head;
			head = head->next;
			delete ptr;
			
		}
	
	}
	friend ostream& operator <<(ostream& out, Poly &p) {
		NODE* ptr;
		ptr = p.head;
		if (ptr == NULL) {
			out << "\x1B[37mEmpty Polynomial. ";
			
			return out;
		}
		ofstream fp("output.txt",ios :: out | ios :: app);
		if (!(fp.is_open())) {
			cout << "Couldn't to open the file" << endl;
			exit(1);
		}
		
		cout << "\x1B[37m";
		while (ptr != NULL) {
			if (ptr->getcoeff() < 0) {
				out << ptr->getcoeff() << "x^" << ptr->getpow();
				fp << ptr->getcoeff() << "x^" << ptr->getpow();
				if (ptr->next != NULL) {
					out << " + ";
					fp << " + ";
				}
				
			}
			if ((ptr->getcoeff() > 0)) {
				out << ptr->getcoeff() << "x^" << ptr->getpow();
				fp << ptr->getcoeff() << "x^" << ptr->getpow();
				if (ptr->next != NULL) {
					out << " + ";
					fp << " + ";
				}
			}
		
			if (ptr->getpow() == 0)
			{
				out << ptr->getcoeff();
				fp << ptr->getcoeff();
				if (ptr->next != NULL) {
					out << " + ";
					fp << " + ";
				}
			}

			ptr = ptr->next;
			
		}
		cout << "\x1B[36m";
		
		fp <<"\n"<< endl;
		fp.close();
		return out;
	}
	friend Poly operator + (Poly &p1,Poly &p2) {
		Poly  tmp;
	   
		NODE* ptr2 = p2.head;
		NODE* ptr1 = p1.head;
			while (ptr2 != NULL) {
			
				tmp.add_node(tmp.creat_node(ptr2->getcoeff(), ptr2->getpow()));

				
				ptr2 = ptr2->next;
			}
			while (ptr1 != NULL) {
				tmp.add_node(tmp.creat_node(ptr1->getcoeff(), ptr1->getpow()));

				ptr1 = ptr1->next;
			}
		
		return tmp;
	}
	friend istream& operator >>(istream& in, Poly& p) {
		NODE* ptr;
	
		ptr = p.head;
		int way = 0;
		cout << "1-Using A file.\n"
			<< "2-Using A keyboard.\n";
		cout << "Choose A Number:";cin >> way;
		if (ptr != NULL) {
			p.delete_poly();
		}

		if(way ==1){
			int size = 0;
			fstream fp;
			fp.open("input.txt", ios::in);
			if (!fp) {
				cout << "Could not open the file" << endl;
				exit(1);
			}
			else {
				fp >> size;
				int* arr_pow = new int[size];
				int* arr_coeff = new int[size];
				for (int i = 0; i < size; i++) {
					fp >> arr_coeff[i] >> arr_pow[i];
				}
				p.setpoly(arr_coeff, arr_pow, size);
				
			
		
			}
			return in;
		}
		else if (way == 2) {
		
			int size;
			cout << "The Size of the polynomial :" << endl;
			cin >> size;
			cout << "Enter The Coeff array(Please put a space between the numbers) :" << endl;
			int* COEFF_arr = new int[size];
			for (int i = 0; i < size; i++) {
				cout << i + 1 << "-Insert Number " << " :";
				cin >> COEFF_arr[i];
			}
			cout << "Enter The Power array(Please put a space between the numbers) :" << endl;
			int* POW_arr = new int[size];
			for (int i = 0; i < size; i++) {
				cout << "Insert Number " << i + 1 << " :";
				cin >> POW_arr[i];
			}
			p.setpoly(COEFF_arr, POW_arr, size);

			return in;
		}
		else {
			cout << "Please Choose a number 1-2.";
			system("PAUSE");
			system("CLS");

		}
	}
	
	Poly* next;
	
};
class LinkedList {
private:
	Poly* head;
public:
	LinkedList() {
		head = NULL;
	}
	~LinkedList() {}
	void add_NODE(Poly *n) {
		Poly* p1, * p2;
		p1 = p2 = head;
		if (head == NULL) {

			head = n;
			n->next=NULL;
			return;
		}
		while (p1->next != NULL) {
			p1 = p1->next;
		}
		p1->next = n;
		n->next = NULL;
		return;
		
	}
	void print_list() {
		Poly* ptr;
		ptr = head;
		int i = 1;
		cout << endl << "Polynomials List :--------------" << endl;
		if (ptr == NULL) {
			cout << "\x1B[37mThere's No polynomials in the list\n\x1B[36m" << endl;
			return;
		}
		while (ptr != NULL) {
	
			cout <<" ("<<i<<") "<<*ptr;
			cout << endl;
			i++;
			ptr = ptr->next;
			
		}
		cout << endl;
	}
	Poly * find_poly(int i) {
		
		Poly *ptr;
		int count = 1;
		ptr = head;
		if (ptr == NULL) {
			cout << "\x1B[31mErorr : Empty Polynomial.\x1B[36m" << endl;
			exit(1);
		}
		while (ptr != NULL ) {
			if (count == i) {
				return ptr;
			}
			ptr = ptr->next;
			count++;
		}
		
		cout << "\x1B[37mTheres No Polynomial saved in " <<"(" <<i<<")\x1B[0m";
		cout << endl;
	}

};

int degree(Poly *A) {
	
	return A->tail_get()->getpow();
}




