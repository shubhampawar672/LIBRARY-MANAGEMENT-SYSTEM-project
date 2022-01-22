//LIBRARY MANAGEMENT SYSTEM
//Shubham Pawar , 20141236 ,SY ,IT, GCEK.
//Industrial Training Project(2022)
#include<iostream>
#include<string.h>
#include<conio.h>
using namespace std;
class library
{
private:
    struct node
    {
        int book_id;
        string book_name,authour_name;
        node *next;
    };
public:
    node *head=NULL;
    void menu();
    void Insert();
    void Search();
    void update();
    void Delete();
    void show();
    void issue();
    void returnb();
};

void library:: menu()
{   p:
     system("cls");
    cout<<"\t*********************************************************\n";
    cout<<"\t\t\tLIBRARY MANAGEMENT SYSTEM \n";
    cout<<"\t*********************************************************\n\n";
     int ch;
        cout<<"\t\t******MAIN MENU******\n\n";
        cout<<"\t 1.Insert new record \n";
        cout<<"\t 2.Search record \n";
        cout<<"\t 3.Update record \n";
        cout<<"\t 4.Delete record \n";
        cout<<"\t 5.Show all records\n";
        cout<<"\t 6.Issue book\n";
        cout<<"\t 7.Return book\n";
        cout<<"\t 8.Exit \n";
        cout<<"\t Enter your choice \n\t";
        cin>>ch;
          switch(ch)
          {
          case 1:
               Insert();
            break;
            case 2:
                Search();
            break;
            case 3:
                update();
            break;
            case 4:
                Delete();
            break;
            case 5:
                show();
            break;
            case 6:
                issue();
                break;
            case 7:
                returnb();
                break;
            case 8:
                 exit(0);
            break;
                default:
                cout<<"\n\t Enter proper choice(1-4) \n";
          }
          getch();
          goto p;


}
void library ::Insert()
{   system("cls");
    cout<<"\t*********************************************************\n";
    cout<<"\t\t\tLIBRARY MANAGEMENT SYSTEM \n";
    cout<<"\t*********************************************************\n\n";
    node *newnode=new node;
    cout<<"\n\tBook ID:";
    cin>>newnode->book_id;
    cout<<"\n\tBook Name:";
    cin>>newnode->book_name;
    cout<<"\n\tBook Author Name:";
    cin>>newnode->authour_name;
    newnode->next=NULL;
    if(head==NULL)
    {
        head=newnode;
    }
    else
    {
        node *temp=head;
        while(temp->next!=NULL)
        {
            temp=temp->next;
        }
        temp->next=newnode;
    }
    cout<<"\n\t\tBook inserted successfully\n";
}
void library::Search()
{    system("cls");
    int test_id,found=0;
    cout<<"\t*********************************************************\n";
    cout<<"\t\t\tLIBRARY MANAGEMENT SYSTEM \n";
    cout<<"\t*********************************************************\n\n";
    if(head==NULL)
    {
        cout<<"\n\tList is Empty";
    }
    else
    {
        cout<<"\n\tEnter book id :";
        cin>>test_id;
        node *temp1=head;
        while(temp1!=NULL)
        {
            if(test_id==temp1->book_id)
            {     system("cls");

                cout<<"\t*********************************************************\n";
                cout<<"\t\t\tLIBRARY MANAGEMENT SYSTEM \n";
                cout<<"\t*********************************************************\n\n";
                cout<<"\n\tBook ID :"<<temp1->book_id;
                cout<<"\n\tBook Name :"<<temp1->book_name;
                cout<<"\n\tAuthor Name :"<<temp1->authour_name;
                found++;
            }
            temp1=temp1->next;
        }
        if(found==0)
        {
            cout<<"\n\tBook record not found";
        }
    }
}
void library::update()
{
     system("cls");
    int test_id,found=0;
    cout<<"\t*********************************************************\n";
    cout<<"\t\t\tLIBRARY MANAGEMENT SYSTEM \n";
    cout<<"\t*********************************************************\n\n";
    if(head==NULL)
    {
        cout<<"\n\tList is Empty";
    }
    else
    {
        cout<<"\n\tEnter book id :";
        cin>>test_id;
        node *temp1=head;
        while(temp1!=NULL)
        {
            if(test_id==temp1->book_id)
            {     system("cls");

                cout<<"\t*********************************************************\n";
                cout<<"\t\t\tLIBRARY MANAGEMENT SYSTEM \n";
                cout<<"\t*********************************************************\n\n";
                cout<<"\n\tBook ID :";
                cin>>temp1->book_id;
                cout<<"\n\tBook Name :";
                cin>>temp1->book_name;
                cout<<"\n\tAuthor Name :";
                cin>>temp1->authour_name;
                found++;
                cout<<"\n\tBook record updated successfully....";
            }
            temp1=temp1->next;
        }
        if(found==0)
        {
            cout<<"\n\tBook record not found";
        }
    }
}
void library::Delete()
{
     system("cls");
    int test_id,found=0;

    cout<<"\t*********************************************************\n";
    cout<<"\t\t\tLIBRARY MANAGEMENT SYSTEM \n";
    cout<<"\t*********************************************************\n\n";
    if(head==NULL)
    {
        cout<<"\n\tList is Empty";
    }
    else
    {
        cout<<"\n\tEnter book id :";
        cin>>test_id;

        if(test_id==head->book_id)
        {
            node *temp=head;
            head=head->next;
            delete temp;
            cout<<"\n\tBook record deleted successfully..";
            found++;
        }


    else
    {
        node *pre=head;
        node *curr=head;
        while(curr!=NULL)
        {
            if(test_id==curr->book_id)
            {
                pre->next=curr->next;
                delete curr;
                cout<<"\n\tBook record deleted successfully..";
                 found++;
                 break;
            }
            pre=curr;
            curr=curr->next;
        }
    }
    }
    if(found==0)
    {
        cout<<"\n\t record invalid";
    }
}
void library::show()
{
     system("cls");
    cout<<"\t*********************************************************\n";
    cout<<"\t\t\tLIBRARY MANAGEMENT SYSTEM \n";
    cout<<"\t*********************************************************\n\n";
    if(head==NULL)
    {
        cout<<"\n\tList is Empty";
    }
    else
    {   node *temp1=head;
        while(temp1!=NULL)
        {       cout<<"\n\tBook ID :"<<temp1->book_id;
                cout<<"\n\tBook Name :"<<temp1->book_name;
                cout<<"\n\tAuthor Name :"<<temp1->authour_name;
                cout<<"\n\t------------------------------------------------------------";
               temp1=temp1->next;
        }

        }
    }
