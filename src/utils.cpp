#include "utils.h"
#include "Graph.h"
#include <sstream>
#include <cmath>
#include <fstream>



using namespace std;

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
 * 
**/
Graph <Coords> readFiles(string nodeFile, string edgeFile){

	Graph <Coords> graph;

	string line;
	
	ifstream fnodes;
	int nNodes;
	int nodeID;
	Coords nodeCoords;

	//open node file
	fnodes.open(nodeFile);
	if(!fnodes.is_open()){
		cerr << "fnodes failed!" << endl;
		return;
	}
	
	//read node file
	getline(fnodes, line);
	nNodes = atoi(strtok((char*)line.c_str(), "\n"));
	cout << nNodes << endl;

	while (getline (fnodes,line)){

		nodeID = floor(atof(strtok((char*)line.c_str(), "(,")));

		nodeCoords.x = floor(atof(strtok(NULL, "(,)")));

		nodeCoords.y = floor(atof(strtok(NULL, "(,)")));

		graph.addVertex(nodeCoords);

		graph.v
	}


	fnodes.close();

	ifstream fedges;
	int nEdges;
	int node1, node2;
	int index = 0;

	//open edgs file
	fedges.open(edgeFile);
	if(!fedges.is_open()){
		cerr << "fnodes failed!" << endl;
		return;
	}

	//read edge file
	getline(fedges, line);
	nEdges = atoi(strtok((char*)line.c_str(), "\n"));
	cout << "nEdges: " << nEdges << endl;

	while (getline (fedges,line)){

		node1 = floor(atof(strtok((char*)line.c_str(), "(,")));

		node2 = floor(atof(strtok(NULL, "(,)")));

		
		index++;
	}

	fedges.close();

	return graph;
}
