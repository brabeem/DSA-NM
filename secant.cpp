#include<iostream>
#include<math.h>
using namespace std;

class secantRootMethd{
public:
	double polyFunc(double x){
		return (pow(x,3)-(3*pow(x,2))+(2*x)-2);
	}

	double trig(double x){
		return ((x*sin(x)) + cos(x));
	}

	double cubik(double x){
		return (pow(x,3) + (4*x) + 5);
	}

	double anotherPoint(int i ,double a , double b){
            double temp = 0;
			switch(i){
			case 1:
			temp = a*polyFunc(b) - b * polyFunc(a);
			temp = temp /(polyFunc(b) - polyFunc(a)); 
            return temp;
			case 2:
			temp = a * trig(b) - b* trig(a);
			temp = temp /(trig(b) - trig(a));
			return temp;
			case 3:
			temp = a * cubik(b) - b* cubik(a);
            temp = temp / (cubik(b) - cubik(a));
            return temp;
			default:
			cout<<"Invalid number entered!"<<endl;
			return -1;
		}
	}

	double calcRoot(double err,double a,double b){
		double c =0;
		double fc ,fb,fa;
		int i;
		cout<<"Which func are you working with? 1 : polyFunc ,2: trig ,3: cubik"<<endl;
		cin>> i;
		do{
		   c = anotherPoint(i,a,b);
		   switch(i){
		   	case 1:
		   	fc = polyFunc(c);
		   	fa = polyFunc(a);
		   	fb  =polyFunc(b);
		   	break;
		   	case 2:
		   	fc = trig(c);
		   	fa = trig(a);
		   	fb = trig(b);
		   	break;
		   	case 3:
		   	fc = cubik(c);
		   	fa = cubik(a);
		   	fb = cubik(b);
		   	break;
		   	default:
		   	cout<<"Invalid number!!"<<endl;
		   }
		   a = b;
		   b = c;
		}while(err < abs(fc));
		return c;
	}
};


int main(){
	secantRootMethd srm;
	double err,a,b;
	cout<<"Enter err,lower interval and upper interval : "<<endl;
	cin>>err>>a>>b;
	cout<<srm.calcRoot(err,a,b)<<endl;
	return 0;
}