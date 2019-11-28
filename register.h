#include<bits/stdc++.h>
#include "md5.h"

using namespace std;

#define line(c,n) for(int i=0;i<n;i++) cout<<c;

class registeruser{
    string email;
    string password;
    string contact;
    string defaultaddress;
    public:
      void registercustomer();
      void registerseller();
};

void registeruser::registercustomer()
{
    system("CLS");
    line('=',120);
    cout<<endl<<endl;
    cout<<"\t\t\tCustomer Registration Portal\t\t\t";
    cout<<endl<<endl;
    line('=',120);
    string fname,lname,email,pass1,pass2,phone;
    string fname1,lname1,email1,pass4,pass5,phone1;
    cout<<"\nPlease enter the information asked:\n\n";
    cout<<endl;
    line('_',120);
    cout<<"First Name:\t";
    cin>>fname;
    cout<<"\nLast Name:\t";
    cin>>lname;
    bool sense=true;
    tip:
    cout<<"\nE-mail id:\t";
    cin>>email;
    ifstream fio("../other/emails.txt");
    while(fio>>email1)
    {
        if(email==email1)
        {
            int n;
            cout<<"\n1.Try different email-id\t\t2.exit registration process";
            cin>>n;
            if(n==1)
                goto tip;
            if(n==2)
                return;
        }
    }
    fio.close();
if(sense)
{
    top:
        cout<<endl;
    cout<<"Password should contain atleast one small letter,one capital letter ,one digit,and one special character"<<endl;
    cout<<"\nPassword:\t";
    cin>>pass1;
     int a=0,b=0,c=0,d=0;
    for(int i=0;i<pass1.size();i++)
    {
        if(isalpha(pass1[i]))
        {
            if(isupper(pass1[i]))
                a++;
            if(islower(pass1[i]))
                b++;
        }
        if(isdigit(pass1[i]))
            c++;
        if((!isdigit(pass1[i])) && (!isalpha(pass1[i])))
            d++;
    }
    if(a==0 || b==0 || c==0 || d==0)
        goto top;

    cout<<"\nRe-enter Password:\t";
    cin>>pass2;
    if(pass1!=pass2)
    {
        cout<<"\n**Password didn't match**";
        goto top;
    }
    ph1:
    cout<<"\nPhone No.:\t";
    cin>>phone;
    if(phone.size()!=10)
    {
        cout<<"Invalid No.,Please Enter again";
        goto ph1;
    }
}
    fstream fout("../customer/customerdata.txt",ios::app);
     string username;

    unsigned int i=0;
    string type;
    int flag=0;
    while(i<email.size())
    {
        if(email[i]=='@')
            flag=1;
        if(!flag)
         username+=email[i];
        if(flag)
            type+=email[i];
         i++;
    }
    if((type!="@gmail.com") && (type!="@yahoo.com") && (type!="@iitj.ac.in"))
    {
        cout<<"Inavalid Email-Id";
        sense=false;
        goto tip;
    }
    fout<<setw(30)<<username<<setw(30)<<fname<<" "<<lname<<setw(40)<<email<<setw(30)<<phone<<"\n";
    fout.close();

    fout.open("../customer/users.txt",ios::app);
    fout<<setw(30)<<username<<setw(80)<<md5(pass1)<<endl;
    fout.close();
    system("CLS");
     cout<<"Successfully Registered!!!!!!!!!!";
     delay(1000);
    system("CLS");
    line('=',120);

    cout<<"\n\t\t\t\t\tYOUR LOGIN DATA\n";
    line('_',120);
    cout<<endl;
    cout<<setw(20)<<"USERNAME:"<<setw(30)<<username<<endl<<setw(20)<<"NAME:"<<setw(30)<<fname<<" "<<lname<<endl
        <<setw(20)<<"EMAIL-ID:"<<setw(30)<<email<<endl<<setw(20)<<"CONTACT:\t"<<setw(30)<<phone<<endl;
    line('=',120);
    fout.open("../other/emails.txt",ios::app);
    fout<<setw(20)<<email<<endl;
    fout.close();
    cout<<endl<<endl;
    cout<<"You will be redirected to Login page automatically!!";
    delay(2000);
}

