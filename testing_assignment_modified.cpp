#include<iostream>
#include<istream>
#include<fstream>
#include<stdlib.h>
#include<string.h>
using namespace std;

class User
{
    string Name;
    int ID;
    string Password;
};

class Book{
        string title;
        string author;
        string ISBN;
        string publication;
        void Book_Request();
        void Show_duedate();
};

class Book_database{
        vector<Book>books;
        void Add_book();
        void Update();
        void Delete();
        void Search();
};

class User_database{
        vector<user>users;
        void Add_user();
        void Update();
        void Delete();
        void Search();
};



class Professor : public user
{
    int Fine_amount;
    vector<Book>books;
    void Calculate_fine();
    void Clear_fine_amount();
};

class Student : public user
{
    int Fine_amount;
    vector<book>books;
    void Calculate_fine();
    void Clear_fine_amount();
};

class Librarian{
        void Add_user();
        void Delete_user();
        void Update_user();
        void Add_book();
        void Delete_book();
        void Update_book(); 
};

void login();
void registr();
void forgot();
void student_login(string user,string pass);
void teacher_login(string user,string pass);
void show_all_books(string user,string pass,int role);
void show_books_of_particular_user(string user, string pass);
void book_issue_request(string user,string pass);
void add_book(string user, string pass);

main()
{
        int choice;
        cout<<"***********************************************************************\n\n\n";
        cout<<"                      Welcome to login page                               \n\n";
        cout<<"*******************        MENU        *******************************\n\n";
        cout<<"1.LOGIN"<<endl;
        cout<<"2.REGISTER"<<endl;
        cout<<"3.FORGOT PASSWORD (or) USERNAME"<<endl;
        cout<<"4.Exit"<<endl;
        cout<<"\nEnter your choice :";
        cin>>choice;
        cout<<endl;
        switch(choice)
        {
                case 1:
                        login();
                        break;
                case 2:
                        registr();
                        break;
                case 3:
                        forgot();
                        break;
                case 4:

                        cout<<"Thanks for using this program\nThis program is created by @harsha20599\n\n";
                        break;
                default:
                        system("cls");
                        cout<<"You've made a mistake , give it a try again\n"<<endl; 
                        main();
        }
        
}

void login()
{       
        int role;
        cout<<"1. Student"<<endl;
        cout<<"2. Teacher"<<endl;
        cout<<"3. Librarian"<<endl;
        cout<<"Login As a"<<endl;
        cout<<"Enter the Number of Choice";
        cin>>role;
        
        
        
        int count,rl;
        string user,pass,u,p;
        system("cls");
        cout<<"please enter the following details"<<endl;
        cout<<"USERNAME :";
        cin>>user;
        cout<<"PASSWORD :";
        cin>>pass;
        
        ifstream input("database.txt");
        while(input>>u>>p>>rl)
        {
                if(u==user && p==pass && rl==role)
        
                {
                        count=1;
                        system("cls");
                }
        }
        input.close();
        if(count==1)
        {       
                switch(role){
                    case 1: student_login(user,pass);
                            break;
                    case 2: teacher_login(user,pass);
                            break;
                    case 3:cout<<"\nHello"<<user<<"\nLOGIN SUCESS\nWe're glad that you're here.\nThanks for logging in\n";
                            cin.get();
                            cin.get();
                            main();
                }        
                
        }
        else
        {
                cout<<"\nLOGIN ERROR\nPlease check your username and password\n";
                main();
        }
}

void registr()
{
        system("cls");
        string reguser,regpass,ru,rp;
        int role;
        cout<<"1. Student"<<endl;
        cout<<"2. Teacher"<<endl;
        cout<<"3. Librarian"<<endl;
        cout<<"Login As a"<<endl;
        
        cout<<"Enter the Number of role you want to register As:";
        cin>>role;
        cout<<"Enter the username :";
        cin>>reguser;
        cout<<"\nEnter the password :";
        cin>>regpass;
        
        ofstream reg("database.txt",ios::app);
        reg<<reguser<<' '<<regpass<<' '<<role<<endl;
        system("cls");
        cout<<"\nRegistration Sucessful\n";
        main();
        
        
}

void forgot()
{
        int ch;
        system("cls");
        cout<<"Forgotten ? We're here for help\n";
        cout<<"1.Search your id by username"<<endl;
        cout<<"2.Search your id by password"<<endl;
        cout<<"3.Main menu"<<endl;
        cout<<"Enter your choice :";
        cin>>ch;
        switch(ch)
        {
                case 1:
                {
                        int count=0;
                        string searchuser,su,sp;
                        cout<<"\nEnter your remembered username :";
                        cin>>searchuser;
                        
                        ifstream searchu("database.txt");
                        while(searchu>>su>>sp)
                        {
                                if(su==searchuser)
                                {
                                        count=1;
                                }
                        }
                        searchu.close();
                        if(count==1)
                        {
                                cout<<"\n\nHurray, account found\n";
                                cout<<"\nYour password is "<<sp;
                                cin.get();
                                cin.get();
                                system("cls");
                                main();
                        }
                        else
                        {
                                cout<<"\nSorry, Your userID is not found in our database\n";
                                cout<<"\nPlease kindly contact your system administrator for more details \n";
                                cin.get();
                                cin.get();
                                main();
                        }
                        break;
                }
                case 2:
                {
                        int count=0;
                        string searchpass,su2,sp2;
                        cout<<"\nEnter the remembered password :";
                        cin>>searchpass;
                        
                        ifstream searchp("database.txt");
                        while(searchp>>su2>>sp2)
                        {
                                if(sp2==searchpass)
                                {
                                        count=1;
                                }       
                        }
                        searchp.close();
                        if(count==1)
                        {
                                cout<<"\nYour password is found in the database \n";
                                cout<<"\nYour Id is : "<<su2;
                                cin.get();
                                cin.get();
                                system("cls");
                                main();
                        }
                        else
                        {
                                cout<<"Sorry, We cannot found your password in our database \n";
                                cout<<"\nkindly contact your administrator for more information\n";
                                cin.get();
                                cin.get();
                                main();
                        }
                
                        break;
                }
                
                case 3:
                {
                        cin.get();
                        main();
                }
                default:
                        cout<<"Sorry, You entered wrong choice. Kindly try again"<<endl;
                        forgot();
        }
}



