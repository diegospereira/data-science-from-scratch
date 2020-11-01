#include <iostream>
#include <exception>

class IndexMismatch : public std::exception
{
    virtual const char *message() const throw()
    {
        return "Matrix index mismatch";
    }
} IndexMismatch;
