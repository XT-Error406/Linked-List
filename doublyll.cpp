#include <bits/stdc++.h>
using namespace std;

/*******Node in doubly List**************************/
class Node{
     
     public:
     int data;
     Node*Next;	
     Node*Prev;
     
     Node(int d){
     	
     	this->data=d;
     	this->Next=NULL;
          this->Prev=NULL;
     }
};
/*******TO  get length of LL**************************/

int len(Node*&head){
  int len=0;
     Node*temp=head;
      while(temp!=NULL){
          len++;
          temp=temp->Next;
     }
     return len;
}
/******** At head ****************/

void at_head(Node*&head,int d){
     
     if(head==NULL){
          
          Node*temp=new Node(d);
          head=temp;
          return;
     }  
    Node*temp=new Node(d);
    
    temp->Next=head;
    
    head=temp;
}
/******** At Tail ****************/


void at_tail(Node*tail,int d){
     
     Node*temp=new Node(d);
     
     tail->Next=temp;
     
     tail=temp;
}

/******** insert At any pos ****************/
void at_pos(Node* &head,Node*&tail,int pos,int d){
     
     if(pos<=0 ||pos>len(head) ){
          cout<<"Not vaild Position"<<endl;
          return;
     }
     if(pos==1){
          at_head(head,d);
          return;
     }
     
     int cnt=1;
     Node*temp=head;
     while(cnt<pos-1 && temp!=NULL){
          
          temp=temp->Next;
          cnt++;
     }
     
     if(temp->Next==NULL){
          at_tail(tail,d);
          return;
     }
     else{
          Node*New_node=new Node(d);
          
          New_node->Next=temp->Next;
          temp->Next->Prev=New_node;
          temp->Next=New_node;
          New_node->Prev=temp;
          
     }
}

/******** TO delete a Node form a position ****************/

void to_delete(Node* &head,int pos){
     if(head==NULL){
          cout<<" Empty list "<<endl;
          return;
     }
    if(pos<=0 ||pos>len(head) ){
          cout<<"Not vaild Position"<<endl;
          return;
     }
     if(pos==1){
         
      Node*temp=head;
      head=head->Next;
      if(head!=NULL){
          //single node then head points to NULL prev of NULL not exist
       head->Prev=NULL;
    }
      temp->Next=NULL;
      delete temp; 
      return;
     }
     
     int cnt=1;
     Node*curr=head;
     Node*back=NULL;
     while(cnt!=pos){
          back=curr;
          curr=curr->Next; 
          cnt++;
     }
     if(curr->Next==NULL){
          
       back->Next=curr->Next;
       curr->Prev=NULL;
       delete curr;
       return;
     } 
    else{ 
     back->Next=curr->Next;
     curr->Next->Prev=back;
     curr->Next=NULL;
     curr->Prev=NULL;  // It is not necessary to explicitly set 
     delete curr;
  }
}



/*******To print the ll ***************/
void print(Node* &head){
     
     Node*temp=head;
     while(temp!=NULL){
          
          cout<<temp->data<<" ";
          temp=temp->Next;
     }
     cout<<endl;
}

/*****************************************/
int main(){
     
    // Node*head=NULL;
        
     Node*first=new Node(5);
     Node*head=first;
     Node*tail=first;
     print(head);
     
     at_head(head,10);
     print(head);
     at_head(head,20);
     print(head);
     
    // cout<<head->data<<" and "<<tail->data<<endl;
     
     // at_tail(tail,40);
     
     // print(head);
     
     // at_pos(head,tail,4,300);
     // print(head);
     
     to_delete(head,1);
     print(head);
     
     
     return 0;
}