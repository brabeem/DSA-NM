#include<iostream>


using namespace std;
struct node {
	int data;
	node * nxt;
	node * prev;
};

class stak{
private:
	node * top;
	node * head;
public:
	stak():top(NULL),head(NULL){}

	node * createNode(){
		node * temp = new node;
		cout<<"Enter the data:"<<endl;
		cin>> temp -> data;
		return temp;
	}
	

	void push(){
		node * temp = createNode();		
		if(head == NULL){
			head = temp;
			top = temp;
			head ->prev = NULL;
		}
		else{
		node * q = top;
		top -> nxt = temp;
		top = temp;
		top -> prev = q;
	    }
	}


	void pop(){
		if(top == NULL){
			cout<<"Not possible"<<endl;
		}
		else{
			top -> prev -> nxt = NULL;
			top = top -> prev;
		}
	}

	void display(){
		node * temp = top;
		while(temp!=NULL){
			cout<<temp->data<<endl;
			temp = temp -> prev;
		}
	}

};
int main(){
	stak s;
	s.push();
	s.push();
	s.push();
	cout<<endl<<endl<<endl;
	cout<<"after pushing"<<endl;
	s.display();
	cout<<endl<<endl<<endl;
	cout<<"after poping"<<endl;
	s.pop();
	s.display();
	return 0;
}