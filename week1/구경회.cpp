#include <iostream>
#include <string>

using namespace std;

class Library
{
public:
	string title;
	string author;
	string content;

	void setbook(string title, string author, string content)
	{
		this->title = title;
		this->author = author;
		this->content = content;
	}
};

Library book[20];

class Student
{
public:
    string name;
    int age;
    int stdnum;
    string major;
    Student(string name, int age, int stdnum, string major)
    {
    	this->name = name;
        this->age = age;
        this->stdnum = stdnum;
        this->major = major;
    }
    void read(int n);
    void write(int n);
    void hello(Student p);
    void recommend(Student p, int n);
};

    void Student::read(int n)
    {
    	cout << name << " read " << book[n].title << endl;
    }

    void Student::write(int n)
    {
    	book[n].setbook(major, name, "His story about his major");
    	cout << "I am "<< name << ", I write a book about my story" << endl;
    }

    void Student::hello(Student p)
    {
        cout << "Hello " << p.name << ", my name is " << name << endl;
    }

    void Student::recommend(Student p, int n)
    {
    	cout << "Hey " << p.name << ", how about to read " << book[n].title << endl;
    	p.read(n);
    }

int main()
{
    Student a = Student("a", 20, 25169, "CSE");
    Student b = Student("b", 23, 15070, "MEC");
    Student c = Student("c", 27, 25250, "CSE");
    Student d = Student("d", 21, 15953, "DML");
    Student e = Student("e", 20, 25560, "CSE");
    Student f = Student("f", 22, 15080, "MEC");
    Student g = Student("g", 20, 25564, "CSE");
    Student h = Student("h", 22, 25569, "CSE");
    Student i = Student("i", 25, 15957, "DML");
    Student j = Student("j", 20, 15959, "DML");

    book[0].setbook("Apple", "S.Jobs", "Mac");
    book[1].setbook("Banana", "Kim.s", "Fruit");
    book[2].setbook("Car", "Lee.hj", "BMW");
    book[3].setbook("Dragon", "Newton", "Dungeon");
    book[4].setbook("Effort", "King.ms", "Money");

   	a.hello(b);
   	c.hello(d);
   	e.hello(f);
   	g.hello(h);
   	i.hello(j);

   	a.write(5);
   	a.recommend(b, 5);
   	b.write(6);
   	b.recommend(c, 6);
   	c.write(7);
   	c.recommend(d, 7);
   	d.write(8);
   	d.recommend(e, 8);
   	e.write(9);
   	e.recommend(f, 9);

   	f.read(0);
   	f.write(10);
   	g.read(1);
   	g.write(11);
   	h.read(2);
   	h.write(12);
   	i.read(3);
   	i.write(13);
   	j.read(4);
   	j.write(14);

    system("pause");
}