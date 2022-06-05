#include<iostream>
#include<math.h>
using namespace std;

struct node{
	node* leftChild;
	node* rightChild;
	node* parent;
	int height;
	int balanceFac;
	int dat;
};

class AVL{
private:
	node* root;
public:
	AVL():root(NULL){}

	node* createNode(int data){
		 node* temp = new node;
		 temp -> dat = data;
		 temp -> height = 0;
         return temp;
	}
    
    node * returnRoot(){return root;}

    void updateHeight(node* temp){
        int leftH,rightH;
        if(temp == NULL){
    	  return;
        }
    	updateHeight(temp -> leftChild);
    	updateHeight(temp -> rightChild);
        if(temp -> leftChild == NULL){
        	leftH = -1;
        }
        else{
            leftH = temp -> leftChild -> height;
        }
        if(temp -> rightChild == NULL){
        	rightH = -1;
        }
        else{
        	rightH = temp -> rightChild -> height;
        }
    	temp -> height = max(leftH,rightH) + 1;
    }
	
	

	void insertify(node* temp,int data){
	
	    if(data < temp -> dat){
	    	if(temp -> leftChild != NULL){
			insertify(temp -> leftChild,data);
		    }
		    else{
		    	node* tempT = createNode(data);
                temp -> leftChild = tempT;
                tempT -> parent = temp;
                tempT -> leftChild = NULL;
                tempT -> rightChild = NULL;
                updateHeight(root);
                maintainAVL(tempT);
		    }
		}
		else {
			if(temp -> rightChild != NULL){
			insertify(temp -> rightChild,data);
		    }
		    else{
		    	node* tempT = createNode(data);
		    	temp -> rightChild = tempT;
		    	tempT -> parent = temp;
		    	tempT -> leftChild = NULL;
		    	tempT -> rightChild = NULL;
		    	updateHeight(root);
		    	maintainAVL(tempT);
		    }
		}
	}

	void insert(int data){

		    if(root == NULL){
		      node* tempT = createNode(data);
		      root = tempT;
			  tempT -> leftChild = NULL;
			  tempT -> rightChild = NULL;
			  tempT -> parent = NULL;
		    }
		    else{
		      insertify(root,data);
	        }
	}

	void inOrder(node* oot ){
    	if(oot == NULL){return;}
    	else{
    		inOrder(oot -> leftChild);
    		cout<< oot -> dat <<endl;
    		inOrder(oot -> rightChild);
    	}
    }
    
    void displayHeight(node* temp){
    	if(temp == NULL){
    		return;
    	}
    	cout<<temp -> height<<endl;
    	displayHeight(temp -> leftChild);
    	displayHeight(temp -> rightChild);
    }

    void leftRotate(node* toBeMod){
    	node* pToBeMod = toBeMod -> parent;
    	node* toBeModR = toBeMod -> rightChild;
    	node* temp = toBeModR -> leftChild;
    	if(root == toBeMod){root = toBeModR;}
    	toBeMod -> rightChild = temp;
    	toBeModR -> leftChild = toBeMod;
    	if(temp!=NULL){temp -> parent = toBeMod;}
    	toBeMod -> parent = toBeModR;
    	toBeModR -> parent = pToBeMod;
    	if(pToBeMod != NULL){pToBeMod -> rightChild = toBeModR;}
    	updateHeight(root);	
    }
    

    void rightRotate(node* toBeMod){
    	node* pToBeMod = toBeMod -> parent;
    	node* toBeModL = toBeMod -> leftChild;
    	node* temp = toBeModL -> rightChild;
    	if(root == toBeMod){root = toBeModL;}
    	toBeMod -> leftChild = temp;
        toBeModL -> rightChild = toBeMod;
        if(temp != NULL){temp -> parent = toBeMod;}  
        toBeMod -> parent = toBeModL;
        toBeModL -> parent = pToBeMod;
        if(pToBeMod != NULL){ pToBeMod -> leftChild = toBeModL;}
        updateHeight(root);   
    }
    
    int heightOf(node* temp){
    	if(temp == NULL){
    		return -1;
    	}
    	int leftH,rightH;
    	leftH = heightOf(temp -> leftChild);
    	rightH = heightOf(temp->rightChild); 
        return (max(leftH , rightH) +1);
    }
    

    void maintainAVL(node* tempu){
    	node* temp;
    	int a = -1;
    	int tRLH, tRRH;
    	int tLLH,tLRH;

    	while(tempu != NULL){
    	
    		temp = tempu;
            
            if(temp -> leftChild != NULL && temp -> rightChild != NULL){
    		temp -> balanceFac = temp -> leftChild -> height  - temp -> rightChild -> height ;
    	    }
    	    else if(temp -> leftChild == NULL && temp -> rightChild != NULL){
    	    	temp -> balanceFac = a-temp -> rightChild -> height;

    	    }
    	    else if(temp -> leftChild != NULL && temp -> rightChild == NULL){
    	    	temp -> balanceFac = temp -> leftChild -> height - a;
    	    }
    	    else{
    	    	temp -> balanceFac = 0;
    	    }
            

    		if(temp -> balanceFac < -1 ){
    			temp = temp -> rightChild;
    			if(temp -> leftChild == NULL){tRLH = -1;}
    	        else{tRLH = temp -> leftChild -> height;}

    	        if(temp -> rightChild == NULL){tRRH = -1;}
    	        else{tRRH = temp -> rightChild -> height; }

    			if(tRLH > tRRH){
    				rightRotate(temp);
    				leftRotate(temp -> parent -> parent);
    			}
    			else{
    				leftRotate(temp -> parent);
    			}
    		}
    		

    		if(temp -> balanceFac > 1){
    			temp = temp -> leftChild;
    			if(temp -> leftChild == NULL){tLLH = -1;}
                else{tLLH = temp -> leftChild -> height;}

                if(temp -> rightChild == NULL){tLRH = -1;}
                else{tLRH = temp -> rightChild -> height;}
    			
    			if(tLLH < tLRH){
    				leftRotate(temp);
    				rightRotate(temp -> parent -> parent);
    			}
    			else{
    				rightRotate(temp -> parent);
    			}
    		}
    		

    		tempu = tempu -> parent;
    	}
    }

