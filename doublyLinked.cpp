#include<iostream>

using namespace std;

struct node{
	int data;
	node * nxt;
	node * init;
};

class doublyLinkedls{
private:
	node * head;
	node * tail;
public:
	doublyLinkedls():head(NULL),tail(NULL){}
	
	node * createNode(){
		node * temp = new node;
		cout<<"Enter the data:"<<endl;
		cin>> temp -> data;
		temp -> nxt = NULL;
		temp -> init = NULL;
		return temp;
	}


	void append(){
		node * temp = createNode();
		temp -> nxt = NULL;
		if(head == NULL){
			head = temp;
			tail = temp;
			temp -> init = NULL;
		}
		else{
			node * q = tail;
		    tail = temp;
		    q -> nxt = temp;
		    temp -> init = q;
		}
	}


	void addAtBegin(){
		node * temp = createNode();
		temp -> init = NULL;
		if(head == NULL){
			head = temp;
			tail = temp;
			temp -> nxt = NULL;
		}
		else{
			head -> init = temp;
			temp -> nxt = head;
			head = temp;
		}
	}

	void insert(int pos){
		int i = 1;
		node * var = head;
		node * temp = createNode();
			while(i != pos-1){
				var = var -> nxt;
				i++;
			}
			node * q = var -> nxt;
			var -> nxt = temp;
			temp -> init = var;
			temp -> nxt = q;
			q -> init = temp;
	}

	void del(int pos){
		int i = 1;
		node * temp = head;
		if(head == NULL){
			cout<<"Empty"<<endl;
		}
		if(pos == 1){
			head = head -> nxt;
			head -> init = NULL;
		}
		else{
			while(i != pos){
				temp = temp -> nxt;
				i++;
			}
			temp -> init -> nxt = temp -> nxt;
		}
	}
	void reverseDisplay(){
		node* temp = tail;
		while(temp!=NULL){
			cout<<temp->data<<endl;
			temp = temp -> init;
		}

	}
    
	void display(){
		node * temp = head;
		while(temp != NULL){
			cout<< temp -> data<< endl;
			temp = temp -> nxt;
		}
	}
};

int main(){
	doublyLinkedls dll;
	dll.append();
	dll.append();
    dll.append();
    dll.append();
	dll.display();
	dll.reverseDisplay();
	return 0;
}