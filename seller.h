#include<bits/stdc++.h>
#include<fstream>

#include"admin.h"

using namespace std;
#define line(c,n); for(int i=0;i<n;i++) cout<<c

class seller{

    string email;
    string username;

    string contact;
    public:
         int maxid[8];
         int seller_id;
        seller();
        void initialize(admin ob2);

        string get_username()
        {
            return username;
        }
        int getproduct_id(int n)
        {
            return maxid[n]++;
        }
    void displayseller();
     void update();
};
seller::seller()
{
    for(int i=0;i<8;i++)
        maxid[i]=0;
}
void seller::initialize(admin ob2)
{
    username=ob2.username;
    fstream  fio("../seller/seller_user.txt",ios::in);
    string us;
    int id;
    while(fio>>us>>id)
    {
        if(username==us)
        {
            seller_id=id;
        }
    }
    fio.close();
    int x=0;
   string fil="../seller/"+username+"_data.txt";
   fio.open(fil.c_str(),ios::in);
   for(int i=1;i<8;i++)
   {
       int flag=1;
       if(fio.eof())
       {
           flag=0;
       }
       if(flag)
       {
           fio>>maxid[i];
       }
   }
   fio.close();
   system("CLS");
}
void seller::displayseller()
{

int flag=1;
    string product_id,product_name;
    double product_price;
    int product_quantity;

   fstream fio;
   string fil="../seller/"+get_username()+"/"+get_username()+"_mobiles.txt";

   fio.open(fil.c_str(),ios::in);
   cout<<setw(15)<<"PRODUCT_ID"<<setw(40)<<"NAME"<<setw(15)<<"PRICE"<<setw(15)<<"QUANTITY"<<endl;

    while(fio>>product_id>>product_name>>product_price>>product_quantity)
    {
        if(flag)
        {
            cout<<"MOBILES:\n\n";
            flag=0;
        }
        cout<<setw(15)<<product_id<<setw(30)<<product_name<<setw(15)<<product_price<<setw(15)<<product_quantity<<endl;
    }
    flag=1;
    fio.close();
    cout<<endl;
    fil="../seller/"+username+"/"+username+"_laptops.txt";

    fio.open(fil.c_str(),ios::in);

     while(fio>>product_id>>product_name>>product_price>>product_quantity)
    {
        if(flag)
        {
             cout<<"LAPTOPS:\n\n";
             flag=0;
        }
        cout<<setw(15)<<product_id<<setw(40)<<product_name<<setw(15)<<product_price<<setw(15)<<product_quantity<<endl;
    }
    flag=1;
    fio.close();
    cout<<endl;
    fil="../seller"+username+"/"+username+"_headphones.txt";

    fio.open(fil.c_str(),ios::in);

     while(fio>>product_id>>product_name>>product_price>>product_quantity)
    {
        if(flag)
        {
            cout<<"HEADPHONES & SPEAKERS:\n\n";
            flag=0;
        }
        cout<<setw(15)<<product_id<<setw(40)<<product_name<<setw(15)<<product_price<<setw(15)<<product_quantity<<endl;
    }
    flag=1;
    fio.close();
    cout<<endl;
    fil="../seller/"+username+"/"+username+"_daily_items.txt";

    fio.open(fil.c_str(),ios::in);

     while(fio>>product_id>>product_name>>product_price>>product_quantity)
            {
                if(flag)
                {
                cout<<"Daily Items:\n\n";
                flag=0;
                }
                cout<<setw(15)<<product_id<<setw(40)<<product_name<<setw(15)<<product_price<<setw(15)<<product_quantity<<endl;
            }
            flag=1;
    fio.close();
    cout<<endl;
    fil="../seller/"+username+"/"+username+"_eatables.txt";

    fio.open(fil.c_str(),ios::in);

     while(fio>>product_id>>product_name>>product_price>>product_quantity)
    {
        if(flag)
        {
            cout<<"EATABLES:\n\n";
            flag=0;
        }
        cout<<setw(15)<<product_id<<setw(40)<<product_name<<setw(15)<<product_price<<setw(15)<<product_quantity<<endl;
    }
    flag=1;
    fio.close();
    cout<<endl;
    fil="../seller/"+username+"/"+username+"_stationary.txt";

    fio.open(fil.c_str(),ios::in);

     while(fio>>product_id>>product_name>>product_price>>product_quantity)
    {
        if(flag)
        {
            cout<<"STATIONARY:\n\n";
            flag=0;
        }
        cout<<setw(15)<<product_id<<setw(40)<<product_name<<setw(15)<<product_price<<setw(15)<<product_quantity<<endl;
    }
    flag=1;
    fio.close();
    cout<<endl;
    fil="../seller/"+username+"/"+username+"_fruits.txt";

    fio.open(fil.c_str(),ios::in);

     while(fio>>product_id>>product_name>>product_price>>product_quantity)
    {
        if(flag)
        {
            cout<<"FRUITS & VEGETABLES:\n\n";
            flag=0;
        }
        cout<<setw(10)<<product_id<<setw(15)<<product_name<<setw(15)<<product_price<<setw(15)<<product_quantity<<endl;
    }
    fio.close();
    cout<<endl;
}
void seller::update()
{

     ostringstream st;
          st<<seller_id;
          string id=st.str();
    string product_id,product_name;
    double product_price;
    int product_quantity;
    line('=',120);
    cout<<endl;
    cout<<"\nSeller:  "<<username<<"\n";
line('=',120);
    cout<<endl;
    cout<<"\nYOUR PRODUCTS APPEAR HERE!!\n";
    EXIT:
   displayseller();
   cout<<endl;
   line('_',120);
   cout<<endl;
   cout<<"\n=> Enter the product id to update it\n=> Enter 'add' to add product to the store\n=> Enter 'view' to view products and sign out\n=> Enter 'exit' to sign out"<<endl;
   cout<<"\n\nINPUT:\t";
   cin>>product_id;
   if(product_id=="view")
   {
       line('_',120);
       cout<<endl;
       displayseller();
   }
  if(product_id=="exit")
  {
    system("CLS");
    system("COLOR A");
      cout<<"\n\nSigning you out...\n";
      line('_',120);
      delay(120);
      return;
  }

  if(product_id=="add")
  {
      START1:
          system("CLS");
      cout<<"\n\nWhat do you want to add:\n";
      line('-',60);
      cout<<"\n1.Mobile\n2.Laptops\n3.Headphones& Earphones\n";
      cout<<"4.Eatables\n5.Stationary\n6.Fruits & Vegetables\n7.Daily Items\n";
      line('-',60);
      int n;
      cout<<endl;
      cout<<"\nINPUT:\t";
      cin>>n;
      fstream fout;
system("CLS");
      if(n==1)
      {
          string fil="../seller/"+username+"/"+username+"_mobiles.txt";
          fout.open(fil.c_str(),ios::out | ios::app);

          string temp;
          ostringstream ss;
          ss<<maxid[n];
          temp=ss.str();
          maxid[n]++;
          product_id=id+".1."+temp;
          cout<<"\nMOBILES:\n";
          line('_',120);
          cout<<"\n\nProduct Name(without spaces):\t";
          cin>>product_name;

          cout<<"\nProduct_price:\t";
          cin>>product_price;
          cout<<"\nQuantity:\t";
          cin>>product_quantity;
          fout<<setw(15)<<product_id<<setw(40)<<product_name<<setw(15)<<product_price<<setw(15)<<product_quantity<<endl;
            cout<<"\nProduct successfully added!!\n\n";
            line('_',120);
          fout.close();
          fil="../seller"+username+"/"+username+"_data.txt";
          fout.open(fil.c_str(),ios::out);
          for(int i=1;i<8;i++)
            fout<<setw(5)<<maxid[i];
          fout.close();
            goto EXIT;
      }
      if(n==2)
      {

          string fil="../seller/"+username+"/"+get_username()+"_laptops.txt";
          fout.open(fil.c_str(),ios::out | ios::app);

          string temp;
          ostringstream ss;
          ss<<maxid[n];
          temp=ss.str();
            maxid[n]++;
          product_id=id+".2."+temp;

          cout<<"\nLAPTOPS:\n";
          line('_',120);
          cout<<"\n\nProduct Name(without spaces):\t";
          cin>>product_name;
          cout<<"\nProduct_price:\t";
          cin>>product_price;
          cout<<"\nQuantity:\t";
          cin>>product_quantity;
          fout<<setw(15)<<product_id<<setw(40)<<product_name<<setw(15)<<product_price<<setw(15)<<product_quantity<<endl;
            cout<<"\nProduct successfully added!!\n\n";
            line('_',120);
             fil="../seller/"+username+"/"+username+"_data.txt";
          fout.open(fil.c_str(),ios::out);
          for(int i=1;i<8;i++)
            fout<<setw(5)<<maxid[i];
          fout.close();
            goto EXIT;
      }
      if(n==3)
      {
          string fil="../seller/"+username+"/"+get_username()+"_headphones"+".txt";
          fout.open(fil.c_str(),ios::out | ios::app);

          string temp;
          ostringstream ss;
          ss<<maxid[n];
          temp=ss.str();
          maxid[n]++;
          product_id=id+".3."+temp;
          cout<<"\nHEADPHONES & SPEAKERS:\n";
          line('_',120);
          cout<<"\n\nProduct Name:\t";
          cin>>product_name;
          cout<<"\nProduct_price:\t";
          cin>>product_price;
          cout<<"\nQuantity:\t";
          cin>>product_quantity;
          fout<<setw(15)<<product_id<<setw(40)<<product_name<<setw(15)<<product_price<<setw(15)<<product_quantity<<endl;
            cout<<"\nProduct successfully added!!\n\n";
            line('_',120);
             fil="../seller/"+username+"/"+username+"_data.txt";
          fout.open(fil.c_str(),ios::out);
          for(int i=1;i<8;i++)
            fout<<setw(5)<<maxid[i];
          fout.close();
            goto EXIT;
      }
      if(n==4)
      {
          string fil="../seller/"+username+"/"+get_username()+"_eatables.txt";
          fout.open(fil.c_str(),ios::out | ios::app);

          string temp;
          ostringstream ss;
          ss<<maxid[n];
          maxid[n]++;
          temp=ss.str();
          product_id=id+".4."+temp;
          cout<<"\nEATABLES:\n";
          line('_',120);
          cout<<"\n\nProduct Name:\t";
          cin>>product_name;
          cout<<"\nProduct_price:\t";
          cin>>product_price;
          cout<<"\nQuantity:\t";
          cin>>product_quantity;
          fout<<setw(15)<<product_id<<setw(40)<<product_name<<setw(15)<<product_price<<setw(15)<<product_quantity<<endl;
           cout<<"\nProduct successfully added!!\n\n";
           line('_',120);
            fil="../seller/"+username+"/"+username+"_data.txt";
          fout.open(fil.c_str(),ios::out);
          for(int i=1;i<8;i++)
            fout<<setw(5)<<maxid[i];
          fout.close();
            goto EXIT;
      }
      if(n==5)
      {
          string fil="../seller/"+username+"/"+get_username()+"_stationary.txt";
          fout.open(fil.c_str(),ios::out | ios::app);

          string temp;
          ostringstream ss;
          ss<<maxid[n];
          maxid[n]++;
          temp=ss.str();
          product_id=id+".5."+temp;
          cout<<"\nSTATIONARY ITEMS:\n";
          line('_',120);
          cout<<"\n\nProduct Name:\t";
          cin>>product_name;
          cout<<"\nProduct_price:\t";
          cin>>product_price;
          cout<<"\nQuantity:\t";
          cin>>product_quantity;
          fout<<setw(15)<<product_id<<setw(40)<<product_name<<setw(15)<<product_price<<setw(15)<<product_quantity<<endl;

        cout<<"\nProduct successfully added!!\n\n";
        line('_',120);
         fil="../seller/"+username+"/"+username+"_data.txt";
          fout.open(fil.c_str(),ios::out);
          for(int i=1;i<8;i++)
            fout<<setw(5)<<maxid[i];
          fout.close();
        goto EXIT;
      }
      if(n==6)
      {
          string fil="../seller/"+username+"/"+get_username()+"_fruits"+".txt";
          fout.open(fil.c_str(),ios::out | ios::app);

          string temp;
          ostringstream ss;
          ss<<maxid[n];
          temp=ss.str();
          maxid[n]++;
          product_id=id+".6."+temp;
          cout<<"\nFruits and Vegetables:\n";
          line('_',120);
          cout<<"\n\nProduct Name:\t";
          cin>>product_name;
          cout<<"\nProduct_price:\t";
          cin>>product_price;
          cout<<"\nQuantity:\t";
          cin>>product_quantity;
          fout<<setw(15)<<product_id<<setw(40)<<product_name<<setw(15)<<product_price<<setw(15)<<product_quantity<<endl;
            cout<<"\nProduct successfully added!!\n\n";
            line('_',120);
             fil="../seller/"+username+"/"+username+"_data.txt";
          fout.open(fil.c_str(),ios::out);
          for(int i=1;i<8;i++)
            fout<<setw(5)<<maxid[i];
          fout.close();
            goto EXIT;
      }
      if(n==7)
      {
          string fil="../seller/"+username+"/"+get_username()+"_daily_items.txt";
          fout.open(fil.c_str(),ios::out | ios::app);

          string temp;
          ostringstream ss;
          ss<<maxid[n];
          temp=ss.str();
          maxid[n]++;
          product_id=id+".7."+temp;
          cout<<"\nDaily Items:\n";
          line('_',120);
          cout<<"\n\nProduct Name:\t";
          cin>>product_name;
          cout<<"\nProduct_price:\t";
          cin>>product_price;
          cout<<"\nQuantity:\t";
          cin>>product_quantity;
          fout<<setw(15)<<product_id<<setw(40)<<product_name<<setw(15)<<product_price<<setw(15)<<product_quantity<<endl;
            cout<<"\nProduct successfully added!!\n\n";
            line('_',120);
             fil="../seller/"+username+"/"+username+"_data.txt";
          fout.open(fil.c_str(),ios::out);
          for(int i=1;i<8;i++)
            fout<<setw(5)<<maxid[i];
          fout.close();
            goto EXIT;
      }
  }
/////update part
string product_id1;
if(product_id[2]=='1')
{

        string fil="../seller/"+username+"/"+username+"_mobiles.txt";
        fstream fio(fil.c_str(),ios::in);
        ofstream fout("temp.txt",ios::app);

        while(fio>>product_id1>>product_name>>product_price>>product_quantity)
        {
            if(product_id == product_id1)
            {
            double new_product_price;
            int new_product_quantity;
            line('_',120);
            cout<<"Updating "+product_id+"...\n";
            line('_',120);
            cout<<"\n\nProduct Price:\t";
            cin>>new_product_price;
            cout<<"\nQuantity:\t";
            cin>>new_product_quantity;
            cout<<"\n";
            line('_',120);
            fout<<setw(15)<<product_id<<setw(40)<<product_name<<setw(15)<<new_product_price<<setw(15)<<new_product_quantity<<"\n";
            }
            else
            {
            fout<<setw(15)<<product_id<<setw(40)<<product_name<<setw(15)<<product_price<<setw(15)<<product_quantity<<"\n";
            }

        fio.close();
        fout.close();
        remove(fil.c_str());
       rename("temp.txt",fil.c_str());
    }
    goto EXIT;
}

    if(product_id[2]=='2') {
    string fil="../seller/"+username+"/"+username+"_laptops.txt";
    fstream fio(fil.c_str(),ios::in);
    ofstream fout("temp.txt",ios::app);

     while(fio>>product_id1>>product_name>>product_price>>product_quantity)
    {
        if(product_id == product_id1) {
            double new_product_price;
            int new_product_quantity;
            line('_',120);
            cout<<"Updating "+product_id+"........\n";
            line('_',120);
            cout<<"\n\nProduct Price:\t";
            cin>>new_product_price;
            cout<<"\nQuantity:\t";
            cin>>new_product_quantity;
            cout<<"\n";
            line('_',120);
            fout<<setw(15)<<product_id<<setw(40)<<product_name<<setw(15)<<new_product_price<<setw(15)<<new_product_quantity<<"\n";
        }
        else {
            fout<<setw(15)<<product_id<<setw(40)<<product_name<<setw(15)<<product_price<<setw(15)<<product_quantity<<"\n";
        }

        fio.close();
        fout.close();
        remove(fil.c_str());
      rename("temp.txt",fil.c_str());
  }
  goto EXIT;
}

    if(product_id[2]=='3') {
    string fil="../seller/"+username+"/"+username+"_headphones.txt";
    fstream fio(fil.c_str(),ios::in);
    ofstream fout("temp.txt",ios::app);

     while(fio>>product_id1>>product_name>>product_price>>product_quantity)
    {
        if(product_id == product_id1)
        {
            double new_product_price;
            int new_product_quantity;
            line('_',120);
            cout<<"Updating "+product_id+"......\n";
            line('_',120);
            cout<<"\n\nProduct Price:\t";
            cin>>new_product_price;
            cout<<"\nQuantity:\t";
            cin>>new_product_quantity;
            cout<<"\n";
            line('_',120);
            fout<<setw(15)<<product_id<<setw(40)<<product_name<<setw(15)<<new_product_price<<setw(15)<<new_product_quantity<<"\n";
        }
        else
        {
            fout<<setw(15)<<product_id<<setw(40)<<product_name<<setw(15)<<product_price<<setw(15)<<product_quantity<<"\n";
        }

        fio.close();
        fout.close();
        remove(fil.c_str());
       rename("temp.txt",fil.c_str());
  } goto EXIT;
}

    if(product_id[2]=='4') {
    string fil="../seller/"+username+"/"+username+"_eatables.txt";
    fstream fio(fil.c_str(),ios::in);
    ofstream fout("temp.txt",ios::app);

     while(fio>>product_id1>>product_name>>product_price>>product_quantity)
    {
        if(product_id == product_id1) {
            double new_product_price;
            int new_product_quantity;
            line('_',120);
            cout<<"Updating "+product_id+"......\n";
            line('_',120);
            cout<<"\n\nProduct Price:\t";
            cin>>new_product_price;
            cout<<"\nQuantity:\t";
            cin>>new_product_quantity;
            cout<<"\n";
            line('_',120);
            fout<<setw(15)<<product_id<<setw(40)<<product_name<<setw(15)<<new_product_price<<setw(15)<<new_product_quantity<<"\n";
        }
        else {
            fout<<setw(15)<<product_id<<setw(40)<<product_name<<setw(15)<<product_price<<setw(15)<<product_quantity<<"\n";
        }

        fio.close();
        fout.close();
        remove(fil.c_str());
        rename("temp.txt",fil.c_str());
  }
   goto EXIT;
}

    if(product_id[2]=='5') {
    string fil="../seller/"+username+"/"+username+"_stationary.txt";
    fstream fio(fil.c_str(),ios::in);
    ofstream fout("temp.txt",ios::app);

     while(fio>>product_id1>>product_name>>product_price>>product_quantity)
    {
        if(product_id == product_id1) {
            double new_product_price;
            int new_product_quantity;
            line('_',120);
            cout<<"Updating "+product_id+"......\n";
            line('_',120);
            cout<<"\n\nProduct Price:\t";
            cin>>new_product_price;
            cout<<"\nQuantity:\t";
            cin>>new_product_quantity;
            cout<<"\n";
            line('_',120);
            fout<<setw(15)<<product_id<<setw(40)<<product_name<<setw(15)<<new_product_price<<setw(15)<<new_product_quantity<<"\n";
        }
        else {
            fout<<setw(15)<<product_id<<setw(40)<<product_name<<setw(15)<<product_price<<setw(15)<<product_quantity<<"\n";
        }

        fio.close();
        fout.close();
        remove(fil.c_str());
        rename("temp.txt",fil.c_str());
  }
   goto EXIT;
}

    if(product_id[2]=='6') {
    string fil="../seller/"+username+"/"+username+"_fruits.txt";
    fstream fio(fil.c_str(),ios::in);
    ofstream fout("temp.txt",ios::app);

     while(fio>>product_id1>>product_name>>product_price>>product_quantity)
    {
        if(product_id == product_id1) {
            double new_product_price;
            int new_product_quantity;
            line('_',120);
            cout<<"Updating "+product_id+".....\n";
            line('_',120);
            cout<<"\n\nProduct Price:\t";
            cin>>new_product_price;
            cout<<"\nQuantity:\t";
            cin>>new_product_quantity;
            cout<<"\n";
            line('_',120);
            fout<<setw(15)<<product_id<<setw(40)<<product_name<<setw(15)<<new_product_price<<setw(15)<<new_product_quantity<<"\n";
        }
        else {
            fout<<setw(15)<<product_id<<setw(40)<<product_name<<setw(15)<<product_price<<setw(15)<<product_quantity<<"\n";
        }

        fio.close();
        fout.close();
        remove(fil.c_str());
        rename("temp.txt",fil.c_str());
  }
   goto EXIT;
}

    if(product_id[2]=='7') {
    string fil="../seller/"+username+"/"+username+"_daily_items.txt";
    fstream fio(fil.c_str(),ios::in);
    ofstream fout("temp.txt",ios::app);

     while(fio>>product_id1>>product_name>>product_price>>product_quantity)
    {
        if(product_id == product_id1) {
            double new_product_price;
            int new_product_quantity;
            line('_',120);
            cout<<"Updating "+product_id+"....\n";
            line('_',120);
            cout<<"\n\nProduct Price:\t";
            cin>>new_product_price;
            cout<<"\nQuantity:\t";
            cin>>new_product_quantity;
            cout<<"\n";
            line('_',120);
            fout<<setw(15)<<product_id<<setw(40)<<product_name<<setw(15)<<new_product_price<<setw(15)<<new_product_quantity<<"\n";
        }
        else {
            fout<<setw(15)<<product_id<<setw(40)<<product_name<<setw(15)<<product_price<<setw(15)<<product_quantity<<"\n";
        }

        fio.close();
        fout.close();
        remove(fil.c_str());
        rename("temp.txt",fil.c_str());
  }
   goto EXIT;
}

line('=',120);
}
