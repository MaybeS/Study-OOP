# 첫 주, C와 C++

## 첫째 날
가장 먼저 알고 넘어가야 할 것은 C++은 C의 superset이 아니라는 점 입니다. 정말 비슷한 언어이지만 둘은 서로 다른 언어입니다. 가장 큰 차이점은 절차지향적이던 C와 객체 지향인 C++의 패러다임의 전환에 있을 것입니다. 세세한 차이점들도 조금씩 알아갈 테지만 먼저 절차지향, 객체지향 무엇인지 알아보고 갑시다.

### 절차지향
절차 지향 프로그래밍은 이제 C를 막 배운 우리에게 익숙한 방법입니다. 한 줄 한 줄 적어 내려가며 프로그램을 작성하고 프로그램이 그러한 코드를 한 줄 한 줄 읽어서 하나하나 명령으로 바꿔서 실행하는 그러한 방식을 절차지향이라고 합니다. 말 그대로 '절차'적인 방식이지요.

### 객체지향
객체 지향 프로그래밍은 프로그램을 명령어의 나열로 보지 않고 독립된 **객체**의 모임으로 구성하는 것을 말합니다. 객체는 쉽게 말하면 우리가 실제 세계에서 겪는 사물과 비슷합니다. *누가*, *무엇을* 한다. 와 같은 상호작용을 기술하여 프로그램을 구성하는 것을 말하는데 많은 상황에서 우리가 이전에 사용하던 **절차지향**에 비해 쉽고 간편하게 기술할 수 있습니다.
<hr>
정말 간단하게 사실 그냥 들어본 수준에 해당할 정도로 짤막한 설명이긴 했지만 우리가 C프로그램을 작성할 때 한 줄 한 줄 절차 적으로 실행되던 프로그램이 이제 어떤 **객체**와 **객체**의 상호작용으로 설명될 수 있다는 것만 이해하시면 되요. 간단한 예시를 들어볼까요? 자동차는 객체라고 해봅시다. 이 자동차는 움직이거나 정지하는 행동을 취할 수 있죠. 또한 서로 자동차 간의 충돌이나 연결을 생각해 볼 수도 있을 것입니다. 이 자동차를 움직이기 위해서는 *자동차*라는 객체에 *움직이라는* 명령을 내리면 된다는 소리죠.

그러나 처음부터 **객체**를 설계하고 객체지향적인 프로그램을 구성하는 것은 생각보다 어려운 작업이에요.
그래서 우리는 C에서 배웠던 것처럼 C++을 차근 차근 배워볼 거에요. 물론 C와 어떤 점에서 다르고 왜 다른 지를 알아간다면 더욱 좋겠죠.
그래서 전통적인 시작부터 한번 해봅시다. 바로 Hello, world!를 출력하는 프로그램으로 말이죠.

#### Hello, world!
```
#include <iostream>
using namespace std;
int main()
{
  cout << "Hello, world!" << endl;
  return 0;
}
```
오늘의 숙제는 같은 기능을 하는 C 코드와 이 코드가 어디가 다른지 찾아보는 거에요.
다 찾았다면 옆에 +를 눌러서 무엇이 다른가 적어주세요. 

## 둘째 날
사실 막 그렇게 많은 차이가 있다고 느껴지지는 않을 거에요. 헤더파일의 이름과, using namespace std; 한 줄, 그리고 printf가 이상한 cout << << endl로 바뀐 것 외에는 그렇게 큰 차이도 없게 보여요. C와 C++은 매우 비슷하거든요.

우리는 오늘 간단한 세계를 만들어 볼 거에요. 이 세계에는 사람들이 있고 각 사람들은 나이와 이름을 가지고 있습니다. 각 사람들은 서로 인사를 할 수 있다고 해봐요.

