#include <stdlib.h>
#include <stdio.h>
#include "StackArray.h"



struct graphVertex {
	int data;
	int inDegree;
	int outDegree;
	int processed;
	struct graphArc* firstArc;
	struct graphVertex* nextVertex;
};

struct graphHead {
	int count;
	struct graphVertex* first;

};

struct graphArc {
	struct graphVertex* destination;
	struct graphArc* nextArc;
};

typedef struct graphHead* Graph;
typedef struct graphVertex* Vertex;
typedef struct graphArc* Arc;

Graph createGraph();
void insertVertex(Graph myGraph, int data);
int deleteVertex(Graph myGraph, int key);

void displayVertices(Graph myGraph);
void insertArc(Graph myGraph, int srcKey, int dstKey);
void displayGraph(Graph myGraph);
int main() {
	Graph myGraph;
	myGraph = createGraph();

	
	insertVertex(myGraph, 5);
	insertVertex(myGraph, 6);
	insertVertex(myGraph, 7);
	insertVertex(myGraph, 10);
	insertVertex(myGraph, 3);
	insertVertex(myGraph, 2);
	insertVertex(myGraph, 1);
	insertVertex(myGraph, 4);
	insertVertex(myGraph, 8);


	displayVertices(myGraph);
	
	insertArc(myGraph, 5, 6);

	insertArc(myGraph, 6, 10);
	insertArc(myGraph, 6, 7);


	insertArc(myGraph, 7, 3);
	insertArc(myGraph, 7, 2);

	insertArc(myGraph, 10, 7);
	insertArc(myGraph, 10, 3);
	
	
	insertArc(myGraph, 2, 4);
	insertArc(myGraph, 2, 1);
	insertArc(myGraph, 1, 4);
	insertArc(myGraph, 4, 8);
	
	

	

	displayGraph(myGraph);

	system("Pause");
	return 0;
}

void displayVertices(Graph myGraph) {
	printf("Vertice content : \n");
	Vertex currVertex = myGraph->first;
	while (currVertex != NULL) {
		printf("-- %d ", currVertex->data);
		currVertex = currVertex->nextVertex;
		
	}
	printf("END \n");
}

Graph createGraph() {
	// graph creation using dummy node
	Graph myGraph = (Graph)malloc(sizeof(struct graphHead));
	myGraph->count = 0;
	myGraph->first = NULL;
	return myGraph;
}


void insertVertex(Graph myGraph, int data) {
	// new vertex sallocation
	Vertex newVertex = (Vertex)malloc(sizeof(struct graphVertex));
	newVertex->firstArc = NULL;
	newVertex->data = data;
	newVertex->processed = 0;
	newVertex->nextVertex = NULL;
	myGraph->count++; 


	Vertex currVertex = myGraph->first;

	//find insertion point
	if (myGraph->first == NULL) {
		myGraph->first = newVertex;
	}
	else {
		// search for insertion point
		//insertArc(myGraph->first, newVertex);
		while (currVertex->nextVertex != NULL) {
			currVertex = currVertex->nextVertex;
		}

		currVertex->nextVertex = newVertex;

	}
}


int deleteVertex(Graph myGraph , int key) {
	if (myGraph->first == NULL) {
		return -2;
	}
	// locate vertex to be deleted

	if (myGraph->first->inDegree > 0 || myGraph->first->outDegree > 0) {
		return -1;
	}

	//okay to delete the vertex
	myGraph->count--;
	return 1;
}


void insertArc(Graph myGraph , int srcKey , int dstKey) {
	// new arc allocation
	Arc newArc = (Arc)malloc(sizeof(struct graphArc));
	newArc->nextArc = NULL;
	newArc->destination = NULL;

	Vertex srcVertex ,dstVertex = NULL;
	srcVertex = myGraph->first;
	dstVertex = myGraph->first;
	// shifting vertexes until catch it
	while (srcVertex->data != srcKey) {
		srcVertex = srcVertex->nextVertex;
	}
	while (dstVertex->data != dstKey) {
		dstVertex = dstVertex->nextVertex;
	}


	newArc->destination = dstVertex;
	if (srcVertex->firstArc == NULL) {
		srcVertex->firstArc = newArc;
	}
	else {
		Arc currArc;
		currArc = srcVertex->firstArc;
		while (currArc->nextArc != NULL) {
			currArc = currArc->nextArc;
		}
		currArc->nextArc = newArc;
	}
}


void displayGraph(Graph myGraph) {
	/*
	PushStack(myStack, 5);
	DisplayStack(myStack);
	*/
	
	Stack myStack = CreateStack(MAXIMUM_VERTICES);
	Vertex currVertex ,popVertex = NULL;
	Arc currArc = NULL ;
	currVertex = myGraph->first;
	currVertex->processed = 1;
	PushStack(myStack, currVertex);
	printf("Depth first \n");

	while (!IsEmptyStack(myStack)) {
		popVertex = PopStack(myStack);
		printf(" %d ", popVertex->data);
		currArc = popVertex->firstArc;

		while (currArc != NULL) {
			if (currArc->destination->processed == 0) {
				PushStack(myStack, currArc->destination);
			}
			currArc->destination->processed = 1;
			currArc = currArc->nextArc;
		}

	}

}

/*
if (currVertex->processed == 0) {
PushStack(myStack, currVertex);
currVertex->processed = 1;
}
while (!IsEmptyStack(myStack)) {
popVertex = PopStack(myStack);
printf(" %d ", popVertex->data);
currArc = currVertex->firstArc;
while (currArc != NULL) {
PushStack(myStack, currArc->destination);
currArc->destination->processed = 1;
currArc = currArc->nextArc;
}
}*/











/*
currVertex = PopStack(myStack);
currArc = currVertex->firstArc;

printf("%d", currVertex->data);
while (currArc != NULL) {
PushStack(myStack, currArc->destination);
currArc = currArc->nextArc;
}
*/