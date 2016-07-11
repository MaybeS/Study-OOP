#include <iostream>
#include <string>
using namespace std;
int k = 0;
class Book{								//책 클래스
public:
	string title;							//책 제목
	string author;							//저자
	string contents;						//내용

	Book(string title="", string author="", string contents=""){	//책 생성자
		this->title = title;
		this->author = author;
		this->contents = contents;
	};
	static Book written(string title, string author, string contents);
	~Book(){};							//책 소멸자
};

Book bookshelf[20];
class Student{								//학생 클래스
public:
	string name;							//학생 이름
	int age;							//학생 나이
	int student_num;						//학생 학번
	string major;							//학생 전공
	//static Book bookshelf
	Student(string name="", int age=20, int student_num=2016000000, string major="")	//학생 생성자
	{
		this->name = name;
		this->age = age;
		this->student_num = student_num;
		this->major = major;
	};
	~Student(){};							//학생 소멸자
	void read(Book book)						//책 읽기 메소드
	{
		cout<<this->name<<" is read a book that named "<<book.title<<endl;
	}
	Book write()							//책 쓰기 메소드
	{
		cout<<"Book writing.."<<"this is your book, "<<this->name<<endl;
		string title, contents, author;	
		cout<<"Please input your book's title : ";
		cin >> title;
		cout<<"Please input your book's contents : ";
		cin >> contents;
		author = this->name;
		Book book = Book(title,author,contents);
		bookshelf[k] = book;
		k++;
		return book;
	}
	void hello(Student other)					//인사 메소드
	{
		cout<<"Hello, "<<other.name<<"!"<<endl;
	}
	void recommend(Student other, Book recommended)			//책 추천 메소드
	{
		cout<<other.name<<"! This book is my recommend!"<< endl;
		other.read(recommended);
	}
};

	

Book Book::written(string title, string author, string contents){
        Book book = Book(title,author,contents);
        bookshelf[k] = book;
        k++;
        return book;
        }
int main()
{
	Student student[10];
	string name = "student";
	for(int i=0;i<10;i++){									//학생 10명 초기화
		name = "student";
		student[i] = Student(name.append(1,'_').append(1,'a'+(char)i),20,2016000000+i*5,"computer science");
	}

	Book book[5];
	string title;
	for(int i=0;i<5;i++){
		title = "book";
		book[i] = Book::written(title.append(1,'_').append(1,'a'+(char)i),"","");
	}
	student[2].hello(student[5]);			//1회 인사
	student[2].recommend(student[5],book[2]);	//1회 읽기
	student[7].hello(student[1]);			//2회 인사
	student[1].read(book[0]);			//2회 읽기
	Book book_write_8 = student[8].write();		//1회 쓰기
	student[8].recommend(student[3],book_write_8);	//3회 읽기
	student[0].read(book[4]);			//4회 읽기
	Book book_write_0 = student[0].write();		//2회 쓰기
	student[9].hello(student[4]);			//3회 인사
	student[9].recommend(student[4],book[3]);	//5회 읽기
	Book book_write_4 = student[4].write();		//3회 쓰기
	Book book_write_9 = student[9].write();		//4회 쓰기
	student[5].hello(student[4]);			//4회 인사
	student[9].recommend(student[5],book_write_9);	//6회 읽기
	student[4].recommend(student[5],book_write_4);	//7회 읽기
	Book book_write_6 = student[6].write();		//5회 쓰기
	Book book_write_6_1 = student[6].write();	//6회 쓰기
	Book book_write_3 = student[3].write();		//7회 쓰기
	student[0].hello(student[5]);			//5회 인사
	Book book_write_5 = student[5].write();		//8회 쓰기
	student[5].recommend(student[0],book_write_5);	//8회 읽기
	Book book_write_7 = student[7].write();		//9회 쓰기
	Book book_write_7_1 = student[7].write();	//10회 쓰기
	student[6].read(book_write_7);			//9회 읽기
	student[9].read(book_write_7_1);		//10회 읽기
	for(int i=0;i<15;i++){
		cout << bookshelf[i].title <<' '<<bookshelf[i].author<<' '<<bookshelf[i].contents<<endl;
	}
}
