#include <iostream>
#include<string>
using namespace std;


class student				//student, book 클래스 선언
{
public:
	int age;
	int sc;
	string sub;
	string name;
};
class book
{
public:
	string name;
	string author;
	string contents;
};
book st[100]; //서고 제작
void read(student p, book b) //읽기 쓰기 추천 인사 함수
{
	cout << p.name << "read" << b.name << endl;
}
void hello(student p, student c)
{
	cout << p.name << "Hello" << c.name << endl;
}
void recommend(student p, student c, book b)
{
	cout << p.name << " recommend the book " << b.name << " to " << c.name << endl;
}
book write(student x, string a, string b,int*j)
{
	book i;
	i.author = x.name;
	i.name = a;
	i.contents = b;
	st[*j] = i;
		*j++;
		return i;
}

int main()
{
	int n = 0;
	int* j = &n;
	student s1, s2, s3, s4, s5, s6, s7, s8, s9, s0;
	student ss[10] = { s1,s2,s3,s4,s5,s6,s7,s8,s9,s0 };
	for (int i = 0; i < 10; i++)	//학생 초기화
	{
		ss[i].name = "a";
		ss[i].age = i;
		ss[i].sc = i;
		ss[i].sub = "b";
	}
	for (int i = 0; i < 5; i++) //5권의 책 제작
	{
		write(ss[i], "a", "A", j);
	}

	for (int i = 0; i < 5; i++) // 인사
	{
		hello(ss[i], ss[9 - i]);
	}
	for (int i = 0; i < 10; i++)//쓰기
	{
		write(ss[i], "A", "b", j);
	}
	for (int i = 0; i < 10; i++)//읽기
	{
		read(ss[i], st[9 - i]);
	}
	return 0;
}