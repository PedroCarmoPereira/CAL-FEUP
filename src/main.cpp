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

#define DIST_PORTO_FAFE		68300

/**
 * Joins the two graphs.
**/
Graph<Node> joinGraph(Graph<Node> graph_source, Graph<Node> graph_dest){

    vector<Vertex<Node> *>  vertexSet = graph_dest.getVertexSet();
    for(vector<Vertex<Node > *>::const_iterator itv = vertexSet.begin(); itv != vertexSet.end(); itv++){
        graph_source.addVertex((*itv)->getInfo());
	}
	for(vector<Vertex<Node > *>::const_iterator itv = vertexSet.begin(); itv != vertexSet.end(); itv++){
		vector<Edge<Node> > adjSet = (*itv)->getAdj();
		for(vector<Edge<Node> >::const_iterator it = adjSet.begin(); it != adjSet.end(); it++)
			graph_source.addEdge((*itv)->getInfo(), (*it).getDest()->getInfo(),(*it).getWeight() );
	}
    return graph_source;
}

/**
 * Inserts the driver.
**/
void insertDriver(Driver &driver){
	//Driver(0, 90379615, 288195753, dep, arr, 10, 10, 5)
	/*
	time_t now = time(0);
	tms dep = *localtime(&now);
	tms arr = *localtime(&now);
	dep.tm_hour = 10;
	dep.tm_min = 45;
	arr.tm_hour = 23;
	arr.tm_min = 59;
	*/

	time_t now = time(0);
	tms dep, arr;
	dep = *localtime(&now);
	arr = *localtime(&now);

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
	cin >> dep.tm_hour;
	cout << "departure minute:";
	cin >> dep.tm_min;

	cout << "arrival hour:";
	cin >> arr.tm_hour;
	cout << "arrival minute:";
	cin >> arr.tm_min;

	if(arr.tm_hour < dep.tm_hour){
		arr.tm_mday++;
		arr.tm_wday++;
		arr.tm_yday++;
	}

	int dT;
	cout << "destiantination tolerance:"; 
	cin >> dT;

	int aT;
	cout << "arrival tolerance:"; 
	cin >> aT;

	int cap;
	cout << "vehicle capacity:"; 
	cin >> cap;

	driver = Driver(id, s, d, dep, arr, dT, aT, cap);
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

	User u = User( id, s, d, *dep, *arr, dT, aT, 0);
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
void menu(vector<User> & v, Driver & driver){
	bool var_exit = false;
	bool driver_flag = false;
	while(!var_exit){

		cout << "Welcome to RideSharing! Please choose a option." << endl;
    	cout << "1-Insert Driver." << endl;
		cout << "2-Read users from file." << endl;
		cout << "3-Insert new users." << endl;
		cout << "4-See all users." << endl;
		cout << "5-Start Program." << endl;
		cout << "6-Exit." << endl;
		int s;
		cin >> s; 

		switch (s){
			case 1:
					insertDriver(driver);
					driver_flag = true;
					cout << endl;
					break;
			case 2:
					v = readUsers("users.txt");
					cout << endl;
					break;
			case 3:
					insertUser(v);
					cout << endl;
					break;
			case 4:
					displayUsers(v);
					cout << endl;
					break;
			case 5:
					if(!driver_flag){
						cout << "Error! Insert driver!" << endl;
						break;
					}
					var_exit = true;
					break;
			case 6:
					cout << "Exiting.." << endl;
					exit(0);
			default:
					cout << "Invalid Option!\n" << endl;
					cin.clear();
					cin.ignore();
					break;
		}
	}
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
	Graph<Node> g_dep = readFiles(nodeFile, edgeFile);
	setFiles(FAFE, nodeFile, edgeFile);
	Graph<Node> g_arr = readFiles(nodeFile, edgeFile);

	Driver driver;
	vector<User> u;
	menu(u, driver);

	//process Porto and fafe graphs
	RideShare r = RideShare(g_dep,g_arr, driver, u);
	r.removeUsers();
	r.trimGraph();

	//get all the nodes we need to go, only users
	r.pickUp();
	vector<Node> source_nodes = r.getSource_nodes();
	vector<Node> dest_nodes = r.getDest_nodes();

	//get the final graphs, remove the other nodes
	g_dep = r.getGraphSource();
	g_arr = r.getGraphDest();
	for(auto v : g_dep.getVertexSet()){
		if(v->getInfo().id != r.driver.getSourceID() && v->getInfo().id != r.driver.getDestinationID()){
			bool to_remove = true;
			for(auto u : source_nodes){
				if(v->getInfo().id == u.id)
					to_remove = false;
			}
			if(to_remove)
				g_dep.removeVertex(v->getInfo());	
		}
	}
	for(auto v : g_arr.getVertexSet()){
		if(v->getInfo().id != r.driver.getSourceID() && v->getInfo().id != r.driver.getDestinationID()){
			bool to_remove = true;
			for(auto u : dest_nodes){
				if(v->getInfo().id == u.id)
					to_remove = false;
			}
			if(to_remove)
				g_arr.removeVertex(v->getInfo());	
		}
	}
	//GraphViewer
	//Join the two final graphs
	/*
	GraphViewer *gv;
	Graph<Node> q = joinGraph(g_dep, g_arr);
	graphViewer(gv, &q);
	*/

	//use the graphs and the nodes to implement Held–Karp algorithm
	Node d_n1 = g_dep.findVertex(r.driver.getSourceID())->getInfo();
	Node d_n2 = g_arr.findVertex(r.driver.getDestinationID())->getInfo();
	
	cout << "\nOPTIMAL PATH ORIGIN" << endl;
	for( auto u : g_dep.getTSP_Path(d_n1, false)) cout << u << " \t" << endl;
	
	cout << "\nOPTIMAL PATH DESTINATION" << endl;
	for( auto u : g_arr.getTSP_Path(d_n2, true)) cout << u << " \t" << endl;
	//gv->closeWindow();

	return 0;
}
