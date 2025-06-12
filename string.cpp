#include "string.h"

String String::regrow() {
	String temp;
	temp.cs = new char[this->cap * this->cap + 1] {};
	for (int i = 0;i < this->s;i++) {
		temp.cs[i] = this->cs[i];
	}
	delete[] cs;
	temp.s = this->s;
	temp.cap = this->cap * this->cap + 1;
	return temp;
}
// constructor

String::String() {
	cap = 1;
	s = 0;
	cs = nullptr;
}

// dosra constructor 

String::String(const char* p) {
	int i = 0;
	this->cap = 1;
	this->s = 0;
	this->cs = new char[this->cap + 1] {};
	while (p[i] != '\0') {
		if (this->s == this->cap) {
			*this = regrow();
			this->cs[this->s] = p[i];
			this->s++;
		}
		else {
			this->cs[this->s] = p[i];
			this->s++;
		}
		i++;
	}
}
// deep copy
String::String(const String& s1) {
	this->s = s1.s;
	this->cap = s1.cap;
	this->cs = new char[s1.cap] {};
	for (int i = 0;i < s1.s;i++) {
		this->cs[i] = s1.cs[i];
	}
}
// tesra constructor
String::String(int size, char ch) {
	this->s = size;
	this->cap = size;
	this->cs = new char[cap + 1];
	for (int i = 0;i < s;i++) {
		cs[i] = ch;
	}
}
// itos
String String::itos(int num) {
	int temp = num;
	int count = 0;
	while (temp > 0) {
		count++;
		temp = temp / 10;
	}
	if (num == 0) {
		return String(1, '0');
	}
	String pakora;
	pakora.s = count;
	pakora.cap = pakora.s;
	pakora.cs = new char[count];
	for (int i = count - 1;i >= 0;i--) {
		pakora.cs[i] = num % 10 + '0';
		num = num / 10;
	}
	return pakora;
}
// chota constructor
String::String(const int num) {
	*this = itos(num);
}
//assignment operator
String& String :: operator=(const String& _s) {
	this->s = 0;
	this->cap = 1;
	this->cs = nullptr;
	this->s = _s.s;
	this->cap = _s.cap;
	this->cs = new char[this->cap];
	for (int i = 0;i < this->s;i++) {
		this->cs[i] = _s.cs[i];
	}
	return *this;
}
// replace function 
void String::replace_first(char ch) {
	this->cs[0] = ch;
}

