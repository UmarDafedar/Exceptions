/*
uncaught_exception() And uncaught_exceptionss()

1. bool uncaught_exception() throw();
   bool uncaught_exception() noexcept;
2. int uncaught_exceptions() noexcept;

1) Detects if the current thread has a live exception object, that is, an exception has been thrown or rethrown and not yet entered a matching catch clause, 
    std::terminate or std::unexpected. In other words, std::uncaught_exception detects if stack unwinding is currently in progress.
2) Detects how many exceptions in the current thread have been thrown or rethrown and not yet entered their matching catch clauses.

Sometimes it's safe to throw an exception even while std::uncaught_exception() == true. 
For example, if stack unwinding causes an object to be destructed, the destructor for that object could run code that throws an exception as long as the exception 
is caught by some catch block before escaping the destructor.

Return value
1) true if stack unwinding is currently in progress in this thread.
2) The number of uncaught exception objects in the current thread.
*/

#include <iostream>
#include <exception>
#include <stdexcept>
 
struct Foo {
    int count = std::uncaught_exceptions();
    ~Foo() {
        std::cout << (count == std::uncaught_exceptions()
            ? "~Foo() called normally\n"
            : "~Foo() called during stack unwinding\n");
    }
};
int main()
{
    Foo f;
    try {
        Foo f;
        std::cout << "Exception thrown\n";
        throw std::runtime_error("test exception");
    } catch (const std::exception& e) {
        std::cout << "Exception caught: " << e.what() << '\n';
    }
}
