#include<iostream>
using namespace std;
int i,j;
class al
{
    public:
    string name;
    int fuel;
    al *next;
    int v,e;
    void create();
    void edge();
    void display();

}*start[10];
void al :: create()
{
cout<<"No of vertices : ";
cin>>v;
cout<<"Enter the name of cities : ";
for(i=0;i<v;i++)
{
    start[i]=new al;
    cin>>start[i]->name;
    start[i]->next=NULL;
}
}
void al :: display()
{
    al *n;
    n=new al;
    for(i=0;i<v;i++)
    {
      cout<<"\nSource: "<<start[i]->name;
      n=start[i]->next;
      while(n!=NULL)
      {
        cout<<"\nDest : "<<n->name;
        cout<<"\nFuel Reuired : "<<n->fuel;
        n=n->next;
      }
    }
}
void al :: edge()
{
string s,d;
al *n1,*temp;
cout<<"How many edges : ";
cin>>e;
for(i=0;i<e;i++)
{
cout<<"Enter source : ";
cin>>s;
cout<<"Enter Dest : ";
cin>>d;
for(j=0;j<v;j++)
{
    if(s==start[j]->name)
    break;
}


n1=new al;
n1->name=d;
cout<<"\nEnter fuel required : ";
cin>>n1->fuel;
n1->next-NULL;
temp=start[j];
while(temp->next!=NULL)
{
    temp=temp->next;
}
temp->next=n1;
}
}

int main()
{
    int ch;
    al a;
    do
    {
        cout<<"\n1.Create\n2.Edge\n3.display\n4.exit";
        cout<<"\nEnter your choice : ";
        cin>>ch;
        switch(ch)
        {
            case 1 :
            a.create();
            break;
            case 2:
            a.edge();
            break;
            case 3:
            a.display();
            break;
            case 4 :
            cout<<"Exit";
            break;
            default :
            cout<<"Enter correct choice ";
        }

    } while (ch!=4);
    return 0;
}