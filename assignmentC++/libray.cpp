#include<iostream>
#include<istream>
#include<fstream>
#include<stdlib.h>
#include<string.h>
#include<bits/stdc++.h>
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

class Books_database{
//        vector<int>books;
        int total_books;
        public: 
		Books_database(){
        	total_books=0;
		}
        void Book_issue_request(string user,string pass, int role);
        void Add_book(string user, string pass);
        void Search(string user,string pass,int role);
        void Display_all_books(string user,string pass,int role);
        void Display_books_of_particular_user(string user,string pass,int role);
};

class Users_database{
        int total_users;
        public :
		Users_database(){
			total_users=0;
		}
		void Display_all_users(string user,string pass);
        void Add_user(string user,string pass);
        void Search(string user,string pass);
};

class Professor : public User
{
    int Fine_amount;
    vector<Book>books;
    void Calculate_fine();
    void Clear_fine_amount();
};

class Student : public User
{
    int Fine_amount;
    vector<Book>books;
    void Calculate_fine();
    void Clear_fine_amount();
};

class Librarian : public User{
        void Add_user();
        void Delete_user();
        void Update_user();
        void Add_book();
        void Delete_book();
        void Update_book(); 
};

Books_database books_database;
Users_database users_database;

void login();
void registr();
void forgot();
void student_login(string user,string pass);
void teacher_login(string user,string pass);
void librarian_login(string user,string pass);
void show_all_books(string user,string pass,int role);



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
        int role,id;
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
        while(input>>id>>u>>p>>rl)
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
                    case 3: librarian_login(user,pass);
							cout<<"\nHello"<<user<<"\nLOGIN SUCESS\nWe're glad that you're here.\nThanks for logging in\n";
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
        int role,id=1;
        cout<<"1. Student"<<endl;
        cout<<"2. Teacher"<<endl;
        cout<<"3. Librarian"<<endl;
        ifstream input("database.txt");
        while(input>>id>>ru>>rp>>role){
                id++;
        }
        
        cout<<"Enter the Number of role you want to register As:";
        cin>>role;
        cout<<"Enter the username :";
        cin>>reguser;
        cout<<"\nEnter the password :";
        cin>>regpass;
        
        ofstream reg("database.txt",ios::app);
        reg<<id<<' '<<reguser<<' '<<regpass<<' '<<role<<endl;
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
    int i=1,back=0;
    string book,student,status;
    cout<<"Hello "<<user<<endl;
    int op;
    cout<<"Operations that You can do here Are listed below."<<endl;
    cout<<"1. See all books"<<endl;
    cout<<"2. See books you Have"<<endl;
    cout<<"3. Request to Issue a Book"<<endl;
    cout<<"4. Logout";
    cout<<"\ntype Your Choice"<<endl;
    cin>>op;
    system("cls");
    switch(op){
        case 1:  books_database.Display_all_books(user,pass,1);
                 break;
        case 2:  books_database.Display_books_of_particular_user(user,pass,1);
                 break; 
        case 3:  books_database.Book_issue_request(user,pass,1);
                 break;         
        case 4: main();
                 break;
    }
}

void librarian_login(string user,string pass){

	cout<<"The available operations for you are:"<<endl;
	cout<<"1. See all books status"<<endl;
	cout<<"2. add book"<<endl;
	cout<<"3. see all  Users"<<endl;
	cout<<"4. Add User"<<endl;
    cout<<"5. Logout"<<endl;
	cout<<"\nEnter the number of your choice : \n";
	int op;
	cin>>op;
	system("cls");
	switch(op){
		case 1:books_database.Display_all_books(user,pass,3);
		        break;
                case 2:books_database.Add_book(user,pass);
		        break;
                case 3:users_database.Display_all_users(user,pass);
		        break;
                case 4:users_database.Add_user(user,pass);
		        break;
                case 5: main();
                        break;
	}
}

