#include<iostream>
#include<math.h>
using namespace std;
class scientificNotation{
private:
	double bse;
	double exp;
public:
	scientificNotation():bse(0),exp(0){}
	scientificNotation(double a,double b):bse(a),exp(b){}
	double getBase(){
		return bse;
	}
	double getExp(){
		return exp;
	}
	scientificNotation operator*(const scientificNotation& a){
		scientificNotation sc;
		sc.bse = bse * a.bse;
		sc.exp = exp + a.exp;
		return sc;
	}

	scientificNotation operator/(const scientificNotation& a){
		scientificNotation sc;
		sc.bse = bse/a.bse;
		sc.exp = exp - a.exp;
		return sc;
	}
};

const string B = "spare";
const string A = "present";
const string C = "target";
void move(int n,string from , string to,string usin){
	if(n == 1){
		cout<<"Move 1 from "<<from<<" to "<<to<<endl;
		return;
	}
	move(n-1,from,usin,to);
	cout<<"Move "<<n<<" from "<<from<<" to "<<to<<endl;
	move(n-1,usin,to,from);
}
int main(){
	int num;
	cout<<"Plz,Enter the number of Rings: "<<endl;
	cin>>num;
	scientificNotation below(3.1536,13);
	scientificNotation upper(1,log10(pow(2,num-1)));
	scientificNotation timeInYrs = upper/below;
	cout<<"Its gonna take computer"<<timeInYrs.getBase()<<"* 10^"<<timeInYrs.getExp()<<"years"<<endl; 
	move(num,A,C,B);

return 0;
}