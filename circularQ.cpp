#include<iostream>

using namespace std;
const int SIZE = 5;

class cq{
private:
    int start,end;
    int arr[SIZE];
public:
    cq():start(0),end(0){}
    bool isEmpty(){
        if(start == end){
            return true;
        }
        else
            return false;
    }

    bool isFull(){
        if(start == (end + 1) % SIZE){
            return true;
        }
        else
            return false;
    }

    void enque(){
        int a;
        if(isFull()){
            cout<<"You can't enque anymore!!"<<endl;
        }
        else{
            cout<<"Enter the number to enque: "<<endl;
            cin>>a;
            end = (end + 1)%SIZE;
            arr[end] = a;
        }
    }

    void deque(){
        if(isEmpty()){
            cout<<"You can't deque!"<<endl;
        }
        else{
            start = (start + 1)%SIZE;
        }
    }

    void display(){
        for(int i = start+1;i!=(end+1)%SIZE; i = (i+1)%SIZE){
            cout << arr[i]<<endl;
        }
    }
};


int main(){
    cq cq1;
    char ch;
    int a;
    do{
        cout<<"Enter what to perform: 1:enque,2:deque,3:display :"<<endl;
        cin>>a;
      switch(a){
        case 1:
        cq1.enque();
        break;
        case 2:
        cq1.deque();
        break;
        case 3:
        cq1.display();
        break;
        default:
        cout<<"You entered invalid number"<<endl;
        break;
      }
      cout<<"Do you want to continue"<<endl;
      cin>>ch;
    }while(ch == 'y');
    return 0;
}