void library::issue()
{
     system("cls");
    int found=0;
    string bname;
    cout<<"\t*********************************************************\n";
    cout<<"\t\t\tLIBRARY MANAGEMENT SYSTEM \n";
    cout<<"\t*********************************************************\n\n";
    if(head==NULL)
    {
        cout<<"\n\tBooks are not available\n";
        return;
    }
    else
    {

         cout<<"\n\tEnter book name:";
        cin>>bname;
        if(bname==head->book_name)
        {
            node *temp=head;
            head=head->next;
            delete temp;
            cout<<"\n\tBook issued...\n";
            found++;
        }


    else
    {
        node *pre=head;
        node *curr=head;
        while(curr!=NULL)
        {
            if(bname==curr->book_name)
            {
                pre->next=curr->next;
                delete curr;
                cout<<"\n\tBook issued ...\n";
                 found++;
                 break;
            }
            pre=curr;
            curr=curr->next;
        }
    }
    }
    if(found==0)
    {
        cout<<"\n\t This book is not available in library!!\n";
    }
}
void library ::returnb()
{   system("cls");
    cout<<"\t*********************************************************\n";
    cout<<"\t\t\tLIBRARY MANAGEMENT SYSTEM \n";
    cout<<"\t*********************************************************\n\n";
    node *newnode=new node;
    cout<<"\n\tEnter book ID:";
    cin>>newnode->book_id;
    cout<<"\n\tEnter book Name:";
    cin>>newnode->book_name;
    cout<<"\n\tEnter book author Name:";
    cin>>newnode->authour_name;
    newnode->next=NULL;
    int days;
    cout<<"\n\tEnter number of days in which book is returned:";
    cin>>days;
    if(days>15)
    {
        cout<<"\n\tYou have pay fine of Rs.1 for late return.Please pay the fine at counter.";
    }
    if(head==NULL)
    {
        head=newnode;
    }
    else
    {
        node *temp=head;
        while(temp->next!=NULL)
        {
            temp=temp->next;
        }
        temp->next=newnode;
    }
    cout<<"\n\tBook returned.....\n";
}
int main()
{
   library obj;
   obj.menu();
   obj.Insert();
   obj.Search();
   obj.update();
   obj.Delete();
   obj.show();
   obj.issue();
   obj.returnb();
    return 0;
}

