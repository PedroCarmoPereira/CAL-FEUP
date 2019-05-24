#include "utils.h"
#include "Graph.h"
#include "User.h"
#include <sstream>
#include <cmath>
#include <fstream>
#include <vector>

using namespace std;

/**
 * 
**/
Coords coords(int x, int y){
	Coords c;
	c.x_or_lat = x;
	c.y_or_lon = y;
	return c;
}

Node::Node(){this->id = 0;}

Node::Node(int id): id(id){}

Node::Node(const Node& node){
	this->id = node.id;
	this->coords.x_or_lat = node.getCoords().x_or_lat;
	this->coords.y_or_lon = node.getCoords().y_or_lon;
}

Node::Node(int id, Coords c){
	this->id = id;
	this->coords.x_or_lat = c.x_or_lat;
	this->coords.y_or_lon = c.y_or_lon;
}

Node & Node::operator=(const Node & node){
	this->id = node.id;
	this->coords.x_or_lat = node.getCoords().x_or_lat;
	this->coords.y_or_lon = node.getCoords().y_or_lon;
	return *this;
}

bool Node::operator==(const Node &n)const{
	return this->id == n.id;
}

Coords Node::getCoords() const{
	return this->coords;
}

/**
 * 
**/
void setFiles(location loc, string &nodeFile, string &edgeFile){
	stringstream sn, se;
	sn << "../maps/";
	se << "../maps/";
	switch(loc){
	case 0:
		sn << "Aveiro/T01_nodes_X_Y_Aveiro.txt";
		se << "Aveiro/T01_edges_Aveiro.txt";
		break;
	case 1:
		sn << "Braga/T01_nodes_X_Y_Braga.txt";
		se << "Braga/T01_edges_Braga.txt";
		break;
	case 2:
		sn << "Coimbra/T01_nodes_X_Y_Coimbra.txt";
		se << "Coimbra/T01_edges_Coimbra.txt";
		break;
	case 3:
		sn << "Ermesinde/T01_nodes_X_Y_Ermesinde.txt";
		se << "Ermesinde/T01_edges_Ermesinde.txt";
		break;
	case 4:
		sn << "Fafe/T01_nodes_X_Y_Fafe.txt";
		se << "Fafe/T01_edges_Fafe.txt";
		break;
	case 5:
		sn << "Gondomar/T01_nodes_X_Y_Gondomar.txt";
		se << "Gondomar/T01_edges_Gondomar.txt";
		break;
	case 6:
		sn << "Lisboa/T01_nodes_X_Y_Lisboa.txt";
		se << "Lisboa/T01_edges_Lisboa.txt";
		break;
	case 7:
		sn << "Maia/T01_nodes_X_Y_Maia.txt";
		se << "Maia/T01_edges_Maia.txt";
		break;
	case 8:
		sn << "Porto/T01_nodes_X_Y_Porto.txt";
		se << "Porto/T01_edges_Porto.txt";
		break;
	case 9:
		sn << "Viseu/T01_nodes_X_Y_Viseu.txt";
		se << "Viseu/T01_edges_Viseu.txt";
		break;
	default:
		sn << "Portugal/T01_nodes_X_Y_Portugal.txt";
		se << "Portugal/T01_edges_Portugal.txt";
		break;
	}

	nodeFile = sn.str();
	edgeFile = se.str();
}

/**
 * Calculates the Euclidean distance beteewn two vertexes.
 * @param n1
 * @param n2
 * @return sqrt[ (n1.xA-n2.xB)^2 + (n1.yA-n2.yB)^2 ]
**/
double edgeWeight(Vertex <Node> n1, Vertex <Node> n2){

	Coords aux1 = n1.getInfo().getCoords();
	Coords aux2 = n2.getInfo().getCoords();
	double r = sqrt(pow(aux1.x_or_lat-aux2.x_or_lat, 2) + pow(aux1.y_or_lon-aux2.y_or_lon, 2));
	return r;
}

