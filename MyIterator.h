#pragma once
#include "MySTLString.h"

namespace Ite
{
	// The aliases in namespace Ite
	using size_type = int;
	using value_type = MySTLString;
	using reference = MySTLString&;
	using const_reference = const reference;
	using pointer = MySTLString*;
	using const_pointer = const pointer;
}

class MyIterator
{
public:

	// Copy constructor
	MyIterator(const MyIterator&);

	// Destructor
	~MyIterator();

	// Copy assignment overloaded
	MyIterator& operator=(const MyIterator);

	// Operator++() overloaded
	// Prefix increment
	MyIterator& operator++();

	// Operator* overloaded
	Ite::reference operator*()	const;
};

class MyInputIterator : public virtual MyIterator
{
public:

	// Postfix increment
	MyIterator operator++(int);

	// Operator* overloaded
	Ite::value_type operator*() const;

	// Operator-> overloaded
	Ite::pointer operator->()	const;

	// Non-member operator== overloaded
	friend bool operator==(const MyIterator&, const MyIterator&);

	// Non-member operator!= overloaded
	friend bool operator!=(const MyIterator&, const MyIterator&);
};

// Once MyInputIterator has been deferenced, 
// it is undefined to deference one before that
class MyOutputIterator :public virtual MyIterator
{
public:

	// Operator* overloaded 
	Ite::reference operator*() const;
	
	// Operator++ overloaded
	// Postfix increment without multiple passes
	MyIterator operator++(int);
};

// Deferences may only be on the left side of an assignment
// once MyInputIterator has been dereferenced, 
// it is undefined to dereference one before that.
class MyForwardIterator :public MyInputIterator, public MyOutputIterator
{
	// Default constructor
	MyForwardIterator();

	// Operator++ overloaded
	// Postfix increment with multiple passes
	MyIterator operator++(int);
};

class MyBidirectionalIterator :public MyForwardIterator
{
	// Operator-- overloaded
	// Prefix decrement with multiple passes
	MyIterator& operator--();

	// Operator-- overloaded
	// Postfix decrement with multiple passes
	MyIterator operator--(int);
};

class MyRandomAccessIterator : public MyBidirectionalIterator
{
	// Non-member bool operator functions overloaded
	friend bool operator>(const MyIterator&, const MyIterator&);
	friend bool operator<(const MyIterator&, const MyIterator&);
	friend bool operator<=(const MyIterator&, const MyIterator&);
	friend bool operator>=(const MyIterator&, const MyIterator&);

	// Non-member arithmetic operator+ and - overloaded
	// Operator+ overloaded like "a + n", in which a is an iterator and n is a constant number
	friend MyIterator operator+(const MyIterator&, Ite::size_type);

	// Operator+ overloaded like "n + a", in which a is an iterator and n is a constant number
	friend MyIterator operator+(Ite::size_type, const MyIterator&);

	// Operator- overloaded like "a - n", in which a is an iterator and n is a constant number
	friend MyIterator operator-(const MyIterator&, Ite::size_type);

	// Operator- overloaded like "a - b", in which the both of a and b are iterators
	friend MyIterator operator-(const MyIterator&, const MyIterator&);

	// compound assignment member operator += and -=
	// Operator+= overloaded
	MyIterator& operator+=(Ite::size_type);

	// Operator-= overloaded
	MyIterator& operator-=(Ite::size_type);

	// Operator[] overloaded
	Ite::reference operator[](Ite::size_type) const;
};