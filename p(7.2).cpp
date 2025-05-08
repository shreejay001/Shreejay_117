#include<iostream>
#include<fstream>
#include<vector>
#include<sstream>
using namespace std;

int main()
{

    ifstream file("data.txt");

    if(!file)
    {
        cout<<"Error: File could not be opened.";
        return 1;
    }


vector<string> lines;
string line;
int lineCount=0, wordCount=0,charCount=0;

while(getline(file,line))
{
    lines.push_back(line);
    lineCount++;

    charCount+= line.length();

stringstream ss(line);
string word;
while(ss>>word)
{
    wordCount++;
}
}




file.close();

cout<<"\n Total lines are "<<lineCount;
cout<<"\n Total words are "<<wordCount;
cout<<"\n Total characters are "<<charCount;
}
