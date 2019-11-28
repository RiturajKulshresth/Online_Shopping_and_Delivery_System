#include<bits/stdc++.h>
using namespace std;

#define line(c,n) for(int i=0;i<n;i++) cout<<c;

void displaycategories(string command)
{
    string product_id,product_name;
    double product_price;
    int product_quantity;

    if(command=="all")
    {
        bool isthere=false;
        fstream fio("../seller/seller_user.txt",ios::in);
        string username;
        while(fio>>username)
        {
            int slag=1;

            string fil="../seller/"+username+"/"+username+"_mobiles.txt";

            fstream fout(fil.c_str(),ios::in);
            int flag=1;
            while(fout>>product_id>>product_name>>product_price>>product_quantity)
            {
                if(slag)
                {
                      cout<<"FROM "<<username<<endl<<endl;
                         cout<<setw(15)<<"PRODUCT ID"<<setw(40)<<"NAME"<<setw(15)<<"PRICE"<<setw(15)<<"QUANITY"<<endl;
                        line('_',120);
                        cout<<endl;
                      slag=0;
                }
                if(flag)
                {
                    cout<<"\nMOBILES:\n";
                    flag=0;
                }


                cout<<setw(15)<<product_id<<setw(40)<<product_name<<setw(15)<<product_price<<setw(15)<<product_quantity<<endl;
            }
            flag=1;
            fout.close();
            fil="../seller/"+username+"/"+username+"_laptops.txt";

            fout.open(fil.c_str(),ios::in);

             while(fout>>product_id>>product_name>>product_price>>product_quantity)
            {
                if(slag)
                {
                      cout<<"FROM "<<username<<endl<<endl;
                        cout<<setw(15)<<"PRODUCT ID"<<setw(40)<<"NAME"<<setw(15)<<"PRICE"<<setw(15)<<"QUANITY"<<endl;
                        line('_',120);
                        cout<<endl;
                      slag=0;
                }
               if(flag)
               {
                   cout<<"\nLAPTOPS:\n";
                   flag=0;
               }

                 cout<<endl;
                cout<<setw(15)<<product_id<<setw(40)<<product_name<<setw(15)<<product_price<<setw(15)<<product_quantity<<endl;
            }
            flag=1;
            fout.close();
            fil="../seller/"+username+"/"+username+"_daily_items.txt";
            fout.open(fil.c_str(),ios::in);

             while(fout>>product_id>>product_name>>product_price>>product_quantity)
            {
                if(slag)
                {
                      cout<<"FROM "<<username<<endl<<endl;
                        cout<<setw(15)<<"PRODUCT ID"<<setw(40)<<"NAME"<<setw(15)<<"PRICE"<<setw(15)<<"QUANITY"<<endl;
                        line('_',120);
                        cout<<endl;
                      slag=0;
                }
                 if(flag)
                 {
                      cout<<"Daily Items:\n";
                      flag=0;
                 }

                cout<<setw(10)<<product_id<<setw(20)<<product_name<<setw(10)<<product_price<<setw(10)<<product_quantity<<endl;
            }
            flag=1;
            fout.close();
            fil="../seller/"+username+"/"+username+"_eatables.txt";
            fout.open(fil.c_str(),ios::in);
             while(fout>>product_id>>product_name>>product_price>>product_quantity)
            {
                if(slag)
                {
                      cout<<"FROM "<<username<<endl;
                        cout<<setw(15)<<"PRODUCT ID"<<setw(40)<<"NAME"<<setw(15)<<"PRICE"<<setw(15)<<"QUANITY"<<endl;
                        line('_',120);
                        cout<<endl;
                      slag=0;
                }
               if(flag)
               {
                    cout<<"EATABLES:\n";
                    flag=0;
               }
                cout<<setw(15)<<product_id<<setw(40)<<product_name<<setw(15)<<product_price<<setw(15)<<product_quantity<<endl;
            }
            flag=1;
            fout.close();
            fil="../seller/"+username+"/"+username+"_stationary.txt";

            fout.open(fil.c_str(),ios::in);

             while(fout>>product_id>>product_name>>product_price>>product_quantity)
            {
                if(slag)
                {
                      cout<<"FROM "<<username<<endl;
                        cout<<setw(15)<<"PRODUCT ID"<<setw(40)<<"NAME"<<setw(15)<<"PRICE"<<setw(15)<<"QUANITY"<<endl;
                        line('_',120);
                        cout<<endl;
                      slag=0;
                }
               if(flag)
               {
                   cout<<"Stationary:\n";
                   flag=0;
               }

                cout<<setw(15)<<product_id<<setw(40)<<product_name<<setw(15)<<product_price<<setw(15)<<product_quantity<<endl;
            }
            flag=1;
            fout.close();
            fil="../seller/"+username+"/"+username+"_fruits.txt";

            fout.open(fil.c_str(),ios::in);

             while(fout>>product_id>>product_name>>product_price>>product_quantity)
            {
                if(slag)
                {
                      cout<<"FROM "<<username<<endl<<endl;
                        cout<<setw(15)<<"PRODUCT ID"<<setw(40)<<"NAME"<<setw(15)<<"PRICE"<<setw(15)<<"QUANITY"<<endl;
                        line('_',120);
                        cout<<endl;
                      slag=0;
                }
              if(flag)
              {
                   cout<<"FRUITS & VEGETABLES:\n";
                  flag=0;
              }
                cout<<setw(15)<<product_id<<setw(40)<<product_name<<setw(15)<<product_price<<setw(15)<<product_quantity<<endl;
            }
            fout.close();
        }
    }
    if(command=="specific")
    {
        cout<<"Select from available categories:\n"<<endl;
        line('-',120);
        cout<<endl;
        cout<<"1.Mobiles\n2.Laptops\n3.Headphones & Speakers\n4.Daily Items\n5.Stationary\n6.Fruits & vegetables";
        line('-',120);
        int n;
        cout<<endl;
        cout<<"INPUT:\t";
        cin>>n;
        system("CLS");
        if(n==1)
        {
            cout<<"MOBILES:\n\n";
             fstream fio("../seller/seller_user.txt",ios::in);
             string username;
             while(fio>>username)
             {

                  string fil="../seller/"+username+"/"+username+"_mobiles.txt";

                 fstream fio2(fil.c_str(),ios::in);
                 int flag=1;
                 while(fio2>>product_id>>product_name>>product_price>>product_quantity)
                 {
                     if(flag)
                     {
                         cout<<endl;
                         cout<<"From "<<username<<endl;
                           cout<<setw(15)<<"PRODUCT ID"<<setw(40)<<"NAME"<<setw(15)<<"PRICE"<<setw(15)<<"QUANITY"<<endl;
                        line('_',120);
                        cout<<endl;
                         flag=0;
                     }
                        cout<<setw(15)<<product_id<<setw(40)<<product_name<<setw(15)<<product_price<<setw(15)<<product_quantity<<endl;
                }
                  fio2.close();
             }
        }
        if(n==2)
        {
            cout<<"LAPTOPS:\n\n";
            fstream fio("../seller/seller_user.txt",ios::in);
            string username;
             while(fio>>username)
             {

                 string fil="../seller/"+username+"/"+username+"_laptops.txt";

                 fstream fio2(fil.c_str(),ios::in);
                 int flag=1;
                 while(fio2>>product_id>>product_name>>product_price>>product_quantity)
                 {
                     if(flag)
                     {
                         cout<<"From "<<username<<endl<<endl;
                           cout<<setw(15)<<"PRODUCT ID"<<setw(40)<<"NAME"<<setw(15)<<"PRICE"<<setw(15)<<"QUANITY"<<endl;
                        line('_',120);
                        cout<<endl;
                         flag=0;
                     }
                        cout<<setw(15)<<product_id<<setw(40)<<product_name<<setw(15)<<product_price<<setw(15)<<product_quantity<<endl;
                }
                 fio2.close();
             }
        }
        if(n==3)
        {
            //headphones
            cout<<"HEADPHONES & SPEAKERS:\n\n";
            fstream fio("../seller/seller_user.txt",ios::in);
            string username;
             while(fio>>username)
             {

                 string fil="../seller/"+username+"/"+username+"_headphones.txt";

                 fstream fio2(fil.c_str(),ios::in);
                 int flag=1;
                 while(fio2>>product_id>>product_name>>product_price>>product_quantity)
                 {
                     if(flag)
                     {
                         cout<<"From "<<username<<endl;
                           cout<<setw(15)<<"PRODUCT ID"<<setw(40)<<"NAME"<<setw(15)<<"PRICE"<<setw(15)<<"QUANITY"<<endl;
                        line('_',120);
                        cout<<endl;
                         flag=0;
                     }
                        cout<<setw(15)<<product_id<<setw(40)<<product_name<<setw(15)<<product_price<<setw(15)<<product_quantity<<endl;

                }
                fio2.close();
             }
        }
        if(n==4)
        {
            fstream fio("../seller/seller_user.txt",ios::in);
            string username;
             while(fio>>username)
             {

                 string fil="../seller/"+username+"/"+username+"_daily_items.txt";

                 fstream fio2(fil.c_str(),ios::in);
                 int flag=1;
                 while(fio2>>product_id>>product_name>>product_price>>product_quantity)
                 {
                     if(flag)
                     {
                         cout<<"From "<<username<<endl<<endl;
                           cout<<setw(15)<<"PRODUCT ID"<<setw(40)<<"NAME"<<setw(15)<<"PRICE"<<setw(15)<<"QUANITY"<<endl;
                        line('_',120);
                        cout<<endl;
                         flag=0;
                     }

                        cout<<setw(15)<<product_id<<setw(40)<<product_name<<setw(15)<<product_price<<setw(15)<<product_quantity<<endl;


                }
                 fio2.close();
             }
        }
        if(n==5)
        {
            cout<<"STATIONARY ITEMS:\n\n";
            fstream fio("../seller/seller_user.txt",ios::in);
            string username;
             while(fio>>username)
             {

                 string fil="../seller/"+username+"/"+username+"_stationary.txt";

                 fstream fio2(fil.c_str(),ios::in);
                 int flag=1;
                 while(fio2>>product_id>>product_name>>product_price>>product_quantity)
                 {
                     if(flag)
                     {
                         cout<<"From "<<username<<endl;
                           cout<<setw(15)<<"PRODUCT ID"<<setw(40)<<"NAME"<<setw(15)<<"PRICE"<<setw(15)<<"QUANITY"<<endl;
                        line('_',120);
                        cout<<endl;
                         flag=0;
                     }

                        cout<<setw(15)<<product_id<<setw(40)<<product_name<<setw(15)<<product_price<<setw(15)<<product_quantity<<endl;

                }
                 fio2.close();
             }
        }
        if(n==6)
        {
            //fruits and vegetables
            cout<<"FRUITS 'N' VEGETABLES:\n\n";
            fstream fio("../seller/seller_user.txt",ios::in);
            string username;
             while(fio>>username)
             {

                 string fil="../seller/"+username+"/"+username+"_fruits.txt";

                 fstream fio2(fil.c_str(),ios::in);
                 int flag=1;
                 while(fio2>>product_id>>product_name>>product_price>>product_quantity)
                 {
                     if(flag)
                     {
                         cout<<"From "<<username<<endl;
                           cout<<setw(15)<<"PRODUCT ID"<<setw(40)<<"NAME"<<setw(15)<<"PRICE"<<setw(15)<<"QUANITY"<<endl;
                        line('_',120);
                        cout<<endl;
                         flag=0;
                     }

                        cout<<setw(15)<<product_id<<setw(40)<<product_name<<setw(15)<<product_price<<setw(15)<<product_quantity<<endl;


                }
                  fio2.close();
             }
        }
    }
}
