#include<bits/stdc++.h>
#include<fstream>

#include"product.h"
#include"DISPLAY.h"
#include"payment.h"
#include"register.h"
#include"delivery.h"

using namespace std;

void signout()
{
    cout<<"Signing you out.....";
    delay(400);
}

//////////////////////////////////////////////////////DRIVER FUNCTION/////////////////////////////////////////////////////////////////////////////////////
int main()
{
    string name,password;
    char n,x,y,w,u;
        system("CLS");
        system("COLOR F0");

        string welcome="WELCOME TO SHOPPING MART , IIT JODHPUR";
        cout<<endl<<endl<<endl<<"\t\t\t";
        for(int i=0; i<welcome.size(); i++) {
            delay(100);
            cout<<welcome[i];
            if(i==7) {
                cout<<"\n\t\t\t\t\t";
            }
            if(i==10) {
                cout<<"\n\t\t\t\t\t\t";
            }
            if(i==19) {
                cout<<"\n\t\t\t\t\t\t\t\t";
            }
            if(i==26) {
                cout<<"\n\t\t\t\t\t\t\t\t\t";
            }
        }
        cout<<endl<<endl<<endl<<"\n\n\t\t\t\t\t\t";
        cout<<"LOADING ";
        for(int j=0; j<5; j++) {
            delay(500);
            cout<<".";
        }
    delay(2000);


WINDOW:
     system("CLS");
     system("COLOR F");
     cout<<endl;
     line('_',120);
     cout<<endl;
    cout<<"\n\nLOGIN OPTINS:\n";
    cout<<"1.Customer\t\t2.Delivery Agency\t\t3.Seller\t\t";
    cout<<"\n\n4.----REGISTER\n\n5.Exit"<<endl<<endl;
    cout<<"INPUT:\t";
    cin>>n;

    cout<<endl;
    user logindata;
    seller object2;
system("CLS");
////////////////////////////////////////////////////customer work/////////////////////////////////////////////////////////////////////////////////////////
    if(n=='1')
    {
        customer object;
        if(logindata.verifycustomer())
        {
            system("CLS");
             object.initialize(logindata);
             line('_',120);
             system("COLOR F");
            cout<<"\n\tWelcome "<<logindata.username<<"\n\nHere are options for your operations:\n";

            data1:
        cout<<endl;
            cout<<"\n1.Update Profile\n2.Search Products"<<endl<<endl;
            cout<<"INPUT:\t";
            cin>>x;
            cout<<endl;
        line('_',80);
        cout<<endl;
            if(x=='1')
            {
               system("CLS");
                object.updateprofile();
                goto data1;
            }
            if(x=='2')
            {
                cat:
                system("CLS");
                line('_',120);
                  cout<<"\n\nWant to see\n 1.(all products)\n 2.(specific category)\n\nAny other key to exit";
                  cout<<"\n\nINPUT:\t";
                    cin>>w;
                    if(w=='1')
                    {
                        int v;
                        system("CLS");
                           displaycategories("all");
                           cout<<"\n\n1. Buy the product\n2.Exit"<<endl;
                           cout<<"\nINPUT:\t";
                           cin>>v;
                           if(v=='1')
                           {
                                shoppingcart sayit;
                               string product_id;
                               int quanity;
                              // system("CLS");
                               cout<<"PRODUCT_ID:\t";
                               cin>>product_id;
                               cout<<endl;
                               cout<<"QUANITY:\t";
                               cin>>quanity;
                               sayit.additem(product_id,object.get_user(), quanity);
                               cout<<"Product successfully added to Shopping cart!!!";
                               delay(500);
                           }
                           system("CLS");

                            cout<<"\t\tWant to buy more\n1.YES\t2.NO";
                            cout<<"\n\nINPUT:\t";
                            cin>>u;
                          cout<<endl;
                           if(u=='1')
                           {
                               goto cat;
                           }
                           if(u=='2')
                           {
                               object.placeorder();
                               system("CLS");
                               cout<<"\n\nSomething you forgot?\n";
                               cout<<"Want to update or bye some more product\n\n";
                               cout<<"1.YES\t\t2.Sign Out\n";
                               char we;
                               cout<<endl<<"INPUT:\t";
                               cin>>we;
                               if(we=='1')
                                goto data1;
                               else
                               {
                                   signout();
                                   goto WINDOW;
                               }
                           }
                    }
                   if(w=='2')
                   {
                       char v;
                        displaycategories("specific");
                         cout<<"\n\n1.Buy the product\n2.Exit";
                         cout<<endl<<endl;
                         cout<<"INPUT:\t";
                           cin>>v;
                           cout<<endl;
                           if(v=='1')
                           {
                               string product_id;
                               int quanity;
                               cout<<"PRODUCT_ID:\t";
                               cin>>product_id;
                               cout<<endl<<"QUANTITY:\t";
                               cin>>quanity;
                               shoppingcart sayit;
                               sayit.additem(product_id,object.get_user(),quanity);
                           }
                           cout<<"\n\nWant to buy more\n1.YES\t\t2.Proceed for checkout";
                           cout<<"\nINPUT:\t";
                          cin>>u;
                           if(u=='1')
                           {
                               goto cat;

                           }
                           if(u=='2')
                           {
                                system("CLS");
                               object.placeorder();
                               system("CLS");
                               cout<<"\n\nSomething you forgot?\n";
                               cout<<"Want to update or bye some more product\n\n";
                               cout<<"1.YES\t\t2.Sign Out\n";
                               char we;
                               cout<<endl<<"INPUT:\t";
                               cin>>we;
                               if(we=='1')
                                goto data1;
                               else
                               {
                                   signout();
                                   goto WINDOW;
                               }
                           }
                   }
                   if(w=='3')
                   {
                        goto data1;
                   }
            }

        }
        else
        {
            system("CLS");
            cout<<"\n\n\t\t\t**Unrecognized Username or Password**";
            cout<<"\n\n\t\tReturning to Login page............";
            delay(1000);
            system("CLS");
             goto WINDOW;
        }
    }
/////////////////////////////////////////////////////////customer end/////////////////////////////////////////////////////////////////////////////////////

    if(n=='2')
    {
        admin ob2;
        del:
            system("CLS");
        string username,password;
        cout<<"\nUSERNAME:\t";
        cin>>username;
        cout<<"\n\nPassword:\t";
        cin>>password;
        if(ob2.verify_delivery_agency(username,password))
        {
            system("CLS");
            cout<<"\n\nTODAY'S ORDERS ARE:\n";
            delivery ob3;
            ob3.check_orders();
        }
        else
        {
              system("CLS");
              line('_',120);
           cout<<"\n\n**Unrecognized Username or Password** ,Please try again";
           goto del;
        }
    }
/////////////////////////////////////////////////////////SELLER WORK///////////////////////////////////////////////////////////////////////////////////////
    if(n=='3')
    {
        LOGIN:
        admin ob2;
       if(ob2.verifyseller())
       {
           seller object2;
           object2.initialize(ob2);


            object2.update();
       }
       else
       {
           system("CLS");
           line('_',120);
           cout<<"\n\n**Unrecognized Username or Password** ,Please try again\n\nIf not registered yet, then proceed for registration\n";
           cout<<"\n1.Register\t\t2.Log in";
           cout<<endl<<"INPUT:\t";
           cin>>x;
           cout<<endl;
           if(x=='1')
           {
               goto REGISTER;
           }
          if(x=='2')
            {
                goto LOGIN;
            }
       }
    }
//////////////////////////////////////////////////////SELLER END///////////////////////////////////////////////////////////////////////////////////////////

////////////////////////////////////////////////////REGISTRATION PROCESS///////////////////////////////////////////////////////////////////////////////////
    if(n=='4')
    {

        REGISTER:
            system("CLS");
        line('=',120);
        cout<<"\n\t\t\t\t\tRegistration Portal\n"
        line('=',120);
        cout<<"\nRegister as:\n\n1.Customer\n2.Seller\n\nAny other key to exit\n";
        cout<<"INPUT:\t";
        cin>>x;
        registeruser object3;
        if(x=='1')
        {
            object3.registercustomer();
            goto WINDOW;
        }
        if(x=='2')
        {
            object3.registerseller();
            goto WINDOW;
        }
        if(x!='1' && x!='2')
        {
            cout<<"\n\nLeaving Registration portal....\n";
            line('_',120);

            goto WINDOW;
        }
    }
/////////////////////////////////////////////////REGISTRATION END//////////////////////////////////////////////////////////////////////////////////////////

////////////////////////////////////////////////EXIT??????????????????????????????????????????????????????????????????????????????????????????????????????
    if(n=='5')
    {
        system("CLS");
        cout<<"EXITING THE SHOPPING MART....."<<endl<<endl;
        delay(500);
        return 0;
    }
    if(n!='1' && n!='2' && n!='3' && n!='4' && n!='5')
    {
        system("CLS");
        cout<<"\nINVALID INPUT\n";
        line('_',120);
        delay(1000);
        goto WINDOW;
    }
return 0;
}

/////////////////////////////////////////////////////////////MAIN FUNCTION END/////////////////////////////////////////////////////////////////////////////

