#include<bits/stdc++.h>
#include<fstream>

using namespace std;
#define line(c,n); for(int i=0;i<n;i++) cout<<c

class admin{
pair<string,string> delivery;
    public:
        admin()
        {
            delivery.first="deliver";
            delivery.second="delivery";
        }
        bool verify_delivery_agency(string username,string password)
        {
            if(username==delivery.first && password==delivery.second)
                return true;
            return false;
        }
        string username;
        string pass;

      bool verifyseller()
      {
          system("CLS");
        line('=',120);
         cout<<"\n\t\t\t\t\tLOGIN WINDOW\n";
        line('=',120);

         cout<<"\nPlease Enter your login credentials\n";
         cout<<"\n\n Username :\t";
         cin>>username;
         cout<<"\nPassword:\t";
         cin>>pass;
        cout<<endl;
      line('_',120);
         ifstream fio("../seller/sellers.txt");
         string name,password;
         while(fio>>name>>password)
         {

             if(username==name && md5(pass)==password)
             {
                 fio.close();
                 return true;
             }
         }
         fio.close();
         return false;
      }
};
