#include<iostream>

using namespace std;

int pingala(int n){
	if(n == 1){
		return 0;
	}
	else if(n == 2){
		return 1;
	}
	else{	
		return pingala(n-1) + pingala(n-2);
	}
}

int main(){
	int n;
	cout<<"Enter which term to find: "<<endl;
	cin>>n;
	cout<<pingala(n)<<endl;
	return 0;
}