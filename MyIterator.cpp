#include "MyIterator.h"
#include <cstring>
#include <iostream>

/* Class MyIterator */
// Copy constructor
MyIterator::MyIterator(const MyIterator& it)
{
	p = it.p;
}

// destructor
MyIterator::~MyIterator()
{

}

// Copy assignment overloaded
MyIterator& MyIterator::operator=(const MyIterator& it)
{
	if (*this == it)
	{
		return *this;
	}
	p = nullptr;
	p = it.p;
	return *this;
}

// Prefix increment
MyIterator& MyIterator::operator++()
{
	++p;
	return *this;
}

// Operator* overloaded
Ite::reference MyIterator::operator*() const
{
	return *p;
}

/*
// Operator<< overloaded
std::ostream& operator<<(std::ostream& os, MyIterator& It)
{
	os << It.p->data();
	return os;
}
*/

/* Class MyInputIterator */

// Copy constructor
MyInputIterator::MyInputIterator(MyInputIterator& myInputIt)
{
	MyIterator::p = myInputIt.p;
}

// Postfix increment
MyIterator MyInputIterator::operator++(int)
{
	MyInputIterator temp(*this);
	++p;
	return temp;
}

// Operator* overloaded, return a Ite::value_type 
Ite::value_type MyInputIterator::operator*() const
{
	return *p;
}

// Operator->() overloaded, return a Ite::pointer
Ite::pointer MyInputIterator::operator->() const
{
	return this->p;
}

// Non-member operator== overloaded, return a bool whether two MyIterator is equal
bool operator==(const MyIterator& lIt, const MyIterator& rIt)
{
	return !(std::strcmp(lIt.p->data(), rIt.p->data()));
}

// Non-member operator!= overloaded, return a bool whether two MyIterator is non-equal
bool operator!=(const MyIterator& lIt, const MyIterator& rIt)
{
	return !(lIt == rIt);
}


/* Class MyOutputIterator */

// Copy constructor
MyOutputIterator::MyOutputIterator(MyOutputIterator& myOutIt)
{
	MyIterator::p = myOutIt.p;
}

// Operator* overloaded
Ite::reference MyOutputIterator::operator*() const
{
	return *p;
}

// Operator++ overloaded
// Postfix increment without multiple passes
MyIterator MyOutputIterator::operator++(int)
{
	MyOutputIterator temp(*this);
	++p;
	return temp;
}

/* MyForwardIterator */
MyForwardIterator::MyForwardIterator(MyForwardIterator& myForwardIt)
{
	MyIterator::p = myForwardIt.p;
}

// Postfix increment with multiple passes
MyIterator MyForwardIterator::operator++(int count)
{
	if (count < 0)
	{
		std::cerr << "You should pass a positive number.\n" << std::endl;
		return *this;
	}
	while (count > 0)
	{
		++p;
		--count;
	}
	return *this;
}

/* MyBidirectionlaIterator */
// Operator-- overloaded
// Prefix decrement with mutliple passes
MyIterator& MyBidirectionalIterator::operator--()
{
	--p;
	return *this;
}

// Operator-- overloaded
// Postfix decrement with mutliple passes
MyIterator MyBidirectionalIterator::operator--(int)
{
	MyBidirectionalIterator it(*this);
	--p;
	return it;
}

/* Class MyRandomAccessIterator */
// Non-member bool operator function overloaded
bool operator>=(const MyIterator& lhs, const MyIterator& rhs)
{
	int rLen = lhs.p->size();
	int lLen = rhs.p->size();

	size_t minLen = rLen < rLen ? lLen : rLen;

	// deal with the situation when one or two of is 0.
	if (rLen == 0 && lLen == 0)
	{
		return true;
	}
	else if (rLen != 0 && lLen == 0)
	{
		return true;
	}
	else if (rLen == 0 && lLen != 0)
	{
		return false;
	}

	// Compare the character in [0, minLen) lexicographically
	char* lCharString = new char[rLen + 1];
	char* rCharString = new char[lLen + 1];

	strcpy(lCharString, (lhs.p)->data());
	strcpy(rCharString, (rhs.p)->data());
	for (size_t i = 0; i < minLen; ++i)
	{
		if (lCharString[i] > rCharString[i])
		{
			return true;
		}
		else // lhs.p->at[i] < rhs.p->at[i]
		{
			return false;
		}
	}

	// All characters in [0, minLen) are equal
	return rLen > lLen ? true : false;
}

// Implement operator< in code-reuse way
bool operator<(const MyIterator& lhs, const MyIterator& rhs)
{
	return !(lhs >= rhs);
}

// Implement operator>= in code-reuse way
bool operator<=(const MyIterator& lhs, const MyIterator& rhs)
{
	return (lhs < rhs) || (rhs == lhs);
}

// Implement opeator> in code-reuse way
bool operator>(const MyIterator& lhs, const MyIterator& rhs)
{
	return !(lhs >= rhs);
}

// Implement opeator+(const MyIterator& lhs, Ite::size_type count)
MyIterator operator+(const MyIterator& lhs, Ite::size_type count)
{
	MyIterator it(lhs);

	if (count < 0)
	{
		std::cerr << "You should pass a positive number.\n" << std::endl;
		return it;
	}

	while (count > 0)
	{
		++it.p;
		--count;
	}
	return it;
}

//  Implement opeator+(Ite::size_type count, const MyIterator& rhs) in code-reuse way
MyIterator operator+(Ite::size_type pos, const MyIterator& rhs)
{
	MyIterator it(rhs + pos);
	return it;
}

// Implement operator-(const MyIterator& lhs, Ite::size_type count)
MyIterator operator-(const MyIterator& lhs, Ite::size_type pos)
{
	MyIterator it(lhs);

	if (pos < 0)
	{
		std::cerr << "You should pass a positive number.\n" << std::endl;
	}

	while (pos > 0)
	{
		--it.p;
		--pos;
	}
	return it;
}

// Operator+= overloaded
MyIterator& MyRandomAccessIterator::operator+=(Ite::size_type pos)
{
	p = (p + pos);
	return *this;
}

// Operator-= overloaded
MyIterator& MyRandomAccessIterator::operator-=(Ite::size_type pos)
{
	p = (p - pos);
	return *this;
}

// Operator[] overloaded
Ite::reference MyRandomAccessIterator::operator[](Ite::size_type pos) const
{
	return *p;
}

