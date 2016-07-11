#include <iostream>
#include <string>
#include <ctime>

using namespace std;

#define MAX_BOOK 16
#define MAX_STUDENT 32

string randString()
{
	string ret = "";
	int size = rand() % 16 + 1;
	while (--size)
		ret += 'A' + rand() % 26;
	return ret;
}

class Book
{
public:
	string title, author, content;
	Book(string, string, string);
};

class Student
{
public:
	string name, major;
	int age, number;

	Student(string, int, int, string);

	void hello(Student& student) const {
		cout << "Hi " << student.name << ", my name is " << this->name << ". nice meet you!" << endl;
	}
	void read(Book& book) const {
		cout << book.title << " written by " << book.author << ". " << endl << "contents is " << book.content << endl;
	}
	Book * write() const {
		return new Book(randString(), this->name, randString());
	}
	void recommend(Student& student, Book& book) const {
		cout << student.name << ", plz read " << book.title << ", written by " << book.author << endl;
		student.read(book);
	}
};

static Book * books[MAX_BOOK];
static Student * students[MAX_STUDENT];

Book::Book(string title, string author, string content)
{
	this->title = title;
	this->author = author;
	this->content = content;

	static int bookcnt = 0;
	books[bookcnt++] = this;
}
Student::Student(string name, int age, int number, string major)
{
	this->name = name;
	this->age = age;
	this->number = number;
	this->major = major;

	static int studentcnt = 0;
	students[studentcnt++] = this;
}

int main()
{
	srand(time(NULL));
	for (int i = 0; i < MAX_STUDENT; ++i)
		new Student(randString(), rand() % 10 + 18, 2016000 + rand() % 1000, randString());

	for (int i = 0; i < MAX_BOOK - 5; ++i)
		new Book(randString(), randString(), randString());

	for (int i = 0; i < MAX_STUDENT; ++i)
		students[i]->hello(*students[rand() % MAX_STUDENT]);

	for (int i = 0; i < 5; ++i)
		students[rand() % MAX_STUDENT]->write();

	for (int i = 0; i < MAX_STUDENT; ++i)
		students[i]->read(*books[rand() % MAX_BOOK]);
}