#include<iostream>

using namespace std;

int partition(int * A , int p , int r){
	int pivot = A[r];
	int i = 0; 
	int temp;
	for(int j = 0 ; j < r ; j++){
		if(A[j] <= pivot){
			
			temp = A[j];
			A[j] = A[i];
			A[i] = temp;
			i++;
		}
	}
	temp = A[r];
	A[r] = A[i];
	A[i] = temp;
	return i;
}

void quickSort(int * A ,int p ,int r){
	    if(p>=r){
		  return;
	    }
		int q = partition(A,p,r);
		quickSort(A,p,q-1);
		quickSort(A,q+1,r);
	
}

int main(){
	int A[] = {6,3,2,7,4,8,5,9};
	int len = 8;
	quickSort(A,0,len-1);
	for(int i = 0;i<len;i++){

		cout<<A[i]<<endl;
	}
	return 0;
}