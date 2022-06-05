#include<iostream>
#include<climits>
#include<string.h>
#include<cstring>
using namespace std;

enum color {white,black};
struct vertex{
	color vertexColor;
	int index;
	string name;
	vertex* parent;
	int disFromS;
};

struct edges{
	vertex* vertexPtr;
	edges* nxt;
	int len;
};

class graph{
  protected:
	int numOfVertices;
	vertex** vertexList;
	edges** adjacencyList;
  public:

	void constructGraph(){
		int num;
		char ch;
		for(int i = 0; i< numOfVertices;i++){
			vertexList[i] = new vertex;
			cout<<"Plz,Enter the name of the "<<i<<" th vertex : "<<endl;
            cin>>vertexList[i] -> name;
            vertexList[i] -> index = i;
            vertexList[i] -> vertexColor = white;
            vertexList[i] -> parent = NULL;
            vertexList[i] -> disFromS = INT_MAX;
		}
        edges* ptr;
		for(int i = 0; i< numOfVertices;i++){
			cout<<"Is it connected towards other vertex also? y/n : "<<vertexList[i] -> name<<endl;
			cin>>ch;
			if(ch == 'y'){
				adjacencyList[i] = new edges;
				adjacencyList[i] -> nxt = NULL;
			    cout<<"What vertex is "<<vertexList[i] -> name<<" connected to?"<<endl;
			    cin>>num;
			    adjacencyList[i] -> vertexPtr = vertexList[num];
			    cout<<"Weight : ";
			    cin>>adjacencyList[i] -> len;
			}
			else{
				adjacencyList[i] = NULL;
			}
			cout<<"Is it connected towards other vertex also? y/n : "<<vertexList[i] -> name<<endl;
			cin>>ch;
			while(ch == 'y'){
				ptr = adjacencyList[i];
				adjacencyList[i] =  new edges;
				adjacencyList[i] -> nxt = ptr;
			    cout<<"What vertex is "<<vertexList[i] -> name<<" connected to?"<<endl;
			    cin>>num;
			    cout<<"Weight : ";
			    cin>>adjacencyList[i] -> len;
			    adjacencyList[i] -> vertexPtr = vertexList[num];
			    cout<<"Is it connected towards other vertex also? y/n : "<<vertexList[i] -> name<<endl;
			    cin>>ch;
			}

		}
	}

	void showGraph(){
	   cout<<"Your adjacency List is as follows:  "<<endl;
       for(int i = 0;i<numOfVertices;i++){
           cout<<"Vertex "<<vertexList[i]->name<<" -- ";
           edges* tempP = adjacencyList[i];
           while(tempP != NULL){
              cout<<tempP -> vertexPtr -> name<<"("<<tempP -> len<<")"<<"   ";
              tempP = tempP -> nxt;
           }
           cout<<endl;
       }
	}

	graph(){
		cout<<"Enter the number of vertices: "<<endl;
		cin>>numOfVertices;
		vertexList = new vertex*[numOfVertices];
		adjacencyList = new edges*[numOfVertices];
		constructGraph();
		showGraph();
	}
};

class minHeap:public graph{
    protected:
    	vertex** priorityQ;
    	int heapSize;
    public:

     minHeap(){
     	heapSize = numOfVertices;
     	priorityQ = new vertex*[numOfVertices];
     	for(int i=0;i<numOfVertices;i++){
     		priorityQ[i]=vertexList[i];
     	}
     }

	 void minHeapify(int pIndex){
	 	int smallest;
		if(2*pIndex > heapSize){
			return;
		}
		smallest = pIndex;
		if((2*pIndex <= heapSize) && priorityQ[2*pIndex -1]->disFromS < priorityQ[pIndex -1]->disFromS){
			smallest = 2*pIndex;
		}
		if((2*pIndex + 1 <= heapSize) && priorityQ[2*pIndex]->disFromS < priorityQ[smallest -1] -> disFromS){
			smallest=2*pIndex + 1;
		}
		if(smallest != pIndex){
			vertex* temp = priorityQ[smallest-1];
			priorityQ[smallest -1] = priorityQ[pIndex -1];
			priorityQ[pIndex -1]=temp;
			minHeapify(smallest);
		}
	 }

	 void buildMinHeap(){
	 	for(int i= heapSize/2;i>=1;i--){
	 		minHeapify(i);
	 	}
	 }

	 int extractMin(){
	 	//exchange with the heapsize element
	 	//and then decrese the heap size
	 	vertex* temp = priorityQ[0];
	 	priorityQ[0] = priorityQ[heapSize - 1];
	 	priorityQ[heapSize -1] = temp;
	 	heapSize--;
	 	minHeapify(1);
	 	return priorityQ[heapSize] -> index;
	 }

	 /*void decreaseKey(int pIndex ,int newKey){
	 	priorityQ[pIndex-1] -> disFromS = newKey;
	    int parent = pIndex/2;
	 	while(pIndex > 1){
	 		if(priorityQ[pIndex -1] -> disFromS < priorityQ[parent -1] -> disFromS){
	 		   vertex* temp = priorityQ[pIndex -1];
	 		   priorityQ[pIndex -1] = priorityQ[parent -1];
	 		   priorityQ[parent -1] = temp;
	 		}
	 		else{
	 			return;
	 		}
	 		pIndex = parent;
	 		parent = parent/2;
	 	}
	 }*/

};

class dijstra:public minHeap{
    public:
    	dijstra(){

    	}
    	void implementDijstra(){
    		int source;
    		cout<<"Plz,Enter the source: "<<endl;
    		cin>>source;
    		priorityQ[source] -> disFromS = 0;
    		priorityQ[source] -> parent = NULL;

    		while(heapSize > 0){
                buildMinHeap();
    			int min = extractMin();
    			vertexList[min] -> vertexColor = black;
    			edges* ptr = adjacencyList[min];
    			while(ptr != NULL){
    				if(ptr -> vertexPtr -> vertexColor == white){
                       int newKey = vertexList[min] -> disFromS + ptr -> len;
                       if(newKey < ptr -> vertexPtr -> disFromS){
                       	  ptr -> vertexPtr -> disFromS = newKey;
                       	  ptr -> vertexPtr -> parent = vertexList[min];
                       }
    				}
    				ptr = ptr -> nxt;
    			}
    		}

    	}

    	void backTrackShortestPath(){
    		cout<<"Plz,Enter the destination: "<<endl;
    		int destination;
    		cin>>destination;
    		vertex* dest = vertexList[destination];
    		cout<<"Shortest path distance : "<<vertexList[destination] -> disFromS<<endl;
    		while(dest != NULL){
    			cout<<dest -> name<<" -> ";
    			dest = dest -> parent;
    		}
    	}

};





int main(){
    dijstra dj;
    dj.implementDijstra();
    dj.backTrackShortestPath();
	return 0;
}