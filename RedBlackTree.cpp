#include<iostream>

using namespace std;

struct node{
	int id;
	node* parent;
	node* leftChild;
	node* rightChild;
	bool color;
};

class RedBlackTree{
private:
	node* root;
	node* sentinel;
public:
	RedBlackTree(){
		sentinel = new node;
		sentinel->color = 0;
		sentinel->parent = NULL;
		sentinel->leftChild = NULL;
		sentinel->rightChild = NULL;
		root = sentinel;
	}
    

    node* createNode(int val){
    	node* temp = new node;
    	temp -> id = val;
    	temp -> color = 1;
    	temp -> parent = sentinel;
    	temp -> leftChild = sentinel;
    	temp -> rightChild = sentinel;
    	return temp;
    }
    
    node* returnRoot(){return root;}
    
    void rightRotate(node* toBeMod){
    	node* toBeModL =  toBeMod -> leftChild;
    	node* toBeModP =  toBeMod -> parent;
    	toBeMod  -> parent = toBeModL;
    	if(toBeModL -> rightChild != sentinel){
    		toBeModL -> rightChild -> parent = toBeMod;
    	}
    	toBeMod  -> leftChild = toBeModL -> rightChild;
    	toBeModL -> rightChild = toBeMod;
    	toBeModL -> parent = toBeModP;
        if(toBeModP == sentinel){
        	root = toBeModL;
        	toBeModL -> parent = sentinel;
        }
    	else if(toBeModP -> leftChild == toBeMod){
    		toBeModP -> leftChild = toBeModL;
    	} 
    	else{
    		toBeModP -> rightChild = toBeModL;
    	}
    }

    void leftRotate(node* toBeMod){
    	node* toBeModR = toBeMod -> rightChild;
    	node* toBeModP = toBeMod -> parent;
    	toBeMod -> parent = toBeModR;
    	if(toBeModR -> leftChild != sentinel ){
    		toBeModR -> leftChild -> parent = toBeMod;
    	}
    	toBeMod -> rightChild = toBeModR -> leftChild;
    	toBeModR -> leftChild = toBeMod;
    	toBeModR -> parent = toBeModP;
        if(toBeModP == sentinel){
        	root = toBeModR;
        	toBeModR -> parent = sentinel;
        }
    	else if(toBeModP -> leftChild == toBeMod){
    		toBeModP -> leftChild = toBeModR;
    	} 
    	else{
    		toBeModP -> rightChild = toBeModR;
    	}
    }
    
    void redBlackMaintain(node* temp){
    	while(temp -> parent -> color == 1){
    		if(temp -> parent == temp -> parent -> parent -> leftChild){
    			node* ant = temp -> parent -> parent -> rightChild;
    			if(ant -> color == 1){
    				ant -> parent-> color = 1;
    				ant -> color = 0;
    				temp -> parent -> color = 0;
    				temp = temp -> parent -> parent;
    			}
    			else{
    				if(temp -> parent -> rightChild == temp){
    					temp = temp -> parent;
    					leftRotate(temp);
    				}
    				temp -> parent -> color = 0;
    				temp -> parent -> parent -> color = 1;
    				temp -> leftChild -> color = 1;
    				rightRotate(temp -> parent -> parent);
    			}
    		}
    		else{
    			node* ant = temp -> parent -> parent -> leftChild;
    			if(ant -> color == 1){
    				ant -> color = 0;
    				ant -> parent -> color = 1;
    				temp -> parent -> color = 0;
    				temp = temp -> parent -> parent;
    			}
    			else{
    				if(temp -> parent -> leftChild == temp){
    					temp = temp -> parent;
    					rightRotate(temp);
    				}
    				temp -> parent -> color = 0;
    				temp -> parent -> parent -> color = 1;
    				leftRotate(temp -> parent -> parent);
    			}
    		}
    	}
    	root -> color = 0;
    }

