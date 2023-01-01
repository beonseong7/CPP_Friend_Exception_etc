#include<iostream>

class bad_hmean
{
private:
	double v1;
	double v2;
public:
	bad_hmean(double a = 0, double b = 0) :v1(a), v2(b) {}
	void mesg();
};
inline void bad_hmean::mesg()
{
	std::cout << "hmean(" << v1 << "," << v2 << "):"
		<< "잘못된 매개변수: a=-b\n";
}
class bad_geman
{
public:
	double v1;
	double v2;
	bad_geman(double a = 0, double b = 0) : v1(a), v2(b) {}
	const char* mesg();
};
inline const char* bad_geman::mesg()
{
	return "gmean() 매개변수들은 >=0이어야합니다.\n";
}