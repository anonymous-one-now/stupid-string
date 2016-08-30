// Copyright 2016.08.30 by FreAkPoint
// To be familiar with Cpp, so I make a string class for study

// Make a string container. And try to finish all the function in the basic::string, and I will test it 
class MySTLString
{
public:
	// Default constructor
	MySTLString();									
	
	// Constructs the string with count copies of character ch. 
	MySTLString(size_t count, char ch);		

	// Convert char consequence to MySTLString
	MySTLString(const char *s);

	// Copy constructor 
	MySTLString(const MySTLString &s);
	
	// Operator assignment overloaded
	MySTLString operator=(const MySTLString &s);

private:
	char* data_;
};