void student_login(string user, string pass){
    system("cls");
    int i=1,back=0;
    string book,student,status;
    cout<<"Hello "<<user<<endl;
    int op;
    cout<<"Operations that You can do here Are listed below."<<endl;
    cout<<"1. See all books"<<endl;
    cout<<"2. See books you Have"<<endl;
    cout<<"3. Request to Issue a Book"<<endl;
    cout<<"4. Logout";
    cout<<"type Your Choice"<<endl;
    cin>>op;
    switch(op){
        case 1:  show_all_books(user,pass,1);
                 break;
        case 2:  show_books_of_particular_user(user,pass);
                 break; 
        case 3:  book_issue_request(user,pass);
                 break;         
        case 4: main();
                 break;
    }
}

void teacher_login(string user, string pass){
    system("cls");
    string book,status,student;
    int i,back=0;
    cout<<"Hello "<<user<<"You are logged in as teacher"<<endl;
    int op;
    cout<<"Operations that You can do here Are listed below."<<endl;
    cout<<"1. See all books"<<endl;
    cout<<"2. Add a book"<<endl;
    cout<<"3. Logout";
    cout<<"Enter the number of Your Choice"<<endl;
    cin>>op;
    switch(op){
        case 1:  show_all_books(user,pass,2);
                break;
        case 2: add_book(user,pass);
                break;
        case 3: main();
                break;   
        
    }
}

void show_all_books(string user,string pass,int role){
    system("cls");
    string book,status,student;
    int i,back=0;
    if(role==1){
                 ifstream input("books.txt");
                 i=1;
                 cout<<"No."<<"book"<<" "<<"status"<<" "<<"student"<<endl;
                 while(input>>book>>status>>student)
                 {
                      cout<<i<<". "<<book<<" "<<status<<" "<<student<<endl; 
                      i++;
                 }
                 input.close();
                 cout<<"To go back press 1"<<endl;
                 back=0;
                 cin>>back;
                 if(back==1)student_login(user,pass);
                 else main();
    }
    else if(role == 2){
        ifstream input("books.txt");
                 i=1;
                 cout<<"No."<<"book"<<" "<<"status"<<" "<<"student"<<endl;
                 while(input>>book>>status>>student)
                 {
                      cout<<i<<". "<<book<<" "<<status<<" "<<student<<endl; 
                      i++;
                 }
                 input.close();
                 cout<<"To go back press 1"<<endl;
                 back=0;
                 cin>>back;
                 if(back==1)teacher_login(user,pass);
                 else main();
    }
}

void show_books_of_particular_user(string user, string pass){
    system("cls");
                string book,status,student;
                int i,back=0;
                ifstream input("books.txt");
                 i=1;
                 cout<<"No."<<"book"<<" "<<"status"<<" "<<"student"<<endl;
                 while(input>>book>>status>>student)
                 {     
                     if(user==student){
                      cout<<i<<". "<<book<<" "<<status<<" "<<student<<endl; 
                      i++;}
                 }
                 input.close();
                 cout<<"To go back press 1"<<endl;
                 back=0;
                 cin>>back;
                 if(back==1)student_login(user,pass);
                 else main();
}

void book_issue_request(string user, string pass){
           system("cls");
                 string status,book,student;
                 int i,back=0;
               ifstream input("books.txt");
                 cout<<"List of books You issued.";
                 i=1;
                 cout<<"No."<<"book"<<" "<<"status"<<" "<<"student"<<endl;
                 while(input>>book>>status>>student)
                 {     
                     if(user==student){
                      cout<<i<<". "<<book<<" "<<status<<" "<<student<<endl; 
                      i++;}
                 }
                 if(i>=5)cout<<"You can't Request to Issue Book You have reached to limit of 5books."<<endl;
                 input.close();
                 cout<<"To go back press 1"<<endl;
                 back=0;
                 cin>>back;
                 if(back==1)student_login(user,pass);
                 else main();
}

void add_book(string user, string pass){
    system("cls");
    string book ,student="None",status="Available";
                cout<<"Enter the book details";
                cout<<"Book Name:";cin>>book;
                ofstream reg("books.txt",ios::app);
                reg<<book<<' '<<status<<' '<<student<<endl;
                cout<<"\nBook added Sucessfully\n";
                system("cls");
                teacher_login(user,pass);
}


