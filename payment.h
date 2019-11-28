#include<bits/stdc++.h>
#include<fstream>

using namespace std;
#define line(c,n); for(int i=0;i<n;i++) cout<<c

void delay(unsigned int mseconds)
{
    clock_t goal = mseconds + clock();
    while (goal > clock());
}

void onlinePayment()
{
    system("CLS");
    line('=',120);
    cout<<endl<<endl;
    cout<<"\t\t\tOnline Payment Portal\n";
    cout<<endl;
    line('=',120);
    string cardNo;
    string cardFName, cardLName;
    int cvv;
    int exp_mon, exp_year;

    cout<<"Please enter your card details below\n";
    cout<<endl;
CARD:
    cout<<"\nCard Number:\t";
    cin>>cardNo;
    if(cardNo.size() != 16) {
        cout<<"Please enter a valid Card Number\n";
        goto CARD;
    }
    cout<<"\nName on the Card:\n\t\tFirst Name:\t";
    cin>>cardFName;
    cout<<"\n\t\tLast Name:\t";
    cin>>cardLName;
DATE:
    cout<<"\nExpiry Date:\n\t\tMonth:\t";
    cin>>exp_mon;
    if(exp_mon>12) {
        cout<<"\t\tINVALID.. Please enter again";
        goto DATE;
    }
    cout<<"\n\t\tYear:\t";
    cin>>exp_year;
CODE:
    cout<<"\nCVV:\t";
    cin>>cvv;
    if(!(cvv>99 &&cvv<1000)) {
        cout<<"\tINVALID...Please enter again";
        goto CODE;
    }
    cout<<endl;
    line('_',120);
    system("CLS");
    cout<<"Payment Processing......";
    delay(2000);
    cout<<"\n\n--- Payment Successful ---";
    cout<<endl<<endl;
}

