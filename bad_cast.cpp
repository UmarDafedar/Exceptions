/*
  1. dynamic_cast can be performed between the two related polymorphic class objects
  2. dynamic_cast is performed between the pointers of two related polymorphic class objects and the references of two related polymorphic classes
  3. bad_cast specifies the type casting has failed
  
  default constructor:
  --------------------
  bad_cast() throw();
  bad_cast() noexcept;
  
  Copy Constructor
  -------------------
  bad_cast(const bad_cast& other) throw();
  bad_cast(const bad_cast& other) noexcept;
  
  Copy assignment Operator:
  -----------------------
  bad_cast& operator=(const bad_cast& other) throw();
  bad_cast& operator=(const bad_cast& other) noexcept;
  
  what()
  -----
  virtual const char* what() const throw();
  virtual const char* what() const noexcept;
  
  destructor
  ----------
  virtual ~bad_cast();
*/

#include<iostream>

using namespace std;

class Base
{
 public:
  Base(){cout<<"Base::Constructor"<<endl;}
  virtual ~Base(){cout<<"Base::Destructor"<<endl;}
};

class Derived:public Base
{
 public:
 Derived(){cout<<"Derived::Constructor"<<endl;}
 virtual ~Derived(){cout<<"Derived::Destructor"<<endl;}
};

int main()
{
 Base b;
 try
 {
  Derived &d=dynamic_cast<Derived&>(b); // base class to derived class returns an incomplete object
 }
 catch(bad_cast& e)
 {
  cout<<e.what()<<endl;
 }
 return 0;
}
