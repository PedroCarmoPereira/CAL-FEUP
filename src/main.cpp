#include <iostream>
#include "utils.h"
#include "graphviewer.h"
#include "User.h"


using namespace std;

bool var_exit = false;

void insertUser(){
	int id;
	cout << "id:"; 
	cin >> id;

	coords_t s;
	cout << "source x_or_lat:";
	cin >> s.x_or_lat;
	cout << "source y_or_lon:";
	cin >> s.y_or_lon;

	coords_t d;
	cout << "destination x_or_lat:";
	cin >> d.x_or_lat;
	cout << "destination y_or_lon:";
	cin >> d.y_or_lon;

	simple_time_t dep;
	cout << "departure hour:";
	cin >> dep.hour;
	cout << "departure min:";
	cin >> dep.min;
	cout << "departure pastMidnight 1-true/0-false:";
	cin >> dep.pastMidnight;

	simple_time_t arr;
	cout << "arrival hour:";
	cin >> arr.hour;
	cout << "arrival min:";
	cin >> arr.min;
	cout << "arrival pastMidnight 1-true/0-false:";
	cin >> arr.pastMidnight;

	int dT;
	cout << "destiantination tolerance:"; 
	cin >> dT;

	int aT;
	cout << "arrival tolerance:"; 
	cin >> aT;
	

	//User u = User( id, s, d, dep, arr, dT, aT);

}

void displayUsers(){
    cout << "(...)\n" << endl;

}

int main(){
	string nodeFile, edgeFile;
	setFiles(PORTO, nodeFile, edgeFile);
	//cout << nodeFile << endl;
	//cout << edgeFile << endl;

	GraphViewer *gv = new GraphViewer(600, 600, false);
	gv->createWindow(600, 600);
	gv->defineVertexColor("blue");
	gv->defineEdgeColor("black");
	//gv->closeWindow();

	readFiles(gv, nodeFile, edgeFile);

/**************************************  MENU  ***********************************************/

	while(!var_exit){

		cout << "Welcome to RideSharing! Please choose a option." << endl;
		cout << "1-Insert new user." << endl;
		cout << "2-See all users." << endl;
		cout << "3-Exit." << endl;
		int s;
		cin >> s; 
		switch (s)
		{
		case 1:
			insertUser();
			cout << endl;
			break;
		case 2:
			displayUsers();
			cout << endl;
			break;
		case 3:
			cout << "Exit\n" << endl;
			var_exit = true;
			break;
		default:
			cout << "Invalid Option!\n" << endl;
			break;
		}
	}

/*********************************************************************************************/
	//getchar();
	gv->closeWindow();

	return 0;
}
