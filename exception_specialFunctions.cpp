/*
1. exception_ptr
  typedef exception_ptr;
  
  a. It is a pointer points to an exception object
  b. default constructed exception_ptr is a null pointer. It does not point to an exception object
  c. Two instances of exception_ptr compare equal only if they are both null or both point at the same exception object
  d. exception_ptr is not impicitly convertible to any arithmetic, enumeration, or pointer type
  e. it is contextually converted to bool and will evaluate to false if exception_ptr is null, true otherwise
  f. exception object referened by excpetion_ptr remains valid as long as there remains at least one exception_ptr that is referencing it
  g. It is shared ownership pointer
  h. Meets the requirements of nullablepointer
  i. It manages an exception object which has been thrown and captured with current_exception
  
2. curret_exception()
   
   exception_ptr current_exception() noexcept;
   
  a. If called during exception handling in a catch clause, captures the current exception object and returns the exception_ptr that holds either copy or reference
      to the exception oject
  b. exception object remains valid as long as exception pointer pointing to object is valid
  c. If the implementation of this function requires a call to new and the call fails, the returned pointer will hold a reference to an instance of std::bad_alloc.
  d. If the implementation of this function requires copying the captured exception object and its copy constructor throws an exception, 
      the returned pointer will hold a reference to the exception thrown. If the copy constructor of the thrown exception object also throws, 
       the returned pointer may hold a reference to an instance of std::bad_exception to break the endless loop.
  e. If the function is called when no exception is being handled, an empty std::exception_ptr is returned.

3. rethrow_exception()

  void rethrow_exception(exception_ptr p);
 
 a. throws previously captured exception object referred to by an excepion_ptr p or copy of that object.
 b. behavior is undefined if p is nullptr

4. make_exception_ptr
  
  template<typename E>
  exception_ptr make_exception_ptr(E e) noexcept
  {
    try
    {
      throw e;
    }
    catch(...)
    {
      return current_exception();
    }
  }
  
*/

#include<iostream>
#include<exception>

using namespace std;

int main()
{
 cout<<"Main Function is called "<<endl;
 exception_ptr p; // exception pointer points to the exception object
 try
 {
  p=current_exception(); // At this point there are no exceptions. So, current_exception will have a null pointer
  int* ptr=new int[100000000000000];
 }
 catch(bad_alloc& ba)
 {
  p=make_exception_ptr(ba); // returns exception_ptr pointing to exception object
  cout<<"Entered catch block"<<endl;
 }
 
 if(p)
 {
  cout<<"Entered"<<endl;
  try
  {
   rethrow_exception(p);
  }
  catch(exception& e)
  {
   cout<<e.what()<<endl;
  }
 }
 return 0;
}
