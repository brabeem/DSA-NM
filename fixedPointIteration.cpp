#include<iostream>
#include<math.h>
using namespace std;

double func(double x){
	return ((20/pow(x,4)) + 0.8*x);
}

int main(){
	double err = 0.000005;
	double val = 4;
	double valNxt = 0;
	double e = 5;
	while(e>err){
		cout<< val <<"       ";
		valNxt = func(val);
		cout<< valNxt<<endl; 
        e = abs(valNxt - val);
        val = valNxt;
	}
	cout<<"Ans : "<<valNxt;
	return 0;
}