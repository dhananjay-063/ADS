#include<iostream>
using namespace std;
class cms
{
public:
int id;
string name, address;
cms *next,*prev;
long long mob,amt;
void accept();
void display();
void search();
void update();
void del();
void ldel();
void fdel();

}*start=NULL,*end1;
void cms::accept()
{
cms *temp;
temp=new cms;
cout<<"Enter the donar id =";
cin>>temp->id;
cout<<"Enter the donar name =";
cin>>temp->name;
cout<<"Enter the donar address =";
cin>>temp->address;
cout<<"Enter the donor mob =";
cin>>temp->mob;
cout<<"Enter the amount : ";
cin>>temp->amt;
temp->next=temp->prev=NULL;

if(start==NULL)
{
    end1=start=temp;
}
else
{
  end1->next=temp;
  temp->prev=end1;
  end1=temp;
}


};

void cms::display()
{
cms *temp;
int c=0;
temp=start;
while(temp!=NULL)
{
cout<<"\n"<<temp->id<<"\t\t"<<temp->name<<"\t\t"<<temp->address<<"\t\t"<<temp->mob<<"\t\t"<<temp->amt;
temp=temp->next;
c++;
}

cout<<"\nTotal no of books :"<<c;
};
void cms::search()
{
 cms *temp;
temp=start;
int n,f=0;
cout<<"Enter the id for search : ";
cin>>n;
while(temp!=NULL)
{

  if(temp->id==n)
{
 f=1;
cout<<"Record found ";
cout<<"\nDonarid\t\tName\t\tAddress\t\tMobno\t\t\tAmount";
cout<<"\n"<<temp->id<<"\t\t"<<temp->name<<"\t\t"<<temp->address<<"\t\t"<<temp->mob<<"\t\t"<<temp->amt;

 break;
}
temp=temp->next;
}
if(f==0)
{
 cout<<"Record not found : ";
}
};
void cms :: update()// Update the record
{
cms *temp;
temp=start;
int n,f=0;
cout<<"Enter the id for update : ";
cin>>n;
if(temp==NULL)
{
 cout<<"Records is empty ";
}
else
{
while(temp!=NULL)
{
  if(temp->id==n)
{
 f=1;
cout<<"Record found ";
cout<<"Enter the donar name =";
cin>>temp->name;
cout<<"Enter the donar address =";
cin>>temp->address;
cout<<"Enter the book mobile =";
cin>>temp->mob;
cout<<"Enter the book amount = ";
cin>>temp->amt;
break;
 
}
temp=temp->next;
}
}
if(f==0)
{
 cout<<"Record not found : ";
}
};
void cms::ldel()
{
   
    cms *temp,*p;
    temp=start;
    
  if(temp->next==NULL)
    {
      
        delete(temp);
    }
    else
    {
      f=1;
        while(temp->next->next!=NULL)
        {
            temp=temp->next;
        }
        p=temp->next;
        delete(p);
        temp->next=NULL;
    }
    cout<<"\nLast Element Deleted Successfully";
   
  
}
void cms::fdel()
{
  cms *temp,*p;
temp=start;

if(temp!=NULL && temp->id==n)
{
    
    start=start->next;
    delete(temp);
    cout<<"\nFirst Element Deleted Successfully";
    return;
}

}
void cms::del()// Search the record
{
 cms *temp,*p;
temp=start;
int n,f=0;
cout<<"Enter the id for delete : ";
cin>>n;
while(temp!=NULL)
{
  if(temp->id==n)
{
 p->next=temp->next;
temp->next->prev=p->next;
delete(temp);
 f=1;
cout<<"Record found and Deleted successfully";

 break;
}
p=temp;
temp=temp->next;
}



if(f==0)
{
 cout<<"Record not found : ";
}
};
int main()
{
cms m;

int ch, i;
do
{
cout<<"\nWELCOME TO CMS ! ";
cout<<"\n1.Accept the  record\n2.Display the b record\n3.search the  record\n4.Update   record\n5.delete 1st  the record\n6.delete last record\n7.delete any record\n8.exit";
cout<<"\nENTER YOUR CHOICE = : ";
cin>>ch;
switch(ch)
{
case 1:
m.accept();
break;
case 2:
cout<<"\nDonarid\t\tName\t\tAddress\t\tMobno\t\t\tAmount";
m.display();
break;
case 3:
 m.search();
break;
case 4:
 m.update();
break;
case 5:
 m.fdel();
break;
case 6:
m.ldel();
break;
case 7:
m.del();
break;
case 8:
 cout<<"Thanks for visiting...!!!"<<endl;
break;
default:
cout<<"Wrong choice";
}
}while(ch!=8);
return 0;
}




