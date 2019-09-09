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
//	tmp = getMonthDay(res.m_year, res.m_month);//tmp���汣����ǵ��µ�������
//	while (delay >= tmp)//������ӵ��������ڵ��µ�������
//	{
//		delay -= tmp;//��Ҫ�ӵ�������ȥ������
//		res.m_month++;//�����·ݼ�1���൱�ڼ���һ������
//		if (res.m_month > 12)//����ӵ��·ݴ���12��֮��
//		{
//			res.m_month = 1;//�ͽ��·���Ϊ1
//			res.m_year++;//���+1�����ڶ���
//		}
//		tmp = getMonthDay(res.m_year, res.m_month);//���ʱ���ٴμ�����������µ�������
//	}
//	//�����whileѭ�����������ӵ������Ѿ������Լ�ȥ���µ�����
//
//	res.m_day += delay;//��ʣ�µ������ӵ�����µ�������
//	if (res.m_day > tmp)//�����ʱ���ϵ�����������ڱ��µ��������Ļ�
//	{
//		res.m_month++;//�ͽ��·ݼ�����1
//		if (res.m_month > 12)//�����ж��·ݴ���12��
//		{
//			res.m_month = 1;
//			res.m_year++;
//		}
//		res.m_day -= tmp;//�����ڵ�������ȥ�ϸ��µ�����������������µ�����
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
			src = getLeapNum(d.m_year, res.m_year);//src�����ŵ���d��res֮�������ĸ���
			n1 = (res.m_year - d.m_year) * 365 + src;//��ʱ��n��ŵ��ǽ���������ת��Ϊ����,Ȼ��ʣ�µĲ��־�ת������������Ǹ����
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
			src = getLeapNum(d.m_year, res.m_year);//src�����ŵ���d��res֮�������ĸ���
			n2 = (d.m_day - res.m_day) * 365 + src;//��ʱ��n��ŵ��ǽ���������ת��Ϊ����,Ȼ��ʣ�µĲ��־�ת������������Ǹ����
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