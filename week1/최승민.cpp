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
	
	Book(string author, string title, string story) ///북 변수 만들기용 생성자
	{
		this->author = author;
		this->title = title;
		this->story = story;
	}
	Book() /// 배열용 북 생성자
	{}

};

Book saving[15]; ///책 저장할곳
int i = 0; /// 왜 여기다썻지... 그냥 포문용

class Student ///클라스 스튜던트!
{
public:
	string name;
	int age;
	int StdNumber;
	string major;
	
	Student(string name, int age, int StdNumber, string major)///학생정보 저장용 생성자
	{
		this->name = name;
		this->age = age;
		this->major = major;
		this->StdNumber = StdNumber;
	}

	void read(string chek,string Stud)///문도! 읽는다!
	{
		cout << "student " << Stud  <<" read " << chek << endl;
	}
	Book write()///문도! 책만든다!
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
	void hello(Student p)//안녕 친구들 해결사가 왔어~
	{
		cout << "Hello " << p.name << ", myname is " << name << endl;
	}
	void recommend(Student p, Book chek)//어서 읽어라!
	{
		cout << "Hey " << p.name << " read this " << chek.title << endl;
		p.read(chek.title, p.name);
	}
	Student()//배열용 생성자 이거 개꿀!
	{}
	
}; 
Student hackseng[10];///학생정보 저장할곳
int main()
{
	
	srand((unsigned)time(NULL));
	int j,k;
	string namae;///나마에가 영어로 이렇게 쓰는게 맞나...(이름 변수)
	Book math = Book("choi", "math", "about math");
	Book science = Book("choi", "science", "about basic science");
	Book Korean = Book("Sejong the Great King", "Korean", "about basic Korean");
	Book English = Book("Ancient peole", "English", "about basic english");
	Book society = Book("ostrallopitequs", "society", "about society");
	saving[0] = math;
	saving[1] = science;
	saving[2] = Korean;
	saving[3] = English;
	saving[4] = society;///차곡차곡 넣어주자
	for (j = 0; j < 10; j++)///학생정보를 만들자
	{
		cin >> namae;
		hackseng[j].name = namae;
		hackseng[j].age = rand() % 3 + 20;
		hackseng[j].major = "computer science";
		hackseng[j].StdNumber = 201600000 + rand() % 9999;
	}
	for (j = 0; j < 5; j++)/// 학생을 랜덤하게 인사시키자
	{
		hackseng[rand() % 10].hello(hackseng[rand() % 10]);
	}
	for (j = 0,k = 5; j < 10; j++,k++)///책을 읽고 이것보단 잘만들거 같다고 생각해서 바로 책도 만들어 본다
	{
		Student person = hackseng[rand() % 10];
		person.read(saving[rand() % 5].title,person.name);
		Book newbook = person.write();
		saving[k] = newbook;
	}
	for (j = 0; j < 15; j++)/// 원래 있던 책과 학생들이 발로 만든 책 제목을 쭉 출력해본다
	{
		cout << "saving title is " << saving[j].title <<" " << endl;
	}
}