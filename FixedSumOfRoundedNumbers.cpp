#include <bits/stdc++.h>

using namespace std;


vector<int> toFloor(vector<double>&v){
    vector<int>ans(v.size());
    for(int i =0;i<v.size();i++){
        ans[i] = floor(v[i]);
    }
    return ans;
}

template<typename T> T sumOfVector(vector<T>v){
    T sum=0;
    for(auto it:v){
        sum+=it;
    }
    return sum;
}
template<typename T> void print(vector<T>v){
    for(auto it:v){
        cout<<it<<" ";
    }
    cout<<endl;
    return ;
}
int maxDif(vector<int>&v,vector<double>&v1){
    double dif = 0.0;
    int index = 0;
    for(int i =0;i<v.size();i++){
        if(dif<(v1[i]-(double)v[i])){
            dif = (v1[i]-(double)v[i]);
            index = i;
        }
    }
    return index;
}
struct Node{
    double val;
    int index;
};
struct CompareHeight { 
    bool operator()(Node const& p1, Node const& p2) 
    { 
        double d1 = p1.val-floor(p1.val);
        double d2 = p2.val - floor(p2.val);
        return d1<d2; 
    }
}; 
int fixedSumSolution2(vector<double>v){
    vector<int>flooredVector(toFloor(v));
    double sum = sumOfVector(v);
    int sum1 = sumOfVector(flooredVector);
    int dif = round(sum -(double)sum1);
    priority_queue<Node,vector<Node>,CompareHeight >q;
    for(int i =0;i<v.size();i++){
        Node temp = {v[i],i};
        q.push(temp);
    }
    while(dif){
        int index =q.top().index;
        flooredVector[index]++;
        q.pop();
        Node temp = {(double)flooredVector[index],index};
        q.push(Node(temp));
        dif--;
    }
   // print(flooredVector);
    return sumOfVector(flooredVector);
}


int fixedSumSolution(vector<double>v){
    vector<int>flooredVector(toFloor(v));
    double sum = sumOfVector(v);
    int sum1 = sumOfVector(flooredVector);
    int dif = round(sum -(double)sum1);
    //cout<<"DIFF - "<<dif<<" "<<sum<<" "<<sum1<<endl;
    while(dif){
        int index = maxDif(flooredVector,v);
        flooredVector[index]++;
        dif--;
    }
   // print(flooredVector);
    return sumOfVector(flooredVector);
}

int main(){
    int a;
    cin>>a;
    while(a--){
    long int sum = 0;
    sum = (a*(a+1))/2;
    for(int i = 1;i<=sum;i++){
        double t = i/(1.0*sum);
        long int newSum = t*sum;
        vector<double>v;
        for(int j=1;j<=a;j++){
            double tt = j/(1.0*sum);
             v.push_back(tt*newSum);
        }
        //cout<<sum<<" -- "<<newSum<<endl;
       // print(v);
        
        long int returnSum;
        if(a<1000)
        returnSum = fixedSumSolution(v);
        else
        returnSum = fixedSumSolution2(v);
        if(abs(returnSum-newSum)>0){
            cout<<"Wrong"<<endl;
        }
    }
    }
    return 0;
}
