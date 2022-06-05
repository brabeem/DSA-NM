#include<iostream>    
struct node{ 
     // A node has two components: some data and a pointer to the next node. 
     int node_data; 
     node* next; 
}; 

int main(){ 
     // Make some nodes: 
     node A,B,C; 
     // Make a reference to the 'front' of the list 
     node* start; 
     // Make the list start at 'A' 
     start = &A; 
     // Create a link from 'A' to 'B' 
     A.next = &B; 
     // Create a link from 'B' to 'C' 
     B.next = &C; 
     // Give 'C' a special value to show it's the end of the list: 
     C.next = NULL; 
     return 0; 
    } 