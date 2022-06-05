#include<iostream>

using namespace std;


int main(){
	int num;
	cout<<"Enter the number of unknowns: "<<endl;
	cin>>num;
    float* ans =  new float[num];
	float** A  =  new float*[num];
    float** U  =  new float*[num];
    float** L  =  new float*[num]; 
    for(int i = 0;i<num;i++){
    	A[i] = new float[num];
        U[i] = new float[num + 1];
        L[i] = new float[num + 1];
    }
	
    cout<<"Enter the a*x1 + b* x2 + c* x3 + ........+z* x26+...= num(enter the constants only) "<<endl;
    for(int i = 0;i<num;i++){
    	for(int j = 0;j<num + 1;j++){
            if(j < num){
                cin>>A[i][j];
                L[i][j] = 0;
            }
            else{
                cin>>L[i][j];
            }
            U[i][j] = 0;	
    	}
    }

    

    float temp = 0;
    for(int i =0; i<num;i++){
        for(int j=0;j<num;j++){
            if(i<=j){
                temp = 0;
                for(int k = 0;k<i;k++){
                temp = temp + L[i][k] * U[k][j];
                }
                U[i][j] = A[i][j] - temp;
                if(i == j){
                    L[i][j] = 1;
                }
                else{
                    L[i][j] =0;
                }
            }
            else{
                temp = 0;
                for(int k = 0;k<j;k++){
                temp = temp + L[i][k] * U[k][j];
                }
                L[i][j] = (A[i][j] - temp)/U[j][j];
                U[i][j] = 0;
            }
        }
    }

    /*for(int i = 0; i< num; i++){
        for(int j = 0; j< num+1 ;j++){
            cout<<L[i][j]<<"      ";
        }
        cout<<endl;
    }
    cout<<endl<<endl;
    for(int i = 0; i< num; i++){
        for(int j = 0; j< num+1 ;j++){
            cout<<U[i][j]<<"      ";
        }
        cout<<endl;
    }*/
    

    int col = num;
    for(int row = 0;row < num;row++){
        temp = 0;
        for(int k =0;k<row;k++){
            temp = temp + L[row][k] * U[k][col];
        }
        U[row][col] = (L[row][col] - temp)/L[row][row];
    }
    
    ans[num-1] = U[num-1][num]/(U[num -1][num - 1]);
    for(int i = num - 2 ;i >= 0;i--){
        temp = 0;
        for(int k =i+1;k<num;k++){
            temp = temp + U[i][k] * ans[k];
        }
        ans[i] = (U[i][num] - temp)/U[i][i];
    }

    for(int i = 0;i<num;i++){
        cout<<ans[i]<<endl;
    }

    for(int i = 0;i<num;i++){
    	delete A[i];
        delete U[i];
        delete L[i];
    }
    delete A;
    delete U;
    delete L;
    delete [] ans;

	return 0;
}