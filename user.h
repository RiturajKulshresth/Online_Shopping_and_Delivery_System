#include<bits/stdc++.h>
#include<fstream>

using namespace std;
#define line(c,n); for(int i=0;i<n;i++) cout<<c

class customer;
class user{

    pair<string,string> admin;
    public:
     pair<string,string> getadmin()
     {
         return admin;
     }
     string username,password;
     bool verifycustomer()
     {
    line('=',120);
         cout<<"\n\t\t\t\t\tLOGIN WINDOW\n";
    line('=',120);
         cout<<"\n\nPlease Enter your Login Credenetials\n";
         cout<<"\n\nUsername:\t";
         cin>>username;
         cout<<"\nPassword:\t";
           cin>>password;
         ifstream fio("../customer/users.txt");
         string name,pass;
         while(fio>>name>>pass)
         {

             if(username==name && pass==md5(password))
             {
                 fio.close();
                 return true;
             }
         }
         fio.close();

         return false;
     }
     friend class customer;
};

