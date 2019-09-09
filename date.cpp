#include <iostream>
#include "date.h"
using namespace std;

static uint getMonthDay(uint y,uint m)
{
	if (m > 12 || m == 0)
	{
		return 0;
	}
	if (m == 4 || m == 6 || m == 9 || m == 11)
	{
		return 30;
	}
	else if (m == 2)
	{
		return 28 + (y % 400 == 0 || (y % 4 == 0 && y % 100));
	}
	else
	{
		return 31;
	}
}

int getLeapNum(int sy, int ey)
{
	int tmp = sy % 4;
	if (tmp)
	{
		sy += (4 - tmp);
	}
	return (ey - sy) / 4 ;
}

//Date Date::operator +(uint delay) const
//{
//	Date res = *this;
//	uint tmp;
//	tmp = getMonthDay(res.m_year, res.m_month);//tmp里面保存的是当月的总天数
//	while (delay >= tmp)//如果所加的天数大于当月的总天数
//	{
//		delay -= tmp;//用要加的天数减去当月数
//		res.m_month++;//并且月份加1，相当于加了一个整月
//		if (res.m_month > 12)//如果加的月份大于12月之后
//		{
//			res.m_month = 1;//就将月份置为1
//			res.m_year++;//年份+1，到第二年
//		}
//		tmp = getMonthDay(res.m_year, res.m_month);//这个时候再次计算现在这个月的总天数
//	}
//	//上面的while循环结束后，所加的天数已经不足以减去整月的天数
//
//	res.m_day += delay;//将剩下的天数加到这个月的日期中
//	if (res.m_day > tmp)//如果此时加上的这个天数大于本月的总天数的话
//	{
//		res.m_month++;//就将月份继续加1
//		if (res.m_month > 12)//并且判断月份大于12月
//		{
//			res.m_month = 1;
//			res.m_year++;
//		}
//		res.m_day -= tmp;//给现在的天数减去上个月的总天数，就是这个月的天数
//	}
//	return res;
//}

//Date Date::operator -(uint delay) const
//{
//	Date res = *this;
//	uint tmp;
//	tmp = getMonthDay(res.m_year, res.m_month);
//	while (delay >= tmp)
//	{
//		delay -= tmp;
//		res.m_month--;
//		if (res.m_month < 1)
//		{
//			res.m_month = 12;
//			res.m_year--;
//		}
//		tmp = getMonthDay(res.m_year, res.m_month);
//	}
//
//	res.m_day -= delay;
//	if (res.m_day <= 0)
//	{
//		res.m_month--;
//		if (res.m_month < 1)
//		{
//			res.m_month = 12;
//			res.m_year--;
//			
//		}
//		tmp = getMonthDay(res.m_year, res.m_month);
//		res.m_day += tmp;
//	}
//	return res;
//}

int Date::Num( Date & d)
{
	Date res = *this;
	uint tmp;
	uint src, m1 = 0, m2 = 0, n1 = 0, n2 = 0;
	if (res > (d))
	{
		if (res.m_year == d.m_year)
		{
			if (res.m_month == d.m_month)
			{
				return (res.m_day - d.m_day);
			}
			else
			{
				while (d.m_month < res.m_month)
				{
					tmp = getMonthDay(d.m_year, d.m_month);
					m1 += tmp;
					d.m_month++;
				}
				return m1 + (unsigned int)(res.m_day - d.m_day);
			}
		}
		else
		{
			src = getLeapNum(d.m_year, res.m_year);//src里面存放的是d到res之间的闰年的个数
			n1 = (res.m_year - d.m_year) * 365 + src;//这时的n存放的是将相差的年数转换为天数,然后剩下的部分就转换成了上面的那个情况
			d.m_year = res.m_year;
			while (d.m_month < res.m_month)
			{
				tmp = getMonthDay(d.m_year, d.m_month);
				m1 += tmp;
				d.m_month++;
			}
			return n1 + m1 + (unsigned int)(res.m_day - d.m_day);
		}
	}
	else if (res == (d))
	{
		return 0;
	}
	else
	{
		if (res.m_year == d.m_year)
		{
			if (res.m_month == d.m_month)
			{
				return (d.m_day - res.m_day);
			}
			else
			{
				while (d.m_month > res.m_month)
				{
					tmp = getMonthDay(res.m_year, res.m_month);
					m2 += tmp;
					res.m_month++;
				}
				return m2 + (unsigned int)(d.m_day - res.m_day);
			}
		}
		else
		{
			src = getLeapNum(d.m_year, res.m_year);//src里面存放的是d到res之间的闰年的个数
			n2 = (d.m_day - res.m_day) * 365 + src;//这时的n存放的是将相差的年数转换为天数,然后剩下的部分就转换成了上面的那个情况
			res.m_year = d.m_year;
			while (d.m_month > res.m_month)
			{
				tmp = getMonthDay(res.m_year, res.m_month);
				m2 += tmp;
				res.m_month++;
			}
			return n2 + m2 + (unsigned int)(d.m_day - res.m_day);
		}
	}
}

//ostream & operator << (ostream & os, Date & d)
//{
//	os << d.m_year << '-' << d.m_month << '-' << d.m_day;
//	return os;
//}

bool Date::operator <(const Date & d) const
{
	if (m_year < d.m_year)
	{
		return true;
	}
	if (m_year == d.m_year && m_month < d.m_month)
	{
		return true;
	}
	else if (m_year == d.m_year &&
		m_month == d.m_month &&
		m_day < d.m_day)
	{
		return true;
	}
	return false;
}
bool Date::operator >(const Date & d) const
{
	if (m_year > d.m_year)
	{
		return true;
	}
	if (m_year == d.m_year && m_month > d.m_month)
	{
		return true;
	}
	else if (m_year == d.m_year &&
		m_month == d.m_month &&
		m_day > d.m_day)
	{
		return true;
	}
	return false;
}
bool Date::operator >=(const Date & d) const
{
	return !(*this < d);
}
bool Date::operator <=(const Date & d) const
{
	return !(*this > d);
}
bool Date::operator ==(const Date & d) const
{
	if (m_year == d.m_year &&
		m_month == d.m_month &&
		m_day == d.m_day)
	{
		return true;
	}
	return false;
}
bool Date::operator !=(const Date & d) const
{
	return !(*this == d);
}