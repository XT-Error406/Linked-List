#include <bits/stdc++.h>
using namespace std;

class Node{
   public:
   	int data;
   	Node*Next;
   	
   	Node(int d){
   		
   		this->data=d;
   		this->Next=NULL;
   	}
};
/************** At postion ************/
void at_pos (Node* &head,int val,int d){
    
    if(head==NULL){
       Node*temp=new Node(d);
       head=temp;
       temp->Next=temp;//temp-next=head
       return;
    }    
  
// their is No head or tail ptr, we just take a ptr;
   else{
     Node*temp=head;
   
       while(temp->data!=val){
      
           temp=temp->Next;
     }
    
   Node*New_node=new Node(d);
   
   New_node->Next=temp->Next;
   temp->Next=New_node; 
   
  }
   
}

/************* To delete *****************/

void to_delete(Node*&tail,int val){
   
   if(tail==NULL){
      cout<<" Empty list "<<endl;
      return;
   }
   
   Node*prev=tail;
   Node*curr=prev->Next;
   
   
   while(curr->data!=val && curr!=tail){
     
      prev=curr;
      curr=curr->Next;
   }
    // if list is with single node prev,curr=prev-next means prev
     if(prev==curr){
       tail=NULL;
        cout<<" list is Empty Now "<<endl;
         delete curr;
          return;
      }
     
     // means we are deleting very first node aur cicrular node with given ptr 
     if(tail==curr && curr->data==val){
       
       tail=tail->Next;
        prev->Next=curr->Next;
         curr->Next=NULL;
          delete curr;
          return;
     }
     
    //  cout<<prev->data <<" is the cur "<<curr->data<<endl;
    // return;
     // means we are delelting in the middle of linked list
    if(curr!=tail){ 
      prev->Next=curr->Next;
      curr->Next=NULL;
      delete curr;
      return;
      }
    // val not found invaild  
   else{
      cout<<"value Not found "<<endl;
      return;
   }
   
}

/***************To print ***************/

void print(Node*&head){
   
   Node*temp=head;
   do{
      cout<<head->data<<" ";
      head=head->Next;
   }while(temp!=head);
   
   cout<<endl;
}

int main(){
   
  
   Node*tail=NULL;
   at_pos(tail,5,10);
 //  to_delete(tail,10);
   print(tail);
   
   at_pos(tail,10,30);
   print(tail);
   
   at_pos(tail,30,50);
   print(tail);
   
   to_delete(tail,60);
   print(tail);
    
    return 0;
}
