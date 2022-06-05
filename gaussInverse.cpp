#include<iostream>

using namespace std;


int main(){
	int num;
	cout<<"Enter the number of unknowns: "<<endl;
	cin>>num;
	float** mat  = new float*[num];
    for(int i = 0;i<num;i++){
    	mat[i] = new float[num + num];
    }
	cout<<"Enter the a*x1 + b* x2 + c* x3 + ........+z* x26+...= num(enter the constants only) "<<endl;
    for(int i = 0;i<num;i++){
    	for(int j = 0;j<num + num;j++){
    		cin>>mat[i][j];
    	}
    }
    cout<<endl;
    float a ,b;
    for(int col = 0; col< num;col++){
    	for(int row = 0;row<num;row++){
    		if(row!=col){
    				a = mat[row][col];
                    b = mat[col][col];
    			for(int k = 0;k<num+num;k++){
    				mat[row][k] = (mat[row][k] - (a/b)*mat[col][k]);
    		    }
                /*for(int i = 0;i<num;i++){
                    for(int j= 0;j<num+num;j++){
                        cout<<mat[i][j]<<"      ";
                    }
                    cout<<endl;
                }
                cout<<endl<<endl<<endl;*/
    		}
    	}   
    }
    float l = 0;
    for(int i = 0; i< num ; i++ ){
        for(int j = 0; j<num;j++){
            if(i == j){
                l = mat[i][j];
                for(int k = 0; k<num+num;k++){
                    mat[i][k] = mat[i][k] /l;
                }
            }
        }
    }
    
    for(int i = 0;i<num;i++){
        for(int j= num;j<num+num;j++){
            cout<<mat[i][j]<<"          ";
        }
        cout<<endl;
    }
    cout<<endl<<endl<<endl;
    for(int i = 0;i<num;i++){
    	delete mat[i];
    }
    delete mat;

	return 0;
}