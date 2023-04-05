#include <bits/stdc++.h>

#define endl  '\n'

#define fast ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define YES cout<<"YES"<<endl;
#define NO cout<<"NO"<<endl;

using namespace std;

class Node{
	
public:
	
	int data;
	Node* next;
	
 
 Node(int d){
 	
 	this->data=d;
 	this->next=NULL;
 }
	
	
};

void athead(Node* &head ,int d){  // insert at head
	
	Node*temp=new Node(d);
	temp->next=head;
	head=temp;
	
}

void attail(Node* &tail ,int d){  //insert at tail
	
	Node*temp=new Node(d);
	 tail->next=temp;
	 tail=temp;
}

void atpos(Node* &head ,Node* &tail,int pos,int d){   //insert at a given postion --> always check edge case like invaild postion ,,head ptr,tail update
	
	if(pos==0){
		
		cout<<"NOT Possible "<<endl;
		
		return;
	}
	
	if(pos==1){
		
		athead(head,d);
		  return;
	}
	else{
		
		Node*Prev=head;
		
		 Node*NewNode=new Node(d);
		
		  int t=pos-2;
		
		while(t--){
			
			Prev=Prev->next;	
		}
		
		if(Prev==NULL){
			cout<<"Not vaild Postion"<<endl;
			return;
		}
		
		if(Prev->next==NULL){
		//	attail(tail,d);
			Prev->next=NewNode;
			tail=NewNode;
			 return;
		}
	  else{
			NewNode->next=Prev->next;
	         Prev->next=NewNode;
		}
	    
	}
	
}

void print(Node* &head){
	
	Node*temp=head;
	
	while(temp!=NULL){ //temp->next!=NULL
		
		cout<<temp->data<<" ";
		
		temp=temp->next; // TempNode -->data ,next means next pe new node hogi ---TempNode-->Next
	}
}

int main()
{
	
	
	
   //dyanmic memory 
   
  Node*first=new Node(3); // tail 
  Node*head=first;
  Node*tail=first;
   athead(head,7);
   athead(head,6);
   athead(head,5);
   athead(head,1);  //head  
   
   attail(tail,8);
   
   attail(tail,10);
   
    print(head);
    
    cout<<endl;
    
    atpos(head,tail,8,20);
    
    print(head);
    
    cout<<endl;
    
    cout<<head->data<<" and tail "<<tail->data<<endl;
    
   atpos(head,tail,10,30);// as only n+1 tk insert -->here n=8 -->upto 9 ,not 10 
    
    print(head);
    
     cout<<endl;
     
     cout<<head->data<<" and tail "<<tail->data<<endl;
     
     attail(tail,40);
     
      print(head);
      
      cout<<endl;
      
      cout<<head->data<<" and tail "<<tail->data<<endl;
      
      atpos(head,tail,1,0);
      
      print(head);
      
      cout<<endl;
      
      cout<<head->data<<" and tail "<<tail->data<<endl;
      
   /*
   
   
    // object  creation m constructor call 
	
	Node first(5);
	cout<<first.data;
	
    */    
    
    return 0;
}
