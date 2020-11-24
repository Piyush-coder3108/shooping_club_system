#include<iostream>
#include<list>
#include<set>
#include<stack>
#include<unordered_map>
using namespace std;
template<typename T>
class graph{
unordered_map<T,list<pair<T,int>>> l;
unordered_map<T,list<pair<T,T>>> givedir;
unordered_map<T,list<pair<T,T>>> setdir;
public:
void addedge(T x,T y,string dir,int dis,bool bi=true){
    l[x].push_back(make_pair(y,dis));
    givedir[x].push_back(make_pair(y,dir));
    if(bi){
        l[y].push_back(make_pair(x,dis));
        if(dir=="left")
            givedir[y].push_back(make_pair(x,"right"));
        else
            givedir[y].push_back(make_pair(x,"left"));
    }
}

void assign_dir(string x,string y,string z){
setdir[x].push_back(make_pair(y,z));
if(z=="left")
setdir[y].push_back(make_pair(x,"right"));
else if(z=="right")
setdir[y].push_back(make_pair(x,"left"));
else
  setdir[y].push_back(make_pair(x,z));


}


bool check_corners(string a){
string s;
string sample[20]={"1","2","3","4","5","6","7","8","9","10","11","12","13","14","15","16","17","18","19","20"};
for(int i=1;i<20;i++){
    s="Corner-"+sample[i-1];
    if(s==a){
        return true;
    }

}
return false;
}

bool check_points(string a){
string s;
string sample[20]={"1","2","3","4","5","6","7","8","9","10"};
for(int i=1;i<20;i++){
    s="Point-"+sample[i-1];
    if(s==a){
        return true;
    }

}
return false;
}


void djki(T src,T destination){
    unordered_map<T,int> dist;
    for(auto j:l){
        dist[j.first]=214000;
    }
    unordered_map<T,T> parent;
    set<pair<int,T>> s;
    dist[src]=0;
    s.insert(make_pair(0,src));
    while(!s.empty()){
        auto p= *(s.begin());
        T node=p.second;
        int nodedis=p.first;
        s.erase(s.begin());

        for(auto nbr:l[node]){

            if(nodedis+nbr.second<dist[nbr.first]){
                T des=nbr.first;
                parent[nbr.first]=node;

                auto f=s.find(make_pair(dist[des],des));
                if(f!=s.end()){
                    s.erase(f);
                }
                dist[des]=nodedis+nbr.second;
                s.insert(make_pair(dist[des],des));
            }

        }
    }
   // for(auto d:dist){
      //  cout<<d.first<<" is located at a distance of "<<d.second<<endl;
    //}
    cout<<endl<<endl<<endl;
    //for( auto par: parent){
      //  cout<<par.first<<"      "<<par.second<<endl;

    //}
   assign_dir("DUNE","STARBUCKS","straight");
   assign_dir("DUNE","HELIOS","right");
   assign_dir("STARBUCKS","HELIOS","left");
   assign_dir("OPPO","VIP","straight");
   assign_dir("OPPO","DANIEL WELLINGTON","left");
   assign_dir("VIP","DANIEL WELLINGTON","right");
   assign_dir("SPAR","LIFESTYLE","straight");
   assign_dir("SPAR","ARROW","right");
   assign_dir("LIFESTYLE","ARROW","left");
   assign_dir("BURGER KING","SUBWAY","straight");
   assign_dir("BURGER KING","MCDONALDS","right");
   assign_dir("SUBWAY","MCDONALDS","left");
   assign_dir("MAC","STARBUCKS","straight");
   assign_dir("MAC","OZONE","right");
   assign_dir("WASHROOM-T1","OZONE","left");
   assign_dir("DECATHLON","WASHROOM-FF1","straight");
   assign_dir("DECATHLON","HOMECENTRE","right");
   assign_dir("WASHROOM-FF1","HOMECENTRE","left");
   assign_dir("PURE","NEEDLE DUST","straight");
   assign_dir("PURE","HONEY & DOUGH","left");
   assign_dir("NEEDLE DUST","HONEY & DOUGH","right");
   assign_dir("JACK & JONES","SPEEDO","straight");
   assign_dir("JACK & JONES","ONE PLUS","left");
   assign_dir("SPEEDO","ONE PLUS","right");
   assign_dir("SAMIYOSA","CHAAYOS","straight");
   assign_dir("SAMIYOSA","INNIFREE","left");
   assign_dir("CHAAYOS","INNIFREE","right");
   assign_dir("CRAFT STUDIO INDIA","DESCENDING STAIRS FOR THIRD FLOOR (NO.2)","straight");
   assign_dir("CRAFT STUDIO INDIA","HOMECENTRE","left");
   assign_dir("DESCENDING STAIRS FOR THIRD FLOOR (NO.2)","HOMECENTRE","right");




    cout<<"You should follow this path: "<<endl<<endl;
    stack<T> storepath;
    stack<int> distancepath;
    T fin=destination;
    while(fin!=src){
         T temp=parent[fin];
         int distance= dist[fin]-dist[temp];
         storepath.push(fin);
         distancepath.push(distance);
       // cout<<fin<<" <---"<<distance<<" m ---- ";

        fin=temp;

    }
     storepath.push(src);

     T previous;
     while(!distancepath.empty()){
        string direction="straight";
        T tem=storepath.top();
            storepath.pop();

        if(check_points(tem)){
           for(auto n:setdir[previous]){
            if(n.first==storepath.top())
                  direction=n.second;
        }
        cout<<"Now take "<<direction<<" and Move "<<distancepath.top()<<" m ,you will reach at---> ";
        previous=tem;
        }
        else if(check_corners(tem)){
            for(auto n: givedir[tem]){
            if(n.first==storepath.top())
                  direction=n.second;
        }
        if(direction=="left")
            direction="right";
        else
            direction="left";
        cout<<"Now take "<<direction<<" and Move "<<distancepath.top()<<" m ,you will reach at --->";
        previous=tem;
        }
        else if(tem==src||tem==destination){
        for(auto n: givedir[tem]){
            if(n.first==storepath.top())
                  direction=n.second;
        }
        cout<<"Now take "<<direction<<" and Move "<<distancepath.top()<<" m ,you will reach at---> ";
        previous=tem;
        }
        else{
         cout<<tem<<endl;
        if(check_corners(storepath.top())|| check_points(storepath.top())){

           if(distancepath.top()==0){
            for(auto n: givedir[tem]){
                if(n.first==storepath.top()){
                   cout<<"Move "<<n.second<<",you will reach at---> ";
                }
            }
        }
        else
          cout<<"Move "<<distancepath.top()<<" m "<<direction<<endl;
        }
        else{
        if(distancepath.top()==0){
            for(auto n: givedir[tem]){
                if(n.first==storepath.top()){
                   cout<<"Move "<<n.second<<",you will reach at---> ";
                }
            }
        }
        else
        cout<<"Move "<<distancepath.top()<<" m "<<direction<<",you will reach at---> ";}
        previous=tem;
        }

        distancepath.pop();

     }
     cout<<storepath.top();
     storepath.pop();
}

};