    void insert(int val){
    	node* temp = root;
    	if(root == sentinel){
    		node* created = createNode(val);
    		created -> color = 0;
            root = created;
            root -> parent = sentinel;
    	}
    	else{
    	 while(temp != sentinel){
    		if(temp -> id < val){
    			if(temp -> rightChild == sentinel){
    				node* created = createNode(val);
    				temp -> rightChild = created;
    				created -> parent = temp;
                    redBlackMaintain(created);
    				temp = sentinel;
    			}
    			else{
    				temp = temp -> rightChild;
    			}
    		   
    	    }
    	    else{
    	    	if(temp -> leftChild == sentinel){
    	    		node* created = createNode(val);
    	    		temp -> leftChild = created;
    	    		created -> parent = temp;
    	    		redBlackMaintain(created);
    	    		temp = sentinel;
    	    	}
    	    	else{    		    
    	    		temp = temp -> leftChild;
                }
    	    }
    	 }
       }
    }
    

    
    void inOrder(node* temp){
    	if(temp == sentinel){
    		cout<<endl<<endl<<endl;
    		return;
    	}
    	inOrder(temp -> leftChild);
    	cout<<temp -> id<<" color = "<<temp ->color<<endl;
    	inOrder(temp -> rightChild);
    }
    
    int minOf(node* temp){
    	if(temp -> leftChild == sentinel){
    		return temp -> id;
    	}
    	return minOf(temp -> leftChild);
    }
    
    node* bstSearch(int num){
    	bool found = false;
    	node* temp = root;
    	while(!found && temp != sentinel){
    		if(num < temp -> id){
    			temp = temp -> leftChild;
    		}
    		else if(num > temp -> id){
    			temp = temp -> rightChild;
    		}
    		else{
    			found = true;
    		}
    	}
    	if(!found){
    		cout<<"NOT FOUND";
    		return NULL;
    	}
    	else{
    		return temp;
    	}
    }
    
    void redBlackDel(int num){
    	node* temp = bstSearch(num);
    	if(temp != NULL){
    		if(temp -> rightChild == sentinel && temp -> leftChild == sentinel){
    			if(temp -> parent-> leftChild == temp){
    				temp -> parent -> leftChild = sentinel;
    				if(temp -> color != 1){
    				   fixDel(temp -> leftChild,temp -> parent,temp -> parent -> rightChild);
    			    }
    			}
    			else{
    				temp -> parent -> rightChild = sentinel;
    				if(temp -> color != 1){
    				   fixDel(temp -> leftChild,temp -> parent,temp -> parent -> leftChild);
                    }
    			}
    			delete temp;
    		}
    		else if(temp -> leftChild == sentinel || temp -> rightChild == sentinel){
    			if(temp == temp -> parent -> leftChild){
    				if(temp -> leftChild == sentinel){
    					temp -> parent -> leftChild = temp -> rightChild;
    					temp -> rightChild -> parent = temp -> parent;
                        if(temp -> color != 1){
                        	if(temp -> rightChild -> color == 1){
                        		temp -> rightChild -> color = 0;
                        	}
                        	else{
    					        fixDel(temp -> rightChild,temp -> parent,temp -> parent -> rightChild);
    					    }
    					}
    					delete temp;
    				}
    				else{
    					temp -> parent -> leftChild = temp -> leftChild;
    					temp -> leftChild -> parent = temp -> parent;
    					if(temp -> color != 1){
    					  if(temp -> leftChild -> color == 1){
    					  	temp -> leftChild -> color = 0;
    					  }
    					  else{
    					      fixDel(temp -> leftChild,temp -> parent,temp -> parent -> rightChild);
    					  }
    					}
    					delete temp;
    				}
    			}
    			else{
    				if(temp -> leftChild == sentinel){
    					temp -> parent -> rightChild = temp -> rightChild;
    					temp -> rightChild -> parent = temp -> parent;
    					if(temp -> color != 1){
    						if(temp -> rightChild -> color == 1){
    							temp -> rightChild -> color = 0;
    						}
    						else{
    					        fixDel(temp -> rightChild,temp -> parent,temp -> parent -> leftChild);
    					    }
    					}
    					delete temp;
    				}
    				else{
    					temp -> parent -> rightChild = temp -> leftChild;
    					temp -> leftChild -> parent = temp -> parent;
    					if(temp -> color != 1){
    						if(temp -> leftChild -> color == 1){
    							temp -> leftChild -> color = 0;
    						}
    						else{
    					    fixDel(temp -> leftChild,temp -> parent,temp -> parent -> leftChild);
    					    }
    					}
    					delete temp;
    				}
    			}
    		}
    		else{
    			int a = minOf(temp -> rightChild);
    			redBlackDel(a);
    			temp -> id = a;
    		}
    	}
    }

