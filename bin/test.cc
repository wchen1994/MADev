#include <iostream>

using namespace std;

class Foo{
public:
	virtual void print(){
		cout << "foo" << endl;
	}
};

class Bar : public Foo{
public:
	void print(){
		cout << "bar" << endl;
	}
};

int main(){
	Bar bar;
	Foo *pt = &bar;
	pt->print();

	return 0;
}
