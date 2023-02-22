#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class process{
    public:
    int id,at,bt,ct;

    
};



void roundRobin(process p[],int tq,int n){
    vector<process> gantt;
    queue<process> rq;
    int cot=0;
    rq.push(p[0]);
    cout<<"front :"<<rq.front().bt<<endl;
    cout<<"is empty::"<<rq.empty()<<endl;
    while(!rq.empty()){
        process temp=rq.front();
        cout<<"current process in rq is: "<<temp.bt<<endl;
        gantt.push_back(temp);
        rq.pop();
        if(temp.bt>=tq){
            temp.bt-=tq;
        }
        else{
            temp.bt=0;
        }
        cout<<"current bt after :"<<temp.bt<<endl;
        // for(int i=0;i<n;i++){
        //     if(p[i].at<=cot && p[i].bt!=0){
        //         rq.push(p[i]);
        //     }
        // }
        // if(temp.bt!=0){
        //     rq.push(temp);
        // }
    }
}

void sortByAt(process p[],int n){
    int min_idx=0;
    for(int i=0;i<n;i++){
        min_idx=i;
        for(int j=i+1;j<n;j++){
            if(p[j].at<p[min_idx].at){
                process temp=p[j];
                p[j]=p[min_idx];
                p[min_idx]=temp;
            }
        }
    }
}

int main(){
    int n;
    cout<<"give number of process:";
    cin >>n;
    process p[n];
    for(int i=0;i<n;i++){
        p[i].id=i;
    }
    cout<<"arival times:\n";
    for(int i=0;i<n;i++){
        cin>>p[i].at;
    }
    cout<<"birst times: \n";
    for(int i=0;i<n;i++){
        cin>>p[i].bt;
    }
    int tq=0;
    cout<<"time quantum:";
    cin>>tq;
    sortByAt(p,n);
    roundRobin(p,tq,n);
}