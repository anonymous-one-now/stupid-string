#include "MySTLString.h"
#include <iostream>

using std::cout;
using std::endl;

int main(void)
{
	// test default constructor
	MySTLString s1;

	// test constructor with count copies of character ch.
	MySTLString s2(3, 'a');

	// test constructor that convert char consequence to MySTLString
	MySTLString s3("asd");

	// test copy constructor
	MySTLString s4(s3);

	// test operator assignment overloaded
	MySTLString s5;
	s5 = s4;
	// test at() to return reference
	cout << "Test at():" << endl;
//	cout << "s1.at(0) = " << s1.at(0) << endl;			// will throw exception
	cout << "s3.at(1) = " << s3.at(1) << endl;
	cout << "**********************" << endl;

	// test front() to return reference
	cout << "Test front():" << endl;
//	cout << "s1.front() = " << s1.front() << endl;		// will throw exception
	cout << "s2.front() = " << s2.front() << endl;
	cout << "**********************" << endl;

	// test back() to return reference
	cout << "Test back():" << endl;
//	cout << "s1.back() = " << s1.back() << endl;		// will throw exception
	cout << "s3.back() = " << s3.back() << endl;
	cout << "**********************" << endl;

	// test data() to return pointer
//	cout << "s1.data() = " << s1.data() << endl;		// will throw exception
	cout << "s3.data() = " << s3.data() << endl;
	cout << "**********************" << endl;

	// test operator[](size_type pos) to return CharT
//	cout << "s1.data() = " << s1.data() << endl;		// will throw exception
	cout << "s3.data() = " << s3.data() << endl;
	cout << "the length of s3.data() = " << s3.data() << endl; 
	cout << "**********************" << endl;

	system("PAUSE");
	return 0;
}