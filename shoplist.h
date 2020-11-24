#include<iostream>
#include<bits/stdc++.h>
#include<cstring>
using namespace std;

class Node
{
    friend class List;
    string val;
    int flag;
    int pos;
    Node *link;
    Node *down;

    public:
        Node() {
            val = "NULL";
            link = NULL;
            flag=0;
            pos=0;
            down=NULL;
        }
         Node(string v) {
            val = v;
            link = NULL;
            down=NULL;
            flag=0;
            pos=0;

        }
        Node(string v,int p) {
            val = v;
            link = NULL;
            down=NULL;
            flag=0;
            pos=p;

        }
};

class List
{

    Node *head;
    public:
        List() {
            head = new Node();


        }
        void append(string,string,int);
        void append(string,string,string,int);
        void append(string);
        void show_cat();
        void show();
        void show(Node*);
        void display(Node*);
        Node* search_child(string,string);
        Node* search_element(string);
        Node* search_child_child(Node*,string);
        string return_child(string,int);
};
Node* List::search_element(string v){
Node * temp=head;
while(temp!=NULL){
    if(temp->val==v)
        return temp;
    temp=temp->link;
}

}


Node* List::search_child(string a,string b){
Node* temp= head;
while(temp!=NULL){
    if(temp->val==a){
        Node* temp2= temp->down;
        while(temp2!=NULL){
                if(temp2->val==b)
                    return temp2;
            temp2=temp2->link;
        }

    }
     temp=temp->link;
}


}

string List::return_child(string a,int b){
if(a!="APPARELS"){
Node* temp= head;
while(temp!=NULL){
    if(temp->val==a){
        Node* temp2= temp->down;
        while(temp2!=NULL){
                if(temp2->pos==b)
                    return temp2->val;
            temp2=temp2->link;
        }

    }
     temp=temp->link;
}}
else{
 Node* temp= head;
while(temp!=NULL){
    if(temp->val==a){
        Node* temp2= temp->down;
        while(temp2!=NULL){
            Node* tem= temp2->down;
                while(tem!=NULL){
                if(tem->pos==b)
                    return tem->val;
                  tem=tem->link;
                }
            temp2=temp2->link;

        }

    }
     temp=temp->link;
}

}


}

Node* List::search_child_child(Node* a,string b){
Node* temp= a->down;
while(temp!=NULL){
    if(temp->flag==1){
        Node* temp2= temp->down;
        while(temp2!=NULL){
                if(temp2->val==b)
                    return temp2;
            temp2=temp2->link;
        }

    }
     temp=temp->link;
}


}
void List::append(string item)
{
    Node *pivot = new Node(item);
    if (head==NULL) {
        head= pivot;
    }
    else {
        Node *temp = head;
        while (temp->link != NULL) {
            temp = temp->link;
        }
        temp->link = pivot;
    }

}


void List::append(string v,string item,int p)
{
    Node* newnode= new Node(item,p);

    Node *found= search_element(v);
    if(found->down==NULL){
            found->flag=1;
        found->down=newnode;
    }
    else{

        Node*temp= found->down;
        while(temp->link!=NULL){
            temp=temp->link;
        }
        temp->link=newnode;
    }

}
void List::append(string a,string b, string c,int p){
Node* newnode=new Node(c,p);
Node* found= search_child(a,b);
if(found->down==NULL){
            found->flag=1;
        found->down=newnode;
    }
    else{

        Node* temp= found->down;
        while(temp->link!=NULL){
            temp=temp->link;
        }
        temp->link=newnode;
    }




}


void List::show()
{
   Node* temp= head;
    temp=temp->link;
   while(temp!=NULL){
    cout<<"\t"<<temp->val<<endl;
    if(temp->flag==1){
        display(temp);
    }
    temp=temp->link;
   }
}

void List::show_cat(){
Node* temp= head;
temp=temp->link;
int i=1;
while(temp->link!=NULL){
    cout<<"\t\t\t\t"<<i<<" ) "<<temp->val<<endl;
    temp=temp->link;
    i++;
}


}
void List::display(Node* h){
    Node* temp=h->down;
    int i=1;
    while(temp!=NULL){
            if(temp->val=="MEN"||temp->val=="WOMEN"||temp->val=="UNISEX"||temp->val=="KIDS"){
                cout<<"\t\t# "<<temp->val<<endl;
            }
            else{
            cout<<"\t\t"<<temp->pos<<"). "<<temp->val<<endl;}
            if(temp->flag==1){
                show(temp);
            }
        temp=temp->link;

    }

}

void List::show(Node* h){
 Node* temp=h->down;
    while(temp!=NULL){
            cout<<"\t\t\t"<<temp->pos<<"). "<<temp->val<<endl;
        temp=temp->link;
    }
}