// stoi
int String::stoi() {
	int temp = 0;
	int count = 1;
	for (int i = 1;i < this->s;i++) {
		count = count * 10;
	}
	for (int i = 0;i < this->s;i++) {
		temp = ((this->cs[i] - '0') * count) + temp;
		count = count / 10;
	}
	return temp;
}
// TRIM
String String::trim() {
	String temp(*this);
	for (int i = 0;i < temp.s;i++) {
		if (temp.cs[i] == '\n' || temp.cs[i] == '\t' || temp.cs[i] == ' ') {
			for (int j = i;j < temp.s;j++) {
				temp.cs[j] = temp.cs[j + 1];
			}
			temp.s--;
			if (temp.cs[i] == '\n' || temp.cs[i] == '\t' || temp.cs[i] == ' ') {
				i--;
			}
		}
		else {
			for (int j = temp.s - 1;j > i;j--) {
				if (temp.cs[j] == '\n' || temp.cs[j] == '\t' || temp.cs[j] == ' ') {
					temp.s--;
				}
				else {
					return temp;
				}
			}
		}

	}
}
// [] operator
char String :: operator[](int i) const {
	if (i > this->s) {
		return -1;
	}
	else if (i < 0) {
		return -1;
	}
	else {
		return this->cs[i];
	}
}
// equal operator
bool String::is_equal(const String& s1)const {
	if (this->s != s1.s) {
		return false;
	}
	else {
		for (int i = 0;i < this->s;i++) {
			if (this->cs[i] == s1.cs[i]) {
				continue;
			}
			else {
				return false;
			}
		}
		return true;
	}
}
// is_less
bool String::is_less(const String& s1) {

	for (int i = 0;i < this->s;i++) {
		if (this->cs[i] < s1.cs[i]) {
			return true;
		}
		else if (this->cs[i] > s1.cs[i]) {
			return false;
		}
	}
}
// is_greater
bool String::is_greater(const String& s1) {

	for (int i = 0;i < this->s;i++) {
		if (this->cs[i] > s1.cs[i]) {
			return true;
		}
		else if (this->cs[i] < s1.cs[i]) {
			return false;
		}
	}
}
// split
String* String::split(char delium, int& count) const {
	String* SPs = nullptr;
	for (int i = 0;i < this->s;i++) {
		if (this->cs[i] == delium) {
			count++;
		}
	}
	SPs = new String[count + 1]{};
	int idx = 0;
	for (int i = 0;i < this->s;i++) {
		if (this->cs[i] == delium) {
			SPs[idx].cap = SPs[idx].s + 1;
			SPs[idx].cs = new char[SPs[idx].cap + 1] {};
			idx++;
		}
		else {
			SPs[idx].s++;
		}
	}
	SPs[idx].cap = SPs[idx].s + 1;
	SPs[idx].cs = new char[SPs[idx].cap + 1] {};
	int index = 0;
	int j = 0;
	for (int i = 0;i < this->s;i++) {
		if (this->cs[i] == delium) {
			index++, j = 0;
		}
		else {
			SPs[index].cs[j] = this->cs[i];
			j++;
		}
	}
	return SPs;
}
// tokenization
String* String::tokenization(const char* delium, int& count) const {
	String* SPs = nullptr;
	for (int i = 0;i < this->s;i++) {
		if (this->cs[i] == *delium) {
			count++;
		}
	}
	SPs = new String[count + 1]{};
	int idx = 0;
	for (int i = 0;i < this->s;i++) {
		if (this->cs[i] == *delium) {
			SPs[idx].cap = SPs[idx].s + 1;
			SPs[idx].cs = new char[SPs[idx].cap + 1] {};
			idx++;
		}
		else {
			SPs[idx].s++;
		}
	}
	SPs[idx].cap = SPs[idx].s + 1;
	SPs[idx].cs = new char[SPs[idx].cap + 1] {};
	int index = 0;
	int j = 0;
	for (int i = 0;i < this->s;i++) {
		if (this->cs[i] == *delium) {
			index++, j = 0;
		}
		else {
			SPs[index].cs[j] = this->cs[i];
			j++;
		}
	}
	return SPs;
}
// Concatenation
String String::Concatenation(const String& s1) {
	String res;
	res.s = this->s + s1.s;
	res.cap = this->cap * s1.cap;
	res.cs = new char[res.cap];
	int i = 0;
	// first one 
	for (int j = 0;j < this->s;j++) {
		res.cs[i] = this->cs[j];
		i++;
	}
	//second one
	for (int j = 0;j < s1.s;j++) {
		res.cs[i] = s1.cs[j];
		i++;
	}
	return res;
}
// destructor
String :: ~String() {
	delete[]  cs;
}

//print
ostream& operator << (ostream& os, const String& s1) {
	for (int i = 0;i < s1.s;i++) {
		cout << s1.cs[i];
	}
	return os;
}
String operator+(const String& s1, const String& s2) {
	String result;
	result.s = s1.s + s2.s;
	result.cap = s1.cap + s2.cap;
	result.cs = new char[result.cap + 1] {};
	int count = 0;
	for (int i = 0;i < s1.s;i++) {
		result.cs[count] = s1.cs[i];
		count++;
	}
	for (int i = 0;i < s2.s;i++) {
		result.cs[count] = s2.cs[i];
		count++;
	}
	return result;
}
//cin
istream& operator>>(istream& os, String& s1) {
	String temp;
	temp.cap = 100;
	temp.cs = new char[temp.cap] {};
	os.getline(temp.cs, 100);
	int i = 0;
	while (temp.cs[i] != '\0') {
		temp.s++;
		i++;
	}
	s1 = temp;
	return os;
}