void teacher_login(string user, string pass){
    string book,status,student;
    int i,back=0;
    cout<<"Hello "<<user<<"You are logged in as teacher"<<endl;
    int op;
    cout<<"Operations that You can do here Are listed below."<<endl;
    cout<<"1. See all books"<<endl;
    cout<<"2. See all books you have issued"<<endl;
    cout<<"3. request to issue a book"<<endl;
    cout<<"4. Logout";
    cout<<"Enter the number of Your Choice"<<endl;
    cin>>op;
    system("cls");
    switch(op){
        case 1:  books_database.Display_all_books(user,pass,2);
                break;
        case 2: books_database.Display_books_of_particular_user(user,pass,2);
                break;
        case 3: books_database.Book_issue_request(user,pass,2);
                break;   
        case 4: main();
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

void Books_database :: Display_all_books(string user,string pass,int role){
    system("cls");
    int i,back=0;
    string ISBN,title,status,publications,author;
    string issuedto;
    ifstream input("books.txt");
                 i=1;
                 cout<<"No. | ISBN | title | author | status | publications | uname(issued/requested)"<<endl;
                 while(input>>ISBN>>title>>author>>status>>publications>>issuedto)
                 {
                      cout<<i<<". "<<ISBN<<" "<<title<<" "<<author<<" "<<status<<" "<<publications<<" "<<issuedto<<endl; 
                      i++;
                 }
                 input.close();
                 if(i==1)cout<<"\nNo books available in Database.\n";
                 cout<<"To go back press 1"<<endl;
    
    if(role==1){     
                 back=0;
                 cin>>back;
                 if(back==1){system("cls");
				 student_login(user,pass);}
                 else main();
    }
    else if(role == 2){
                 back=0;
                 cin>>back;
                 if(back==1){
				 system("cls");teacher_login(user,pass);}
                 else main();
    }
    else if(role==3){
    	         back=0;
                 cin>>back;
                 if(back==1){system("cls");
				 librarian_login(user,pass);}
                 else main();
	}
	
}
void Books_database :: Display_books_of_particular_user(string user, string pass,int role){
                 system("cls");
                string ISBN,title,status,publications,author,issuedto;
                int i,back=0;
                ifstream input("books.txt");
                 i=1;
                 cout<<"No. | ISBN | title | author | status | publications | uname(issued/requested)"<<endl;
                 while(input>>ISBN>>title>>author>>status>>publications>>issuedto)
                 {     
                     if(user==issuedto){
                      cout<<i<<". "<<ISBN<<" "<<title<<" "<<author<<" "<<status<<" "<<publications<<" "<<issuedto<<endl; 
                      i++;}
                 }
                 input.close();
                 cout<<"To go back press 1"<<endl;
                 back=0;
                 cin>>back;
                 if(back==1){
                 	system("cls");
				    if(role==1)student_login(user,pass);
				    if(role==2)teacher_login(user,pass);
				 }
                 else main();
}

void Books_database :: Book_issue_request(string user, string pass,int role){
                 system("cls");
                string ISBN,title,status,publications,author,issuedto;
                int i,back=0;
                ifstream input("books.txt");
                 i=1;
                 cout<<"No. | ISBN | title | author | status | publications | uname(issued/requested)"<<endl;
                 while(input>>ISBN>>title>>author>>status>>publications>>issuedto)
                 {     
                     if(user==issuedto){
                      cout<<i<<". "<<ISBN<<" "<<title<<" "<<author<<" "<<status<<" "<<publications<<" "<<issuedto<<endl; 
                      i++;}
                 }
                 input.close();
                 
                 if(role==1){
                         if(i>=5){
                              cout<<"You can't issue a Book as you reached the limit"<<endl;
                              back=0;
                              cout<<"To go back press 1"<<endl;
                              cin>>back;   
                         }
                         else {
                                cout<<"Enter the Name of Book you want to request for(without space use '_' for space)"<<endl;
                                string book;
                                cin>>book;
                                ifstream input("books.txt");
                                 i=1;
                                 cout<<"No. | ISBN | title | author | status | publications | uname(issued/requested)"<<endl;
                                 while(input>>ISBN>>title>>author>>status>>publications>>issuedto)
                                 {     
                                     if(book==title && (status=="Available" || status=="available")){
                                      string &st = status;
                                      string &iss = issuedto;
                                      st = "requested";
                                      iss = user;
                                      i++;
                                      break;}
                                      else if(book==title){
                                              cout<<i<<". "<<ISBN<<" "<<title<<" "<<author<<" "<<status<<" "<<publications<<" "<<issuedto<<endl; 
                                      }
                                 }
                                 input.close();
                                 system("cls");
                                if(i==1)cout<<"No such book available currently thanks."<<endl;
                                else cout<<"Book requested succesfully"<<endl;
                                student_login(user,pass);
                         }
                 }
                else{
                       cout<<"Enter the Name of Book you want to request for(without space use '_' for space)"<<endl;
                                string book;
                                cin>>book;
                                ifstream input("books.txt");
                                 i=1;
                                 cout<<"No. | ISBN | title | author | status | publications | uname(issued/requested)"<<endl;
                                 while(input>>ISBN>>title>>author>>status>>publications>>issuedto)
                                 {     
                                     if(book==title && (status=="Available" || status=="available")){
                                      status = "requested";
                                      issuedto = user;
                                      i++;
                                      break;}
                                      else if(book==title){
                                              cout<<i<<". "<<ISBN<<" "<<title<<" "<<author<<" "<<status<<" "<<publications<<" "<<issuedto<<endl; 
                                      }
                                 }
                                 input.close();
                                 system("cls");
                                if(i==1)cout<<"No such book available currently thanks."<<endl;
                                else cout<<"Book requested succesfully"<<endl;
                                teacher_login(user,pass);     
                }
}

void Books_database :: Add_book(string user, string pass){
    system("cls");
    string title,author,ISBN ,status="Available",publications,issuedto="none";
                cout<<"Enter the book details";
                cout<<"\nISBN : ";cin>>ISBN;
                cout<<"\nBook Name: ";cin>>title;
                cout<<"\nAuthor: ";cin>>author;
                cout<<"\nPublications: ";cin>>publications;
                ofstream reg("books.txt",ios::app);
                reg<<ISBN<<' '<<title<<' '<<author<<' '<<status<<' '<<publications<<' '<<issuedto <<endl;
                system("cls");
                cout<<"\nBook added Sucessfully\n";
                librarian_login(user,pass);
}

void Users_database :: Add_user(string user,string pass){
        system("cls");
        string reguser,regpass,ru,rp;
        int role,id=1;
        cout<<"1. Student"<<endl;
        cout<<"2. Teacher"<<endl;
        
        ifstream input("database.txt");
        while(input>>id>>ru>>rp>>role){
                id++;
        }
        
        cout<<"Enter the Number of role you want to add User As:";
        cin>>role;
        while(!(role==1 ||role==2)){
                cout<<"Can't assign this role. Please enter your choice again.";
                cin>>role;
                cout<<endl;
        }
        cout<<"\nEnter the username :";
        cin>>reguser;
        cout<<"\nEnter the password :";
        cin>>regpass;
        
        ofstream reg("database.txt",ios::app);
        reg<<id<<' '<<reguser<<' '<<regpass<<' '<<role<<endl;
        system("cls");
        cout<<"\nUser added Sucessfully\n";
        librarian_login(user,pass);
        
}
void Users_database :: Display_all_users(string user, string pass){
 		system("cls");
        string us,ps;
        int id,role;
        vector<string>roles;
        roles.push_back("Student");
        roles.push_back("Teacher");
        roles.push_back("Librarian");
        cout<<"ID | uname | role"<<endl;
        ifstream input("database.txt");
        while(input>>id>>us>>ps>>role){
                cout<<id<<" "<<us<<" "<<roles[role-1]<<endl;
        }
        input.close();
        int back=0;
        cout<<"To go back Enter 1";
        cin>>back;
        if(back==1)librarian_login(user,pass);
}

void Books_database :: Search(string user, string pass,int role){
        system("cls");
    int i,back=0;
    string ISBN,title,status,publications,author;
    string key;
    cout<<"\n Enter the name of book or author :";
    cin>>key;
    cout<<endl;
    int cnt=0;
    ifstream input("books.txt");
                 i=1;
                 cout<<"No."<<"book"<<" "<<"status"<<" "<<"student"<<endl;
                 while(input>>ISBN>>title>>author>>status>>publications)
                 {
                      if(key == title || key==author){
                              cnt++;
                      cout<<i<<". "<<ISBN<<" "<<title<<" "<<author<<" "<<status<<" "<<publications<<endl; 
                      i++;}
                 }
                 input.close();
                 cout<<"To go back press 1"<<endl;
                 if(cnt==0)cout<<"No matching Book is found"<<endl;
    
    if(role==1){     
                 back=0;
                 cin>>back;
                 if(back==1)student_login(user,pass);
                 else main();
    }
    else if(role == 2){
                 back=0;
                 cin>>back;
                 if(back==1)teacher_login(user,pass);
                 else main();
    }
    else if(role == 3){
                back=0;
                 cin>>back;
                 if(back==1)librarian_login(user,pass);
                 else main();
    }
}

void Users_database :: Search(string user,string pass){
        string key;
        cout<<"\n enter the username to search: ";
        cin>>key;
     string us,ps;
        int id,role;
        cout<<"ID | uname | role"<<endl;
        int cnt=0;
        ifstream input("datatbase.txt");
        while(input>>id>>us>>ps>>role){
                if(key==user){
                cout<<id<<" "<<us<<" "<<role<<endl;
                cnt++;
                }
        }
        input.close();
        if(cnt==0)cout<<"No matching User is found"<<endl;
        int back=0;
        cout<<"To go back Enter 1";
        cin>>back;
        if(back==1)librarian_login(user,pass);
}
  

