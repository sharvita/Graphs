#include <iostream>
#include <string>
using namespace std;


struct Node
{
	char data;

	Node *north, *south, *east, *west;// these are pointers so that they can be pointed to a specific nodes 
};
int main() {

	Node A, B, C, D, E, F, G, H, I, J, K, L;
	Node *currentLocation = &A;

	A.data = 'A';
	B.data = 'B';
	C.data = 'C';
	D.data = 'D';
	E.data = 'E';
	F.data = 'F';
	G.data = 'G';
	H.data = 'H';
	I.data = 'I';
	J.data = 'J';
	K.data = 'K';
	L.data = 'L';

	currentLocation->data = A.data; // this sets the current location to this.
	

	A.north = NULL;
	A.south = &E;
	A.west = NULL;
	A.east = &B;


	B.north = NULL;
	B.east = NULL;
	B.south = &F;
	B.west = &A;
	

	C.north = NULL;
	C.east = NULL;
	C.south = &G;
	C.west = NULL;

	D.north = NULL;
	D.east = NULL;
	D.south = &H;
	D.west = NULL;

	E.north = &A;
	E.east = NULL;
	E.south = &I;
	E.west = NULL;


	F.north = &B;
	F.east = &G;
	F.south = NULL;
	F.west = NULL;


	G.north = &C;
	G.east = &H;
	G.south = NULL;
	G.west = &F;


	H.north = &D;
	H.east = NULL;
	H.south = &L;
	H.west = &G;


	I.north = &E;
	I.east = &J;
	I.south = NULL;
	I.west = NULL;


	J.north = NULL;
	J.east = &K;
	J.south = NULL;
	J.west = &I;


	K.north = NULL;
	K.east = NULL;
	K.south = NULL;
	K.west = &J;

	char input;

	do
	{
		cout << "Current Location is " << currentLocation->data << endl;

		if (currentLocation->north != NULL)//checks and prints all the cases that are not null.
			cout << "Enter N to go North " << endl;

		if (currentLocation->south != NULL)
			cout << "Enter S to go South " << endl;

		if (currentLocation->east != NULL)
			cout << "Enter E to go East " << endl;

		if (currentLocation->west != NULL)
			cout << "Enter W to go West " << endl;
		
		cout << "Enter Q to exit the game anytime" << endl;

		cin >> input;
	    

		if ((input == 'N' || input == 'n') && currentLocation->north != NULL) // This keeps track of the position of the user
		{
			currentLocation = currentLocation->north;
		}

		else if ((input == 'S' || input == 's') && currentLocation->south != NULL)
		{
			currentLocation = currentLocation->south;
		}

		else if ((input == 'E' || input == 'e') && currentLocation->east != NULL)
		{
			currentLocation = currentLocation->east;
		}

		 else if ((input == 'W' || input == 'w') && currentLocation->west != NULL)

		 {
			currentLocation = currentLocation->west;
		}

		 else if(input != 'Q' && input != 'q') // If the user wants to quit
		{
			cout << "Invalid Input" << endl;
		}

		cout << endl;

	} while (currentLocation->data != 'L' && (input != 'Q' && input != 'q')); // until user enters Q

	if (currentLocation->data == 'L')
		cout << "You Win" << endl;
	system("pause");

	
	return 0;
	
}