    /*void maintainAVL(node* tempu){
    	node* temp;
    	while(tempu != NULL){
    	
    		temp = tempu;  
    		temp -> balanceFac = heightOf(temp -> leftChild)  - heightOf(temp -> rightChild) ;
    		if(temp -> balanceFac < -1 ){
    			temp = temp -> rightChild;
    			if(heightOf(temp -> leftChild) > heightOf(temp -> rightChild)){
    				rightRotate(temp);
    				leftRotate(temp -> parent -> parent);
    			}
    			else{
    				leftRotate(temp -> parent);
    			}
    		}
    		

    		if(temp -> balanceFac > 1){
    			temp = temp -> leftChild;
    			if(heightOf(temp -> leftChild) < heightOf(temp -> rightChild)){
    				leftRotate(temp);
    				rightRotate(temp -> parent -> parent);
    			}
    			else{
    				rightRotate(temp -> parent);
    			}
    		}
    		

    		tempu = tempu -> parent;
    	}
    }*/
    int minOfTreeWithRoot(node* Root){
        while(Root -> leftChild != NULL){
            Root = Root -> leftChild;
        }
        return Root -> dat;
    }

    void delet(int val){
    	bool found = false;
    	node* temp = root;
        int  min; 
    	while(!found && temp != NULL){
    		if(val < temp -> dat){
    			temp = temp -> leftChild; 
    		}
    		else if(val > temp -> dat){
    			temp = temp -> rightChild;
    		}
    		else{
    			found = true;
    		}
    	}
    	if(temp == NULL){
    		cout<<"Element not found : err"<<endl;
    		return;
    	}
    	if(temp -> leftChild == NULL && temp -> rightChild == NULL){
    		
            if(temp -> parent -> leftChild == temp){
                temp -> parent -> leftChild = NULL;
            }
    		if(temp -> parent -> rightChild == temp ){
                temp -> parent -> rightChild = NULL;
            }
    		delete temp;
    	}
    	else if(temp -> leftChild == NULL || temp -> rightChild == NULL){
    		if(temp -> leftChild == NULL){
    			temp -> rightChild -> parent = temp -> parent;
    			if(temp -> parent -> leftChild == temp){
    				temp -> parent -> leftChild = temp -> rightChild;
    			}
    			else{
    				temp -> parent -> rightChild = temp -> rightChild;
    			}
    			delete temp;
    		}
    		else{
    			temp -> leftChild -> parent = temp -> parent;
    			if(temp -> parent -> leftChild == temp){
    				temp -> parent -> leftChild = temp -> leftChild;
    			}
    			else{
    				temp -> parent -> rightChild = temp -> leftChild;
    			}
    			delete temp;
    		}

    	}
    	else{
            min = minOfTreeWithRoot(temp -> rightChild);
            delet(min);
            temp -> dat = min ;
    	}
    }

    int suckseSirOf(int val){
        bool found = false;
        node* temp = root;
        while(!found && temp!= NULL){
            if(val>temp -> dat){
                temp = temp -> rightChild;
            }
            else if(val<temp -> dat){
                temp = temp -> leftChild;
            }
            else{
                found = true;
            }
        }
        if(temp == NULL){
            cout<<"Invalid number Entered !!"<<endl;
            return 0;
        }
        if(temp -> rightChild != NULL){
            return minOfTreeWithRoot(temp -> rightChild);
        }
        else{
            while(temp -> parent -> leftChild != temp && temp != NULL){
                temp = temp -> parent;
            }
            if(temp == NULL){
                cout<<"Its itself the largest number in the tree!!"<<endl;
                return 0;
            }
            else{
                return temp -> dat;
            }
        }
    }

};

int main(){
	AVL tree;
    tree.insert(1);
    tree.insert(2);
    tree.insert(3);
    tree.insert(4);
    tree.insert(5);
    tree.insert(6);
    tree.insert(7);
    tree.insert(8);
    tree.inOrder(tree.returnRoot());
    tree.delet(4);
    tree.inOrder(tree.returnRoot());
    tree.insert(9);
    tree.inOrder(tree.returnRoot());
    cout<<endl<<endl<<endl;
    cout<<tree.heightOf(tree.returnRoot())<<endl<<endl;
    cout<<tree.suckseSirOf(6)<<endl;
    return 0;
}