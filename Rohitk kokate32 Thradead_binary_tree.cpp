#include<iostream>
using namespace std;
struct node
{
		int data,rth,lth;
 		struct node *left,*right;
};
class TBT
{
public:
	void insert(node*,node*);
	void inorder(node*);
	void preorder(node*);
	void postorder(node*);
};
  
void TBT::insert(struct node *root,struct node *nn)
{
	int flag=0;
	do
	{
    	if(root->data<nn->data&&root->rth==1)
    	{
     		 nn->left=root;
     		 nn->right=root->right;
     		 root->right=nn;
     		 root->rth=0;
     		 flag=1;
   		 }
    	else if(root->data<nn->data&&root->rth==0)
    		root=root->right;
   		else if(root->data>nn->data&&root->lth==1)
   		 {
    		 nn->right=root;
   			 nn->left=root->left;
   			 root->left=nn;
  			 root->lth=0;
   			 flag=1;
   		 }
   		 else if(root->data>nn->data&&root->lth==0)
   		 root=root->left;
	}while(flag==0);
}

void TBT::inorder(struct node *root)
{
	int flag=0;
	struct node *trav=root;
	while(trav!=NULL)
	{
   		 while(trav->lth==0&&flag==0)
   			 trav=trav->left;
   			 cout<<trav->data<<"  ";
  	    	if(trav->rth==0)
    		{
    			trav=trav->right;
   				 flag=0;
   			 }
    		else
    		{
   				 trav=trav->right;
    			 flag=1;
    		}
	}
}
void TBT::preorder(struct node *root)
{
	int flag=0;
	struct node *trav=root;
	while(trav!=NULL)
	{
  	  while(trav->lth==0&&flag==0)
  	  {
        cout<<trav->data<<"  ";
        trav=trav->left;
   	  }
   		 if(trav->lth==1)
    	cout<<trav->data<<"  ";
     	if(trav->rth==0)
    	flag=0;
    	else
    	flag=1;
    	trav=trav->right;
	}
}
int main()
{
	struct node *root=NULL,*nn;
	TBT T;
	int key,choice;
	do
	{
		cout<<"\n1.Insert Data\n2.Inorder\n3.Preorder\n4.Exit\n";
		cout<<"\n Enter your choice:";
		cin>>choice;
		switch(choice)
		{
    		case 1:
     		   cout<<"\nEnter key:";
     		   cin>>key;
     		   nn=new struct node;
     		   nn->data=key;
      		   nn->left=nn->right=NULL;
     		   nn->lth=nn->rth=1;
     		   if(root==NULL)
    		    root=nn;
       		   else
       			T.insert(root,nn);
        		break;
   			case 2:
       			cout<<"\nInorder is:";
       			T.inorder(root);
       			 break;
    		case 3:
       			 cout<<"\nPreorder is:";
       			 T.preorder(root);
       			 break;
    		case 4:
    	    break;
   			 default:
       			 cout<<"\n Wrong choice entered:";
       			 break;
 		}
	}while(choice!=4);
return 0;
}
