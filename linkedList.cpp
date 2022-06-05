#include<iostream>

using namespace std;
struct node{
	int data;
	node * nxt;
};
node * Start = NULL;

node * createNode(){
	node * temp = new node;
	return temp;
}

void add_node_at_begin(){
	node * temp = createNode();
	cout<<"Enter the number :"<<endl;
	cin>>temp->data;
	if(Start == NULL){
		Start = temp;
	}
	else{
		temp->nxt = Start;
		Start = temp;
	}
}

void display(){
	node * ptr = Start;
	while(ptr!=NULL){
		cout<< ptr->data <<endl;
		ptr = ptr -> nxt;
	} 
}

void append(){
	node * temp = createNode();
	cout<<"Enter the data:"<<endl;
	cin>>temp->data;
	temp -> nxt = NULL;
	if(Start == NULL){
		Start = temp;
	}
	else{
		node * q = Start;
		while(q -> nxt != NULL){
			q = q -> nxt;
		}
		q -> nxt = temp;
	}
}
//insert after this number given as an input
void insert(int num){
	node * temp = createNode();
	cout<<"Enter the data:"<<endl;
	cin>>temp -> data;
	if(Start == NULL){
		cout<<"Insertion is not possible"<<endl;
	}
	else{
		node * copy = NULL;
		node * q = Start;
		while(q -> data != num){
			q = q -> nxt;
		}
		copy = q -> nxt ;
		q -> nxt = temp;
		temp -> nxt = copy;
	}
}

void del(int num){
	node * q = Start;
	if(q->nxt == NULL){
		Start = NULL;
	}
	else if(q -> data == num){
		Start = q -> nxt;
	}
	else{
	while((q->nxt)->data != num){
		q = q -> nxt;
	}
	q -> nxt = (q -> nxt) -> nxt;
    }
}

int main(){
	int opt;
	int num;
    int delNum;
    char cont;
    do{ 
    	cout<<"Enter 1:add_node_at_begin 2:append 3:insert 4:delete 5:display"<<endl;
	    cin>>opt;
	switch(opt){
		case 1:
		add_node_at_begin();
		break;
		
		case 2:
		append();
		break;
		
		case 3:
		cout<<"Enter the number after which you want to insert: "<< endl;
		cin>>num;
		insert(num);
		break;
		
		case 4:
        cout<<"Enter the number you want to delete"<< endl;
        cin>>delNum;
		del(delNum);
		break;
		
		case 5:
		display();
		break;
		
		default:
		cout<<"You entered the invalid option.Thank you!"<<endl;
	}
	cout<<"Enter 'y' if you want to continue"<<endl;
	cin>>cont;
}while(cont == 'y');
	return 0;
}