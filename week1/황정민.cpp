#include<iostream>
#include<string>

using namespace std;

class Book {
public:
	string title;
	string author;
	string contents;
};


class Student {
public:
	string name;
	string major;
	int age;
	int number;

	Student(string name, string major, int age, int number) {
		this->name = name;
		this->major = major;
		this->age = age;
		this->number = number;
	}
	void read(Book bk) {
		cout << name << " read " << bk.title << endl;
	}
	void write(Book* bk) {
		cout << "Input Book's title : " << endl;
		cin >> bk->title;
		cout << "Input Book's contents : " << endl;
		cin >> bk->contents;
		bk->author = this->name;
	}
	void hello(Student s) {
		cout <<"Hello "<< s.name << ", my name is " << name << endl;
	}
	void recommend(Book bk,Student s) {
		s.read(bk);
	}
};

int main() {
	Student a("a", "cse", 20, 1);
	Student b("b", "cse", 20, 2);
	Student c("c", "cse", 20, 3);
	Student d("d", "cse", 20, 4);
	Student e("e", "cse", 20, 5);
	Student f("f", "cse", 20, 6);
	Student g("g", "cse", 20, 7);
	Student h("h", "cse", 20, 8);
	Student i("i", "cse", 20, 9);
	Student j("j", "cse", 20, 10);
	Book arr[10];
	Student arr2[10] = { a,b,c,d,e,f,g,h,i,j };
	int tmp;
	for (tmp = 0; tmp < 10; tmp++) {
		arr2[tmp].write(arr + tmp);
	}
	for (tmp = 0; tmp < 5; tmp++) {
		arr2[tmp].read(arr[4 - tmp]);
	}
	for (tmp = 5; tmp < 10; tmp++) {
		arr2[tmp].recommend(arr[tmp], arr2[9 - tmp]);
	}
	for (tmp = 0; tmp < 5; tmp++) {
		arr2[tmp].hello(arr2[9 - tmp]);
	}
}