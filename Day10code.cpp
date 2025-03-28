#include<iostream>
using namespace std;
class students{
    public:
        float e1;
        int studentId;
        string name;
        float marks[5];
        void input(){
            try
            {
                for (int i = 0; i <5;i ++){
                    cout<<"Enter marks of student "<<i+1<<" ";
                    cin>>marks[i];
                    if(marks[i]<0 or marks[i]>100){
                        throw e1;
                    }
                }
            }
            catch(float& e)
            {
                cout<<"Invalid marks"<<endl;
            }
            
        }
        void calculatePercentage(){
            int per;
            for (int i=0; i<5;i ++){
                per = (marks[i]/100)*100;
                cout<<"Percentage of student "<<i+1<<"= "<<per<<endl;
            }
        }
};
int main(){
    students s;
    s.input();
    cout<<"!----------------------------------------------------------!"<<endl;
    s.calculatePercentage();
    return 0;
}