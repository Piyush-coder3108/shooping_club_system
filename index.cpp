//#include<iostream>
#include<windows.h>
//#include<fstream>
#include<conio.h>
//#include<string>
#include<bits/stdc++.h>
//#include<list>
//#include<unordered_map>
#include"shoplist.h"
#include"shoppath.h"
using namespace std;
void startpage();
vector<pair<int,pair<string,int>>> product;
queue<string> customer_bill;

int customer=1;
string enterpassword();
bool login();
bool login2();
string username;

string returnshop(string a[],int size){
for(int i=0; i<size; i++)
        {   if(i<10)
            cout<<"0"<<i<<" ). "<<a[i]<<endl;
            else
            cout<<i<<" ). "<<a[i]<<endl;
        }
    cout<<"Enter your choice: ";
    int choice;
    cin>>choice;
    string s=a[choice];
   return s;
}
void add_product(){
product.push_back(make_pair(101,make_pair("Lifebuoy",20)));
product.push_back(make_pair(102,make_pair("Lux",10)));
product.push_back(make_pair(103,make_pair("Oats",30)));
product.push_back(make_pair(104,make_pair("No.1",20)));
product.push_back(make_pair(105,make_pair("Colgate",20)));
product.push_back(make_pair(106,make_pair("Comb",10)));
product.push_back(make_pair(107,make_pair("Pepsodent",40)));
product.push_back(make_pair(108,make_pair("Eggs",40)));
product.push_back(make_pair(109,make_pair("Cake",500)));
product.push_back(make_pair(110,make_pair("Pastry",25)));


}

void wallet_func();

class wallet
{
    int balance;
    string name,email,mobile_no;

public:
    void newregistration(string n,string mail,string mobile)
    {
        name=n;
        email=mail;
        mobile_no=mobile;
        fstream f;
        f.open("wallets.txt",ios::app);
        f<<username<<"  "<<name<<"  "<<email<<"   "<<mobile_no<<endl;
        f.close();
        balance=0;
        ofstream newf;
        newf.open(username+"_wallet.txt");
        newf<<"Balance: 0                 "<<endl;
        newf<<"Previous Transactions are: ";
        newf.close();
    }

    void payment(){
    cout<<"Which mode you would like to choose: "<<endl;
    cout<<"1.) Credit card"<<endl;
    cout<<"2.) Debit card"<<endl;
    cout<<"3.) UPI"<<endl;
    int choice;
    cout<<"Enter your choice: ";
    cin>>choice;
    cout<<endl;
    do{
    switch(choice){
    case 1: {
    cout<<"Enter card number: ";
    string n;
    cin>>n;
    cout<<endl;
    cout<<"Enter expiration month: ";
    int m;
    cin>>m;
    cout<<endl;
    cout<<"Enter expiration Year: ";
    int y;
    cin>>y;
    cout<<endl;
    cout<<"Enter security code: ";
    int c;
    cin>>c;
    cout<<endl;
    break;}
    case 2: {cout<<"Enter card number: ";
    string n1;
    cin>>n1;
    cout<<endl;
    cout<<"Enter expiration month: ";
    int m1;
    cin>>m1;
    cout<<endl;
    cout<<"Enter expiration Year: ";
    int y1;
    cin>>y1;
    cout<<endl;
    cout<<"Enter security code: ";
    int c1;
    cin>>c1;
    cout<<endl;
    break;
    }
    case 3: {cout<<"Enter UPI id: ";
    string upi;
    cin>>upi;
    break;}
    default: cout<<"Choose correct option!!!!!"<<endl;
    }
    }while(choice>=4);
    }

