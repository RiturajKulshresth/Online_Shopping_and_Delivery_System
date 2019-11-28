#include<bits/stdc++.h>
#include<fstream>

#include"shopping cart.h"

using namespace std;
#define line(c,n); for(int i=0;i<n;i++) cout<<c

class delivery{
public:
    void check_orders();
    void details();
};

void delivery::check_orders()
{
    fstream fio("../delivery/orders_today.txt",ios::in);
    string name;


    while(fio>>name)
    {
        system("CLS");
        cout<<"BY "<<name<<":\n";
          string fil="../customer/"+name+"/"+name+"_shopping_cart.txt";
        fstream fout(fil.c_str(),ios::in);
         string product_id,product_name;
         double product_price;
         int product_quantity;
         cout<<setw(15)<<"PRODUCT ID"<<setw(40)<<"NAME"<<setw(15)<<"PRICE"<<setw(15)<<"QUANITY"<<endl;
         line('_',120);
        while(fout>>product_id>>product_name>>product_price>>product_quantity)
        {
            cout<<setw(15)<<product_id<<setw(40)<<product_name<<setw(15)<<product_price<<setw(15)<<product_quantity<<endl;
        }
        fout.close();
        fil="../delivery/"+name+"_od.txt";

        fstream fout2(fil.c_str(),ios::in);
        string address,slot,pmode;
        double total_price;
        fout2>>address>>slot>>total_price>>pmode;
        cout<<setw(30)<<"ADDRESS"<<setw(30)<<"SLOT"<<setw(30)<<"TOTAL PRICE"<<setw(30)<<"MODE OF PAYMENT"<<endl;
        line('-',120);
        cout<<endl;
        cout<<setw(30)<<address<<setw(30)<<slot<<setw(30)<<total_price<<setw(30)<<pmode<<endl;
        fout2.close();
        int input;
        cout<<endl<<endl<<"Press Any Key for Next\n\n";
        cout<<"INPUT:\t";
        cin>>input;
    }
}
