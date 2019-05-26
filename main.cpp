#include <iostream>
#include "Stack.h"

using namespace std;

int main()
{
    Stack<int> s;
    for(int i=0;i<34;i++)
    {
        s.Push(i);
        cout<<"count = "<<s.GetCount()<<endl;
        cout<<"capacity = "<<s.GetCapacity()<<endl;
        s.Print();
    }

    for(int i=0;i<34;i++)
    {
        s.Pop();
        cout<<"count = "<<s.GetCount()<<endl;
        cout<<"capacity = "<<s.GetCapacity()<<endl;
        s.Print();
    }

    system("pause");

}
