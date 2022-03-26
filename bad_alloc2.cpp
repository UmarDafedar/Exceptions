#include<iostream>
#include<new>

using namespace std;

int main()
{
 int* ptr;
 try
 {
  ptr=new(nothrow) int[100000000000]; // new fails to allocate a memory.However, it does not throw an error. nullptr is returned
  if(ptr==nullptr)
   cout<<"Memory is not allocated"<<endl;
 }
 catch(bad_alloc& exc)
 {
  cout<<"Allocation Failed ->"<<exc.what()<<endl;
 }

 cout<<"Continuing"<<endl;
 delete[] ptr;
 
 return 0;
}
