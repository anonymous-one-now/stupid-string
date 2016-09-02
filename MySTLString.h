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
	
	// Destructor
	~MySTLString();
	

	using size_type = size_t;		
	using CharT = char;							// the character type
	using value_type = char;					// the value_type
	using reference = value_type;				// reference 
	using const_reference = const value_type&;	// const reference
	using pointer = char*;						// pointer
	using const_pointer = const char*;				// const_pointer

	/* Elment access */
	// Returns reference to the character at specified location pos.
	reference at(size_type pos);
 	const_reference at(size_type pos) const;	// I do not know how to convert a reference to const_reference when to return 

	// Returns reference to the first character
	reference front();
	const_reference front()	const;
	
	// Returns reference to the last character, equivalent to operator[](size() - 1)
	reference back();
	const_reference back()	const;

	// Returns pointer to the underlying array serving as character storage.
	pointer data();
	const_pointer data()	const;

	// Operator assignment overloaded
	MySTLString& operator=(const MySTLString &s);

	// Operator [] overloaded
	reference operator[](size_type pos);
	const_reference operator[](size_type pos) const;

private:
	char* data_;
	int length_;
};