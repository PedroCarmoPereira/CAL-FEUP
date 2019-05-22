#include <iostream>
#include <vector>
#include "utils.h"
#include "graphviewer.h"
#include "User.h"
#include "Graph.h"

using namespace std;

bool var_exit = false;

void insertUser(vector<User>& v){
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


	int dT;
	cout << "destiantination tolerance:"; 
	cin >> dT;

	int aT;
	cout << "arrival tolerance:"; 
	cin >> aT;
	

	User u = User( id, s, d, dT, aT);
	v.push_back(u);

}

void displayUsers(vector<User> v){
    for (auto u: v){
		cout << u.getId() << endl;
	}

}

int main(){
	string nodeFile, edgeFile;
	setFiles(FAFE, nodeFile, edgeFile);
	//cout << nodeFile << endl;
	//cout << edgeFile << endl;

	Graph <int> rideSharing = readFiles(nodeFile, edgeFile);

	GraphViewer *gv;
	graphViewer(gv, &rideSharing);

/**************************************  MENU  ***********************************************/
	vector<User> v;
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
			insertUser(v);
			cout << endl;
			break;
		case 2:
			displayUsers(v);
			cout << endl;
			break;
		case 3:
			cout << "Exit\n" << endl;
			var_exit = true;
			break;
		default:
			cout << "Invalid Option!\n" << endl;
			cin.clear();
			cin.ignore();
			break;
		}
	}

/*********************************************************************************************/
	//getchar();
	//gv->closeWindow();

	return 0;
}
