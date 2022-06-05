#include<iostream>

using namespace std;
const int arrSize = 7;
class maxHeap{
private:
	int heapSize;
	int Arr[arrSize] ;

public:
	maxHeap():heapSize(0){}
	void maxHeapify( int pIndex){
		int temp=0;
		int largest = pIndex;
		int left = 2*pIndex;
		int right = 2*pIndex + 1;
		if(2*pIndex > heapSize){
			return;
		} 
		if(right <= heapSize && Arr[right -1] > Arr[pIndex - 1] ){
			largest = right;
		}
		if(left <= heapSize && Arr[left - 1] > Arr[largest-1]){
			largest = left;
		}
		if(largest!=pIndex){
        temp = Arr[pIndex - 1];
        Arr[pIndex - 1] = Arr[largest - 1];
        Arr[largest - 1] = temp;
        maxHeapify(largest);
       }
	}

	void buildMaxHeap( ){
		for(int i = (arrSize/2); i > 0; i--){
			maxHeapify(i);
		}
	}
	void display(){
    	for(int i = 0;i<heapSize;i++){
          cout<<Arr[i]<<endl;
        }
    }
    
    void HeapSort(){
    	if(heapSize<=1){
    		return;
    	}
    	int temp;
    	temp = Arr[heapSize - 1];
    	Arr[heapSize - 1] = Arr[0];
    	Arr[0] = temp;
    	heapSize--;
    	maxHeapify(1);
    	HeapSort();
    }

    int extractMax(){
    	int max = Arr[0];
    	int temp = Arr[0];
    	Arr[0] = Arr[heapSize - 1];
    	Arr[heapSize - 1] = temp;
    	heapSize--;
    	return max;
    }

    void increaseKey(int i,int key){
    	if(key < Arr[i - 1]){
    		cout<<"Invalid attempt"<<endl;
    	}
    	Arr[i - 1] = key;
    	int parent = i/2;

    	while(i>1&& Arr[parent-1]< key){
    		int temp = Arr[parent-1];
    		Arr[parent-1] = key;
    		Arr[i - 1] = temp;
    		i = i/2;
    		parent = parent/2;
    	}
    }
    
    void heapInsert(int key){
    	heapSize++;
    	Arr[heapSize - 1] = 0;
    	increaseKey(heapSize,key);
    }
};

int main(){
    maxHeap mh;
    
	return 0;
}