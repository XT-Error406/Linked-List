#include <bits/stdc++.h>
using namespace std;

/*******Node in singly List**************************/
class Node{
     
     public:
     int data;
     Node*Next;	
     
     Node(int d){
     	
     	this->data=d;
     	this->Next=NULL;
     }
};

/*******AT head**************************/
void athead(Node* &head,int d){
	
	if(head==NULL){
		
		Node*temp=new Node(d);
		
		 head=temp;
		
	}
	else{
		
		Node*temp=new Node(d);
		
		temp->Next=head;
		head=temp;
	}
}
/*******AT Tail**************************/
void attail(Node* &tail,int d){
	
	if(tail==NULL){
		Node*temp=new Node(d);
		tail=temp;
		// alsoo update head in this because tail==NULL means head and tail points to NULL
	}

	else{
	 Node*temp=new Node(d);
	
	  tail->Next=temp;
	  tail=temp;
   }
	
}

/*******TO inset at any postion **************************/

void at_any_pos(Node* &head,Node* &tail,int pos,int d){
	
	if(pos<=0){
		cout<<"NOT vaild postion"<<endl;
		return;
	}
	if(pos==1){
		athead(head,d);
		return;
	}
	
	int cnt=1;
	Node*temp=head;
	//(pos-2)!=0
	while(cnt<pos-1){
		
		temp=temp->Next;
		cnt++;
	}
	
	if(temp==NULL){
		
		cout<<"Not vaild postion"<<endl;
		return;
	}
	if(temp->Next==NULL){
		//attail(tail,d);
		Node*New_node=new Node(d);
		temp->Next=New_node;
		tail=New_node;
	}
	else{
		
		Node*New_node=new Node(d);
		
		New_node->Next=temp->Next;
		
		temp->Next=New_node;
		
		return;
	}
	
	
	
}
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

/*******TO Delete at any pos**************************/
void to_delete(int pos,Node*&head){
	
	if(pos<=0 || pos>len(head) ){
		cout<<" Not a vaild"<<endl;
		return;
	}
	if(pos==1){
		
		Node*curr=head;
		head=head->Next;
		curr->Next=NULL;
		delete curr;
		
		return;
	}
	
	Node*curr=head;
	Node*prev=NULL;
	 int cnt=1;
   	while(cnt!=pos){//cnt<pos && curr!=NULL if len not given
	 	prev=curr;
	   	curr=curr->Next;
		    cnt++;
	}
	
	prev->Next=curr->Next;
	curr->Next=NULL;
	delete curr;
	
}

/*******TO print**************************/
void print(Node* &head){
	
	Node*temp=head;
	
	while(temp!=NULL){
		
		cout<<temp->data<<" ";
		temp=temp->Next;
	}
	cout<<endl;
}
 
 /******************************************/
int main(){
 
   // Node*first=new Node(2);
   // Node*head=first;
   // print(head);
   
   // athead(head,1);
   // print(head);
   
  // Node*first=NULL;
   
   // athead(first,2);
   // print(first);
   
   // athead(first,3);
   // print(first);
   
   // Node*tail=first;
   
   
   // attail(tail,10);
   // // first=tail;
   // print(first);
   
   // athead(first,2);
   // print(first);
   
   Node*a=new Node(2);
   Node*head=a;
   Node*tail=a;
   athead(head,1);
   
   attail(tail,5);
    
   print(head);
  // cout<<len(head)<<endl;
   //cout<<tail->data;
   at_any_pos(head,tail, 4,30);
   print(head);
   
  // cout<<len(head)<<endl;
  // cout<<tail->data;
   to_delete(5,head);
   print(head);
    return 0;
}