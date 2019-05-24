#include <iostream>
#include <vector>
#include <ctime>
#include "utils.h"
#include "graphviewer.h"
#include "User.h"
#include "Driver.h"

using namespace std;


void insertUser(vector<User>& v){

	time_t now = time(0);
	tms *dep, *arr;
	dep = gmtime(&now);
	arr = gmtime(&now);
	int id;
	cout << "id:"; 
	cin >> id;

	int s;
	cout << "source id:";
	cin >> s;

	int d;
	cout << "destination id:";
	cin >> d;

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

Graph<Node> CreateTestGraph() {
	//BASEADO NO DO BATOSTA		
  Graph<Node> myGraph;

  return myGraph;
}


int main(){
	//string nodeFile, edgeFile;
	//setFiles(PORTO, nodeFile, edgeFile);

	//inicial graph -> city map
	Graph<Node> g;// = readFiles(nodeFile, edgeFile);
	Node n0 = Node(0);
	Node n1 = Node(1);
	Node n2 = Node(2);
	Node n3 = Node(3);
	Node n4 = Node(4);
	Node n5 = Node(5);
	g.addVertex(n0);
	g.addVertex(n1);
	g.addVertex(n2);
	g.addVertex(n3);
	g.addVertex(n4);
	g.addVertex(n5);

	g.addEdge(n0, n1, 5);
	g.addEdge(n1, n5, 2);
	g.addEdge(n0, n2, 3);
	g.addEdge(n2, n3, 4);
	g.addEdge(n3, n5, 1);
	g.addEdge(n3, n4, 2);

	g.dijkstraShortestPath(0);
	const vector<Node> &v = g.getPath(n0, n5);
	cout << weightPath(g, v) << endl;
	/*
	vector<Node> v = g.getPath(n0, n5);
	for(vector<Node>::const_iterator it = v.begin(); it != v.end(); it++) cout << it->id << endl;*/
/*
	Graph<int> g = CreateTestGraph();
	g.dijkstraShortestPath(1);
	vector<int> v = g.getPath(1, 7);
	for(vector<int>::const_iterator it = v.begin(); it != v.end(); it++) cout << *it << endl;*/

	//vector<User> v;
	//menu(v);

	//users graph
	//Graph<Node> users = userGraph(v, g);

	//GraphViewer *gv;
	//graphViewer(gv, &g);

	//getchar();
	//gv->closeWindow();

	return 0;
}
