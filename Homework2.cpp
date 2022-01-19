
#include "poly.h"
#include<string>

void print_MENU() {
	int k = 1;
	for (int i = 0; i < 15.; i++) {
		cout << "\x1B[37m\037 ";
		cout << "\x1B[36m\037 ";
		cout << "\x1B[39m\037 ";
		cout << "\x1B[35m\037 ";
	}
	for (int i = 0; i < 2; i++) {
		cout << "\n";
	}
	
	cout << "\x1B[37m                  |_____________________________Polynomial Calculator_____________________________|\033[0m" << endl <<"\x1B[36m                  |                                                                               |\033[0m"<< endl;
	cout << "\x1B[36m                  |1-Input A polynomial(re-input a poly delete it and put a new one).             |\003\n"
		<< "                  |2-Print The Polynomial list.                                                   |\n"
		<< "                  |3-Delete A node according to the power.                                        |\n"
		<< "                  |4-Find The degree of a Polynomial.                                             |\n"
		<< "                  |5-Evaluate A number to the polynomial.                                         |\n"
		<< "                  |6-Add Two polynomials into a new one.                                          |\n"
		<< "                  |7-Merge Two Polynomials.                                                       |\n"
		<<""
		<< "                  |8-Exit.                                                                        |\n\n";
	    cout << "Please Enter a Number from 1 to 8 :" << endl;
}

int main()
{
	

		
		

	
	int CHOICE;
	LinkedList polynomial_list;
	
	while (1) {
		
		print_MENU();
	
		cin >> CHOICE;
		if (CHOICE==1) {
			
				Poly* A = new Poly;
				cin >> *A;
				polynomial_list.add_NODE(A);
			
				cout << "The Polynomial : " <<*A << endl;
				cout << "Added SUCCESSFULLY" << endl;
				polynomial_list.print_list();
			
				system("PAUSE");
				system("CLS");
				
			
		}
		else if (CHOICE == 5) {
			int select_poly;
			double eva_num;
			
			polynomial_list.print_list();
                                                      			
			cout << "Select a Polynomial :" << endl;
			cin >> select_poly;
			cout << "Input a Number to evaluate :";
			cin >> eva_num;
			cout << endl;
			
			double sum= polynomial_list.find_poly(select_poly)->eval(eva_num);
			cout << "\x1B[37m";
			cout <<"The evaluation of "<<eva_num<<" is :"<< sum << endl;
			cout << "\x1B[36m";
			system("PAUSE");
			system("CLS");
		}
		else if (CHOICE == 3) {
			int select_poly;
			int pow_del;
			polynomial_list.print_list();
			cout << "Select a Polynomial:";
			cin >> select_poly;
			cout << endl;
			cout << "Choose a term to delete according to the power:";
			cin >> pow_del;
			cout << endl;

			polynomial_list.find_poly(select_poly)->delete_node(pow_del);
			cout << "\nSuccessfully Deleted." << endl;
			system("PAUSE");
			system("CLS");
		}
		else if (CHOICE == 4) {
			int select_poly;
			polynomial_list.print_list();
			cout << "Select a Polynomial:";
			cin >> select_poly;
			cout << endl;
			
			
			int deg = degree(polynomial_list.find_poly(select_poly));
		cout << "\x1B[37m";
		cout << "The degree of this function " << "( " << *(polynomial_list.find_poly(select_poly)) << " ) " << "is " << deg;

		cout << "\x1B[36m";
		cout <<"\n"<< endl;
		
			system("PAUSE");
			system("CLS");
		}
		else if (CHOICE == 2) {
			polynomial_list.print_list();
			system("PAUSE");
			system("CLS");
		}
		else if (CHOICE == 6) {
			polynomial_list.print_list();
			int poly1, poly2;
			cout << "Choose The first polynomial(Number):";
			cin >> poly1;
			cout << "Choose The second polynomial(Number):";
			cin >> poly2;
			Poly *A;
			A = new Poly;
			*A = *(polynomial_list.find_poly(poly1) ) + *(polynomial_list.find_poly(poly2));
			polynomial_list.add_NODE(A);
			cout << "Result of adding " << "(" << *(polynomial_list.find_poly(poly1)) << ") + (" << *(polynomial_list.find_poly(poly2)) << ")"<<endl;
			cout << "is : " << *A <<endl;
			cout << "Added SUCCESSFULLY." << endl;
			system("PAUSE");
			system("CLS");
		}
		else if (CHOICE == 7){
		polynomial_list.print_list();
		int poly1, poly2;
		cout << "Choose The first polynomial(Number):";
		cin >> poly1;
		cout << "Choose The second polynomial(Number)(\x1B[31mThis will be deleted !!\x1B[36m):";
		cin >> poly2;

		polynomial_list.find_poly(poly1)->merge(polynomial_list.find_poly(poly2));
		polynomial_list.print_list();

		system("PAUSE");
		system("CLS");
     	 }
		else if (CHOICE == 8) {
		system("CLS");
		return 0;
         }
		else
		{ 
		cout << "Please Enter a Number from 1 to 8" << endl;
		system("PAUSE");
		system("CLS");
		}

	}
	cout << endl;
	return 0;
}

