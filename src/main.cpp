#include <iostream>
#include <vector>
#include <ctime>
#include "Graph.h"
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
	myGraph.addVertex(Node(1, coords(16,  130)));
	myGraph.addVertex(Node(2, coords(64,  324)));
	myGraph.addVertex(Node(3, coords(87,  709)));
	myGraph.addVertex(Node(4, coords(247, 733)));
	myGraph.addVertex(Node(5, coords(270, 534)));
	myGraph.addVertex(Node(6, coords(378, 522)));
	myGraph.addVertex(Node(7, coords(420, 349)));
	myGraph.addVertex(Node(8, coords(445, 156)));
	myGraph.addVertex(Node(9, coords(223,  91)));
	myGraph.addVertex(Node(10, coords(205, 321)));
	myGraph.addVertex(Node(11, coords(139, 286)));
	myGraph.addVertex(Node(12, coords(175, 493)));
	myGraph.addVertex(Node(13, coords(354, 748)));
	myGraph.addVertex(Node(14, coords(597, 727)));
	myGraph.addVertex(Node(15, coords(649, 526)));
	myGraph.addVertex(Node(16, coords(541, 499)));
	myGraph.addVertex(Node(17, coords(508, 628)));
	myGraph.addVertex(Node(18, coords(462, 130)));
	myGraph.addVertex(Node(19, coords(712, 270)));
	myGraph.addVertex(Node(20, coords(595, 238)));
	myGraph.addVertex(Node(21, coords(615, 141)));
	myGraph.addVertex(Node(22, coords(528, 150)));
	myGraph.addVertex(Node(23, coords(519, 217)));
	myGraph.addVertex(Node(24, coords(457, 45)));
	myGraph.addVertex(Node(25, coords(710, 45)));
	myGraph.addVertex(Node(26, coords(153, 234)));
	
	Vertex<Node> *a, *b;
	a = myGraph.findVertex(Node(1));
	b = myGraph.findVertex(Node(2));
	myGraph.addEdge(a->getInfo(), b->getInfo(),  edgeWeight(*a, *b));
	myGraph.addEdge(b->getInfo(), a->getInfo(),  edgeWeight(*a, *b));
	a = myGraph.findVertex(Node(3));
	myGraph.addEdge(b->getInfo(), a->getInfo(),  edgeWeight(*a, *b));
	myGraph.addEdge(a->getInfo(), b->getInfo(),  edgeWeight(*a, *b));
	b = myGraph.findVertex(Node(4));
	myGraph.addEdge(b->getInfo(), a->getInfo(),  edgeWeight(*a, *b));
	myGraph.addEdge(a->getInfo(), b->getInfo(),  edgeWeight(*a, *b));
	a = myGraph.findVertex(Node(13));
	myGraph.addEdge(b->getInfo(), a->getInfo(),  edgeWeight(*a, *b));
	myGraph.addEdge(a->getInfo(), b->getInfo(),  edgeWeight(*a, *b));
	b = myGraph.findVertex(Node(14));
	myGraph.addEdge(b->getInfo(), a->getInfo(),  edgeWeight(*a, *b));
	myGraph.addEdge(a->getInfo(), b->getInfo(),  edgeWeight(*a, *b));
	a = myGraph.findVertex(Node(15));
	myGraph.addEdge(b->getInfo(), a->getInfo(),  edgeWeight(*a, *b));
	myGraph.addEdge(a->getInfo(), b->getInfo(),  edgeWeight(*a, *b));
	b = myGraph.findVertex(Node(16));
	myGraph.addEdge(a->getInfo(), b->getInfo(),  edgeWeight(*a, *b));
	a = myGraph.findVertex(Node(17));
	myGraph.addEdge(b->getInfo(), a->getInfo(),  edgeWeight(*a, *b));
	a = myGraph.findVertex(Node(18));
	myGraph.addEdge(b->getInfo(), a->getInfo(),  edgeWeight(*a, *b));
	b = myGraph.findVertex(Node(13));
	myGraph.addEdge(a->getInfo(), b->getInfo(),  edgeWeight(*a, *b));
	a = myGraph.findVertex(Node(4));
	b = myGraph.findVertex(Node(5));
	myGraph.addEdge(a->getInfo(), b->getInfo(),  edgeWeight(*a, *b));
	myGraph.addEdge(b->getInfo(), a->getInfo(),  edgeWeight(*a, *b));
	a = myGraph.findVertex(Node(6));
	myGraph.addEdge(b->getInfo(), a->getInfo(),  edgeWeight(*a, *b));
	b = myGraph.findVertex(Node(7));
	myGraph.addEdge(a->getInfo(), b->getInfo(),  edgeWeight(*a, *b));
	a = myGraph.findVertex(Node(8));
	myGraph.addEdge(b->getInfo(), a->getInfo(),  edgeWeight(*a, *b));
	b = myGraph.findVertex(Node(9));
	myGraph.addEdge(b->getInfo(), a->getInfo(),  edgeWeight(*a, *b));
	a = myGraph.findVertex(Node(10));
	myGraph.addEdge(b->getInfo(), a->getInfo(),  edgeWeight(*a, *b));
	b = myGraph.findVertex(Node(12));
	myGraph.addEdge(a->getInfo(), b->getInfo(),  edgeWeight(*a, *b));
	b = myGraph.findVertex(Node(7));
	myGraph.addEdge(b->getInfo(), a->getInfo(),  edgeWeight(*a, *b));
	myGraph.addEdge(a->getInfo(), b->getInfo(),  edgeWeight(*a, *b));
	b = myGraph.findVertex(Node(11));
	myGraph.addEdge(b->getInfo(), a->getInfo(),  edgeWeight(*a, *b));
	myGraph.addEdge(a->getInfo(), b->getInfo(),  edgeWeight(*a, *b));
	a = myGraph.findVertex(Node(2));
	myGraph.addEdge(b->getInfo(), a->getInfo(),  edgeWeight(*a, *b));
	myGraph.addEdge(a->getInfo(), b->getInfo(),  edgeWeight(*a, *b));
	a = myGraph.findVertex(Node(26));
	myGraph.addEdge(b->getInfo(), a->getInfo(),  edgeWeight(*a, *b));
	myGraph.addEdge(a->getInfo(), b->getInfo(),  edgeWeight(*a, *b));
	a = myGraph.findVertex(Node(19));
	b = myGraph.findVertex(Node(15));
	myGraph.addEdge(a->getInfo(), b->getInfo(),  edgeWeight(*a, *b));
	myGraph.addEdge(b->getInfo(), a->getInfo(),  edgeWeight(*a, *b));
	b = myGraph.findVertex(Node(25));
	myGraph.addEdge(a->getInfo(), b->getInfo(),  edgeWeight(*a, *b));
	myGraph.addEdge(b->getInfo(), a->getInfo(),  edgeWeight(*a, *b));
	a = myGraph.findVertex(Node(8));
	b = myGraph.findVertex(Node(24));
	myGraph.addEdge(a->getInfo(), b->getInfo(),  edgeWeight(*a, *b));
	a = myGraph.findVertex(Node(25));
	myGraph.addEdge(a->getInfo(), b->getInfo(),  edgeWeight(*a, *b));
	myGraph.addEdge(b->getInfo(), a->getInfo(),  edgeWeight(*a, *b));
	a = myGraph.findVertex(Node(9));
	b = myGraph.findVertex(Node(1));
	myGraph.addEdge(a->getInfo(), b->getInfo(),  edgeWeight(*a, *b));
	myGraph.addEdge(b->getInfo(), a->getInfo(),  edgeWeight(*a, *b));
	a = myGraph.findVertex(Node(19));
	b = myGraph.findVertex(Node(20));
	myGraph.addEdge(a->getInfo(), b->getInfo(),  edgeWeight(*a, *b));
	myGraph.addEdge(b->getInfo(), a->getInfo(),  edgeWeight(*a, *b));
	a = myGraph.findVertex(Node(21));
	myGraph.addEdge(b->getInfo(), a->getInfo(),  edgeWeight(*a, *b));
	b = myGraph.findVertex(Node(22));
	myGraph.addEdge(a->getInfo(), b->getInfo(),  edgeWeight(*a, *b));
	a = myGraph.findVertex(Node(23));
	myGraph.addEdge(b->getInfo(), a->getInfo(),  edgeWeight(*a, *b));
	b = myGraph.findVertex(Node(20));
	myGraph.addEdge(a->getInfo(), b->getInfo(),  edgeWeight(*a, *b));
	a = myGraph.findVertex(Node(12));
	b = myGraph.findVertex(Node(5));
	myGraph.addEdge(a->getInfo(), b->getInfo(),  edgeWeight(*a, *b));
	a = myGraph.findVertex(Node(9));
	b = myGraph.findVertex(Node(24));
	myGraph.addEdge(a->getInfo(), b->getInfo(),  edgeWeight(*a, *b));
	myGraph.addEdge(b->getInfo(), a->getInfo(),  edgeWeight(*a, *b));
  return myGraph;
}


int main(){
	//string nodeFile, edgeFile;
	//setFiles(PORTO, nodeFile, edgeFile);

	//inicial graph -> city map
	Graph<Node> g;// = readFiles(nodeFile, edgeFile);
	Node n1 = Node(1);
	Node n2 = Node(10);
	g = CreateTestGraph();

	g.dijkstraShortestPath(1);
	const vector<Node> &v = g.getPath(n1, n2);
	for(vector<Node>::const_iterator it = v.begin(); it != v.end(); it++) cout << it->id << endl;
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
