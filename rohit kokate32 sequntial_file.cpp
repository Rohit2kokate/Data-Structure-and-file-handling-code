#include<iostream>
#include<fstream>
using namespace std;

struct student
{
	int rollno;
	char name[50];
	float per;
}s;

int main()
{
	int ch,c,rno,flag,a;
	ofstream outf,outf1; 
	outf.open("Rohit.txt");
	ifstream inf;
	do
	{
	cout<<"\n1.ADD RECORD\n2.DISPLAY\n3.DELETE RECORD\n4.MODIFY RECORD\n";
	cout<<"\nEnter your choice:";
	cin>>ch;
	switch(ch)
	{

		case 1: 
					do{
					cout<<"\n";
					cout<<"\nEnter the RollNo,Name,and Percentage:";
					cin>>s.rollno>>s.name>>s.per;
					outf<<"\t"<<s.rollno;
					outf<<"\t"<<s.name;
					outf<<"\t"<<s.per;
					cout<<"[1/0]";
					cin>>a;
					}while(a!=0);
				cout<<"\nRecord added sucessfully:";
				outf.close();
				break;
		
		case 2:
				inf.open("Rohit.txt");
				while(!inf.eof())
				{
					inf>>s.rollno;
					inf>>s.name;
					inf>>s.per;
					cout<<"\nRoll NO is:"<<s.rollno;
					cout<<"\nName: is:"<<s.name;
					cout<<"\nPercentage is:"<<s.per;
				}
				inf.close();
				break;
		
		case 3:
			inf.open("Rohit.txt");
			outf1.open("Kokate.txt");
			cout<<"\nEnter the roll no which you want to delete:";
			cin>>rno;
			flag=0;
			while(!inf.eof())
			{
				inf>>s.rollno;
				inf>>s.name;
				inf>>s.per;
				if(rno==s.rollno)
				{
					flag=1;
					cout<<"\nRecord deleted:";
				}
				else if(rno!=s.rollno)
				{
					 outf1<<"\t"<<s.rollno;
					 outf1<<"\t"<<s.name;
					 outf1<<"\t"<<s.per;		
				}
			}
			if(flag==0)
			{
				cout<<"Record is not present";
			}
			remove("Rohit.txt");
			rename("Kokate.txt","Rohit.txt");
			inf.close();
			outf1.close();		
			break;
         case 4:	
			outf1.open("kokate.txt");
			inf.open("Rohit.txt");
			cout<<"\nEnter the roll no which you want to modify:";
			cin>>rno;
			flag=0;
			while(!inf.eof())
			{
				inf>>s.rollno;
				inf>>s.name;
				inf>>s.per;
				if(rno!=s.rollno)
				{
					cout<<"\nEnter the RollNo,Name,and Percentage:";
					cin>>s.rollno>>s.name>>s.per;
					outf1<<"\t"<<s.rollno;
					outf1<<"\t"<<s.name;
					outf1<<"\t"<<s.per;		
					flag=1;
				}
				else if(rno==s.rollno)
				{
					outf1<<"\t"<<s.rollno;
					outf1<<"\t"<<s.name;
					outf1<<"\t"<<s.per;
				}
			}
			inf.close();
			outf1.close();	
			if(flag==0)
			{
				cout<<"Record is not present";
			}
			remove("Rohit.txt");
			rename("Kokate.txt","Rohit.txt");
			break;
	}
	cout<<"\ndo you want to continue:";
	cin>>c;
	}while(c==1);
	return 0;
}
