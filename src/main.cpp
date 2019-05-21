#include <iostream>
#include "utils.h"
#include "graphviewer.h"

using namespace std;

int main(){
	string nodeFile, edgeFile;
	setFiles(PORTO, nodeFile, edgeFile);
	cout << nodeFile << endl;
	cout << edgeFile << endl;

	GraphViewer *gv = new GraphViewer(900, 1400, true);
	gv->createWindow(900, 1400);
	gv->defineVertexColor("blue");
	gv->defineEdgeColor("black");
	//gv->closeWindow();

	readFiles(gv, nodeFile, edgeFile);

	return 0;
}
