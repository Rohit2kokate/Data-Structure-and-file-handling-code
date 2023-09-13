#include<iostream>
using namespace std;
struct node{
	int data,lth,rth;
	node *left,*right;	
};
class tbt{
	public:
		void inorder(node *);
		void insert(node *,node *);
		void preorder(node *);	
};
void tbt::insert(node *root,node *nw){
	int flag=0;
	node *temp=root;
	while(flag==0){
	if(temp->data<nw->data && temp->rth==1){
		nw->left=temp;
		nw->right=temp->right;
		temp->right=nw;
		temp->rth=0;
		flag=1;
	}
	else if(temp->data<nw->data&&temp->rth==0){
		temp=temp->right;
	}
	else if(temp->data>nw->data && temp->lth==1){
		nw->right=temp;
		nw->left=temp->left;
		temp->left=nw;
		temp->lth=0;
		flag=1;
	}
	else if(temp->data>nw->data&&temp->lth==1){
		temp=temp->left;
	}
}
}
void tbt::inorder(node *root){
	int flag=0;
	node *trav=root;
	while(trav!=NULL){
	 while(flag==0&&trav->lth==0){
		trav=trav->left;
	  }
	  cout<<trav->data;
	  if(trav->rth==0){
	  	flag=0;
	  	trav=trav->right;
	  }
	  else{
	  	flag=1;
	  	trav=trav->right;
	  }
	}
}
int main(){
	tbt t;
	int ch,c;
	node *root=NULL,*nw;
 do{
	cout<<"[1] insert \n[2] inorder";
	cin>>ch;
	switch(ch){
		case 1:
			nw=new node();
			cout<<"enter the data";
			cin>>nw->data;
			nw->left=nw->right=NULL;
			nw->lth=nw->rth=1;
			if(root==NULL){
				root=nw;
			}
			else{
				t.insert(root,nw);
			}
			break;
		case 2:
			cout<<"inorder trv is";
			t.inorder(root);
			break;
    }
    cout<<"do you want to continue";
    cin>>c;
  }while(c!=0);
}