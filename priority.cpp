#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class process{
    public:
    int at,bt,ct,priority,wt,tat,id;
    
    process(){
        
    }
    process(int ari,int bur){
        at=ari;
        bt=bur;
        priority=0;
    }

};

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

int fcfs(process p[],int n){
    int tct=0;
    int c=p[n-1].at;
    int i=0;
    while(i<n){
        if(tct>=p[i].at){
        p[i].ct=tct+p[i].bt;
        cout<<"Process:"<<i<<endl;
        tct=tct+p[i].bt;
        i++;
        }
        else{
            tct++;
        }

    }
    return tct;
}

process minbt(process p[],int ct,int n){
    process ret;
    process non;
    non.bt=0;
    bool flag=true;
    int min_idx=1;
    int i=1;
    int minb=100;
    while(i<n){
        if(p[i].bt<minb && p[i].at<=ct){
            minb=p[i].bt;
            min_idx=i;
            flag=false;
        }
        i++;
    }

    if(flag==true){
        return non;
    }
    cout<<"Print Index:"<<min_idx<<endl;
    ret=p[min_idx];
    p[min_idx].bt=100;
    return ret;
    
}

// int totalTime(process p[],int n){
//     for(int i=0;i<n;i++){

//     }
// }

process minpr(process p[],int ct,int n){
    process ret;
    process non;
    non.bt=0;
    bool flag=true;
    int min_idx=1;
    int i=1;
    int minb=100;
    int prc=0;
    for(int i=1;i<n;i++){
        if(p[i].priority>prc){
            prc=p[i].priority;
            min_idx=i;
        }
    }
    
    for(int i=1;i<n;i++){
        if(p[i].priority==prc && p[i].bt<minb && p[i].at<=ct){
            minb=p[i].bt;
            min_idx=i;
            flag=false;
        }
    }
    // if(flag==true){
    //     return non;
    // }
    // cout<<"Print Index:"<<min_idx<<endl;
    ret=p[min_idx];
    p[min_idx].bt=100;
    p[min_idx].priority=0;
    // ret.priority=prc;
    return ret;
}

vector <process> sortByBt(process p[],int n){
    int cmt=p[0].bt+p[0].at;//completed time
    // int tot=totalTime(p,n);
    vector <process> prs;
    // cout<<cmt<<endl;
    prs.push_back(p[0]);
    prs[0].ct=cmt;
    int minp=0;
    int pn=1;
    int cur=1;
    cout<<cmt<<endl;
    int i=0;
   while(i<(n-1)){
        process temp=minbt(p,cmt,n);
        
        if(temp.bt!=0){
        cout<<temp.bt<<endl;
        cmt+=temp.bt;
        temp.ct=cmt;
        prs.push_back(temp);
        i++;
        }
        else{
            cmt++;
            // cout<<"no process for this"<<cmt<<endl;
        }
        
    }

    return prs;
}

vector<process> sortByPri(process p[],int n){
    int cmt=p[0].bt+p[0].at;//completed time
    // int tot=totalTime(p,n);
    vector <process> prs;
    // cout<<cmt<<endl;
    prs.push_back(p[0]);
    prs[0].ct=cmt;
    int minp=0;
    int pn=1;
    int cur=1;
    // cout<<cmt<<endl;
    int i=0;
   while(i<(n-1)){
        process temp=minpr(p,cmt,n);
        
        if(temp.bt!=0){
        cout<<temp.bt<<endl;
        cmt+=temp.bt;
        temp.ct=cmt;
        prs.push_back(temp);
        i++;
        }
        else{
            cmt++;
            // cout<<"no process for this"<<cmt<<endl;
        }
        
    }

    return prs;
}

int main(){
    int a;
    cout<<"total number of processes:";
    cin>>a;
    process pr[a];
    cout<<"arival time";
    for(int i=0;i<a;i++){
        cin>>pr[i].at;
    }
    cout<<"Burst time";
    for(int i=0;i<a;i++){

        cin>>pr[i].bt;
    }
    cout<<"priority";
    for(int i=0;i<a;i++){
        cin>>pr[i].priority;
    }
    // int ct=fcfs(pr,a);
    // cout<<ct<<endl;
    for(int i=0;i<a;i++){
        pr[i].id=i+1;
    }
    sortByAt(pr,a);
    // vector <process> prs=sortByBt(pr,a);
    // for(int i=0;i<a;i++){
    //     cout<<prs[i].bt<<endl;
    // }
    // for(int i=0;i<a;i++){
    //     cout<<prs[i].ct<<endl;
    // }


    vector <process> prs=sortByPri(pr,a);
    //Printing infos
    // cout<<"arival time:"<<endl;
    // for(int i=0;i<a;i++){
    //     cout<<prs[i].at<<endl;
    // }
    // cout<<"burst times :"<<endl;
    // for(int i=0;i<a;i++){
    //     cout<<prs[i].bt<<endl;
    // }
    // cout<<"completion time"<<endl;
    // for(int i=0;i<a;i++){
    //     cout<<prs[i].ct<<endl;
    // }
    // for(int i=0;i<a;i++){
    //     cout<<pr[i].priority<<endl;
    // }
    // process ot=minpr(pr,11,a);
    // cout<<"max priority=:"<<ot.priority<<endl;
    float avgtat;
    cout<<"Turn around time"<<endl;
    for(int i=0;i<a;i++){
        prs[i].tat=prs[i].ct-prs[i].at;
        // cout<<prs[i].tat<<endl;
        avgtat+=prs[i].tat;
    }
    float no=a;
    cout<<"avetat:"<<avgtat/no<<endl;
    float avgtwt;
    cout<<"Waiting time:"<<endl;
    for(int i=0;i<a;i++){
        prs[i].wt=prs[i].tat-prs[i].bt;
        // cout<<prs[i].wt<<endl;
        avgtwt+=prs[i].wt;
    }
    // float no=a;
    cout<<"avetat:"<<avgtwt/no<<endl;

    cout<<"id\t"<<"at\t"<<"bt\t"<<"priority\t"<<"ct\t"<<"tat\t"<<"wt\t"<<endl;
    for(int i=0;i<a;i++){
        cout<<prs[i].id<<"\t"<<prs[i].at<<"\t"<<prs[i].bt<<"\t"<<prs[i].priority<<"\t\t"<<prs[i].ct<<"\t"<<prs[i].tat<<"\t"<<prs[i].wt<<endl;
    }
}