    string wallet_handler(int bal){
        string s;
        string b=to_string(bal);
    int count=0;
    if(bal==0){
        s="Balance: "+b+"       ";
        return s;
    }
    while(bal>0){
        bal=bal/10;
        count++;
    }
    if(count==1){
    s="Balance: "+b+"       ";
    }
    else if(count==2){
        s="Balance: "+b+"      ";
    }
    else if(count==3){
        s="Balance: "+b+"     ";
    }

    else if(count==4){
        s="Balance: "+b+"    ";
    }
    else if(count==5){
        s="Balance: "+b+"   ";
    }
    else if(count==6){
        s="Balance: "+b+"  ";
    }
    else if(count==7){
        s="Balance: "+b+" ";
    }
    else{
        s="Balance: "+b;
    }

    return s;

    }

    void addmoney(int money)
    {
        if(money>0)
        {    payment();
            fstream fin;
            fin.open(username+"_wallet.txt");
            string u,v;
            fin>>u>>v;
            int balance= stoi(v);
            fin.close();
            fstream fout;
            fout.open(username+"_wallet.txt");
            balance+=money;
            string a=wallet_handler(balance);
            fout<<a;
            fout.seekg(0,ios::end);
            fout<<"+"<<money<<" ";
            fout.close();
            cout<<"\tMoney added successfully!!!!!"<<endl;
            wallet_func();
        }
        else
        {
            cout<<"!!!!!!-------Sorry! please fill a valid entry--------!!!!!!!!"<<endl;
            wallet_func();
        }
    }
    void withdraw(int money)
    {
        fstream fin;
        fin.open(username+"_wallet.txt");
        string u,v;
        fin>>u>>v;
        int balance= stoi(v);
        fin.close();
        if(balance-money>=0)
        {
            fstream fout;
            fout.open(username+"_wallet.txt");
            balance-=money;
            string a=wallet_handler(balance);
            fout<<a;
            fout.seekg(0,ios::end);
            fout<<"-"<<money<<" ";
            fout.close();
            cout<<"You have successfully paid for your bill!!!!!"<<endl;
            wallet_func();
        }
        else{
            cout<<"!!!!!--------Sorry!! Insufficient balance------!!!!!"<<endl;
            wallet_func();
        }

    }
    int checkbalance()
    {
        fstream fin;
        fin.open(username+"_wallet.txt");
        string u,v;
        fin>>u>>v;
        int balance= stoi(v);
        fin.close();
        return balance;
    }

    void print_previoustransaction()
    {
        fstream f;
        f.open(username+"_wallet.txt");
        string ux,vx;
        getline(f,ux);
        getline(f,vx);
        cout<<vx;
        f.close();

    }
};

void wallet_func(){
wallet w1;
            ifstream fin(username+"_wallet.txt");
            if(fin)
            {   wal: cout<<endl<<"Welcome "<<username<<" to your Wallet"<<endl<<endl;
                cout<<"1). Add money"<<endl;
                cout<<"2). View previous transaction"<<endl;
                cout<<"3). Want to pay"<<endl;
                cout<<"Enter your choice: ";
                int wc;
                cin>>wc;
                switch(wc){

              case 1:
                cout<<"Enter amount you want to add to your wallet: ";
                int m;
                cin>>m;
                w1.addmoney(m);
                break;
              case 2:
                w1.print_previoustransaction();
                cout<<"\n\n";
                cout<<"Note: (+) means money is credited and (-) means money is debited"<<endl;
                break;
              case 3: {cout<<"Enter your mobile number: ";
                   string customer_phoneno;
                   cin>>customer_phoneno;
                   ifstream f;
                    f.open(customer_phoneno+".txt");
                    string line;
                    while(f){
                    getline(f,line);
                        if(line=="-1")
                            break;
                        cout<<line<<endl;
                        }
                  f.close();
                  int a;
                 cout<<"Enter amount You want to pay: ";
                 cin>>a;
                   w1.withdraw(a);

              break;
                }
              default:
                cout<<"Please choose valid options!!!!!"<<endl;
                goto wal;

                }

            }
            else{
                cout<<"Sorry!!!!!!! you have not registered yourself to avail wallet benefits "<<endl<<endl<<endl;
                cout<<"1). Want to register for a wallet"<<endl;
                int c;
                cin>>c;
                if(c==1){
                string name,email,mobile;
                cout<<"Enter your name: ";
                cin.ignore();
                getline(cin,name);
                cout<<endl;
                cout<<"Enter your email id: ";
                //cin.ignore();
                getline(cin,email);
                cout<<endl;
                cout<<"Enter your mobile number: ";
                //cin.ignore();
                getline(cin,mobile);
                cout<<endl;
                wallet w;
                w.newregistration(name,email,mobile);
                 startpage();
                }
            }

}


