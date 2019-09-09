#pragma once
#include <iostream>
using namespace std;
typedef unsigned int uint;

class Date
{
	int m_year;
	uint m_month;
	int m_day;


	
public:int Date::Num( Date & d);
	Date(int y, uint m, int d):
		m_year(y),
		m_month(m),
		m_day(d)
	{}

	~Date()
	{
		cout << "123" << endl;
	}
	Date operator +(uint delay) const;
	Date operator -(uint delay) const;

	bool operator <(const Date & d) const;
	bool operator >(const Date & d) const;
	bool operator >=(const Date & d) const;
	bool operator <=(const Date & d) const;
	bool operator ==(const Date & d) const;
	bool operator !=(const Date & d) const;


	friend ostream & operator << (ostream & os, Date & d);
};