/*
  1. bad_typeid exception is thrown by typeid operator
  2. When typeid operator tries to dereference the null pointer of polymorphic class, it throws a bad_typeid exception
  3. For polymorphic class, typeid operator needs vtable for RTTI information and as the ptr with nullptr will not have such information
  4. For non polymorphic class, typeid operator gets the correct information from the ptr with nullptr.


*/

#include<iostream>
#include<typeinfo>

using namespace std;

class PolymoprhicClass
{
 public:
  PolymoprhicClass(){cout<<"PolymoprhicClass::Constructor"<<endl;}
  virtual ~PolymoprhicClass(){cout<<"PolymoprhicClass::Destructor"<<endl;}
};

class NonPolymoprhicClass
{
 public:
  NonPolymoprhicClass(){cout<<"NonPolymoprhicClass::Constructor"<<endl;}
  ~NonPolymoprhicClass(){cout<<"NonPolymoprhicClass::Destructor"<<endl;}
};


int main()
{
 PolymoprhicClass *ptr=nullptr;
 try
 {
  cout<<typeid(*ptr).name()<<endl;
 }
 catch(bad_typeid& bt)
 {
  cout<<bt.what()<<endl;
 }
 
 NonPolymoprhicClass *Nonptr=nullptr;
 try
 {
  cout<<typeid(*Nonptr).name()<<endl;
 }
 catch(bad_typeid& bt)
 {
  cout<<bt.what()<<endl;
 }
 
 return 0;
}
