#include<iostream>
#include"tv.h"

bool Tv::volup()
{
	if (volume < MaxVal)
	{
		volume++;
		return true;
	}
	else
		return false;
}
bool Tv::voldown()
{
	if (volume > MinVal)
	{
		volume--;
		return true;
	}
	else
		return false;
}
void Tv::chanup()
{
	if (channel < maxchannel)
		channel++;
	else
		channel = 1;
}
void Tv::chandonw()
{
	if (channel > 1)
		channel--;
	else
		channel = maxchannel;
}
void Tv::settings() const
{
	using std::cout;
	using std::endl;
	cout << "TV= " << (state == Off ? "OFF" : "ON") << endl;
	if (state == On)
	{
		cout << "���� =" << volume << endl;
		cout << "�г� =" << channel << endl;
		cout << "��� ="
			<< (mode == Antenna ? "������ ���" : "���̺� ���") << endl;
		cout << "�Է� =" << (input == TV ? "TV" : "DVD") << endl;
	}
}