void admin(){

a: cout<<"\n\t\t\t\t1.) Add a product"<<endl;
cout<<"\t\t\t\t2.) Want to see customers queue"<<endl;
cout<<"\t\t\t\t3.) Register an employee(billing counter employee)"<<endl;
cout<<"\t\t\t\t4.) Exit from software";
int c;
cout<<"\t\t\t\t    Enter your choice: ";
cin>>c;
if(c==1){int id,price;
    string name;
        cout<<"\n\t\t\t\t\t Enter product id : ";
        cin>>id;
        cout<<"\n\t\t\t\t\t Enter product name : ";
        cin.ignore();
        getline(cin,name);
        cout<<"\n\t\t\t\t\t Enter product price : ";
        cin>>price;
        product.push_back(make_pair(id,make_pair(name,price)));
        cout<<"\n\t\t\t\t\t Product is successfully added!!!!!"<<endl;
}
else if(c==2){
    queue<string> qu= customer_bill;
    while(!qu.empty()){
        cout<<qu.front()<<endl;
        qu.pop();
    }


}
else if(c==3){
        cout<<"\n\t\t\t--------- Employee Registration--------"<<endl;
    cout<<"\n\t\t\t\t Enter username of employee: ";
    cin>>username;
cout<<endl;
    cout<<"\n\t\t\t\t Enter password: ";
    string pass=enterpassword();
    cout<<"\n\t\t\t\t Enter name of employee: ";
    string name;
    cin.ignore();
    getline(cin,name);
    cout<<"\n\t\t\t\t Enter employee id: ";
    int id;
    cin>>id;
    fstream f;
    f.open(username+"_employee.txt", ios::app);
    f<<username<<endl<<pass<<endl<<name<<endl<<id;
    f.close();

}
else{
    cout<<endl<<"Please enter valid choice!!!!!"<<endl;
    goto a;

}

}
void generate_bill();

void employee(){
cout<<"\t\t\t\t Login (for employees who are at billing counter"<<endl;

        bool success=login2();
        if(!success)
        {
            system("COLOR FC");
            cout<<"\n Sorry!!!!!!!! Login is unsuccessful !!!!!!!!!\n";
            cout<<"############Try to Login again###########\n";
            Sleep(2000);
            system("cls");
            employee();
        }
        else
        {
            system("COLOR F2");
            cout<<"\n!!!!Welcome to billing system , You have been successfully logged in!!!!!\n";
            Sleep(2000);
            system("cls");
            generate_bill();
        }



}

void waiting_func(){
system("cls");
cout<<"\n\n\n\n\n\n\t\t\t\t\t Waiting for customer...................\n\n\n\n\n\n\n\n\n\n"<<endl;
system("pause");
system("cls");
generate_bill();
}

