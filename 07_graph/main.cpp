#include <iostream>
#include "graph.h"

using namespace std;

int main()
{
	//int j,k,n;
	//char s[5] = "±ß"; 
	//VertexType v1;
	MGraph myGraph;
	
	CreateGraph_M(myGraph);
	
	PrintGraph_M(myGraph);
	
	//system("pause");
	return 0;
}
