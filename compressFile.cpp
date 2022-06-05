#include<iostream>
#include<cstring>
#include<string>
using namespace std;
struct node{
	node* leftChild;
	node* rightChild;
	unsigned int freq;
	char ch;
	int top;
	int* arr;
};
const int capacity = 6;
class minHeap{
private:
	int size;
	node* Arr[capacity];
public:
	minHeap():size(0){
		for(int i = 0;i< capacity ;i++){
			Arr[i] = NULL;
		}
	}
	void getData(){
		//cout<<"Plz,Enter the character and frequencies respectively: "<<endl;
		for(int i = 0;i< capacity;i++){
			Arr[i] = new node;
			Arr[i]->leftChild = NULL;
		    Arr[i]->rightChild = NULL;
		}
		Arr[0]->ch = 'a';
		Arr[0]->freq = 25;
		Arr[1]->ch = 'b';
		Arr[1]->freq = 20;
		Arr[2]->ch = 'c';
		Arr[2]->freq = 40;
		Arr[3]->ch = 'd';
		Arr[3]->freq = 0;
		Arr[4]->ch = 'e';
		Arr[4]->freq = 9;
		Arr[5]->ch = 'f';
		Arr[5] -> freq = 10;
		size = capacity;
	}

	void minHeapify(int fIndex){
		if(fIndex > size/2){
			return;
		}
		int fLeft = 2*fIndex;
		int fRight = fLeft + 1;
		int fMin = fIndex;
        if(fRight <= size){
        	if(Arr[fRight-1]->freq < Arr[fIndex -1]->freq){
        		//cout<<"Arr[fRight-1] = "<<Arr[fRight-1] -> freq<<" &&&& "<<" Arr[fIndex -1] ="<<Arr[fIndex -1] -> freq<<endl;
        		fMin = fRight;
        	}
        }
        if(fLeft <= size){
        	if(Arr[fLeft -1]->freq < Arr[fMin -1]->freq){
        		//cout<<"Arr[fLeft -1] = "<<Arr[fLeft -1] -> freq<<" &&&& "<<" Arr[fMin -1] ="<<Arr[fMin -1] -> freq<<endl;
        		fMin = fLeft;
        	}
        }
        //cout<<Arr[fMin -1] -> freq <<endl;
		if(fMin != fIndex){
			node* temp = Arr[fMin - 1];
			Arr[fMin - 1] = Arr[fIndex -1];
			Arr[fIndex -1] = temp;
			minHeapify(fMin);
		} 
	}

	void buildMinHeap(){
		for(int i = size/2;i>=1;i--){
			minHeapify(i);
		}
		/*for(int j = 0;j<size;j++){
			cout<<Arr[j]->freq<<"   ";
		}
		cout<<endl<<endl<<endl;*/
	}

	node* extractMin(){
		buildMinHeap();
		node* temp = Arr[0];
		Arr[0] = Arr[size -1];
		Arr[size - 1] = temp;
		size--;
		return temp;
	}

	void insert(){
		node* leftChild = extractMin();
		node* rightChild = extractMin();
		node* ptr = createNode(leftChild,rightChild);
		size++;
		Arr[size-1] = ptr;

	}

	node* createNode(node* leftChild , node* rightChild){
		node* temp = new node;
		temp -> freq = leftChild -> freq + rightChild -> freq;
		temp -> leftChild = leftChild;
		temp -> rightChild = rightChild;
		return temp;
	}

	void createHuffmanTree(){
		while(size > 1){
			insert();
		}
		//printHuffmanTree(Arr[0]);
		int arr[5] = {0,0,0,0,0};
		assignCode(Arr[0],-1,arr);
	}

	void printHuffmanTree(node* root){
		if(root == NULL){
			return;
		}
		cout<<root -> freq<<endl;
		printHuffmanTree(root -> leftChild);
		printHuffmanTree(root -> rightChild);
	}

	void assignCode(node* root,int top,int arr[5]){
		if(root -> leftChild!=NULL){
			arr[++top] = 0;
			assignCode(root -> leftChild,top,arr);
		}

		if(root -> rightChild!=NULL){
            top--;
			arr[++top] = 1;
			assignCode(root -> rightChild,top,arr);
		}

		if(root -> leftChild == NULL && root -> rightChild == NULL){
			root -> top = top;
			root -> arr = arr;
			for(int i = 0;i<=top;i++){
				cout<<arr[i];
			}
			cout<<endl<<endl;
		}
		
	}

};


int main(){
	minHeap mh;
	mh.getData();
	mh.createHuffmanTree();
	return 0;
}