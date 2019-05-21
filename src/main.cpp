#include <iostream>
#include "utils.h"

using namespace std;

int main(){
	string nodeFile, edgeFile;
	setFiles(PORTUGAL, nodeFile, edgeFile);
	cout << nodeFile << endl;
	cout << edgeFile << endl;
	return 0;
}
