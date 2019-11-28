#include<bits/stdc++.h>
#include<fstream>

#include"customer.h"
#include"seller.h"

using namespace std;
#define line(c,n); for(int i=0;i<n;i++) cout<<c

class shoppingcart{
    string productid;
    int quantity;
    string deliveryslot;
    double price;
    public:
      void additem(string product_id,string username,int quantity);
      void viewshopping_cart(string username);
};

product convert(string product_id)
{
    product object;
    string sellerid;
    unsigned int i=0;

    while(product_id[i]!='.')
    {
        sellerid+=product_id[i];
        i++;
    }

     string sid,sname,fname,lname,email,phone;

    fstream fio("../seller/sellerdata.txt",ios::in);
    while(fio>>sid>>sname>>fname>>lname>>email>>phone)
    {
        if(sid==sellerid)
            break;
    }
    fio.close();
    string types;
    i++;
    while(product_id[i]!='.')
    {
        types+=product_id[i];
        i++;
    }
     int type = 0;

    stringstream geek(types);
    geek >> type;

    string pid,product_name;
    double product_price;
    int product_quantity;


    if(type==1)
    {
        string fil="../seller/"+sname+"/"+sname+"_mobiles.txt";

        fio.open(fil.c_str(),ios::in);
        while(fio>>pid>>product_name>>product_price>>product_quantity)
        {
            if(pid==product_id)
            {
                object.id=product_id;
                object.name=product_name;
                object.price=product_price;
                object.quantity=product_quantity;
                break;
            }
        }
    }

    if(type==2)
    {
        string fil="../seller/"+sname+"/"+sname+"_laptops.txt";

        fio.open(fil.c_str(),ios::in);
        while(fio>>pid>>product_name>>product_price>>product_quantity)
        {
            if(pid==product_id)
            {
                object.id=product_id;
                object.name=product_name;
                object.price=product_price;
                object.quantity=product_quantity;
                break;

            }
        }
    }
    if(type==3)
    {
        string fil="../seller/"+sname+"/"+sname+"_headphones.txt";

        fio.open(fil.c_str(),ios::in);
        while(fio>>pid>>product_name>>product_price>>product_quantity)
        {
            if(pid==product_id)
            {
                object.id=product_id;
                object.name=product_name;
                object.price=product_price;
                object.quantity=product_quantity;
                break;

            }
        }
    }
    if(type==4)
    {
        string fil="../seller/"+sname+"/"+sname+"_daily_items.txt";

        fio.open(fil.c_str(),ios::in);
        while(fio>>pid>>product_name>>product_price>>product_quantity)
        {
            if(pid==product_id)
            {
                object.id=product_id;
                object.name=product_name;
                object.price=product_price;
                object.quantity=product_quantity;
                break;

            }
        }
    }
    if(type==5)
    {
        string fil="../seller/"+sname+"/"+sname+"_eatables.txt";

        fio.open(fil.c_str(),ios::in);
        while(fio>>pid>>product_name>>product_price>>product_quantity)
        {
            if(pid==product_id)
            {
                object.id=product_id;
                object.name=product_name;
                object.price=product_price;
                object.quantity=product_quantity;
                break;

            }
        }
    }
    if(type==6)
    {
        string fil="../seller/"+sname+"/"+sname+"_stationary.txt";

        fio.open(fil.c_str(),ios::in);
        while(fio>>pid>>product_name>>product_price>>product_quantity)
        {
            if(pid==product_id)
            {
                object.id=product_id;
                object.name=product_name;
                object.price=product_price;
                object.quantity=product_quantity;
                break;

            }
        }
    }
    if(type==7)
    {
        string fil="../seller/"+sname+"/"+sname+"_fruits.txt";

        fio.open(fil.c_str(),ios::in);
        while(fio>>pid>>product_name>>product_price>>product_quantity)
        {
            if(pid==product_id)
            {
                object.id=product_id;
                object.name=product_name;
                object.price=product_price;
                object.quantity=product_quantity;
                break;

            }
        }
    }
    return object;
}
void shoppingcart::additem(string product_id,string username,int quanity)
{
    string fil="../customer/"+username+"/"+username+"_shopping_cart.txt";

    product object=convert(product_id);

    fstream fout(fil.c_str(),ios::out|ios::app);

    fout<<setw(15)<<object.id<<setw(40)<<object.name<<setw(15)<<object.price<<setw(15)<<quanity<<endl;
    fout.close();
}

void shoppingcart::viewshopping_cart(string username)
{
    string fil="../customer/"+username+"/"+username+"_shopping_cart.txt";

    string product_id,product_name;
    double product_price;
    int product_quantity;
    fstream fout(fil.c_str(),ios::in);
    cout<<setw(15)<<"PRODUCT ID"<<setw(40)<<"NAME"<<setw(15)<<"PRICE"<<setw(15)<<"QUANITY"<<endl;
    while(fout>>product_id>>product_name>>product_price>>product_quantity)
    {
        cout<<setw(15)<<product_id<<setw(40)<<product_name<<setw(15)<<product_price<<setw(15)<<product_quantity<<endl;
    }
    fout.close();
}