class printpath{
graph<string> g;
public:

    printpath(){
    //GROUND FLOOR
    g.addedge("ENTRY GATE","ADIDAS","left",20);
    g.addedge("ENTRY GATE","KAMA","right",20);
    g.addedge("Corner-1","ADIDAS","right",4);
    g.addedge("Corner-1","FOSSIL","left",2);
    g.addedge("FOSSIL","ASCENDING STAIRS FOR FIRST FLOOR (NO.1)","left",11);
    g.addedge("ASCENDING STAIRS FOR FIRST FLOOR (NO.1)","ZARA","to first floor",0,false);
    g.addedge("ASCENDING STAIRS FOR FIRST FLOOR (NO.1)","BATA","left",11);
    g.addedge("BATA","WASHROOM-G1","left",12);
    g.addedge("WASHROOM-G1","DUNE","left",12);
    g.addedge("DUNE","Point-1","left",3);
    g.addedge("Point-1","STARBUCKS","left",6);
    g.addedge("Point-1","HELIOS","front",7);
    g.addedge("STARBUCKS","HALDIRAM","left",5);
    g.addedge("HALDIRAM","THE BEER CAFE","left",10);
    g.addedge("THE BEER CAFE","Corner-2","left",3);
    g.addedge("Corner-2","MIA","left",5);
    g.addedge("MIA","BLUESTONE","left",5);
    g.addedge("BLUESTONE","WASHROOM-G2","left",10);
    g.addedge("WASHROOM-G2","BEAU MORDE","left",12);
    g.addedge("BEAU MORDE","ASCENDING STAIRS FOR FIRST FLOOR (NO.2)","left",11);
    g.addedge("ASCENDING STAIRS FOR FIRST FLOOR (NO.2)","Corner-3","left",8);
    g.addedge("ASCENDING STAIRS FOR FIRST FLOOR (NO.2)","WOW MOMO","to first floor",0,false);
    g.addedge("Corner-3","LENKSKART.COM","left",4);
   g.addedge("LENSKART.COM","VIP","left",5);
   g.addedge("VIP","Point-2","left",5);
   g.addedge("OPPO","Point-2","right",2);
   g.addedge("Point-2","DANIEL WELLINGTON","front",7);
   g.addedge("OPPO","SAMSUNG","left",7);
   g.addedge("DANIEL WELLINGTON","CARAT LANE","right",5);
   g.addedge("CARAT LANE","HELIOS","right",6);
   g.addedge("SAMSUNG","PUMA","left",6);
   g.addedge("PUMA","KAYA","left",4);
   g.addedge("KAYA","NIKE","left",5);
   g.addedge("Corner-4","NIKE","right",2);
   g.addedge("Corner-4","KAMA","left",4);




   //FIRST FLOOR
    g.addedge("JOCKEY","CALVIN KLEIN","left",20);
    g.addedge("CALVIN KLEIN","Corner-5","left",4);
    g.addedge("Corner-5","ZARA","left",3);
    g.addedge("ZARA","ASCENDING STAIRS FOR SECOND FLOOR (NO.1)","left",11);
    g.addedge("ASCENDING STAIRS FOR SECOND FLOOR (NO.1)","MAX","to the second floor",0,false);
    g.addedge("ASCENDING STAIRS FOR SECOND FLOOR (NO.1)","DESCENDING STAIRS FOR GROUND FLOOR (NO.1)","left",1);
    g.addedge("DESCENDING STAIRS FOR GROUND FLOOR (NO.1)","BIBA","left",11);
    g.addedge("DESCENDING STAIRS FOR GROUND FLOOR (NO.1)","BATA"," to the ground floor ",0,false);
    g.addedge("BIBA","WASHROOM-F1","left",12);
    g.addedge("WASHROOM-F1","BURGER KING","left",12);
    g.addedge("BURGER KING","Point-3","left",6);
    g.addedge("Point-3","SUBWAY","left",6);
    g.addedge("Point-3","MCDONALDS","front",7);
    g.addedge("SUBWAY","DOMINOS","left",8);
    g.addedge("DOMINOS","KFC","left",11);
    g.addedge("KFC","Corner-6","left",4);
    g.addedge("Corner-6","PIZZA HUT","left",5);
    g.addedge("PIZZA HUT","WASHROOM-F2","left",10);
    g.addedge("WASHROOM-F2","WOW MOMO","left",12);
    g.addedge("WOW MOMO","ASCENDING STAIRS FOR SECOND FLOOR (NO.2)","left",11);
    g.addedge("ASCENDING STAIRS FOR SECOND FLOOR (NO.2)","DESCENDING STAIRS FOR SECOND FLOOR (NO.2)","left",1);
    g.addedge("ASCENDING STAIRS FOR SECOND FLOOR (NO.2)","ICONIC KIDS","to the second floor",0,false);
    g.addedge("DESCENDING STAIRS FOR GROUND FLOOR (NO.2)","Corner-7","left",11);
    g.addedge("DESCENDING STAIRS FOR GROUND FLOOR (NO.2)","BEAU MORDE","to the ground floor",0,false);
    g.addedge("Corner-7","DOSA VILLAGE","left",4);
    g.addedge("DOSA VILLAGE","REEBOK","left",5);
    g.addedge("REEBOK","SPEEDO","left",7);
    g.addedge("SPEEDO","Point-4","left",14);
    g.addedge("Point-4","JACK & JONES","left",8);
    g.addedge("Point-4","ONE PLUS","front",8);
    g.addedge("ONEPLUS","APPLE","right",5);
    g.addedge("APPLE","MCDONALDS","right",6);
    g.addedge("JACK & JONES","LOUIS PHILIPPE","left",14);
    g.addedge("LOUIS PHILIPPE","Corner-8","left",5);
    g.addedge("Corner-8","JOCKEY","left",22);


   // SECOND FLOOR

    g.addedge("NYKAA","KIKO","left",20);
    g.addedge("KIKO","Corner-9","left",4);
    g.addedge("Corner-9","MAX","left",3);
    g.addedge("MAX","ASCENDING STAIRS FOR THIRD FLOOR (NO.1)","left",11);
    g.addedge("ASCENDING STAIRS FOR THIRD FLOOR (NO.1)","ASCENDING STAIRS FOR FOURTH FLOOR (NO.1)"," to the third floor ",0,false);
    g.addedge("ASCENDING STAIRS FOR THIRD FLOOR (NO.1)","DESCENDING STAIRS FOR FIRST FLOOR (NO.1)","left",1);
    g.addedge("DESCENDING STAIRS FOR FIRST FLOOR (NO.1)","BIBA"," to the first floor ",0,false);
    g.addedge("ASCENDING STAIRS FOR THIRD FLOOR (NO.1)","MARKET99","left",11);
    g.addedge("MARKET99","WASHROOM-S1","left",12);
    g.addedge("WASHROOM-S1","SPAR","left",12);
    g.addedge("SPAR","Point-5","left",5);
    g.addedge("Point-5","ARROW","front",7);
    g.addedge("Point-5","LIFESTYLE","left",6);
    g.addedge("LIFESTYLE","OCTAVE","left",8);
    g.addedge("OCTAVE","AURELIA","left",11);
    g.addedge("AURELIA","MOTHER CARE","left",9);
    g.addedge("MOTHER CARE","Corner-10","left",8);
    g.addedge("Corner-10","WASHROOM-S2","left",8);
    g.addedge("WASHROOM-S2","ICONIC KIDS","left",12);
    g.addedge("ICONIC KIDS","ASCENDING STAIRS FOR THIRD FLOOR (NO.2)","left",11);
    g.addedge("ASCENDING STAIRS FOR THIRD FLOOR (NO.2)","DELHI HEIGHTS"," to the third floor ",0,false);
    g.addedge("ASCENDING STAIRS FOR THIRD FLOOR (NO.2)","DESCENDING STAIRS FOR FIRST FLOOR (NO.2)","left",1);
    g.addedge("DESCENDING STAIRS FOR FIRST FLOOR (NO.2)","Corner-11","left",11);
    g.addedge("DESCENDING STAIRS FOR FIRST FLOOR (NO.2)","WOW MOMO"," to the first floor ",0,false);
    g.addedge("Corner-11","METRO","left",6);
    g.addedge("METRO","NEEDLE DUST","left",7);
    g.addedge("NEEDLE DUST","Point-6","left",9);
    g.addedge("Point-6","PURE","left",12);
    g.addedge("Point-6","HONEY & DOUGH","front",7);
    g.addedge("HONEY & DOUGH","ARROW","right",5);
    g.addedge("PURE","IHOP","left",6);
    g.addedge("IHOP","Corner-12","left",8);
    g.addedge("Corner-12","HOMECENTRE","left",12);
    g.addedge("HOMECENTRE","NYKAA","left",22);

   //THIRD FLOOR
   g.addedge("CASTLE BARBEQUE","Corner-13","left",25);
   g.addedge("Corner-13","ASCENDING STAIRS FOR FOURTH FLOOR (NO.1)","left",15);
   g.addedge("ASCENDING STAIRS FOR FOURTH FLOOR (NO.1)","DECATHLON","to the fourth floor ",0,false);
   g.addedge("ASCENDING STAIRS FOR FOURTH FLOOR (NO.1)","DESCENDING STAIRS FOR SECOND FLOOR (NO.1)","left",1);
   g.addedge("DESCENDING STAIRS FOR SECOND FLOOR (NO.1)","MAC","left",35);
   g.addedge("DESCENDING STAIRS FOR SECOND FLOOR (NO.1)","MARKET99"," to the second floor ",0,false);
   g.addedge("Point-6","MAC","right",9);
   g.addedge("Point-6","OZONE","front",13);
   g.addedge("Point-6","WASHROOM-T1","left",11);
   g.addedge("WASHROOM-T1","Corner-14","left",6);
   g.addedge("Corner-14","CHUMBAK","left",19);
   g.addedge("CHUMBAK","DELHI HEIGHTS","left",27);
   g.addedge("DELHI HEIGHTS","Corner-15","left",9);
   g.addedge("Corner-15","ASCENDING STAIRS FOR FOURTH FLOOR (NO.2)","left",11);
   g.addedge("ASCENDING STAIRS FOR FOURTH FLOOR (NO.2)","OCTAVE"," to the fourth floor ",0,false);
   g.addedge("ASCENDING STAIRS FOR FOURTH FLOOR (NO.2)","DESCENDING STAIRS FOR SECOND FLOOR (NO.2)","left",1);
   g.addedge("DESCENDING STAIRS FOR SECOND FLOOR (NO.2)","CHAAYOS","left",15);
   g.addedge("DESCENDING STAIRS FOR SECOND FLOOR (NO.2)","ICONIC KIDS"," to second floor ",0,false);
   g.addedge("CHAAYOS","Point-7","left",7);
   g.addedge("Point-7","INNIFREE","front",7);
   g.addedge("INNIFREE","OZONE","right",7);
   g.addedge("Point-7","SAMIYOSA","left",20);
   g.addedge("SAMIYOSA","Corner-16","left",31);
   g.addedge("Corner-16","CASTLE BARBEQUE","left",31);

   //FOURTH FLOOR
   g.addedge("LOCK & LOAD","Corner-17","left",25);
   g.addedge("Corner-17","DESCENDING STAIRS FOR THIRD FLOOR (NO.1)","left",15);
   g.addedge("DESCENDING STAIRS FOR THIRD FLOOR (NO.1)","MAC"," to the third floor ",0,false);
   g.addedge("DESCENDING STAIRS FOR THIRD FLOOR (NO.1)","DECATHLON","left",36);
   g.addedge("DECATHLON","Point-9","left",15);
   g.addedge("Point-9","WASHROOM-FF1","LEFT",8);
   g.addedge("Point-9","HOMEO","front",13);
   g.addedge("WASHROOM-FF1","Corner-18","left",8);
   g.addedge("Corner-18","OCTAVE","left",25);
   g.addedge("OCTAVE","Corner-19","left",13);
   g.addedge("Corner-19","DESCENDING STAIRS FOR THIRD FLOOR (NO.2)","left",12);
   g.addedge("DESCENDING STAIRS FOR THIRD FLOOR (NO.2)","Point-10","left",18);
   g.addedge("DESCENDING STAIRS FOR THIRD FLOOR (NO.2)","CHAAYOS"," to the third floor ",0,false);
   g.addedge("Point-10","CRAFT STUDIO INDIA","left",8);
   g.addedge("Point-10","HOMEO","front",12);
   g.addedge("CRAFT STUDIO INDIA","PVR","left",12);
   g.addedge("PVR","BERCO'S","left",22);
   g.addedge("BERCO'S","Corner-20","left",10);
   g.addedge("Corner-20","LOCK & LOAD","left",12);









    }

    printyourpath(string src, string des){

    g.djki(src,des);
    }


};
