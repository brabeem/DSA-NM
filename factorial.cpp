#include<iostream>

using namespace std;
int factoria(int n){
	if(n == 1){
		return 1;
	}
	return n * factoria(n-1);
}

int main(){
int n;
cout<<"Enter the number whose factorial is to be found:"<<endl;
cin>>n;
cout<<factoria(n)<<endl;
return 0;
}