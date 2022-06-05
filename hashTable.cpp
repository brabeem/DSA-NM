//HASHING WITH CHAINING
#include<iostream>
#include<cstring>
#include<string.h>
#include<math.h>
using namespace std;

struct user{
  string username;
  string pwd;
  user* nxt;
  user* prev;
};

class hashTab{
private:
int nKeys,mSlots;
user** mainTable;
public:
  hashTab():nKeys(0),mSlots(5){
    mainTable = new user*[5];
    for(int i = 0; i< 5; i++){
      mainTable[i] = NULL;
    }
  }
  
  user* signUp(string userName,string pass){
     user* temp = new user;
     temp -> username = userName;
     temp -> pwd = pass;
     temp -> nxt = NULL;
     return temp;
  }
  
  int hashValueOf(string userName){
    int i = 0;
    int sum = 0;
    int separate = 0;
    while(userName[i] != '\0'){
      separate = userName[i] * pow(2,i);
      separate = separate % mSlots;
      sum += separate; 
      i++;
    }
    sum = sum % mSlots;
    return sum;
  }


  void insertH(string userName,string pass){
    nKeys++;
    if(nKeys > mSlots){
      //table size exceeds the loading factor//table doubling
      //first iterate over the maintable copy all the data to the next table of double size
      //then insert the value you want to insert by recursively calling the insertH function
      user** nxtMainTable = new user*[2*mSlots]; 
      user* mainPtr = NULL;
      mSlots = 2* mSlots;
      int hashVal = 0;
      user* collision = NULL;
      user* cMainPtr;
      for(int i = 0;i<(mSlots/2);i++){
        mainPtr = mainTable[i];
        
        while(mainPtr != NULL){
          hashVal = hashValueOf(mainPtr -> username);
          if(nxtMainTable[hashVal] == NULL){
            //put the data directly
            cMainPtr = mainPtr;
            mainPtr = mainPtr -> nxt;
            nxtMainTable[hashVal] = cMainPtr;
            cMainPtr -> nxt = NULL;
            cMainPtr -> prev = NULL;
          }
          else{
            //collision occurs
            cMainPtr = mainPtr;
            mainPtr = mainPtr -> nxt;
            collision = nxtMainTable[hashVal];
            cMainPtr -> nxt = collision;
            collision -> prev = cMainPtr;
            nxtMainTable[hashVal] = cMainPtr;
            cMainPtr -> prev = NULL;
          }
        }


      }
      delete [] mainTable;
      mainTable = nxtMainTable;
      nxtMainTable = NULL;
      nKeys--;
      insertH(userName,pass);
    }
    else{
      user* temp = signUp(userName,pass);
      int hashVal = hashValueOf(userName);
      if(mainTable[hashVal] == NULL){
        //no collision just insert
        mainTable[hashVal] = temp;
      }
      else{
        //collision occurs//solved by chaining
        user* collision = mainTable[hashVal];
        temp -> nxt = collision;
        collision -> prev = temp;
        mainTable[hashVal] = temp;
      }
    }
  }



  string searchH(string userName){
    int hashVal = hashValueOf(userName);
    user* head= mainTable[hashVal];
    bool found = false;
    while(!found && head != NULL){
      if(userName == head -> username){
        found = true;
      }
      else{
        head = head -> nxt;
      }
    }
    if(found){
      return head -> pwd;
    }
    else{
      return "nothing";
    }
  }


void delH(string userName){
  nKeys--;
  if(nKeys > mSlots/4){  
    //NORMAL DELETE 
    int hashVal = hashValueOf(userName);
    bool found  = false;
    if(mainTable[hashVal] == NULL){
      cout<<"username not found"<<endl;
    }
    else{
      user* mainPtr = mainTable[hashVal];
      while(mainPtr != NULL && !found){
        if(mainPtr -> username == userName){
          found = true;
        }
        else{
          mainPtr = mainPtr -> nxt;
        }
      }
      if(mainPtr == NULL){
        cout<<"username not found"<<endl;
      }
      else{

        if(mainPtr -> prev != NULL){
           mainPtr -> prev -> nxt = mainPtr -> nxt;
        }
        else{
          mainTable[hashVal] = mainPtr -> nxt;
        }

        if(mainPtr -> nxt != NULL){
          mainPtr -> nxt -> prev = mainPtr -> prev;
        }
      }
    }
  }
  else{
    //table halving 
      user** nxtMainTable = new user*[mSlots/2]; 
      user* mainPtr = NULL;
      float a = mSlots /2;
      mSlots = mSlots/2;
      int hashVal = 0;
      user* collision = NULL;
      user* cMainPtr;
      for(int i = 0;i<(2*a);i++){
        mainPtr = mainTable[i];
        
        while(mainPtr != NULL){
          hashVal = hashValueOf(mainPtr -> username);
          if(nxtMainTable[hashVal] == NULL){
            //put the data directly
            cMainPtr = mainPtr;
            mainPtr = mainPtr -> nxt;
            nxtMainTable[hashVal] = cMainPtr;
            cMainPtr -> nxt = NULL;
            cMainPtr -> prev = NULL;
          }
          else{
            //collision occurs
            cMainPtr = mainPtr;
            mainPtr = mainPtr -> nxt;
            collision = nxtMainTable[hashVal];
            cMainPtr -> nxt = collision;
            collision -> prev = cMainPtr;
            nxtMainTable[hashVal] = cMainPtr;
            cMainPtr -> prev = NULL;
          }
        }
      }
      delete [] mainTable;
      mainTable = nxtMainTable;
      nxtMainTable = NULL;
      nKeys++;
      delH(userName);
    }
}

};


int main(){
  hashTab hst;
  hst.insertH("brabeem123@gmail.com","123apple");
  hst.insertH("075bei011.brabeem@pcampus.edu.np","vgzjymo9m7");
  hst.insertH("brabeem","don");
  hst.insertH("sakisakuo","nopwd");
  hst.insertH("maHuGorkhey","ehhBoy");
  hst.insertH("dopeKid","yoyo");
  //cout<<hst.searchH("maHuGorkhey");
  hst.delH("dopeKid");
  cout<<hst.searchH("dopeKid");
  return 0;
}