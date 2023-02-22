#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class process{
    public:
    int id,at,bt;

    process();
};

void roundRobin(process p[],int tq){
    
}

int main(){
    int n;
    cout<<"give number of process:";
    cin >>n;
    process p[n];
    cout<<"arival times:\n";
    for(int i=0;i<n;i++){
        cin>>p[i].at;
    }
    cout<<"birst times: \n";
    for(int i=0;i<n;i++){
        cin>>p[i].bt;
    }
    int tq=0;
    cout<<"time quantum";
    cin>>tq;
    roundRobin(p,tq);
}