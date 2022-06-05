#include<iostream>

using namespace std;
const int SIZE = 7;
class stack{
private:
	int top;
	char str[SIZE];
public:
	stack():top(0){}
	bool isFull(){
		if(top == SIZE -1){
			return true;
		}
		else
			return false;
	}

	bool isEmpty(){
		if(top == -1){
			return true;
		}
		else
			return false;
	}
	void push(char a){
		if(!isFull){
		str[++top] = a;
	    }
	}

	void pop(){
		if(!isEmpty()){
		top--;
	    }
	}

	char peek(){
		if(!isEmpty()){
		return str[top];
	    }
	}
};
int main(){
	stack stck;
	char str[SIZE];
	char revStr[SIZE];
	cout<<"enter the string you want to reverse:\n";
	for(int i =0;i<SIZE;i++){
		cin>>str[i];
		stck.push(str[i]);
	}
	for(int i=0;i<SIZE;i++){
		revStr[i] = stck.peek();
		stck.pop();
	}
	cout<<revStr<<endl;
	return 0;
}