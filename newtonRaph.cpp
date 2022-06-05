#include<iostream>
#include<math.h>
using namespace std;
class newtonRaphson{
private:
	int degree;
    int * coeffs;
public:
	newtonRaphson(int num):degree(num){
		coeffs = new int[num + 1];
	}
	

	void getCoeffs(){
		cout<<"Enter the coeffs from 0 to the degree:"<<endl;
		for(int i = 0;i<= degree;i++){
			cin>>*(coeffs + i);
		}
    }
    

    double funcVal(double x){
    	double temp = 0;
    	for(int i = 0;i <= degree;i++){
    		temp = temp + (*(coeffs + i)) * pow(x,i);
    	}
    	return temp;
    }
    

    double derivative(double x){
    	double temp = 0;
    	for(int i = 1;i <=degree; i++){
    		temp = temp + (*(coeffs + i)) * i * pow(x,i-1);
    	}
    	return temp;
    }
    

    double calcRoot(double val){
    	double err;
    	double init;
    	int i = 0;
    	if(i<100){
    	do{
    		init = val;
    		val =  val - (funcVal(val)/derivative(val));
    		err =  abs(val - init);
    		i++;
    	}while(err>=0.0000005);
        }
        else{
        	cout<<"choose some other number around which you want to find root.";
        }
    	return val;
    }
};
int main(){
	double val;
	int degree;
	cout << "Enter the degree :" << endl;
	cin >> degree;
	newtonRaphson nr(degree);
	nr.getCoeffs();
    cout << "Enter the number around which you want to calulate root:"<< endl;
    cin >> val;
	cout << nr.calcRoot(val) << endl;
	return 0;
}