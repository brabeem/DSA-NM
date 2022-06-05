#include<iostream>

using namespace std;

int* countingSort(int * Arr , int num){
	int storeCount[10] = {0,0,0,0,0,0,0,00,0,0};
	static int a = 1;
	int j = 0;
	int b = 0;
	int rem = 0;
	for(int i = 0; i < num ; i++){
		b = Arr[i];
		j =0;
		while(j < a){
			rem = b % 10;
			b = b - rem;
			b = b/10; 
			j++;
		}
		storeCount[rem]++; 
	}
	for(int i = 1; i<=9 ;i++){
		storeCount[i] = storeCount[i] + storeCount[i - 1];
	}
	int* newArr = new int[6];
	int c = 0;
	int lyangreZero = 0;
	for(int k = 0 ; k < num ;k++){
		 c = Arr[k];
		 j = 0;
		 while(j < a){
		 	rem = c % 10;
		 	c = c - rem;
		 	c = c /10;
		 	j++;
		 }
		 if(rem != 0){ newArr[storeCount[rem-1]] = Arr[k]; storeCount[rem - 1]++;}
		 else{newArr[lyangreZero] = c;lyangreZero ++;}
	}
	a++;
	return newArr;
}

void radixSort(int* Arr,int dig,int num){
	int* dummy = Arr ;
	int* temp;
	for(int i = 0;i<dig;i++){
		dummy = countingSort(dummy,num);
	}
	for(int i = 0;i < num;i++){
		cout<<dummy[i]<<endl;
	}
}

int main(){
	int Arr[6] = {345,645,234,789,124,225};
    radixSort(Arr,3,6);
	return 0;
}