    node* siblingOf(node* temp){
    	//FIND SIBLING HERE
    	node* sib = NULL;
        if(temp -> parent -> leftChild == temp){
    		sib = temp -> parent -> rightChild;
    	}
    	else{
    		sib = temp -> parent -> leftChild;
    	}
    	return sib;
    }
     

    //DO NOT ACCESS THE PARENT OF NODEAFTERDEL
    //returnig in every statement is done
    void fixDel(node* nodAfterDel,node* nodAfterDelP,node* nodAfterDelSib){
    	if(nodAfterDelSib -> color == 0){
    		if(nodAfterDelSib == nodAfterDelP -> leftChild){
    			if(nodAfterDelSib -> leftChild -> color == 1 || (nodAfterDelSib -> leftChild -> color == 1 && nodAfterDelSib -> rightChild -> color ==1)){
    				rightRotate(nodAfterDelP);
    				nodAfterDelSib -> leftChild -> color = 0;
    			}
    			else if(nodAfterDelSib -> rightChild -> color == 1){
    				nodAfterDelSib -> rightChild -> color = 0;
    				leftRotate(nodAfterDelSib);
                    rightRotate(nodAfterDelP);
    			}
    			return;
    		}
    		else{
    			if(nodAfterDelSib -> rightChild -> color == 1 || (nodAfterDelSib -> rightChild -> color == 1 && nodAfterDelSib -> leftChild -> color == 1)){
                    leftRotate(nodAfterDelP);
                    nodAfterDelSib -> rightChild ->color = 0;
    			}
    			else if(nodAfterDelSib -> leftChild -> color == 1){
    				nodAfterDelSib -> leftChild -> color == 0;
    				rightRotate(nodAfterDelSib);
    				leftRotate(nodAfterDelP);
    			}
    			return;
    		}
    		
    		if(nodAfterDelSib -> leftChild -> color == 0 && nodAfterDelSib -> rightChild -> color == 0 ){
    			if(nodAfterDelP -> color == 1){
    				nodAfterDelP -> color = 0;
    				nodAfterDelSib-> color = 1;
    			}
    			else if(nodAfterDelP == root){
    				nodAfterDelSib -> color = 1;
    				nodAfterDelP -> color = 0;
    			}
    			else{
    				nodAfterDelSib -> color = 1;
    				node* nxtSib = siblingOf(nodAfterDelP);
    				fixDel(nodAfterDelP,nodAfterDelP -> parent,nxtSib);
    			}

    		}

    	}
    	else{
    		if(nodAfterDelSib == nodAfterDelP -> leftChild){
    			rightRotate(nodAfterDelP);
    			nodAfterDelSib -> color = 0;
    			nodAfterDelP -> color = 1;
    			fixDel(nodAfterDelP -> rightChild,nodAfterDelP,nodAfterDelP -> leftChild);
    		}
    		else{
    			leftRotate(nodAfterDelP);
    			nodAfterDelSib -> color = 0;
    			nodAfterDelP -> color = 1;
    			fixDel(nodAfterDelP -> leftChild,nodAfterDelP,nodAfterDelP -> rightChild);
    		}
    	}

    }



    
};

int main(){
	RedBlackTree RBT;
	RBT.insert(1);
	RBT.insert(2);
	RBT.insert(3);
	RBT.insert(4);
	RBT.redBlackDel(3);
	RBT.inOrder(RBT.returnRoot());
	RBT.insert(5);
	RBT.inOrder(RBT.returnRoot());
	RBT.insert(6);
	RBT.inOrder(RBT.returnRoot());
    RBT.insert(7);
	RBT.inOrder(RBT.returnRoot());
	RBT.redBlackDel(2);
	RBT.inOrder(RBT.returnRoot());
	RBT.inOrder(RBT.returnRoot());
	return 0;
}