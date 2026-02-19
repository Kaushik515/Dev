#include"bits/stdc++.h"
using namespace std;
class Shape{
    private:
    string name;
    public:
    void setName(string s){
        name = s;
    }
    string getName(){
        return name;
    }
    virtual void draw() = 0;
    void show(){
        cout<<"You are in Right Place"<<'\n';
    }
};
class Square : public Shape{
    public:
    void draw(){
        cout<<"You are in Square Class"<<'\n';
    }
};
int main(){
    Shape *sq = new Square;
    sq->draw();
    Square sqr;
    sqr.setName("Circle");
    cout<<sqr.getName()<<'\n';
    sqr.show();
    return 0;
}