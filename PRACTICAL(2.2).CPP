#include<iostream>
#include<cstring>
using namespace std;

class students
{
    int roll_no;
    char name[25];
    float marks[3];

public:
    students()
    {
        roll_no=0;
        strcpy(name,"unknown");
        marks[0]=0;
        marks[1]=0;
        marks[2]=0;
    }


    students(int roll,char n[],int m1,int m2,int m3)
    {
        roll_no=roll;
        strcpy(name,n);
        marks[0]=m1;
        marks[1]=m2;
        marks[2]=m3;
    }

    double average_marks()
    {
        return (marks[0]+marks[1]+marks[2])/3.0;
    }

    void display()
    cout<<"Roll number"<<roll_no<<endl;
    cout<<"Name: "<<name<<endl;
    cout<<"Marks: "<<marks[0]<<","<<marks[1]<<","<<marks[2]<<"\n";
    cout<<"Average marks: "<<average_marks()<<"\n";
}
};

int main()
{
    students s[10];

    for(int i=0; i< 3; i++)
    {
        int roll;
        char n[25];
        int m1,m2,m3;
        cout<< "Enter student roll no"<<endl;
        cin>> roll;
        cout<<"Enter student name"<<endl;
        cin>>n;
        cout<<"Enter marks of 1"<<endl;
        cin>>m1;
        cout<<"Enter marks of 2"<<endl;
        cin>>m2;
        cout<<"Enter marks of 3"<<endl;
        cin>>m3;

        s[i]=students( roll, n, m1, m2, m3);
    }
    for(int i=0; i<3; i++)
    {
        cout<<"The details of"<<i+1<<"student"<<endl;
        s[i].display();
    }
    cout<<"SHREEJAY_24CE117";
    return 0;
}
