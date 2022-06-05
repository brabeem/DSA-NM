#include<iostream>
using namespace std;

struct node {
	int data;
	node * nxt;
};

class Q{
private:
	node * frnt ;
	node * rar;
public:
	Q():frnt(NULL),rar(NULL){}

	node * createNode(){
		node * temp = new node;
		cout<<"Enter the data:"<<endl;
		cin>> temp -> data;
		return temp;
	}

	void enq(){
		node * temp = createNode();
		if(rar == NULL){
			frnt = temp;
			rar = temp;
		}
		else{
			rar -> nxt = temp;
			rar = temp;
			rar -> nxt = NULL;
		}
	}

	void dq(){
		if(rar == NULL||frnt == NULL){
			cout<<"No element"<<endl;
		}
		else{
			frnt = frnt -> nxt ;
		}
	}

	void display(){
		node * temp = frnt ;
		while(temp!=NULL){
			cout << temp -> data << endl;
			temp = temp -> nxt;
		}
	}

};

int main(){
	Q q;
	q.enq();
    q.enq();
    q.enq();
    q.display();
    cout<<endl<<endl<<endl;
    q.dq();
    q.display();
    cout<<endl<<endl<<endl;
    q.dq();
    q.dq();
    q.dq();
    q.display();
    cout<<endl<<endl<<endl;
	return 0;
}