void generate_bill()
{   list<pair<string,pair<int,int>>> v;
   int total_amount=0;
   int q;
    while(true)
    {
        int id;
        cout<<"Enter product id: ";
        cin>>id;
        cout<<"Enter product quantity: ";
        cin>>q;
        int i=0;
        while(true){
        if(product[i].first==id){
        int x=product[i].second.second;
        total_amount+=x*q;
         v.push_back(make_pair(product[i].second.first,make_pair(x,q)));
        break;
    }
    i++;
}
        cout<<endl;
        cout<<"Do you want to enter more product (y/n) : ";
        char c;
        cin>>c;
        if(c=='n')
            break;
        cout<<endl;
    }
    cout<<"Enter Customer mobile number: ";
    string mobile;
    cin>>mobile;
    fstream f;
        f.open(mobile+".txt",ios::app);
        for(auto nbr: v){
            f<<nbr.first<<"         Price per piece: "<<nbr.second.first<<"          Quantity: "<<nbr.second.second<<endl;
        }
        f<<"Total amount You have to pay: "<<total_amount<<endl;
        f.close();
    customer_bill.push(mobile);
    cout<<endl;
    cout<<"Total amount customer has to pay: "<<total_amount<<endl;
    cout<<"Successfully generated customer bill!!!!"<<endl;
    cout<<"Want to generate new bill for customer(y/n) : "<<endl;
    char c;
    cin>>c;
    if(c=='y'){
        generate_bill();
    }
    else{
        waiting_func();
    }

}

