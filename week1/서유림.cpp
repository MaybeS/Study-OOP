// 늦게 내서 죄송합니다ㅠㅠ, 날씨가 너무 더워서 정신이 혼미하네요... 선배도 더위 조심하세요 ㄷㄷ

#include <iostream>
#include <string>
#include <time.h>

using namespace std;


class Book
{
public:
    string title, author, content;
    
    
    Book(string title, string author, string content)
    {
        this->title = title;
        this->author = author;
        this->content = content;
    }

    Book(){}//배열용
    
};

class Student
{
public:
    int age,number;
    string name,major;
    
    Student(string name,string major, int age, int number)
    {
        this->name = name;
        this->major = major;
        this->age = age;
        this->number = number;
    }
    
    void hello(Student s)
    {
        cout << "Hello," << s.name << " my name is " << name << endl;
    }
    void read(Book b)
    {
        cout << name << " read "<< b.title << endl;
    }
    Book write()
    {
        string title, author, content;
        cout << "title : " << endl;
        cin >> title;
        cout << "author : " << endl;
        cin >> author;
        cout << "content : " << endl;
        cin >> content;
        Book new_b = Book(title, author, content);
        return new_b;
    }
    void recommend(Student s, Book b)
    {
        cout << name << " recommends " << b.title << "to " << s.name << endl;
        s.read(b);
    }
    Student(){} //배열용
   
};

Student tutor[10];
int cnt=0;//책 개수
Book lib[15];
int main()
{
    srand((unsigned int)time(NULL));
    string name, major,title,author,content;
    int age, number;
    cout <<"input the name, major, age, number of 10 students"<<endl;
    
    //시작과 동시에 학생 10명을 생성한다.
    for(int i=0;i<10;i++)
    {
        cin>>name>>major>>age>>number;
        tutor[i]=Student(name, major, age, number);
    }
     cout <<"input the title, author, content of 5 books"<<endl;
    //시작과 동시에 책 5권을 생성한다.
    for(int i=0;i<5;i++)
    {
        cin>>title>>author>>content;
        lib[i]=Book(title, author, content);
        cnt++;
    }
    cout <<"Let's make 10 books more!"<<endl;
    
    //처음 만들었던 사람 10명이 새로운 책을 10번 생성한다.Student 클래스의 write 이용.
    for(int i=0;i<10;i++)
        lib[++cnt] = tutor[i].write();
    cout <<"Then, let's read 10 books randomly "<<endl;
    
    //10명의 사람이 랜덤으로 책을 골라서 읽는다.
    for(int i=0;i<10;i++)
        tutor[i].read(lib[rand()%cnt]);
    cout <<"Let's introduce yourself and recommend book."<<endl;
    
    //5명의 사람이 다른 5명에게 랜덤하게 인사를 하고 책을 추천한다.
    for(int i=0;i<5;i++)
    {
        int s1,s2;
        s1=rand()%10;
        s2=rand()%10;
        tutor[s1].hello(tutor[s2]);
        tutor[s1].recommend(tutor[s2],lib[rand()%cnt]);
    }
    system("pause");
    return 0;
}
