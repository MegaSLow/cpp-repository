#include <iostream>
#include <cmath>

void main(void) {
	using namespace std;
	char direct = 'y';
	int select;
	
	while(direct == 'y') {

		cout << "Enter number of variant:";
		cin >> select;

		switch(select) {

		case 1: 
           cout << "Case 1" << endl;
		   
		   break;
		default: 
			cout << "Selected variant doesnt exist" << endl;
			break;
		}

      cout << "Enter y to try again:" ;
	  cin >> direct;


		





	}






}
