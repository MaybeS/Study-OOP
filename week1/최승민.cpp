#include<iostream>
#include<string>
#include<time.h>
using namespace std;

class Book
{
public:
	string author;
	string title;
	string story;
	
	Book(string author, string title, string story) ///�� ���� ������ ������
	{
		this->author = author;
		this->title = title;
		this->story = story;
	}
	Book() /// �迭�� �� ������
	{}

};

Book saving[15]; ///å �����Ұ�
int i = 0; /// �� ����ٛ���... �׳� ������

class Student ///Ŭ�� ��Ʃ��Ʈ!
{
public:
	string name;
	int age;
	int StdNumber;
	string major;
	
	Student(string name, int age, int StdNumber, string major)///�л����� ����� ������
	{
		this->name = name;
		this->age = age;
		this->major = major;
		this->StdNumber = StdNumber;
	}

	void read(string chek,string Stud)///����! �д´�!
	{
		cout << "student " << Stud  <<" read " << chek << endl;
	}
	Book write()///����! å�����!
	{
		string story, title, author;
		cout << "story?? " << endl;
		cin >> story;
		cout << "title?? " << endl;
		cin >> title;
		cout << "author?? " << endl;
		cin >> author;
		Book newbook = Book(author, title, story);
		return newbook;
	}
	void hello(Student p)//�ȳ� ģ���� �ذ�簡 �Ծ�~
	{
		cout << "Hello " << p.name << ", myname is " << name << endl;
	}
	void recommend(Student p, Book chek)//� �о��!
	{
		cout << "Hey " << p.name << " read this " << chek.title << endl;
		p.read(chek.title, p.name);
	}
	Student()//�迭�� ������ �̰� ����!
	{}
	
}; 
Student hackseng[10];///�л����� �����Ұ�
int main()
{
	
	srand((unsigned)time(NULL));
	int j,k;
	string namae;///�������� ����� �̷��� ���°� �³�...(�̸� ����)
	Book math = Book("choi", "math", "about math");
	Book science = Book("choi", "science", "about basic science");
	Book Korean = Book("Sejong the Great King", "Korean", "about basic Korean");
	Book English = Book("Ancient peole", "English", "about basic english");
	Book society = Book("ostrallopitequs", "society", "about society");
	saving[0] = math;
	saving[1] = science;
	saving[2] = Korean;
	saving[3] = English;
	saving[4] = society;///�������� �־�����
	for (j = 0; j < 10; j++)///�л������� ������
	{
		cin >> namae;
		hackseng[j].name = namae;
		hackseng[j].age = rand() % 3 + 20;
		hackseng[j].major = "computer science";
		hackseng[j].StdNumber = 201600000 + rand() % 9999;
	}
	for (j = 0; j < 5; j++)/// �л��� �����ϰ� �λ��Ű��
	{
		hackseng[rand() % 10].hello(hackseng[rand() % 10]);
	}
	for (j = 0,k = 5; j < 10; j++,k++)///å�� �а� �̰ͺ��� �߸���� ���ٰ� �����ؼ� �ٷ� å�� ����� ����
	{
		Student person = hackseng[rand() % 10];
		person.read(saving[rand() % 5].title,person.name);
		Book newbook = person.write();
		saving[k] = newbook;
	}
	for (j = 0; j < 15; j++)/// ���� �ִ� å�� �л����� �߷� ���� å ������ �� ����غ���
	{
		cout << "saving title is " << saving[j].title <<" " << endl;
	}
}