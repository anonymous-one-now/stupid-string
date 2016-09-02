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

	// test when count is zero
	MySTLString s_countIsZero(0, 'a');

	// test constructor that convert char consequence to MySTLString
	// I don't know the reason that the program is crashed when to call s3.destructor in visual stdio 2015, 
	// but I ask my friend and he recode it on Mac. It doesn't happen anymore. WTF!!! It takes at least 2 hours to fix it. 
	MySTLString s3("qwe");

	// test the char consequence which is empty
	MySTLString s_charEmpty("");

	// test copy constructor
	MySTLString s4(s1);

	// test operator assignment overloaded
	MySTLString s5;
	s5 = s4;


	// test at() to return reference
	cout << "Test at():" << endl;
//	cout << "s1.at(0) = " << s1.at(0) << endl;			// will throw exception
	cout << "s3.at(1) = " << s3.at(1) << endl;
	cout << "**********************" << endl;
	
	// test const at() const
	MySTLString::const_reference const_at_value = s3.at(2);
	cout << "Test const at():" << endl;
	cout << "const_at_value(which is s3.at(2)) = " << const_at_value << endl;

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
//	cout << "s1[1] = " << s1[1] << endl;		// will throw exception
	cout << "s2[1] = " << s2[1] << endl; 
	cout << "**********************" << endl;

	system("PAUSE");
	return 0;
}