/**
 * Reads data from files and populates the graph
 * @param edgeFile
 * @param nodeFile
 * @return graph
**/
Graph <Node> readFiles(string nodeFile, string edgeFile){

	Graph <Node> graph;

	string line;
	
	ifstream fnodes;
	int nNodes;
	int nodeID;
	Coords nodeCoords;

	//open node file
	fnodes.open(nodeFile);
	if(!fnodes.is_open()){
		cerr << "fnodes failed!" << endl;
		return graph;
	}
	
	//read node file
	getline(fnodes, line);
	nNodes = atoi(strtok((char*)line.c_str(), "\n"));

	while (getline (fnodes,line)){

		nodeID = floor(atof(strtok((char*)line.c_str(), "(,")));

		nodeCoords.x_or_lat = floor(atof(strtok(NULL, "(,)")));

		nodeCoords.y_or_lon = floor(atof(strtok(NULL, "(,)")));

		graph.addVertex(Node(nodeID, nodeCoords));
	}

	fnodes.close();

	//------------------------

	ifstream fedges;
	int nEdges;
	int node1, node2;

	//open edgs file
	fedges.open(edgeFile);
	if(!fedges.is_open()){
		cerr << "fnodes failed!" << endl;
		return graph;
	}

	//read edge file
	getline(fedges, line);
	nEdges = atoi(strtok((char*)line.c_str(), "\n"));
	//cout << "nEdges: " << nEdges << endl;

	while (getline (fedges,line)){

		node1 = floor(atof(strtok((char*)line.c_str(), "(,")));

		node2 = floor(atof(strtok(NULL, "(,)")));

		graph.addEdge(Node(node1), Node(node2), edgeWeight(*graph.findVertex(node1), *graph.findVertex(node2)));
	}

	fedges.close();

	return graph;
}

/**
 * Converts the Graph <Node > provided into a GraphViewer.
 * Displays the GraphViewer.
**/
void graphViewer(GraphViewer *gv, Graph <Node> * rideSharing){

	//inicialize graph viewer
	gv = new GraphViewer(600, 600, false);
	gv->createWindow(600, 600);
	gv->defineVertexColor("blue");
	gv->defineEdgeColor("black");

	//adding nodes
	Node n;
	for(auto v : rideSharing->getVertexSet()){

		n = v->getInfo();

		gv->addNode(n.id, n.getCoords().x_or_lat, n.getCoords().y_or_lon);
	}

	gv->rearrange();

	//adding edges
	int index = 0;
	Node v1;
	for(auto v : rideSharing->getVertexSet()){

		v1 = v->getInfo();

		// adding all outgoing edges of v1
		for(auto v2 : v->getAdj()){
			gv->addEdge(index, v1.id, v2.getDest()->getInfo().id, EdgeType::DIRECTED);
			index++;
		}
	}

	gv->rearrange();

	//gv->closeWindow();
}

/**
 * Calculates the total sum of shortest path found.
 * All the Node in the path found are in the vector<Node > provided in the arguments.
 * @return weight
**/
double weightPath(Graph <Node> &g, const  vector<Node > &v){

	int weight = 0;
	vector<Node >::const_iterator it1, it2;
	it1 = v.begin();
	it2 = v.begin() + 1;
	while(it2 != v.end()){
		vector<Edge <Node> > v =  g.findVertex(*it1)->getAdj();
		for(vector<Edge <Node> >::const_iterator it3 = v.begin(); it3 != v.end(); it3++)
			if (it3->getDest()->getInfo() == *it2) weight += it3->getWeight();
		it1++;
		it2++;
	}
	return weight;
}

/**
 * Converts the weight (represented as distance) to time.
 * @return t;
**/
time_t weightTotime(double w){
	int x = round(w);
	time_t t;
	t = w/MAX_SPEED;
	return t;
}
