#include <iostream>
#include <string>
#include <time.h>

#define MAX 100

using namespace std;

class Book
{
public:

	string title;
	string author;
	string content;

	Book()
	{
	}

	Book(string content, string title, string author)
	{
		this->title = title;
		this->author = author;
		this->content = content;
	}
};

class Student
{
public:

	string name;
	int age;
	int number;
	string major;

	void read(Book x)
	{
		cout << name << " read the book <<" << x.title << ">>" << endl;
	}

	Book write(string content, string title)
	{
		Book x = Book(content, title, name);
		return x;
	}

	void hello(Student x)
	{
		cout << "Hello " << x.name << ", my name is " << name << endl;
	}

	void recommend(Student another, Book x)
	{
		another.read(x);
	}
};

int main()
{
	Student group[10];
	Book shelf[MAX];
	int shelfPointer = 5;

	char title[10] = "Book of A";

	srand(time(NULL));

	for (int i = 0; i < 10; i++)
		group[i].name = 'A' + i;

	shelf[0] = Book("IN 1977, AS TWELVE-YEAR-OLD THEO STRUGGLES WITH A SCIENCE CLASS PROJECT ON SPACE EXPLORATION, QUESTIONS EMERGE ABOUT WHY HIS FATHER NEVER RETURNED FROM VIETNAM AND WHY THEO'S MOTHER HAS BEEN KEEPING SECRETS FOR MANY YEARS.", "Greetings From Planet Earth", "Barbara Kerley");
	shelf[1] = Book("Far in the future, the World Controllers have created the ideal society.", "Brave New World", "Aldous Huxley");
	shelf[2] = Book("Written in 1948, 1984 was George Orwell¡¯s chilling prophecy about the future.", "1984", "George Orwell");
	shelf[3] = Book("The Republic is a Socratic dialogue, written by Plato around 380 BC, concerning the definition of justice.", "The Republic", "Plato");
	shelf[4] = Book("The novel is a nostalgic story of loss and burgeoning sexuality.", "Norwegian Wood", "Haruki Murakami");

	for (int i = 0; i < 10; i++)
	{
		group[i].hello(group[rand() % 10]);
		group[i].read(shelf[rand() % shelfPointer]);
		
		title[8] = title[8] + 1;
		
		shelf[shelfPointer] = group[i].write("CONTENT", title);

		shelfPointer++;
	}

	system("pause");
	return 0;
}