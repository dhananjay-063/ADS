#include<iostream>
using namespace std;
int i;
class book
{
    public:
    int bid,prize;
    string title,author,pub,isbn;
    book *next;
    void accept();
    void display();
    void beg();
    void search();
    void update();
    void end();
    void par();
    void fdelete();
    void ldelete();
    void pdelete();


} *start=NULL,e;

void book::accept()
{
    book *temp,*newptr;
    temp=new book;
    newptr=new book;
    cout<<"Enter book Id : ";
    cin>>temp->bid;
    cout<<"Enter book title : ";
    cin>>temp->title;
    cout<<"Enter book author : ";
    cin>>temp->author;
    cout<<"Enter book publishier : ";
    cin>>temp->pub;
    cout<<"Enter book isbn : ";
    cin>>temp->isbn;
    cout<<"Enter book prize : ";
    cin>>temp->prize;
    temp->next=NULL;
   if(start==NULL)
    {
        start=temp;
    }
    else
    {
        newptr=start;
    
    while(newptr->next!=NULL)
    {
        newptr=newptr->next;
    }
    newptr->next=temp;
    }

    
    
};
void book::display()
{
    book *temp;
    
    temp=start;
    while(temp!=NULL)
    {
        cout<<"\n"<<temp->bid<<"\t"<<temp->title<<"\t"<<temp->author<<"\t"<<temp->pub<<"\t\t"<<temp->isbn<<"\t"<<temp->prize;
        temp=temp->next;
        
    }
};

void book::beg()
{
    book *temp,*p;
    p=new book;
    temp=new book;
    
    cout<<"Enter the book id : ";
    cin>>p->bid;
    cout<<"Enter book title : ";
    cin>>p->title;
    cout<<"Enter book author : ";
    cin>>p->author;
    cout<<"Enter book publishier : ";
    cin>>p->pub;
    cout<<"Enter book isbn : ";
    cin>>p->isbn;
    cout<<"Enter book prize : ";
    cin>>p->prize;
    p->next=NULL;
    if(start==NULL)
    {
        start=p;
    }
    else
    {
        temp = start;
        start = p;
        p->next = temp;
    }
    

};
void book::search()
{
      book *temp;
      temp=start;
      int s,flag=0,position=0;
      cout<<"Enter Id : ";
      cin>>s;
      while(temp!=NULL)
      {
             
          if(temp->bid==s)
          {
             
               flag=1;
               cout<<"Element found  ";
               cout<<"\n"<<"ID\tTITLE\tAUTHOR\tPUBLISHIER\tISBN\tPRIZE";
               cout<<"\n"<<temp->bid<<"\t"<<temp->title<<"\t"<<temp->author<<"\t"<<temp->pub<<"\t\t"<<temp->isbn<<"\t"<<temp->prize;
               break;
          }
          temp=temp->next;
          
          
        
      }
      
      if(flag==0)
      {
        cout<<"Element not found";
      }
};
void book::update() {
    book *temp;
    temp = start;
    int s, flag = 0;
    cout << "Enter Id : ";
    cin >> s;

    while (temp != NULL) {
        if (temp->bid == s) {
            flag = 1;
            cout << "Element found\n";
            
            cout<<"Enter book Id : ";
            cin>>temp->bid;
            cout << "Enter new book title : ";
            cin >> temp->title;
            cout << "Enter new book author : ";
            cin >> temp->author;
            cout << "Enter new book publisher : ";
            cin >> temp->pub;
            cout << "Enter new book isbn : ";
            cin >> temp->isbn;
            cout << "Enter new book prize : ";
            cin >> temp->prize;

            break;
        }
        
        temp = temp->next;
    }

    if (flag == 0) {
        cout << "Element not found\n";
    }
}

