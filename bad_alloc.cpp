/*
std::bad_alloc is the type of the object thrown as exceptions by the allocation functions to report failure to allocate storage.

constructor:
1. default constructor:
    bad_alloc() throw();
    bad_alloc() noexcept;
    
2. Copy Constructor:
    bad_alloc(const bad_alloc& other) throw();
    bad_alloc(const bad_alloc& other) noexcept;

3. Copy Assignment Operator:
    bad_alloc& operator=(const bad_alloc& other) noexcept;
    bad_alloc& operator=(const bad_alloc& other) throw();
 
 4. what() -> Virtual function
    virtual const char* what() const throw();
    virtual const char* what() const noexcept;
 
 5. Destructor
    ~bad_alloc();
    
*/

#include<iostream>
#include<new>

using namespace std;

int main()
{
 int* ptr;
 try
 {
  ptr=new int[100000000000];
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
