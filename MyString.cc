/*
 * MyString.cc
 *
 *  Created on: Jun 24, 2014
 *      Author: msehgal
 */
// CS251 Data Structures
// String Implementation
// IMPORTANT: Do not use any of the functions in the string C runtime library
// Example. Do not use strcpy, strcmp, etc. Implement your own

// IMPORTANT: See the MyString.h file for a description of
// what each method needs to do.

#include <stdio.h>
#include <stdlib.h>
#include "MyString.h"

// My own implementation of strlen
int
MyString::slength(const char *s) const
{
  // Add implementation here
  int count = 0;
  while(*s!='\0'){
  	count++;
  	s++;
  }
  return count;
}

// Initialize _s. Allocate memory for _s and copy s into _s
void
MyString::initialize(const char * s)
{
	int i;
	_s = new char[slength(s)+1]; // memory allocated

	for(i=0; i<slength(s); i++){
		_s[i] = s[i]; // copying
	}
	_s[i]='\0';
}

// Create a MyString from a C string
MyString::MyString(const char * s)
{
  initialize(s);
}

// Create a MyString from a copy of another string
MyString::MyString(const MyString &s)
{
  initialize(s._s);
}

// Create a MyString with an empty string
MyString::MyString()
{
  _s = new char[1];
  *_s = 0;
}

// Assignment operator. Without this operator the assignment is
// just a shallow copy that will copy the pointer _s. If the original _s
// goes away then the assigned _s will be a dangling reference.
MyString &
MyString::operator = (const MyString & other) {
  if (this != &other) // protect against invalid self-assignment
  {
    // deallocate old memory
    delete [] _s;

    // Initialize _s with the "other" object.
    initialize(other._s);

    // by convention, always return *this
    return *this;
  }
}

// Obtain a substring of at most n chars starting at location i
// if i is larger than the length of the string return an empty string.
MyString
MyString::substring(int i, int n)
{
	 MyString sub;
	if(i>length()){ // if length is greater return string
		//return '\0';
		return MyString();
	}

	int j;
	for(j = 0; j<n; j++){
		// i is the starting location
		// n is the number of chars it will copy
		sub._s[j] = _s[i+j];
	}
	//sub._s='\0';

	sub = MyString(sub._s);
	return sub;
}

// Remove at most n chars starting at location i
void
MyString::remove(int i, int n)
{

	// Add implementation here
	// If i is beyond the end of string return
	MyString sub;
	

}

// Return true if strings "this" and s are equal
bool
MyString::operator == (const MyString & s)
{
  // Add implementation here
  if(this == s
  return false;
}


// Return true if strings "this" and s are not equal
bool
MyString::operator != (const MyString &s)
{
  // Add implementation here
  return false;
}

// Return true if string "this" and s is less or equal
bool
MyString::operator <= (const MyString &s)
{
  // Add implementation here
  return false;
}

// Return true if string "this" is greater than s
bool
MyString::operator > (const MyString &s)
{
  // Add implementation here
  return false;
}

// Return character at position i.  Return '\0' if out of bounds.
char
MyString::operator [] (int i)
{
  // Add implementation here
  return ' ';
}

// Return C representation of string
const char *
MyString::cStr()
{
  // Add implementation here
  return _s;
}

// Get string length of this string.
int
MyString::length() const
{
  // Add implementation here
  return slength(_s);
}

// Destructor. Deallocate the space used by _s
MyString::~MyString()
{
  // Add implementation here
  delete [] _s;
}

// Concatanate two strings (non member method)
MyString operator + (const MyString &s1, const MyString &s2)
{
  // Add implementation here
	MyString s;
	char *finalString;
	finalString = new char[(s1.length()+ s2.length())+1]; // finalString that is going to be concatenated

	if(s1._s == '\0' && s2._s == '\0'){
		return MyString();
	}

	if(s1._s == '\0'){
		s =  s2._s;
		return s;
	}

	if(s2._s == '\0'){
		s =  s1._s;
		return s;
	}

	int i;
	for(i=0; i<s.slength(s1._s); i++){
		finalString[i] = s1._s[i];
	}
	int j;
	for(j=0; j<s.slength(s2._s); j++){
		finalString[i]= s2._s[j];
		i++;
	}
	finalString[i]= '\0';


	s.initialize(finalString);
	return s;

}

