#include<iostream>
#include<istream>
#include<fstream>
#include<string>
#include<stdlib.h>

using namespace std;
void Register();
void Login();
void Forgot();


int main()
{
    int choice;
    cout<<"\n******************************* WEL-COME****************************************\n";
    cout<<"1.REGISTER "<<endl<<"2.LOGIN "<<endl<<"3.FORGOT"<<endl;
    cout<<"Enter your choice : ";
    cin>>choice;

    switch (choice)
    {
    case 1:
    Register();
    break;

    case 2:
    Login();
    break;

    case 3:
    Forgot();
    break;   
    
    case 4:
    cout<<"\nTHANK YOU :) For Login In This Page.";
    break;

    default:
    cout<<"\nsorry :( \nWrong choice "; 
        break;
    main();
    }
} 

void Register()
{
    string reg_user ,reg_pass;
    system("cls");                            // -->for clear screen.
    cout<<"Enter User Name : ";
    cin>>reg_user;
    
    cout<<"Enter Password : ";
    cin>>reg_pass;

    ofstream reg("file.txt",ios::app);      //-->It provide output opration in file.(Write date in file)
    reg<<reg_user<<" "<<reg_pass<<endl;

    system("cls");
    cout<<"CONGRATULATIONS!!! "<<reg_user<<" .\nRegistration is Sucessfull !!!"<<endl;

    main();

}

void Login()
{
    int flage;
    string log_user,log_pass;
    string user,pass;                         //-->These string use to compare username and password.
    cout<<"Enter Your User Name : ";
    cin>>log_user;
    cout<<"Enter Your Password : ";
    cin>>log_pass;

    ifstream log("file.txt");            //-->It provide input opration in the file.(read file)
    while (log>>user>>pass)
    {
      if(user==log_user&& pass==log_pass)
      {
          flage=1;                          //-->if pass and username match with current entring pass and username flage will be set 1.

      }    

    }
    log.close();                           //-->close file
    if(flage==1)
    {
       cout<<"\nSucessfully login !!!";
       cout<<"\nHello "<<log_user<<" Wel-Come To The Page.";

       cin.get();                         //It use to accessing the key or choice.
       cin.get();
       main();
    }
    else
    {
        cout<<"\nSorry :) This Acccount Dose Not Exist.\nPlease Try Again\n\n***********THANK YOU !!!************** ";
        cin.get();
        cin.get();
        main();
    }
   
}

void Forgot()
{
  int key;
  system("cls");
  cout<<"1.Search Account By Username.  "<<endl<<"2.Search Account By Password. "<<endl<<"3.Back To The Main Page. "<<endl;

  cout<<"ENTER YOUR CHOICE : ";
  cin>>key;

  switch(key)

  {
     case 1 :                                               //case 1 (accound found by username)
     {
     int exist=0;
     string searchuser ,su,sp;

     cout<<"Enter Your User Name : ";
     cin>>searchuser;

     ifstream user("file.txt");                       //-->Read file to check Account.

     while(user>>su>>sp)
     {
       if(su==searchuser)
       {
           exist=1;
       }
     }
     user.close();                                      //-->close file.
     if(exist==1)
     {
         cout<<"\nHURREY !!! "<<su<<" Your Account Is Found.\n";
         cout<<"Your Account ID Is : "<<su<<endl;
         cout<<"Your Password is   : "<<sp<<endl;

         cin.get();
         cin.get();
         main();
     }
     else
     {
         cout<<"Sorry :( "<<searchuser<<" \nYour Account Is Not Found . \nPlease Try Again ."<<endl;
         cin.get();
         cin.get();
         main();
     }
     break;
     }
     case 2:                                   //case2(account found by  password)
    {
     int found=0;
     string search_pass ,search_u,search_p;
     cout<<"Enter Your Password : ";
     cin>>search_pass;

     ifstream pass("file.txt");
     while(pass>>search_u>>search_p)
     {
         if(search_pass==search_p)
         {
             found=1;
         }
     }
     pass.close();
     if(found==1)
     {
         cout<<"\nHURREY!!! Your Account Is Found.\n";
         cout<<"Your Account ID Is : "<<search_u<<endl;
         cout<<"Your Password Is   : "<<search_p<<endl;
         cin.get();
         cin.get();
         main();
     }
     else
     {
         cout<<"\nSorry :( \nYour Account Is Not Found \nPlease Try Again ."<<endl;
         cin.get();
         cin.get();
         main();
     }
     break;
    }

     case 3: 
     { 
     cin.get();                            //case 3(deafault case)
     main();
     
     }
     default:
     cout<<"Choice Is Wrong. ";
     Forgot();
    }
 

}

