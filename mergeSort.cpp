#include<iostream>

using namespace std;

void merge(int siz,int * leftPtr,int * rightPtr,int * parent){
	int i = 0;
	int j = 0;
	int pIndex;
	int leftSiz = siz/2; 
	int rightSiz = siz-leftSiz;
	for( pIndex = 0; pIndex < siz; pIndex++){
		if(i>=leftSiz||j>=rightSiz){
		
		  if(i>=leftSiz){
			parent[pIndex] = rightPtr[j];
			j++;
		    }
		  else{
			parent[pIndex] = leftPtr[i];
			i++;
		    }
	    }
		else{
		  if(leftPtr[i] <= rightPtr[j]){
			parent[pIndex] = leftPtr[i];
			i++;
		  }
		  else{
			parent[pIndex] = rightPtr[j];
			j++;
		  }
	   }
	}
}

void mergeSort(int* parent , int siz){
	if(siz < 2){
		return;
	}
	int leftSiz = siz/2; 
	int rightSiz = siz-leftSiz;
	int * leftPtr = new int[leftSiz];
	int * rightPtr = new int[rightSiz];
	for(int i =0;i<leftSiz;i++){
		leftPtr[i] = parent[i];
		
	}
	for(int i = leftSiz;i< siz;i++){
		rightPtr[i - leftSiz] = parent[i];
	}
	mergeSort(leftPtr,leftSiz);
	mergeSort(rightPtr,rightSiz);
	merge(siz,leftPtr,rightPtr,parent);
	delete [] leftPtr;
	delete [] rightPtr;
}

int main(){
	int meroArray[] = {2,4,3,7,5,9,8};
	int num = 7; 
	mergeSort(meroArray,num);
    for(int i = 0;i<num;i++){
    	cout<<meroArray[i]<<endl;
    }
	return 0;
}