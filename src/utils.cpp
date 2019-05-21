#include "utils.h"
#include <sstream>

using namespace std;

void setFiles(location loc, string &nodeFile, string &edgeFile){
	stringstream sn, se;
	sn << "../maps/";
	se << "../maps/";
	switch(loc){
	case 0:
		sn << "Aveiro/T01_nodes_lat_lon_Aveiro.txt";
		se << "Aveiro/T01_edges_Aveiro.txt";
		break;
	case 1:
		sn << "Braga/T01_nodes_lat_lon_Braga.txt";
		se << "Braga/T01_edges_Braga.txt";
		break;
	case 2:
		sn << "Coimbra/T01_nodes_lat_lon_Coimbra.txt";
		se << "Coimbra/T01_edges_Coimbra.txt";
		break;
	case 3:
		sn << "Ermesinde/T01_nodes_lat_lon_Ermesinde.txt";
		se << "Ermesinde/T01_edges_Ermesinde.txt";
		break;
	case 4:
		sn << "Fafe/T01_nodes_lat_lon_Fafe.txt";
		se << "Fafe/T01_edges_Fafe.txt";
		break;
	case 5:
		sn << "Gondomar/T01_nodes_lat_lon_Gondomar.txt";
		se << "Gondomar/T01_edges_Gondomar.txt";
		break;
	case 6:
		sn << "Lisboa/T01_nodes_lat_lon_Lisboa.txt";
		se << "Lisboa/T01_edges_Lisboa.txt";
		break;
	case 7:
		sn << "Maia/T01_nodes_lat_lon_Maia.txt";
		se << "Maia/T01_edges_Maia.txt";
		break;
	case 8:
		sn << "Porto/T01_nodes_lat_lon_Porto.txt";
		se << "Porto/T01_edges_Porto.txt";
		break;
	case 9:
		sn << "Viseu/T01_nodes_lat_lon_Viseu.txt";
		se << "Viseu/T01_edges_Viseu.txt";
		break;
	default:
		sn << "Portugal/T01_nodes_lat_lon_Portugal.txt";
		se << "Portugal/T01_edges_Portugal.txt";
		break;
	}

	nodeFile = sn.str();
	edgeFile = se.str();
}