void registeruser::registerseller()
{
    system("CLS");
    cout<<endl;
    line('=',120);
    cout<<endl<<endl;
    cout<<"\t\t\tSELLER REGISTRATION PORTAL"<<endl<<endl;
    line('=',120);
    cout<<endl<<endl;
        string fname,lname,email,pass1,pass2,phone;
    string fname1,lname1,email1,pass4,pass5,phone1;
    cout<<"\nPlease enter the information asked:\n"<<endl;
    line('_',120);
    cout<<endl<<endl;
    cout<<"First Name:\t";
    cin>>fname;
    cout<<"\nLast Name:\t";
    cin>>lname;
    bool sense=true;
    tip:
    cout<<"\nE-mail id:\t";
    cin>>email;
    string emaill;
    fstream fio("../other/emails.txt",ios::in);
    while(fio>>emaill)
    {
        if(email==email1)
        {
            int n;
            cout<<"\n1.Try different email-id\t\t2.exit registration process";
            cin>>n;
            if(n==1)
                goto tip;
            if(n==2)
                return;
        }
    }
    fio.close();
    top:
if(sense)
{
    cout<<endl;
    cout<<"Password should contain atleast one small letter,one capital letter ,one digit,and one special character"<<endl;
    cout<<"\nPassword:\t";
    cin>>pass1;
     int a=0,b=0,c=0,d=0;
    for(int i=0;i<pass1.size();i++)
    {
        if(isalpha(pass1[i]))
        {
            if(isupper(pass1[i]))
                a++;
            if(islower(pass1[i]))
                b++;
        }
        if(isdigit(pass1[i]))
            c++;
        if((!isdigit(pass1[i])) && (!isalpha(pass1[i])))
            d++;
    }
    if(a==0 || b==0 || c==0 || d==0)
        goto top;
    cout<<"\nRe-enter Password:\t";
    cin>>pass2;
    if(pass1!=pass2)
    {
        cout<<"\n**Password didn't match**";
        goto top;
    }

    ph:
    cout<<"\nPhone No.:\t";
    cin>>phone;

    if(phone.size()!=10)
    {
        cout<<"\n\n********Invalid phone no.**********";
        goto ph;
    }
}
    fstream fout("../seller/sellerdata.txt",ios::app);
     string username,type;
    int i=0;
    int fla=1;
    while(i<email.size())
    {
        if(email[i]=='@')
            fla=0;
        if(fla)
            username+=email[i];
        if(!fla)
            type+=email[i];
        i++;
    }
     if((type!="@gmail.com") && (type!="@yahoo.com") && (type!="@iitj.ac.in"))
    {
        cout<<"Inavalid Email-Id";
        sense=false;
        goto tip;
    }
    int flag=1;
    fio.open("../other/sel_reg.txt",ios::in);
    if(fio.eof())
    {
        cout<<"here";
        flag=0;
    }
      int sellerid=0;
      if(flag)
        fio>>sellerid;
        fio.close();
    fio.open("../other/sel_reg.txt",ios::out);
    fio<<sellerid+1;
    fio.close();
    fout<<setw(10)<<sellerid<<setw(30)<<username<<setw(20)<<fname<<" "<<lname<<setw(40)<<email<<setw(15)<<phone<<"\n";
    fout.close();

    fout.open("../seller/sellers.txt",ios::app);
    fout<<setw(20)<<username<<setw(80)<<md5(pass1)<<"\n";
    fout.close();
     system("CLS");
     cout<<"Successfully Registered!!!!!!!!!!";
     delay(1000);
    system("CLS");
line('=',120);
system("CLS");
    cout<<"\n\t\t\t\t\tYOUR LOGIN DATA\n";
line('_',120);
cout<<endl;
    cout<<setw(20)<<"ID:"<<setw(30)<<sellerid<<endl<<setw(20)<<"USERNAME:"<<setw(30)<<username<<endl<<setw(20)
    <<"NAME:"<<setw(30)<<fname<<" "<<lname<<endl<<setw(20)<<"EMAIL-ID:"<<setw(30)<<email<<endl<<setw(20)
    <<"CONTACT:"<<setw(30)<<phone<<endl;
line('=',120);
delay(5000);
cout<<endl<<endl;
cout<<"************PLEASE REMEMBER YOUR LOGIN DATA**********";
    fout.open("../other/emails.txt",ios::app);
    fout<<setw(-20)<<email<<endl;
    fout.close();
    fout.open("../seller/seller_user.txt",ios::app);
    fout<<setw(30)<<username<<setw(40)<<sellerid<<endl;
    fout.close();
    delay(500);
     cout<<endl<<endl;
    cout<<"You will be redirected to Login page automatically!!";
    delay(5000);
}
