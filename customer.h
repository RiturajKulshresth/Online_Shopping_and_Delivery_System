#include<bits/stdc++.h>
#include<fstream>

#include"user.h"

using namespace std;
#define line(c,n); for(int i=0;i<n;i++) cout<<c


class customer{

    string username;
    string contact;
    string name;
    string address;
public:
    string get_user()
    {
        return username;
    }
    void initialize(user obj)
    {
        username=obj.username;
    }
     void updateprofile();
     void placeorder();
     void searchproduct();
};

void customer::updateprofile()
{
    fstream fio("../customer/customerdata.txt",ios::in);
    fstream fout("tempdata.txt",ios::out | ios::app);
    string username,fname1,lname1,email1,phone1;

    while(fio>>username>>fname1>>lname1>>email1>>phone1)
    {


        if(username==get_user())
        {
            int n;
            line('=',120);
            cout<<"\t\t\t\t\tUpdate Profile\n"
            line('=',120);
           cout<<endl<<"\n\nWhat you want to update\n\n1.Contact\t\t3.Name\n";
           cout<<"\nINPUT:\t";
           cin>>n;
           system("CLS");
           if(n==1)
           {
               string phone;
               line('_',120);
               cout<<"\n\nEnter new contact:\t";
               cin>>phone;

                fout<<setw(20)<<username<<setw(10)<<fname1<<" "<<lname1<<setw(20)<<email1<<setw(15)<<phone<<"\n";
           }
           if(n==2)
           {
               string pass1,pass2;
               line('_',120);
               cout<<"\n\nFirst Name:\t";
               cin>>pass1;
               cout<<"\nLast Name:\t";
               cin>>pass2;
               fname1=pass1;
               lname1=pass2;
               fout<<setw(20)<<username<<setw(10)<<fname1<<" "<<lname1<<setw(20)<<email1<<setw(15)<<phone1<<"\n";
           }
        }
        else
        {
            fout<<setw(20)<<username<<setw(10)<<fname1<<" "<<lname1<<setw(20)<<email1<<setw(15)<<phone1<<"\n";
        }
    }
    fio.close();
    fout.close();
    remove("../customer/customerdata.txt");
    rename("tempdata.txt","../customer/customerdata.txt");
}

void customer::searchproduct()
{
    int x,y,w;

   TOP3:
       system("CLS");
       line('_',120);
            cout<<endl<<"\n\n1.Update Profile\t2.Search Products\n\nAny other key to return to login page\n";
            cin>>x;
            if(x==1)
            {
            updateprofile();

                cout<<"\n!!!!PROFILE UPDATED!!!!";
                goto TOP3;
            }
            if(x==2)
            {
                line('_',120);
                cout<<endl<<"\n\nWant to see\n 1.(all products)\n2.(specific category)\n";
                cout<<"\nINPUT:\t";
                    cin>>w;
                    if(w==1)
                    {
                         displaycategories("all");
                    }
                   if(w==2)
                   {
                       displaycategories("specific");
                   }
            }
            if(x==3)
            {
                cout<<"\n\nreturning to login page\n";
                line('_',120);
            }
}



void customer::placeorder()
{

    cout<<endl;
    cout<<"-------Shopping cart-------\n";
    cout<<endl;
     line('=',120);
    cout<<endl;
    string fil="../customer/"+username+"/"+username+"_shopping_cart.txt";

    fstream fio(fil.c_str(),ios::in);

    string id,name;
    double price;
    int quantity;
    bool flag=true;

    while(fio>>id>>name>>price>>quantity)
    {
        if(flag)
        {
             cout<<"Please review your order:\n";
                cout<<endl;
                line('_',120);
                cout<<endl;
                cout<<setw(80)<<"==YOUR ORDER=="<<endl;
                cout<<setw(15)<<"PRODUCT_ID"<<setw(40)<<"NAME"<<setw(15)<<"PRICE"<<setw(15)<<"QUANITY"<<endl;
            flag=false;
        }
        cout<<setw(15)<<id<<setw(40)<<name<<setw(15)<<price<<setw(15)<<quantity<<endl;
    }
    fio.close();
    if(flag)
    {
         cout<<"Your Shopping cart is empty\n\n";
         delay(500);
        return;
    }
     line('_',120);
     cout<<endl;
    int x;
    UP:

    cout<<"\nWant to proceed for checkout?\n1.YES\n2.delete items from shopping cart\n3.add items to shopping cart\n";
    cout<<"\nINPUT:\t";
    cin>>x;
    if(x==1)
    {
        system("CLS");
        string payment,slot;
        line('_',120);
        cout<<"\n\nAddress:\t";
        cin>>address;
        int w;
        cout<<"\nMode of payment:\n1.Cash on Delivery\n2.Online payment\n";
        cout<<"\nINPUT:\t";
        cin>>w;
        if(w==1)
        {
            payment="Cash_on_Delivery";
        }
        if(w==2)
        {
            payment="Online_Payment";
            onlinePayment();
        }
        int y;
        cout<<"\nDelivery Slot:\n1.9:00 AM to 2:00 PM\n2.5:00 PM to 10:00 PM\n";
        cout<<"\nINPUT:\t";
        cin>>y;
        if(y==1)
        {
            slot="9:00_AM_to_2:00_PM";
        }
        if(y==2)
        {
            slot="5:00_PM_to_10:00_PM";
        }
        //write_order
        int z;
        line('_',120);
        cout<<"\n\n1.Confirm order\t\t2.back\n";
        cout<<"\nINPUT:\t";
        cin>>z;
        string fil="../delivery/"+username+"_od.txt";

    fstream fio(fil.c_str(),ios::in);
        if(z==1)
        {
            system("CLS");
            line('=',120);
            cout<<"\n\n\t\t\t\tThank You for Shopping...\n\n"
            line('=',120);
            fio.open(fil.c_str(),ios::out);
            fio<<setw(30)<<address<<setw(30)<<payment<<setw(30)<<slot<<"\n";
            fio.close();
            fio.open("../delivery/orders_today.txt",ios::out);
            fio<<username<<endl;
            fio.close();
            fil="../customer/"+username+"/"+username+"_shopping_cart.txt";
            fio.open(fil.c_str(),ios::in);
            fio<<" ";
        }
        if(z==2)
        {
            goto UP;
        }

    }
    if(x==2)
    {
        string product1_id,product_id,product_name;
        double product_price;
        int product_quanity;
        cout<<"\nEnter the product_id of item to be deleted:\n";
        line('-',30);
        cout<<"\nINPUT:\t";
        cin>>product1_id;
        cout<<endl;
        line('-',30);
    string fil="../customer/"+username+"/"+username+"_shopping_cart.txt";

        fio.open(fil.c_str(),ios::out);
        fstream fio2("temp1.txt",ios::out);
        while(fio>>product_id>>product_name>>product_price>>product_quanity)
        {

            if(product1_id!=product_id)
            {
                fio2<<setw(15)<<product_id<<setw(30)<<product_name<<setw(15)<<product_price<<setw(15)<<product_quanity<<endl;
            }
        }
        fio.close();
        fio2.close();
         fil="../customer/"+username+"/"+username+"_shopping_cart"+".txt";

        remove(fil.c_str());
        rename("temp1.txt",fil.c_str());

        goto UP;
    }
    if(x==3)
    {
        searchproduct();
    }
}
