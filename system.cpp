#include<iostream>
#include<fstream>
#include<sstream>
#include<string>
using namespace std;

int main()
{
    int a, i=0;
    string text, old, password1, password2, pass, name, password0, age, user, word, word1;
    string creds[2], cp[2];

    cout<<endl;
    cout<<"*************** Security System ***************"<<endl;

    cout<<"______________________________________________________________"<<endl<<endl;
    cout<<"|                       1. Register                          |"<<endl;
    cout<<"|                       2. Login                             |"<<endl;
    cout<<"|                       3. Change Password                   |"<<endl;
    cout<<"|_______________________4. End Program_______________________|"<<endl<<endl;

    do{
        cout<<endl<<endl;
        cout<<"Enter you choice"<<endl;
        cin>>a;
        switch(a)
        {
            case 1: {
                    cout<<"______________________________________________________"<<endl;
                    cout<<"|_______________________Register_____________________|"<<endl;
                    cout<<"|____________________________________________________|"<<endl;
                    
                    cout<<"Enter your username...."<<endl;
                    cin>>name;
                    cout<<"Enter your Password...."<<endl;
                    cin>>password0;
                    cout<<"Enter your age........."<<endl;
                    cin>>age;

                    ofstream outf("Database.txt",ios::out);
                    if(outf.is_open()){
                        outf<<name<<endl;
                        outf<<password0;
                        cout<<"Registration Successfull"<<endl;
                    }
                    
                break;
            }

            case 2:{
                    i=0;

                    cout<<"______________________________________________________"<<endl;
                    cout<<"|_______________________Login________________________|"<<endl;
                    cout<<"|____________________________________________________|"<<endl;

                    ifstream fi("Database.txt",ios::in);
                    cout<<"Please enter username..."<<endl;
                    cin>>user;
                    cout<<"Please enter password..."<<endl;
                    cin>>pass;

                    if(fi.is_open())
                    {
                        while(!fi.eof())
                        {
                            while(getline(fi,text))
                            {
                                istringstream iss(text);
                                iss>>word;
                                creds[i] = word;
                                i++; 
                            }

                            if(creds[0] == user && creds[1] == pass)
                            {
                                cout<<"--- Login Successfull ---"<<endl;
                                cout<<endl<<endl;

                                cout<<"Details are: "<<endl;
                                cout<<"Username is: "<<name<<endl;
                                cout<<"Password is: "<<password0<<endl;
                                cout<<"Age is     : "<<age<<endl;
                            }
                            else{
                                cout<<"Incorrect Credentials"<<endl;
                                cout<<"|     1. Press 2 to Login              |"<<endl;
                                cout<<"|     2. Press 3 for Change Password   |"<<endl;
                                break;
                            }
                        }
                    }
                   break;
                }
            case 3:{

                cout<<"-----------------Change Password -----------------"<<endl;
                i = 0;
                
                ifstream fi1("Database.txt",ios::in);
                cout<<"Enter your old password: "<<endl;
                cin>>old;

                if(fi1.is_open())
                {
                    while(!
                    fi1.eof())
                    {
                        while(getline(fi1 , text))
                        {
                            istringstream iss(text);
                            iss>>word1;
                            cp[i] = word1;
                            i++;                            
                        }
                        if(cp[1] == old)
                        {
                            fi1.close();
                            ofstream outf1("Database.txt");
                            if(outf1.is_open()){
                                cout<<"Enter your New Password: "<<endl;
                                cin>>password1;
                                cout<<"Confirm your New Password: "<<endl;
                                cin>>password2;

                                if(password1 == password2)
                                {
                                    outf1<<cp[0]<<"\n";
                                    outf1<<password1;
                                    cout<<"Password change successfully\n";
                                }
                                else{
                                    outf1<<cp[0]<<"\n";
                                    outf1<<old;
                                    cout<<"Password Do not Match...";
                                }
                            }
                        }
                        else
                        {
                            cout<<"Please Enter a valid Password"<<endl;
                            break;
                        }
                    }
                }
                break;
            }
            case 4:{
                cout<<"-------------Thank You !-------------";
                break;
            }
            default:
                cout<<"Enter a valid choice"<<endl;
                

        }
    }while(a!=4);
    return 0;
    
}