### 클래스
먼저 이런 사람들을 잘 정의해 주어야 합니다. 사람은 나이와 이름을 가지고 인사를 할 수 있어야 한다는 것을 명시해주는 것을 클래스라고 합니다. 이 클래스를 이용하면 여러 사람을 만들어 낼 수 있습니다.
```
#include <iostream>
#include <string>

using namespace std;

class Person 
{
public:
	int age;
	string name;

	void hello(Person p)
	{
		cout << "Hello " << p.name << ", my name is " << name << endl;
	}
};
```
이 코드는 Person이라는 클래스가 정의되어있고 이 Person은 int형의 age(나이)와 string형의 name(이름)을 가지고 있습니다. 또한 hello라는 매서드를 가지고 있는데요, 이 메서드는 다른 Person(사람)을 인자로 받아 그 사람에게 인사를 해줍니다. 하나하나 살펴봅시다.
<hr>
*iostream*과 *string*은 각각 cout과 string을 위한 헤더입니다. string은 문자열을 나타내는 자료형으로 이전의 `char*`와 비슷한 기능을 하지만 좀 더 쓰기 편하고 다양한 기능을 추가로 제공합니다.
<hr>
직관적으로 class Person{}; 은 클래스를 정의하는 부분이라는 것을 알 수 있습니다. class의 이름이 Person이라는 소리겠죠. 여기에 public:이라는 *접근 제한자*가 있습니다. public은 말 그대로 '공용의..'라는 뜻을 가집니다. 즉 밑에 오는 age, name, hello등의 변수와 함수들을 누구나 접근할 수 있다는 뜻입니다. 밑에 가서 좀 더 많은 접근 제한자와 어떻게 쓰이는지 배우도록 합시다. 나머지 부분은 우리가 C에서 했던 것과 크게 다르지 않습니다.

이제 Person인 alice와 charles를 만들고 서로 인사를 시켜보는 코드를 main에 작성해봅시다.
```
int main()
{
	Person alice, charles;
	alice.age = 20;
	alice.name = "alice";

	charles.age = 22;
	charles.name = "charles";;

	alice.hello(charles);
}
```
실행하여 alice가 charles에게 인사를 했다면 성공입니다.

여기서 alice와 charles는 Person**클래스**로 만든 **객체**입니다. hello는 Person클래스의 **매서드**가 됩니다.

### 객체의 삶
인간도 삶처럼 객체도 태어났다가 활동하고 죽어 사라집니다. 객체의 생성과 소멸을 관리하는 **생성자**, **소멸자**는 각각 객체가 생성/소멸 될 때 호출되어 필요한 행동을 할 수 있도록 해줍니다.
우리는 지금 Person이라는 객체에 이름과 나이를 직접 입력해주었는데, 이것을 생성자를 통해서 처리할 수 있습니다.

Person클래스의 생성자와 소멸자는 다음과 같이 써줄 수 있습니다.
```
Person()
{//생성자
}
~Person()
{//소멸자
}
```

그러면 아래와 같은 생성자 소멸자를 Person에 추가하고 실행해봅시다.
```
	Person(int age, string name)
	{
		this->age = age;
		this->name = name;
	}
	~Person()
	{
		cout << name << " is dead." << endl;
	}
```
여기서 this->가 하는 역할은 자기 자신의 변수와 인자의 변수를 구별해주는 역활을 합니다 this->로 표시하면 클래스의 변수라는 것을 명확히 알려줄 수 있으며 중복되는 이름이 없을 경우엔 생략할 수 있습니다.
*아마 포인터를 다루면서 구조체의 포인터에 접근할 때 ->를 사용해본 경험이 있을 겁니다.*

아마 이렇게 생성자와 소멸자를 추가하면 '기본 생상저가 없다'라는 오류를 볼 수 있을 것 입니다. 클래스는 생성자를 선언하지 않더라도 기본 생성자(아무런 인자도 없고 행동도 없는)를 갖습니다. 하지만 하나의 생성자를 정의해주면 기본 생성자를 따로 정해주지 않았다면 기본 생성자는 없어지게 됩니다.

그러면 alice와 charles를 만들어줄 때 우리가 작성한 생성자 형식에 맞춰서
```
Person alice = Person(20, "alice") , charles = Person(22, "charles");
```
이렇게 바꿀 수 있을 것입니다. 이러면 age와 name을 20, alice로 갖는 alice와 22, charles를 갖는 charles라는 Person의 객체들이 생겨났습니다.
이제 `alice.hello(charles);`로 실행하면 아까와 같은 인사 메세지가 뜨지만 charles가 죽었다는 해괴한 메세지를 확인할 수 있습니다. 

그럼 오늘의 숙제는 charles가 어디에서 죽었나 확인해보는 것입니다.

전체코드 
```
#include <iostream>
#include <string>

using namespace std;

class Person 
{
public:
	int age;
	string name;
    
	Person(int age, string name)
	{
		this->age = age;
		this->name = name;
	}
	~Person()
	{
		cout << name << " is dead." << endl;
	}

	void hello(Person p)
	{
		cout << "Hello " << p.name << ", my name is " << name << endl;
	}
};

int main()
{
	Person alice = Person(20, "alice") , charles = Person(22, "charles");
	alice.hello(charles);
	system("pause");
}
```