#include "MySTLString.h"
#include <cstring>
#include <iostream>
#include <stdexcept>

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
MySTLString::MySTLString(const char *s):data_(new char[strlen(s)])
{
	strcpy(data_, s);
}

// Copy constructor. 
// Constructs the string with the copy of the contents of other.
MySTLString::MySTLString(const MySTLString &s):data_(new char[strlen(s.data_)])
{
	strcpy(data_, s.data_);
}

// Returns a reference to the character at specified location pos.
// Bounds checking is performed, exception of type std::out_of_range will be thrown on invalid acess
MySTLString::CharT& MySTLString::at(size_type pos)
{
	if (pos >= strlen(data_))
	{
		throw std::out_of_range("pos is cross-border!\n");
	}
	return data_[pos];
}

// Returns reference to the first character
MySTLString::CharT& MySTLString::front()
{
	if (data_ == nullptr)
	{
		throw std::out_of_range("String is empty!\n");
	}
		return data_[0];
}

// Returns reference to the last character
MySTLString::CharT& MySTLString::back()
{
	if (data_ == nullptr)
	{
		throw std::out_of_range("String is empty!\n");
	}
	return data_[0];
}

// Returns pointer to the underlying array serving as character storage.
// The pointer is such that the range[data(); data()+strlen(data_)] is valid 
// in it correspond to the values stored in the string
const MySTLString::CharT* MySTLString::data() const
{
	if (data_ == nullptr)
	{
		throw std::out_of_range("String is empty!\n");
	}
	return data_;
}

// Operator= overloaded
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

// Operator[] overloaded
// Returns a reference to the character at specified location pos. 
// No bounds checking is perfromed.
MySTLString::CharT& MySTLString::operator[](size_type pos)
{
	return this->at(pos);
}

