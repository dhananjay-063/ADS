#include<iostream>
using namespace std;
int i,j;
class  am
{
    public:
    int fuel;
    int v,e;
    string city[30];
    int a[30][30];
    void create();
    void display();
}a;
void am :: create()
{
    cout<<"Enter the number of city : ";
    cin>>v;
    cout<<"Enter name of city : ";
    for(i=0;i<v;i++)
    {
        cin>>city[i];
    }
    cout<<"Enter the fuel : ";
    for(i=0;i<v;i++)
    {
        for(j=0;j<v;j++)
        {
             if(i==j)
             {
                a[i][j]=0;
             }
             else
             {
                cout<<"\n source city "<<city[i]<<" To "<<city[j];
                cout<<"\nEnter the fuel : ";
                cin>>fuel;
                a[i][j]=fuel;
                a[j][i]=a[i][j];
             }
        }
    }

}
void am :: display()
{
    cout<<"ADJ MATRIX IS"<<endl;
     for(i=0;i<v;i++)
    {
        for(j=0;j<v;j++)
        {
            cout<<"\t"<<a[i][j];
        }
        cout<<"\n";
    }

}
int main()
{
    int ch;
    do
    {
        cout<<"\n1.Create\n2.display\n3.exit";
        cout<<"\nEnter your choice : ";
        cin>>ch;
        switch(ch)
        {
            case 1 :
            a.create();
            break;
            case 2:
            a.display();
            break;
            case 3:
            cout<<"Exit";
            break;
            default :
            cout<<"Enter correct choice ";
        }

    } while (ch!=3);
    return 0;
}