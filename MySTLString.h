// Copyright 2016.08.30 by FreAkPoint
// To be familiar with Cpp, so I make a string class for study
// Most comments excerpt from cppreference.com

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
	

	using size_type = size_t;		
	using CharT = char;				// the character type
	// Returns reference to the character at specified location pos.
	CharT& at(size_type pos);

	// Returns reference to the first character
	CharT& front();
	
	// Returns reference to the last character, equivalent to operator[](size() - 1)
	CharT& back();

	// Returns pointer to the underlying array serving as character storage.
	const CharT* data()	const;

	// Operator assignment overloaded
	MySTLString& operator=(const MySTLString &s);

	// Operator [] overloaded
	CharT& operator[](size_type pos);


private:
	char* data_;
};