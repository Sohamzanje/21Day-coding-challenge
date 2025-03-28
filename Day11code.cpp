#include<iostream>
using namespace std;
class product
{
    protected:
        int productId;
        string name;
        float price;
    public:
        product(int p, string n,float pr)
        {
            productId = p;
            name = n;
            price = pr;
        }
        virtual void displayDetails(){
            cout<<"";
        }

};
class Electronics:public product
{
    protected:
        int warrenty;
    public:
        Electronics(int p, string n,float pr,int w):product(p,n,pr){
            warrenty = w;
        }
        void displayDetails() override
        {
            cout<<"name :"<<name<<endl;
            cout<<"Id :"<<productId<<endl;
            cout<<"price :"<<price<<endl;
            cout<<"Warrenty :"<<warrenty<<"years"<<endl;
        }

};
class Cloting:public product
{
    protected:
        string a;
    public:
        Cloting(int p, string n,float pr,string size):product(p,n,pr){
            a = size;
        }
        void displayDetails() override
        {
            cout<<"name :"<<name<<endl;
            cout<<"Id :"<<productId<<endl;
            cout<<"price :"<<price<<endl;
            cout<<"size :"<<a<<endl;
        }

};
int main(){
    Electronics e(101,"fan",2000,3);
    e.displayDetails();
    cout<<"!------------------------------!"<<endl;
    Cloting c(103,"T-shirt",350,"L");
    c.displayDetails();
    return 0;
}
