#include<bits/stdc++.h>
using namespace std;
class Car{
    public:
    string brand,model;
    int mileage=0;
    void drive(int distance){
        mileage += distance;
    }
    void show(){
        cout<<"Brand: "<<brand<<'\n';
        cout<<"Model: "<<model<<'\n';
        cout<<"Distance driven: "<<mileage<<'\n';
    }
};
int main(){
    Car c1;
    c1.brand = "Suzuki";
    c1.model = "Breeza";
    c1.drive(100);
    c1.show();
    return 0;
}