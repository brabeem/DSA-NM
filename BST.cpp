#include<iostream>
#include<Queue.h>
using namespace std;

struct node{
	int data;
	node* left;
	node* right;
};

class binarySearchTree{
private:
	node* Root;
public:
	binarySearchTree():Root(NULL){}
	
	node*  createNode(int val){
		node* temp = new node;
		temp -> data = val;
		return temp;
	}
    node * returnRoot(){return Root;}
    modifyRoot(node* root){
    	Root = root;
    }
	void insert(node * root,int val ){
		node* temp ;
		if(Root == NULL){
			temp = createNode(val);
			Root = temp;
			return;
		}
		else if(root == NULL){
			return;
		}
		else if(root -> data >= val){
			insert(root -> left,val);
			if(root -> left == NULL){
				temp = createNode(val);
				root -> left = temp;
			}
		}
		else{
			insert(root -> right,val);
			if(root -> right == NULL){
				temp = createNode(val);
				root -> right = temp;
			}
		}
	}


	bool search(node* root,int val ){
		if(root == NULL){return false;}
		else if(root -> data < val){return search(root -> right,val);}
		else if(root -> data > val){return search(root -> left,val);}
		else return true;
	}
    
    
    int findHeight(node* root){
    	int leftH;
    	int rightH;
    	if(root == NULL){
    		return -1;
    	}
    	else{
    		leftH = findHeight(root -> left);
    		rightH = findHeight(root -> right);
    		return max(leftH , rightH) + 1;
    	}
    }
    

   /* isSubtreeLesser(node* root,int val){
    	if(root == NULL){return true;}
    	else if(root -> data < val){
    		return (isSubtreeLesser(root -> left,val)&&isSubtreeLesser(root -> right,val));
    	}
    	else return false;
    }

    isSubTreeGreater(node* root,int val){
    	if(root == NULL){return true;}
    	else if(root -> data > val ){
    		return (isSubTreeGreater(root -> right,val) && isSubTreeGreater(root -> left,val))
    	}
    	else return false;
    }
    

    bool isBinarySearchTree(node* root){
    	if(root == NULL){return true;}
    	else if(isSubtreeLesser(root -> left,root -> data)&&isSubTreeGreater(root -> right,root -> data)&&isBinarySearchTree(root -> left)&&isBinarySearchTree(root -> right)){
    		return true;
    	}
    	else return false;
    }*/

    bool isBinarySearchTree(node* root ,max ,min){
    	if(root == NULL){
    		return true;
    	}
    	else if(root -> data < max && root -> data > min){
    		return (isBinarySearchTree(root -> left,root -> data,min) && isBinarySearchTree(root -> right,max,root -> data));
    	}
    	else return false;
    }

    // level order traversal AND preorder ,inorder and postorder traversal

    void levelOrderTraversal(node* root){
    	if(root == NULL){
    		return;
    	}
    	else{
    		queue.push(root -> left);
    		queue.push(root -> right);
    		cout<< root -> data<< endl;
    		levelOrderTraversal(queue.pop());
    	}
    }

    void preOrder(node* root){
    	if(root == NULL){return;}
    	else{
    		cout<< root -> data <<endl;
    		preOrder(root -> left);
    		preOrder(root -> right);
    	}
    }

    void inOrder(node* root){
    	if(root == NULL){return;}
    	else{
    		inOrder(root -> left);
    		cout<< root -> data <<endl;
    		inOrder(root -> right);
    	}
    }


    void postOrder(node* root){
    	if(root == NULL){return;}
    	else{
    		postOrder(root -> left);
    		postOrder(root -> right);
    		cout<< root -> data <<endl;
    	}
    }

    node* findMin(node* root){
    	if(root -> left  == NULL){
    		return root;
    	}
    	else return findMin(root -> left);
    }

    node* Delete(node* root,int val){
    	if(root -> data < val){
    		root -> right = Delete(root -> right,val);
    	}
    	else if(root -> data > val){
    		root -> left  = Delete(root -> left,val);
    	}
    	else{
    		if(root -> left == NULL && root -> right == NULL){
    			delete root;
    			root = NULL;
    		}
    		else if(root -> left == NULL){
    			node* temp = root;
    			root = root -> right;
    			delete temp;
    		}
    		else if(root -> right == NULL){
    			node* temp = root;
    			root = root -> left;
    			delete temp;
    		}
    		else{
    			node* temp = findMin(node* root);
    			root -> data = temp -> data;
    			root -> right = Delete(root -> right , temp -> data);
    		}
    	}
        return root;
    }
};


int main(){
	binarySearchTree BST;
	int a ;
	char ch;
	do{
		cout<<"Enter 1->insert,2->search,3->findHeight,4->isBinarySearchTree,5->levelOrderTraversal,6->preOrder,7->inOrder,8->postOrder,9->Delete"<<endl;
        cin >>a;
        switch(a){
        	case 1:
        	int b;
        	cout<<"Enter the number to insert: "<<endl;
        	cin>>b;
        	BST.insert(BST.returnRoot(),b);
        	case 2:
        	int s;
        	cout<<"Enter number to search: "<<endl;
        	cin>>s
        	BST.search(BST.returnRoot(),s);
        	case 3:
        	cout<<BST.findHeight(BST.returnRoot());
        	case 4:
        	cout<<BST.isBinarySearchTree();
        	case 5:
        	BST.levelOrderTraversal(BST.returnRoot());
        	case 6:
        	BST.preOrder(BST.returnRoot());
        	case 7:
        	BST.inOrder(BST.returnRoot());
        	case 8:
        	BST.postOrder(BST.returnRoot());
        	case 9:
        	int d;
        	cout<<"Enter the number to delete: "<<endl;
        	cin>>d;
        	node* newRoot = BST.Delete(BST.returnRoot(),d);
        	modifyRoot(newRoot);
        	default:
        	cout<<"you have entered invalid number."<<endl;
        }
        cout<<"Do you want to continue: "<<endl;
        cin>>ch;
	}while(ch == 'y');
	return 0;
}