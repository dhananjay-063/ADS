#include<iostream>
#include<string.h>
using namespace std;
class fmt
{
    public:
    int age,c=0;
    string name,dd,bd,bg,gender,gen;
    fmt *lchild,*rchild;
    void accept();
    void display(fmt *root);
    void inorder(fmt *root);
    void postorder(fmt *root);
    void search(fmt *root);

    void ht();
    void insert(fmt *root,fmt *next);
    void cal();
} *root;  
void fmt::search(fmt *root)
{
string n;
int r;
cout<<"Enter the name for search : ";
cin>>n;
while(root->name != n) {
         //go to left tree
         if(root->name > n) {
            root = root->lchild;
         }//else go to right tree
         else {
            root= root->rchild;
         }
         
         //not found
         if(root == NULL) {
            cout<<"null";
         }
}
cout<<"\nNAME\tAGE\tBIRTHDATE\tDEATHDATE\tBLOODGROUP\tGENRATION\tGENDER";
cout<<"\n"<<root->name<<"\t"<<root->age<<"\t"<<root->bd<<"\t"<<root->dd<<"\t\t"<<root->bg<<"\t\t"<<root->gen<<"\t\t"<<root->gender;
}

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
        cout << "u want to add more family members if yes then press 1 otherwise press 21 : " << endl;
        cin >> ch;
        if (ch == 1)
        {
            next = new fmt();
            cout << "enter the following family information :" << endl;
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
    
            next->lchild = NULL;
            next->rchild = NULL;
            insert(root, next);
        }
    } while (ch == 1);
}
void fmt::insert(fmt *root,fmt *next)
{
    int ch;
   string chr;
    cout << "where u want to inserted data either left or right of "<< "'" << root->name << "'" << " L or R : " << endl;
    cin >> chr;
    if (chr == "l" || chr == "L")
    {
        if (root->lchild == NULL)
        {
            c++;
            root->lchild = next;
  cout<<"Inserted successfully";
        }
        else
        {
            insert(root->lchild, next);
        }
    }
    if (chr == "r" || chr == "R")
    {
        if (root->rchild == NULL)
        {
            c++;
            root->rchild = next;
            cout<<"Inserted successfully";
        }
        else
        {
            insert(root->rchild, next);
        }
    }
}
void fmt::display(fmt *root)
{
    if(root==NULL)
{
    return;
}
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
void fmt::inorder(fmt *root)
{

    if(root==NULL)
    return;
    else
    {
        inorder(root->lchild);
        cout<<"\n"<<root->name<<"\t"<<root->age<<"\t"<<root->bd<<"\t"<<root->dd<<"\t\t"<<root->bg<<"\t\t"<<root->gen<<"\t\t"<<root->gender;
        inorder(root->rchild);
    }
}
void fmt::postorder(fmt *root)
{

    if(root==NULL)
    return;
    else
    {
        postorder(root->lchild);
        postorder(root->rchild);
        cout<<"\n"<<root->name<<"\t"<<root->age<<"\t"<<root->bd<<"\t"<<root->dd<<"\t\t"<<root->bg<<"\t\t"<<root->gen<<"\t\t"<<root->gender;
      
    }
}

int main()
{
    fmt f;
    int ch;
    do
    {
        cout<<"\nWELCOME TO FAMILY TREE ";
        cout<<"\n1.Add the family member\n2.display the family member by preorder\n3.display the family member by inorder\n4.display the family member by postorder\n5.Calculate total record\n6.find\n7.exit ";
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
            cout<<"\nNAME\tAGE\tBIRTHDATE\tDEATHDATE\tBLOODGROUP\tGENRATION\tGENDER";
            f.inorder(root);
            break;
            case 4:
            cout<<"\nNAME\tAGE\tBIRTHDATE\tDEATHDATE\tBLOODGROUP\tGENRATION\tGENDER";
            f.postorder(root);
            break;
            case 5:
            f.cal();
            break;
            case 6:
            f.search(root);
            break;
            case 7:
            cout<<"Thanks for visiting...!!!";
            break;
            default:
            cout<<"Wrong choice";

        }
    } while (ch!=7);
    
}
