#include<iostream>
using namespace std;
class fmt
{
    public:
    int age,c=0;
    string name,dd,bd,bg,gender,gen;
    fmt *lchild,*rchild;
    void accept();
    void display(fmt *root);
    void search();
    void ht();
    void insert(fmt *root,fmt *next);
    void cal();
} *root;
void fmt::accept()
{
    fmt *next;
    root=new fmt;
    next=new fmt;
    int ch;
    cout<<"Enter the name: ";
    cin>>root->name;
    cout<<"Enter age : ";
    cin>>root->age;
    cout<<"Enter birthdate : ";
    cin>>root->bd;
    cout<<"Enter death date : ";
    cin>>root->dd;
    cout<<"Enter blood group: ";
    cin>>root->bg;
    cout<<"Enter generation : ";
    cin>>root->gen;
    cout<<"Enter gender : ";
    cin>>root->gender;
    root->lchild=root->rchild=NULL;
    c++;
    do
    {
        cout<<"\nDo you want to add new family member information : ";
        cout<<"\n1.Yes\n2.No";
        cout<<"\nEnter your choice : ";
        cin>>ch;
        switch(ch)
        {
            case 1:
             
             cout<<"Enter the name: ";
             cin>>next->name;
             cout<<"Enter age : ";
             cin>>next->age;
             cout<<"Enter birthdate : ";
             cin>>next->bd;
             cout<<"Enter death date : ";
             cin>>next->dd;
             cout<<"Enter blood group: ";
             cin>>next->bg;
             cout<<"Enter generation : ";
             cin>>next->gen;
             cout<<"Enter gender : ";
             cin>>next->gender;
             next->lchild=next->rchild=NULL;
             insert(root,next);
             break;
             case 2:
             cout<<"Exit";
             break;
             default:
             cout<<"wrong choice";
             }
    } while (ch!=2);
    
}
void fmt::insert(fmt *root,fmt *next)
{
    int ch;
    do
    {
       cout<<"\nWhere you want to add new family member info : ";
       cout<<"\n1.Left side\n2.Right side\n3.exit ";
       cout<<"\nEnter your choice : ";
       cin>>ch;
       switch(ch)
       {
        case 1:
        if(root->lchild==NULL)
        {
            root->lchild=next;
            cout<<"Record added at left side";
            c++;
        }
        else
        {
            insert(root->lchild,next);
        }
        break;
        case 2:
        if(root->rchild==NULL)
        {
            root->rchild=next;
             cout<<"Record added at right side";
            c++;
        }
        else
        {
            insert(root->rchild,next);
        }
        break;
        case 3:
        cout<<"Exit";
        break;
        default:
        cout<<"Wrong choice";
       }

    } while (ch!=3);
}
void fmt::display(fmt *root)
{
    if(root==NULL)
    return;
    else
    {
        cout<<"\n"<<root->name<<"\t"<<root->age<<"\t"<<root->bd<<"\t"<<root->dd<<"\t\t"<<root->bg<<"\t\t"<<root->gen<<"\t\t"<<root->gender;
        display(root->lchild);
        display(root->rchild);
    }
    
}
void fmt::cal()
{
    cout<<"The total number of record : "<<c;
}
int main()
{
    fmt f;
    int ch;
    do
    {
        cout<<"\nWELCOME TO FAMILY TREE ";
        cout<<"\n1.Add the family member\n2.display the family member\n3.Calculate total record\n4.exit ";
        cout<<"\nEnter your choice : ";
        cin>>ch;
        switch(ch)
        {
            case 1:
            f.accept();
            break;
            case 2:
            cout<<"\nNAME\tAGE\tBIRTHDATE\tDEATHDATE\tBLOODGROUP\tGENRATION\tGENDER";
            f.display(root);
            
            break;
            case 3:
            f.cal();
            break;
            case 4:
            cout<<"Thanks for visiting...!!!";
            break;
            default:
            cout<<"Wrong choice";

        }
    } while (ch!=4);
    
}
