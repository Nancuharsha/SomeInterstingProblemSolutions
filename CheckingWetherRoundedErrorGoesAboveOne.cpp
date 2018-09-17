/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <bits/stdc++.h>

using namespace std;

int main()
{
    double sum = 0.0;
    for(int i =1;i<=10000;i++){
        sum+=i;
        for(int j=1;j<=100;j++){
            for(int k = 1;k<=j;k++){
                double ratio = (k)/(1.0*j);
                long int newSum = round(ratio * sum);
                long newS = 0;
                for(int m=1;m<=i;m++){
                    newS+= (round(newSum*(m/(sum))));
                }
                if(abs(newS-newSum)>1){
                    cout<<"Yes"<<endl;
                    break;
                }
            }
        }
    }

    return 0;
}



