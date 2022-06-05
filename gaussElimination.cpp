#include<iostream>

using namespace std;


int main(){
	int num;
	cout<<"Enter the number of unknowns: "<<endl;
	cin>>num;
	float** mat  = new float*[num];
    for(int i = 0;i<num;i++){
    	mat[i] = new float[num +1];
    }
	cout<<"Enter the a*x1 + b* x2 + c* x3 + ........+z* x26+...= num(enter the constants only) "<<endl;
    for(int i = 0;i<num;i++){
    	for(int j = 0;j<num + 1;j++){
    		cin>>mat[i][j];
    	}
    }
    cout<<endl;
    float a ,b;
    for(int col = 0; col< num-1;col++){
    	for(int row = col+1;row<num;row++){
    		a = mat[row][col];
            b = mat[col][col];
    		for(int k = 0;k<num+1;k++){
    			mat[row][k] = (mat[row][k] - (a/b)*mat[col][k]);
    		    
    		    /*for(int i = 0;i<num;i++){
    		    	for(int j= 0;j<num+1;j++){
    		    		cout<<mat[i][j]<<"      ";
    		    	}
    		    	cout<<endl;
    		    }
    		    cout<<endl<<endl<<endl;*/
    		}
    	}
    }
    float m,n,p;
    float A[num];
    for(int i = 1;i<= num;i++){
         p =0;
         m = mat[num - i][num];
         n = mat[num - i][num - i];
         if(i - 2 >=0){
            for(int q = 0; q<= i-2;q++){
                p +=  A[num-i+q+1] * mat[num - i][num -i+q+1];
            }
         }
         A[num -i] = (m - p)/n;
    }

    for(int i = 0; i< num;i++){
        cout<<A[i]<<endl;
    }

    
    for(int i = 0;i<num;i++){
    	delete mat[i];
    }
    delete mat;

	return 0;
}