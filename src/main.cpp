#include <iostream>
#include "utils.h"
#include "graphviewer.h"
#include "Graph.h"

using namespace std;

int main(){
	string nodeFile, edgeFile;
	setFiles(PORTO, nodeFile, edgeFile);
	cout << nodeFile << endl;
	cout << edgeFile << endl;

	// GraphViewer *gv = new GraphViewer(600, 600, false);
	// gv->createWindow(600, 600);
	// gv->defineVertexColor("blue");
	//gv->defineEdgeColor("black");
	//gv->closeWindow();

	Graph <Coords> rideSharing = readFiles(nodeFile, edgeFile);
	getchar();
	//gv->closeWindow();


	return 0;
}
