#include "date.h"
#include <iostream>
using namespace std;

//int main()
//{
	/*Date * pd1 = (Date *)malloc(sizeof(Date));
	//ֻ�Ƿ���ռ�
	Date * pd2 = (Date *)operator new(sizeof(Date));
	//����ռ䣬ʧ�ܻ���ô���ʽ�����쳣
	Date * pd3 = new Date(1999, 12, 20);
	//��operator new�Ļ����ϵ����˹��캯��
	Date * pd = new Date[3]{Date(1999, 12, 20), Date(2000, 12, 20), Date(2001, 12, 20)};

	cout << pd[0] << endl;
	cout << pd[2] << endl;

	delete[] pd;*/

	/*char * pa = (char *)malloc(1024);
	size_t size = 0;

	Date * pd = new(pa + size)Date(2015, 2, 22);

	size += sizeof(Date);

	Date * pd2 =new(pa + size)Date(2015, 2, 22);

	cout << (void *)pa << endl << pd << endl << pd2;

	return 0;*/
//}

int main()
{
	Date a(1999, 10, 20);

	Date b(1998, 9, 18);
	cout << a.Num(b);

	//cout << (a+(1020))<< endl;
	//cout << (a - (1020)) << endl;

	return 0;
}