class printshoplist{
List l;
public:
    printshoplist(){
        l.append("HYPERMARKET");
        l.append("ELECTRONICS");
        l.append("SPORTS");
        l.append("FOOTWEAR");
        l.append("APPARELS");
        l.append("JEWELLERY & WATCHES");
        l.append("BEAUTY & PERSONAL CARE");
        l.append("HOME DECOR");
        l.append("MULTI BRAND");
        l.append("BAGS & ACCESSORIES");
        l.append("ENTERTAINMENT");
        l.append("RESTAURANT");
        l.append("FOOD COURT");
        l.append("CAFE & QUICK BITES");
        l.append("HYPERMARKET","MARKET99",1);
        l.append("HYPERMARKET","SPAR",2);
        l.append("ELECTRONICS","SAMSUNG",1);
        l.append("ELECTRONICS","OPPO",2);
        l.append("ELECTRONICS","ONE PLUS",3);
        l.append("ELECTRONICS","APPLE",4);
        l.append("ELECTRONICS","CROMA",5);
        l.append("SPORTS","ADIDAS",1);
        l.append("SPORTS","NIKE",2);
        l.append("SPORTS","PUMA",3);
        l.append("SPORTS","DECATHLON",4);
        l.append("FOOTWEAR","BATA",1);
        l.append("FOOTWEAR","METRO",2);
        l.append("FOOTWEAR","NEEDLE DUST",3);
        l.append("APPARELS","MEN",0);
        l.append("APPARELS","WOMEN",0);
        l.append("APPARELS","UNISEX",0);
        l.append("APPARELS","KIDS",0);
        l.append("JEWELLERY & WATCHES","MIA",1);
        l.append("JEWELLERY & WATCHES","HELIOS",2);
        l.append("JEWELLERY & WATCHES","BLUESTONE",3);
        l.append("JEWELLERY & WATCHES","CARAT LANE",4);
        l.append("JEWELLERY & WATCHES","DANIEL WELLINGTON",5);
        l.append("BEAUTY & PERSONAL CARE","KAMA",1);
        l.append("BEAUTY & PERSONAL CARE","KAYA",2);
        l.append("BEAUTY & PERSONAL CARE","MAC",3);
        l.append("BEAUTY & PERSONAL CARE","OZONE",4);
        l.append("BEAUTY & PERSONAL CARE","KIKO",5);
        l.append("BEAUTY & PERSONAL CARE","NYKAA",6);
        l.append("BEAUTY & PERSONAL CARE","INNISFREE",7);
        l.append("HOME DECOR","HOME CENTRE",1);
        l.append("HOME DECOR","PURE",2);
        l.append("HOME DECOR","CHUMBAK",3);
        l.append("HOME DECOR","CRAFT STUDIO INDIA",4);
        l.append("MULTI BRAND","LIFESTYLE",1);
        l.append("MULTI BRAND","MAX",2);
        l.append("BAGS & ACCESSORIES","VIP",1);
        l.append("BAGS & ACCESSORIES","LENSKART.COM",2);
        l.append("BAGS & ACCESSORIES","FOSSIL",3);
        l.append("BAGS & ACCESSORIES","BEAU MONDE",4);
        l.append("ENTERTAINMENT","PVR",1);
        l.append("ENTERTAINMENT","LOCK & LOAD",2);
        l.append("RESTAURANT","BIRYANI BLUES",1);
        l.append("RESTAURANT","CHILI'S",2);
        l.append("RESTAURANT","THE BEER CAFE",3);
        l.append("RESTAURANT","DELHI HEIGHTS",4);
        l.append("RESTAURANT","CASTLE'S BARBEQUE",5);
        l.append("FOOD COURT","BURGER KING",1);
        l.append("FOOD COURT","DOMINOES",2);
        l.append("FOOD COURT","HALDIRAM",3);
        l.append("FOOD COURT","KFC",4);
        l.append("FOOD COURT","PIZZA HUT",5);
        l.append("FOOD COURT","WOW MOMO",6);
        l.append("FOOD COURT","SUBWAY",7);
        l.append("FOOD COURT","SAMIYOSA",8);
        l.append("FOOD COURT","BERCO'S",9);
        l.append("FOOD COURT","DOSA VILLAGE",10);
        l.append("CAFE & QUICK BITES","STARBUCKS",1);
        l.append("CAFE & QUICK BITES","IHOP",2);
        l.append("CAFE & QUICK BITES","CHAAYOS",3);
        l.append("CAFE & QUICK BITES","HONEY & DOUGH",4);
        l.append("APPARELS","MEN","ARROW",1);
        l.append("APPARELS","MEN","JACK & JONES",2);
        l.append("APPARELS","MEN","OCTAVE",3);
        l.append("APPARELS","MEN","LOUIS PHILIPPE",4);
       l.append("APPARELS","WOMEN","BIBA",5);
        l.append("APPARELS","WOMEN","MADAME",6);
        l.append("APPARELS","WOMEN","AURELIA",7);
        l.append("APPARELS","UNISEX","ZARA",8);
        l.append("APPARELS","UNISEX","CALVIN KLEIN",9);
        l.append("APPARELS","UNISEX","JOCKEY",10);
        l.append("APPARELS","KIDS","ICONIC KIDS",11);
        l.append("APPARELS","KIDS","MOTHER CARE",12);


    }

    void showcat(){
    l.show_cat();
    }
    void showshops(){
    l.show();
    }
    void show_shop_per_cat(string s){
    Node* h=l.search_element(s);
    l.display(h);
    }
    string return_shop(string c,int p){

    return l.return_child(c,p);
    }
};