void book::end()
{
    book *newptr,*temp;
    newptr=new book;
    cout<<"Enter book Id : ";
    cin>>newptr->bid;
    cout<<"Enter book title : ";
    cin>>newptr->title;
    cout<<"Enter book author : ";
    cin>>newptr->author;
    cout<<"Enter book publishier : ";
    cin>>newptr->pub;
    cout<<"Enter book isbn : ";
    cin>>newptr->isbn;
    cout<<"Enter book prize : ";
    cin>>newptr->prize;
    newptr->next=NULL;
    if(start==NULL)
    {
        start=newptr;
    }
    else
    {
        temp=start;
    
    while(temp->next!=NULL)
    {
        temp=temp->next;
    }
    temp->next=newptr;
    }
};
void book::par()
{
    book *newptr, *temp;
    newptr = new book;

    cout << "Enter book Id : ";
    cin >> newptr->bid;
    cout << "Enter book title : ";
    cin >> newptr->title;
    cout << "Enter book author : ";
    cin >> newptr->author;
    cout << "Enter book publisher : ";
    cin >> newptr->pub;
    cout << "Enter book isbn : ";
    cin >> newptr->isbn;
    cout << "Enter book prize : ";
    cin >> newptr->prize;

    newptr->next = nullptr;  

    cout << "Enter the position : ";
    int pos;
    cin >> pos;

    temp = start;  

    for (int i = 0; i < pos - 1 && temp != nullptr; i++)  
    {
        temp = temp->next;
    }

    if (temp != nullptr)
    {
        newptr->next = temp->next;
        temp->next = newptr;
    }
    else
    {
        cout << "Invalid position." << endl;
    }
};

void book::fdelete()
{
    book *temp;
    temp=start;
    start=start->next;
    delete(temp);
    cout<<"\nFirst Element Deleted Successfully";
};
void book::ldelete()
{
    book *temp,*p;
    temp=start;
    if(temp->next==NULL)
    {
        delete(temp);
    }
    else
    {
        while(temp->next->next!=NULL)
        {
            temp=temp->next;
        }
        p=temp->next;
        delete(p);
        temp->next=NULL;
    }
    cout<<"\nLast Element Deleted Successfully";
};
void book::pdelete()
{
    book *temp, *p;
    temp = start;

    int x;
    cout << "\nEnter the node which you want to delete : ";
    cin >> x;


    if (temp != nullptr && temp->bid == x)
    {
        start = temp->next;
        delete temp;
        cout << "Data found and deleted." << endl;
        return;
    }

    
    p = temp;
    while (temp != nullptr)
    {
        if (temp->bid == x)
        {
            p->next = temp->next;
            delete temp;
            cout << "Data found and deleted." << endl;
            return;
        }
        p = temp;
        temp = temp->next;
    }

    cout << "Data not found." << endl;
};


int main()
{
    
    int ch,n,i;
    
    do
    {
        cout<<"\nMENU";
        cout<<"\n1.Insert\n2.Display\n3.Insert at Beginning\n4.Insert at End\n5.Insert at Any position\n6.Search the Record\n7.Update the record\n8.Delete the first Node\n9.Delete the last Node\n10.Delete the Any Node\n11.Exit";
        cout<<"\nEnter Your Choice : ";
        cin>>ch;
        switch(ch)
        {
            case 1:
            
                e.accept();
            
            break;
            case 2:
               cout<<"\n"<<"ID\tTITLE\tAUTHOR\tPUBLISHIER\tISBN\tPRIZE";
                e.display();
            
            break;
            case 3:
                e.beg();
               break;
            case 4:
                e.end();
            break;
            case 5:
                e.par();
              break;
            case 6:
                e.search();
                break;
            case 7:
                e.update();
                break;
            case 8:
                e.fdelete();
                break;
            case 9:
                e.ldelete();
                break;
            case 10:
                e.pdelete();
                break;
            case 11:
                cout<<"Thanks for coming";
                break;
            default:
            cout<<"Invalid Choice ";


        }
    } while (ch!=11);
    return 0;
}
