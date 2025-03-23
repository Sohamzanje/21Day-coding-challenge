#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
class sorting{
    public:
    vector <int> arr = {7,2,9, 1,4,10,15,8,6,2 ,5};
    void assending(){
        sort(arr.begin(),arr.end());
        cout<<"The ascending order is :";
        for(int i :arr){
            cout<<i<<" ";
        }
    }
    void dec(){
        sort(arr.begin(),arr.end(),greater<int>());
        cout<<"\nThe descending order is : ";
        for (int j :arr){
            cout<<j<<" ";
        }
    }
};
int main(){
    sorting s;
    s.assending();
    s.dec();
    return 0 ;
}