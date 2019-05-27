#include <iostream>
#include <vector>
#include <ctime>
#include "Graph.h"
#include "utils.h"
#include "graphviewer.h"
#include "User.h"
#include "Driver.h"
#include "RideShare.h"

using namespace std;

/**
 * Joins the two graphs.
**/
Graph<Node> joinGraph(Graph<Node> graph_source, Graph<Node> graph_dest){

    vector<Vertex<Node> *>  vertexSet = graph_dest.getVertexSet();
    for(vector<Vertex<Node > *>::const_iterator itv = vertexSet.begin(); itv != vertexSet.end(); itv++){
        graph_source.addVertex((*itv)->getInfo());
	}
	for(vector<Vertex<Node > *>::const_iterator itv = vertexSet.begin(); itv != vertexSet.end(); itv++){
		vector<Edge<Node>> adjSet = (*itv)->getAdj();
		for(vector<Edge<Node>>::const_iterator it = adjSet.begin(); it != adjSet.end(); it++)
			graph_source.addEdge((*itv)->getInfo(), (*it).getDest()->getInfo(),(*it).getWeight() );
	}
    return graph_source;
}

/**
 * Inserts the created user into the users vector. 
**/
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

/**
 * Displays the Ids of the users created.
 * @param v
**/
void displayUsers(vector<User> v){
    for (auto u: v){
		cout << u.getId() << endl;
	}

}

/**
 * Funtion that displays the menu and computes the user inputs.
 * @param v
**/
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

/**
 * Auxiliar funtion. 
 * Creats the graph that represents the city map.
 * @return myGraph
**/
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

/**
 * Main funtion.
 * Inicializes the city map graph.
 * Inicializes the users vector.
 * Inicializes the user graph.
 **/
int main(){

	//get Porto and Fafe graphs
	string nodeFile, edgeFile;
	setFiles(PORTO, nodeFile, edgeFile);
	Graph<Node> g_porto = readFiles(nodeFile, edgeFile);
	setFiles(FAFE, nodeFile, edgeFile);
	Graph<Node> g_fafe = readFiles(nodeFile, edgeFile);

	//get Driver info
	time_t now = time(0);
	tms dep = *localtime(&now);
	tms arr = *localtime(&now);
	arr.tm_hour++;

	//get users saved in users.txt
	vector<User> u = readUsers("users.txt");

	//process Porto and fafe graphs
	RideShare r = RideShare(g_porto,g_fafe, 0, 90379615, 288195753, dep, arr, 10, 5, 5, u);
	r.removeUsers();
	r.trimGraph();

	//get all the nodes we need to go, only users
	r.pickUp();
	vector<Node> source_nodes = r.getSource_nodes();
	vector<Node> dest_nodes = r.getDest_nodes();

	//get the final graphs, remove the other nodes
	g_porto = r.getGraphSource();
	g_fafe = r.getGraphDest();
	for(auto v : g_porto.getVertexSet()){
		if(v->getInfo().id != 90379615 && v->getInfo().id !=288195753){
			bool to_remove = true;
			for(auto u : source_nodes){
				if(v->getInfo().id == u.id)
					to_remove = false;
			}
			if(to_remove)
				g_porto.removeVertex(v->getInfo());	
		}
	}
	for(auto v : g_fafe.getVertexSet()){
		if(v->getInfo().id != 90379615 && v->getInfo().id !=288195753){
			bool to_remove = true;
			for(auto u : dest_nodes){
				if(v->getInfo().id == u.id)
					to_remove = false;
			}
			if(to_remove)
				g_fafe.removeVertex(v->getInfo());	
		}
	}
	
	//GraphViewer
	//Join the two final graphs
	/*GraphViewer *gv;
	Graph<Node> q = joinGraph(g_porto, g_fafe);
	graphViewer(gv, &q);*/

	//use the graphs and the nodes to implement Held–Karp algorithm
	Node d_n1 = g_porto.findVertex(90379615)->getInfo();
  Node d_n2 = g_fafe.findVertex(288195753)->getInfo();
	g_porto.getTSP_Path(d_n1);
	g_fafe.getTSP_Path(d_n2);


	//gv->closeWindow();

	return 0;
}
