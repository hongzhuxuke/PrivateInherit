#include <iostream>
#include <vector>
using namespace std;

class Parent
{
public:
	Parent()
	{
		cout << "Parent" << endl;
	}

	~Parent()
	{
		cout << "~Parent" << endl;
	}

	void MyId()
	{
		cout << "MyId()" << mstrId.c_str() << endl;
	}

	std::string mstrId = "id";
protected:
	void Call()
	{
		cout << "Call()"  << mstrName.c_str()   << endl;
	}
	std::string mstrName = "name";
private:
	void Sleep()
	{
		cout << "Sleep()" << miSleepTime << endl;
	}
	int miSleepTime;
	static int miSll;
};

class children: protected Parent
{
public:
	children()
	{

	}
	~children()
	{

	}
protected:
private:
};

class GrandSon : public children
{
public:
	GrandSon()
	{
		MyId();//error C2247: “Parent::MyId”不可访问，因为“children”使用“private”从“Parent”继承
		Call();
	}

	~GrandSon()
	{

	}
protected:
private:
};


int main()
{
	GrandSon gS;
	//gS.MyId();


	vector<int> vect;
	vect.resize(2);
	vect.push_back(1333);
	vect.push_back(777);
	vect.push_back(566);
	vect.resize(10);
	vect.push_back(56);
	int iec = vect[11];//Debug 崩溃，release没问题

	for (int i = 0; ; i++)
	{
		std::cout << "[" <<  i << "]  " << vect[i] << iec;
	}
	std::cout << "Hello World!\n"<< iec;
}
 