//implement heap
#include<iostream>

using namespace std;
const int SIZE = 10;
class Maxheap{
private:
	int arr[SIZE]= {1,2,3,4,5,6,7,8,9,10};
	int frnt ;
	int rar;
public:
	Maxheap():frnt(0),rar(SIZE-1){}
	void Maxheapify(int hindex){
		int temp = 0;
		int leftChild = 0;
		int rightChild = 0;
		leftChild = 2 * hindex;
		rightChild = leftChild + 1;
		if(arr[leftChild-1]<= arr[hindex-1]&& arr[rightChild-1]<=arr[hindex-1]){}
		else{
			if(arr[leftChild-1]>=arr[rightChild-1]){
                temp = arr[hindex-1];
				arr[hindex-1] = arr[leftChild-1];
				arr[leftChild-1] = temp;
			}
			else{
				temp = arr[hindex-1];
				arr[hindex-1] = arr[rightChild-1];
				arr[rightChild-1] = temp;
			}
			if(leftChild<=(rar+1)/2){
			   Maxheapify(leftChild);
		    }
		    if(rightChild<=(rar+1)/2){
		    	Maxheapify(rightChild);
		    }
		}
	}

	void buildMaxHeap(){
		for(int i = (rar+1)/2;i>=1;i--){
			Maxheapify(i);
		}
	}

	void display(){
		for(int i = frnt;i<=rar;i++){
			cout<<arr[i]<<endl;
		}
	}

	void extractMax(){
		int temp = 0 ;
		temp = arr[frnt];
		arr[frnt] = arr[SIZE-1];
		arr[SIZE-1] = temp;
		rar--; 
	}
};

int main(){
	Maxheap mh;
    mh.buildMaxHeap();
    mh.display();
    cout<<endl<<endl<<endl;
    mh.extractMax();
    mh.display();
    cout<<endl<<endl<<endl;
    mh.buildMaxHeap();
    mh.display();
    cout<<endl<<endl<<endl;
	return 0;
}