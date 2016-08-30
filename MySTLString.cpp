#include "MySTLString.h"
#include <cstring>

// Construct a empty string(zero size and unspecified capacity).
MySTLString::MySTLString()
{
	data_ = '\0';
}

// Constructs the string with count copies of character ch.
MySTLString::MySTLString(size_t count, char ch):data_(new char[count])
{
	for (size_t i = 0; i < count; ++i)
	{
		data_[i] = ch;
	}
}

// Constructs the string with contents initialized 
// with a copy of the null-terminated character string pointed to by s.
// The length of the string is determined by the first null character. 
MySTLString::MySTLString(const char *s)
{
	strcpy(data_, s);
}

// Copy constructor. 
// Constructs the string with the copy of the contents of other.
MySTLString::MySTLString(const MySTLString &s)
{
	strcpy(data_, s.data_);
}

// operator= overloaded
// Replace the contents with a copy of str.
// If *this and str are the same object, this function has no effect
MySTLString& MySTLString::operator=(const MySTLString &s)
{
	// If *this and str are the same object, this function return *this
	if (this == &s)
	{
		return *this;
	}

	char* temp = new char(*s.data_);	// copy *s.data_
	delete data_;						// free old memory
	data_ = new char(*temp);			// copy data to data_ member
	return *this;						// return this object
}