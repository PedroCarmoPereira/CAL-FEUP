#include <iostream>
#include <vector>
#include <ctime>
#include "utils.h"
#include "graphviewer.h"
#include "User.h"


using namespace std;


void insertUser(vector<User>& v){

	time_t now = time(0);
	tms *dep, *arr;
	dep = gmtime(&now);
	arr = gmtime(&now);
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

	cout << "departure hour:";
	cin >> dep->tm_hour;
	cout << "departure minute:";
	cin >> dep->tm_min;

	cout << "arrival hour:";
	cin >> arr->tm_hour;
	cout << "arrival minute:";
	cin >> arr->tm_min;

	if(arr->tm_hour < dep->tm_hour){
		arr->tm_mday++;
		arr->tm_wday++;
		arr->tm_yday++;
	}

	int dT;
	cout << "destiantination tolerance:"; 
	cin >> dT;

	int aT;
	cout << "arrival tolerance:"; 
	cin >> aT;
	
	int driving;
	cout << "Driver(1)Passanger(0):";
	cin >> driving;


	User u = User( id, s, d, *dep, *arr, dT, aT, driving);
	v.push_back(u);

}

void displayUsers(vector<User> v){
    for (auto u: v){
		cout << u.getId() << endl;
	}

}

void menu(vector<User> & v){
	bool var_exit = false;
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
}

int main(){
	string nodeFile, edgeFile;
	setFiles(PORTO, nodeFile, edgeFile);

	//inicial graph -> city map
	Graph<Node> g = readFiles(nodeFile, edgeFile);

	vector<User> v;
	menu(v);

	//users graph
	Graph<Node> users = userGraph(&v, &g);

	GraphViewer *gv;
	graphViewer(gv, &g);

	//getchar();
	//gv->closeWindow();

	return 0;
}
