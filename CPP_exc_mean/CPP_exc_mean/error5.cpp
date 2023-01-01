#include<iostream>
#include<cmath>
#include<string>
#include"exc_mean.h"
class demo
{
private:
	std::string word;
public:
	demo(const std::string& str)
	{
		word = str;
		std::cout << "demo " << word << "����\n";
	}
	~demo()
	{
		std::cout << "demo" << word << "�ı�\n";
	}
	void show() const
	{
		std::cout << "demo" << word << "����\n";
	}
};
double hmean(double a, double b) throw(bad_hmean);
double gmean(double a, double b) throw(bad_geman);
double means(double a, double b) throw(bad_hmean, bad_geman);

int main()
{
	using std::cout;
	using std::cin;
	using std::endl;
	double x, y, z;
	{
		demo d1("found in block in  main()");
		cout << "�μ��� �Է��Ͻʽÿ�: ";
		while (cin >> x >> y)
		{
			try {
				z = means(x, y);
				cout << x << "�� " << y
					<< "�� ��� �� ����� " << z << endl;
				cout << "���� �μ��� �Է��Ͻʽÿ�: ";
			}
			catch (bad_hmean& bg)
			{
				bg.mesg();
				cout << "�ٽ� �Ͻʽÿ�.\n";
				continue;
			}
			catch (bad_geman& hg)
			{
				cout << hg.mesg();
				cout << "���� �ΰ�: " << hg.v1 << ","
					<< hg.v2 << endl;
				cout << "�˼��մϴ�. ���̻� ������ �� �����ϴ�.\n";
				break;
			}
		}
		d1.show();
	}
	cout << "���α׷��� �����մϴ�.\n";
	cin.get();
	cin.get();
	return 0;
}
double hmean(double a, double b)
{
	if (a == -b)
		throw bad_hmean(a, b);
	return 2.0 * a * b / (a + b);
}
double gmean(double a, double b)
{
	if (a < 0 || b < 0)
		throw bad_geman(a, b);
	return std::sqrt(a * b);
}
double means(double a, double b)
{
	double am, hm, gm;
	demo d2("found in means()");
	am = (a + b) / 2.0;
	try
	{
		hm = hmean(a, b);
		gm = gmean(a, b);
	}
	catch (bad_hmean& bg)
	{
		bg.mesg();
		std::cout << "means()���� ����\n";
		throw;
	}
	d2.show();
	return (am + hm + gm) / 3.0;
}