#include<iostream>
using namespace std;
int key[30],c[30],n ,m;
int i;
class student
{
    public:
    int prn,rno;
    string name,ad;
    float p;
    void declare();
    void htable();
    void accept();
}h[100];
void student :: declare()
{   
    cout<<"Enter total number of key : ";
    cin>>n;
    cout<<"Enter the Keys :  ";
    for(i=0;i<n;i++)
    {
        cin>>key[i];
    }
    for(i=0;i<10;i++)
    {
        h[i].prn=-1;
        c[i]=0;
    }
}
void student :: htable()
{
    cout<<"                 STUDENT MANAGEMENT SYSTEM";
    cout<<"\nPRN\tRNO\tNAME\tADDRESS\tPERCENTAGE\tCHAIN";
    for(i=0;i<10;i++)
    {
   cout<<"\n"<<h[i].prn<<"\t"<<h[i].rno<<"\t"<<h[i].name<<"\t"<<h[i].ad<<"\t"<<h[i].p<<"\t\t"<<c[i];
    }
}
void student :: accept()
{
    int no,pos;
    for(i=0;i<n;i++)
    {
        no=key[i]%10;
        pos=no;
        do{
            if(h[no].prn==-1)
            {
                h[no].prn=key[i];
                cout<<"Roll no : ";
                cin>>h[no].rno;
                cout<<"Name : ";
                cin>>h[no].name;
                cout<<"Address : ";
                cin>>h[no].ad;
                cout<<"Percentage : ";
                cin>>h[no].p;
                break;
            }
            else 
            {
                no++;
                c[pos]=no;
                if(no>n)
                {
                    no=0;
                }
            }
        }while(no<10);
    }

}
int main()
{
    int ch;
    student s;
     
    do
    {
        cout<<"\n              STUDENT MANAGEMENT SYSTEM !!!";
        cout<<"\n1.Declare\n2.ADD RECORD\n3.DISPLAY RECORD\n4.Exit";

        cout<<"\nEnter your choice : ";
        cin>>ch;
        switch(ch)
        {
         
            case 1:
            s.declare();
            break;
            case 2:
            s.accept();
            break;
            case 3:
            s.htable();
            break;
            case 4:
            cout<<".....Thanks for Coming......!!";
            break;
            default:
            cout<<"Wrong choice";
        }
    } while (ch!=4);
    return 0;
}