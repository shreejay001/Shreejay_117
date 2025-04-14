#include<iostream>
using namespace std;

class rectangle
{
    float length,breadth;
    public:
    void getdata()
    {
        cout<<"Enter length: "<<endl;
        cin>>length;
        cout<<"Enter width: "<<endl;
        cin>>breadth;
    }
    float area()
    {
        return length*breadth;
    }
    float perimeter()
    {
        return 2*(length + breadth);
    }
    void putdata()
    {
        cout<<"The length is: "<<length<<endl;
        cout<<"The breadth is: "<<breadth<<endl;
        cout<<"The area of rectangle: "<<area()<<endl;
        cout<<"The perimeter of rectangle: "<<perimeter()<<endl;
    }
};
int main()
{
    rectangle r[50];
    int n;
    cout<<"Enter the number of rectangle: "<<endl;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        cout<<"=========Enter details of rectangle========="<<endl;
        r[i].getdata();
        r[i].putdata();
    }
    cout<<"SHREEJAY_24CE117";

    return 0;
}
