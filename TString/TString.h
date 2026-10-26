#include <iostream>

class TString {
	int size;
	char* str;
public:
	TString();
	TString(int n);
	TString(const char* ch);
	TString(const TString& s);
	~TString();

	TString& operator=(const TString& s);
	TString operator+(const TString& s);
	TString operator+(char c);
	bool operator==(const TString& s) const;
	bool operator>(const TString& s);
	bool operator<(const TString& s);
	char& operator[](int index);

	int getlen() const;
	friend std::ostream& operator<<(std::ostream& out, const TString& s);
	friend std::istream& operator>>(std::istream& is, TString& s);
};
