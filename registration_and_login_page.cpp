#include<iostream>
#include<fstream>
#include<string>
using namespace std;

void login();
void forgot();
void registration();


int main(){
    int choice;

    cout<<"\t\t\t __________________________________________________\n";
    cout<<"\t\t\t|             Welcome to the login page            |\n";
    cout<<"\t\t\t|-----------------   Menu   -----------------------|\n";
    cout<<"\t\t\t|                                                  |\n";
    cout<<"\t\t\t|  Press 1 to LOGIN                                |"<<endl;
    cout<<"\t\t\t|  Press 2 to RESGISTER                            |"<<endl;
    cout<<"\t\t\t|  Press 3 if you FORGOT YOUR PASSWORD             |"<<endl;
    cout<<"\t\t\t|  Press 4 to EXIT                                 |\n";
    cout<<"\t\t\t|__________________________________________________|\n";
    
    cout<<"\n\t\t\t Please Enter Your Choice : ";
    cin>>choice;
    cout<<endl;
    
    switch(choice){
        case 1:
            login();
            break;
        case 2:
            registration();
            break;
        case 3:
            forgot();
            break;
        case 4:
            cout<<"\t\t\tTHANK YOU... \n";
            cout<<"\t\t\tExiting!!!\n";
        default:
            system("cls");
            cout<<"\t\t\tInvalid Choice Entered !!\n";
            cout<<"\t\t\tSelect choice from Menu Given \n";
    }
    return 0;
}

void login(){
    int count;
    string userID;
    string ID;
    string password;
    string pass;
    system ("cls");

    cout<<"\t\t\tEnter the username and password : "<<endl;
    cout<<"\t\t\tUSERNAME : ";
    getline(cin,userID);
    cout<<"\t\t\tPASSWORD : ";
    getline(cin,password)
    ifstream input("records.txt");
    while(input>>ID>>pass){
        if(ID==userID && pass==password){
            count=1;
            system("cls");
        }
    }
    input.close();
    
    if(count==1){
        cout<<userID <<"\n your LOGIN is successful \n Thnaks for logging in ! \n ";
        main();
    }else{
        cout<<"\n LOGIN ERROR \n Please check your username and password \n";
        main();
    }
}

void registration(){
    string ruserID;
    string rpassword;
    string rID;
    string rpass;
    system("cls");
    cout<<"\t\t\tEnter the username : ";
    getline(cin,ruserID);
    cout<<"\t\t\tEnter the password : ";
    getline(cin,rpassword);

    ofstream f1("records.txt",ios::app);
    f1<<ruserID<<' '<<rpassword<<endl;
    system("cls");
    cout<<"\n\t\t\t Registration is successful ! \n";
}

void forgot(){
    int option;
    system("cls");
    cout<<"\t\t\tYou forget the passwod? No worries \n";
    cout<<"Press 1 to search your id by username "<<endl;
    cout<<"Press 2 to go back to the main menu  "<<endl;
    cout<<"\t\t\tEnter your choice : ";
    cin>>option;
    switch(option){
        case 1:{
            int count =0;
            string suserID,sID,sPass;
            cout<<"\n\t\t\tEnter the username which you remembered : ";
            getline(cin,suserID);

            ifstream f2("records.txt");
            while(f2>>sID>>sPass){
                if(sID==suserID){
                    count =1;
                }
            }
            f2.close();
            if(count==1){
                cout<<"\n\n Your account is found ! \n";
                cout<<"\n\n Your password is : "<<sPass<<endl;
            }else{
                cout<<"\n\t Sorry !! your account is not found !!\n";
            }
        }
            break;
        case 2:{
            return;
        }
            break;
        default:
            cout<<"\t\t\t Wrong choice ! please try again "<<endl;
            forgot();

    }
}