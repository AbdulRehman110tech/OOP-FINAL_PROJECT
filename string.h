#ifndef STRING_H
#define STRING_H
#include <iostream>
using namespace std;
class String {
private:
	int s, cap;
	char* cs;
	friend ostream& operator << (ostream& os, const String& s1);
	friend String operator+(const String& s1, const String& s2);
	friend istream& operator>>(istream& os, String& s1);
	// regrow
	String regrow();
public:
	// constructor
	String();
	// dosra constructor 
	String(const char* p);
	// deep copy
	String(const String& s1);
	// tesra constructor
	String(int size, char ch);
	// itos
	String itos(int num);
	// chota constructor
	String(const int num);
	//assignment operator
	String& operator=(const String& _s);
	// replace function 
	void replace_first(char ch);

	// stoi
	int stoi();
	// TRIM
	String trim();
	// [] operator
	char operator[](int i) const;
	// equal operator
	bool is_equal(const String& s1)const;
	// is_less
	bool is_less(const String& s1);
	// is_greater
	bool is_greater(const String& s1);
	// split
	String* split(char delium, int& count) const;
	// tokenization
	String* tokenization(const char* delium, int& count) const;
	// Concatenation
	String Concatenation(const String& s1);
	int return_length() { return this->s; };

	char* data() {
		return this->cs;
	}

	const char* data() const { return this->cs; };
	// destructor
	~String();
};
#endif