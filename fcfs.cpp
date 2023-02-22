#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class process{
    public:
    int at,bt,ct;
    
    process(){}
    process(int ari,int bur){
        at=ari;
        bt=bur;
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
    int flag=0;
    int min_idx=1;
    int minb=100;
    for(int i=1;i<n;i++){
        if(p[i].bt<minb && p[i].at<=ct){
            
            minb=p[i].bt;
           
            min_idx=i;
            flag=1;
        }
    }
    // if(flag==0){
    //     return non;
    // }
    cout<<"Print Index:"<<min_idx<<endl;
    ret=p[min_idx];
    p[min_idx].bt=100;
    return ret;
    
}

vector <process> sortByBt(process p[],int n){
    int cmt=p[0].bt+p[0].at;//completed time
    
    vector <process> prs;
    // cout<<cmt<<endl;
    prs.push_back(p[0]);
    
    int minp=0;
    int pn=1;
    int cur=1;
    cout<<cmt<<endl;
    for(int i=1;i<n;i++){
        process temp=minbt(p,cmt,n);
        cout<<temp.bt<<endl;
        cmt+=temp.bt;
        prs.push_back(temp);
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
    // int ct=fcfs(pr,a);
    // cout<<ct<<endl;
    // for(int i=0;i<a;i++){
    //     cout<<pr[i].ct<<endl;
    // }
    sortByAt(pr,a);
    vector <process> prs=sortByBt(pr,a);
    for(int i=0;i<a;i++){
        cout<<"p"<<i+1<<" "<<prs[i].bt<<endl;
    }
}