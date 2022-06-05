#include<iostream>
#include<string.h>
#include<math.h>
using namespace std;

struct user{
	string username;
	string pass;
};

int hashValueOf(string userName){
    int i = 0;
    int sum = 0;
    int separate = 0;
    while(userName[i] != '\0'){
      separate = userName[i] * pow(2,i);
      separate = separate % 7;
      sum += separate; 
      i++;
    }
    sum = sum % 7;
    return sum;
  }

int main(){
    string userName;
    string goeyman;
    user first;
    cout<<"Enter the userName";
    cin>>userName;
    //goeyman = userName;
    
    first.username = userName;
    //cout<<hashValueOf(userName);
    cout<<first.username;
	return 0;
}