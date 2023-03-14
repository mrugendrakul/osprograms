#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class process{
    public:
    int id,at,bt,ct,com,wt,tat,index;

    
};



void roundRobin(process p[],int tq,int n){
    vector<process> gantt;
    queue<process> rq;
    // process pr[n]=p;
    int cot=0;
    rq.push(p[0]);
    cout<<"front :"<<rq.front().bt<<endl;
    cout<<"is empty::"<<rq.empty()<<endl;
    int visited[n];
    for(int i=0;i<n;i++){
        visited[i]=0;
    }
    while(!rq.empty()){
        // process temp=rq.front();
        cout<<"current process in rq is: "<<rq.front().bt<<" "<<rq.front().at<<endl;
        gantt.push_back(rq.front());
        // rq.pop();
        if(rq.front().bt>tq){
            rq.front().bt-=tq;
            p[rq.front().index].bt-=tq;
            cot+=tq;
        }
        else{
            cot+=rq.front().bt;
            rq.front().bt=0;
            rq.front().com=1;
            rq.front().ct=cot;
            p[rq.front().index].bt=0;
            
            

        }
       
        cout<<"current bt after :"<<rq.front().bt<<endl;
        cout<<"current cot:"<<cot<<endl;
        p[rq.front().index].ct=cot;
        //  rq.pop();
        // cout<<"original bt is:"<<p[rq.front().index].bt<<endl;

        for(int i=1;i<n;i++){
            if(p[i].at<=cot && visited[p[i].index]==0){
                cout<<"new pushes are:"<<p[i].at<<endl;
                visited[p[i].index]=1;
                rq.push(p[i]);
            }
        }

        if(rq.front().bt!=0){
            rq.push(rq.front());
            cout<<"is pushed againt\n";
        }
        cout<<"  _______"<<endl;
        rq.pop();
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
    int brtime[n];
    for(int i=0;i<n;i++){
        brtime[i]=p[i].bt;
    }
    int tq=0;
    cout<<"time quantum:";
    cin>>tq;
    for(int i=0;i<n;i++){
        p[i].index=i;
    }
    sortByAt(p,n);
    roundRobin(p,tq,n);
    cout<<"completion time are :"<<endl;
    for(int i=0;i<n;i++){
        cout<<p[i].ct<<endl;
    }
    
    for(int i=0;i<n;i++){
        p[i].tat=p[i].ct-p[i].at;
    }
    cout<<"waiting times:"<<endl;
    for(int i=0;i<n;i++){
        
        p[i].wt=p[i].tat-brtime[i];
        cout<<p[i].wt<<endl;
    }
    
    float avgtat=0;
    for(int i=0;i<n;i++){
        avgtat+=(float)p[i].tat;
    }
    cout<<"avgtat: "<<avgtat/n<<endl;

    float avgwt=0;
    for(int i=0;i<n;i++){
        avgwt+=(float)p[i].wt;
    }
    cout<<"avgwt: "<<avgwt/n<<endl;
}