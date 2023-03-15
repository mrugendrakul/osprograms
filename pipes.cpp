#include<bits/stdc++.h>
using namespace std;

int main()
{
    queue<string> q;

    int pid = fork();

    if(pid == 0)
    {
        q.push("data from child");
    }
    else
    {
        cout<<q.front();
        q.pop();
    }

}