void startpage()
{
    system("COLOR F0");
    cout<<"     \n\n\n+++++++++++++++++++++++++++++++++++++++++++|  WELCOME TO OUR MALL   |++++++++++++++++++++++++++++++++++++++++++ \n\n\n ";
    cout<<"\n\n\n\n";
    cout<<"Loading required files...!!!!"<<endl;
    Sleep(2000);

    int choice;
    cout<<"\t\t 1.Admin\n";
    cout<<"\t\t 2.Employee \n";
    cout<<"\t\t 3.Customer \n";
    cout<<"\t\t 4.Wallet \n";
    cout<<"\t\t Note: For using our Mall's wallet you must register yourself and login \n";
    cout<<"\t\t Enter Your choice : ";
    cin>>choice;
    if(choice==1)
    {
        bool success=login();
        if(!success)
        {
            system("COLOR FC");
            cout<<"\n Sorry!!!!!!!! Login is unsuccessful !!!!!!!!!\n";
            cout<<"############Try to Login again###########\n";
            Sleep(2000);
            system("cls");
            startpage();
        }
        else
        {
            system("COLOR F2");
            cout<<"\n!!!!Welcome to our system , You have been successfully logged in!!!!!\n";
            Sleep(2000);
            system("cls");
            admin();
        }
    }
    else if(choice==2)
    {
            employee();

    }
    else if(choice==3)
    {
        cout<<endl<<endl;
        cout<<"1. Want to get the path to your destination\n";
        cout<<"2. Want to know about the shops\n";
        cout<<"Enter your choice: ";
        int c;
        cin>>c;
     system("COLOR 60");
        if(c==1)
        {
            string ground[26]= {"ENTRY GATE","WASHROOM-G1","WASHROOM-G2","ASCENDING STAIRS FOR FIRST FLOOR (NO.1)","ASCENDING STAIRS FOR FIRST FLOOR (NO.2)","ADIDAS","NIKE","PUMA","KAMA","KAYA","SAMSUNG","OPPO","VIP","LENSKART.COM",
    "FOSSIL","BEAU MORDE","BATA","DUNE","STARBUCKS","HALDIRAM","THE BEAR CAFE","MIA","BLUESTONE","HELIOS","CARAT LANE","DANIEL WELLINGTON"};

    string first[24]={"WASHROOM-F1","WASHROOM-F2","ASCENDING STAIRS FOR SECOND FLOOR (NO.1)","ASCENDING STAIRS FOR SECOND FLOOR (NO.2)","DESCENDING STAIRS FOR GROUND FLOOR (NO.1)","DESCENDING STAIRS FOR GROUND FLOOR (NO.2)","JOCKEY","CALVIN KLEIN","LOUIS PHILIPPE","ZARA","BIBA","BURGER KING","SUBWAY","MCDONALDS","DOMINOS","KFC","PIZZA HUT","WOW MOMO","DOSA VILLAGE","REEBOK",
    "SPEEDO","JACK & JONES","ONE PLUS","APPLE"};

    string second[24]={"WASHROOM-S1","WASHROOM-S2","ASCENDING STAIRS FOR THIRD FLOOR (NO.1)","ASCENDING STAIRS FOR THIRD FLOOR (NO.2)","DESCENDING STAIRS FOR FIRST FLOOR (NO.1)","DESCENDING STAIRS FOR FIRST FLOOR (NO.2)","NYKAA","KIKO","IHOP","HONEY & DOUGH","HOMECENTRE","MAX","MARKET 99",
    "SPAR","LIFESTYLE","ARROW","OCTAVE","AURELIA","MOTHER CARE","ICONIC KIDS","METRO","NEEDLE DUST","PURE","BIRYANI BLUES"};

    string third[13] = {"WASHROOM-T1","ASCENDING STAIRS FOR FOURTH FLOOR (NO.1)","ASCENDING STAIRS FOR FOURTH FLOOR (NO.2)","DESCENDING STAIRS FOR SECOND FLOOR (NO.1)","DESCENDING STAIRS FOR SECOND FLOOR (NO.2)","CHUMBAK","DELHI HEIGHTS","CASTLE BARBEQUE","SAMIYOSA","CHAAYOS","MAC","OZONE","INNIFREE"};

    string fourth[10] = {"WASHROOM-FF1","DESCENDING STAIRS FOR THIRD FLOOR (NO.1)","DESCENDING STAIRS FOR THIRD FLOOR (NO.2)","CRAFT STUDIO INDIA","DECATHLON","BERCO'S","HOMECENTRE","PVR","LOCK & LOAD","OCTAVE"};

    cout<<"\t\t\tChoose in which floor you are standing"<<endl;

    string cat[15]={"ENTRY GATE","HYPERMARKET","ELECTRONICS","SPORTS","FOOTWEAR","APPARELS","JEWELLERY & WATCHES","BEAUTY & PERSONAL CARE","HOME DECOR","MULTI BRAND","BAGS & ACCESSORIES","ENTERTAINMENT","RESTAURANT"
        ,"FOOD COURT","CAFE & QUICK BITES"};
    cout<<"\t\t\t 1). Ground Floor"<<endl;
    cout<<"\t\t\t 2). First Floor"<<endl;
    cout<<"\t\t\t 3). Second Floor"<<endl;
    cout<<"\t\t\t 4). Third Floor"<<endl;
    cout<<"\t\t\t 5). Fourth Floor"<<endl<<endl<<endl;
    int choice;
    cout<<"Enter your choice: "<<endl;
    cin>>choice;
    system("cls");
    string src;
    switch(choice)
    {
    case 1: {src =returnshop(ground,26);
            cout<<"You have choosed: "<<src;
        break;
    }

    case 2: {
      src= returnshop(first,24);
      cout<<"You have choosed: "<<src;
      break;
    }
    case 3: {
    src=returnshop(second,24);
    cout<<"You have choosed: "<<src;
      break;
    }
    case 4:{
    src=returnshop(third,13);
    cout<<"You have choosed: "<<src;
      break;
    }

    case 5:{
    src=returnshop(fourth,11);
    cout<<"You have choosed: "<<src;
      break;
    }
    default:
        cout<<"Please choose given options!!!!!";

    }

    system("cls");
    cout<<"---------------------------------------|     Choose in which shop you would like to go      | ---------------------------------------- "<<endl;
    cout<<"Choose shop category: "<<endl;
    string c=returnshop(cat,15);
    cout<<c;
    printpath p;
    if(c=="ENTRY GATE"){
        p.printyourpath(src,"ENTRY GATE");
    }
    else{
    string des;
    system("cls");
    printshoplist l;
    l.show_shop_per_cat(c);
    cout<<"\n\n Enter your choice: ";
    int shop;
    cin>>shop;

    system("cls");
    des= l.return_shop(c,shop);
    p.printyourpath(src,des);
    }

        }

        else
        {   printshoplist p;
            b: cout<<"1.Display all shops of all categories \n";
            cout<<"2.Display all categories whose shops are present \n";
            cout<<"3.Display shops of particular category \n";
            int entchoice;
            cin>>entchoice;
            if(entchoice==1)
            {
                cout<<"Shops are: "<<endl;
                p.showshops();}
            else if(entchoice==2){
                cout<<"Following categories shops are: "<<endl;
                p.showcat();
                Sleep(4000);
                goto b;
            }
            else if(entchoice==3){
              a:  p.showcat();
                int n;
                cin>>n;
                string s;
                switch(n){
                case 1: s="HYPERMARKET"; break;
                case 2: s="ELECTRONICS"; break;
                case 3: s="SPORTS"; break;
                case 4: s="FOOTWEAR"; break;
                case 5: s="APPARELS"; break;
                case 6: s="JEWELLERY & WATCHES"; break;
                case 7: s="BEAUTY & PERSONAL CARE"; break;
                case 8: s="HOME DECOR"; break;
                case 9: s="MULTI BRAND"; break;
                case 10: s="BAGS & ACCESSORIES"; break;
                case 11: s="ENTERTAINMENT"; break;
                case 12: s="RESTAURANT"; break;
                case 13: s="FOOD COURT"; break;
                case 14: s="CAFE & QUICK BITES"; break;
                default: cout<<"Please choose correct category"<<endl;
                        goto a;
                }
                p.show_shop_per_cat(s);
            }
            else{
                cout<<"Please choose correct options!!!!!";
            }




        }


    }
    else if(choice==4){
        cout<<endl<<"1) Login "<<endl;
        cout<<"2) Register "<<endl;
        cout<<"Enter your choice: ";
        int n;
        cin>>n;

        if(n==1){
        bool success= login();
        wallet_func();}
        else{
            string name,email,mobile;
                cout<<"Enter your name: ";
                cin.ignore();
                getline(cin,name);
                cout<<endl;
                cout<<"Enter your email id: ";
                //cin.ignore();
                getline(cin,email);
                cout<<endl;
                cout<<"Enter your mobile number: ";
                //cin.ignore();
                getline(cin,mobile);
                cout<<endl;
                wallet w;
                w.newregistration(name,email,mobile);
                wallet_func();
        }
    }
}
//Our Login system which check details from the files
bool login()
{
    string pass,u,p;
    cout<<"Enter user name : ";
    cin>>username;
    cout<<"Enter Password(max:10 characters) : ";
    pass=enterpassword();
    ifstream read(username+".txt");
    getline(read,u);
    getline(read,p);

    if(username.compare("admin")==0)
        customer=0;
    if(u==username && p==pass)
        return true;
    else
        return false;


}

bool login2()
{
    string pass,u,p;
    cout<<"Enter user name : ";
    cin>>username;
    cout<<"Enter Password(max:10 characters) : ";
    pass=enterpassword();
    ifstream read(username+"_employee.txt");
    getline(read,u);
    getline(read,p);

    if(username.compare("admin")==0)
        customer=0;
    if(u==username && p==pass)
        return true;
    else
        return false;


}
string enterpassword()
{
    char password[32];
    char a;
    int i=0;
    for(i=0;;)
    {
        a=getch();
        if(a>='a'&&a<='z'|| a>='A'&& a<='Z'|| a>='0'&& a<='9')
        {
            password[i]=a;
            ++i;
            cout<<"*";
        }
        if(a=='\b' && i>=1)
        {
            cout<<"\b \b";
            --i;
        }
        if(a=='\r')
        {
            password[i]='\0';
            break;
        }
    }
    return password;
}
int main()
{
    add_product();
    startpage();

    return 0;
}
