#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>


using namespace std;

// 필수 기능
class Animal
{
public:
    virtual void makeSound() = 0;
    ~Animal() {}

};


class Dog : public Animal
{
    void makeSound()
    {
        cout << "Woof Woof" << endl;
    }

};

class Cat : public Animal
{
    void makeSound()
    {
        cout << "Mew Mew" << endl;
    }
};

class Cow : public Animal
{
    void makeSound()
    {
        cout << "Moo Moo" << endl;
    }
};


// --------------------------------------------------------------------- //

// 도전 기능
class Zoo {
private:
    Animal* animals[10] = { nullptr, }; // 동물 객체를 저장하는 포인터 배열
    int count = 0;

public:

    // 동물을 동물원에 추가하는 함수
    // - Animal 객체의 포인터를 받아 포인터 배열에 저장합니다.
    // - 같은 동물이라도 여러 번 추가될 수 있습니다.
    // - 입력 매개변수: Animal* (추가할 동물 객체)
    // - 반환값: 없음
    void addAnimal(Animal* animal)
    {
        if (count < 10 && animals[count] == nullptr)
        {
            animals[count++] = animal;
        }
        else
        {
            cout << "Zoo is full" << endl;
        }

    }

    // 동물원에 있는 모든 동물의 행동을 수행하는 함수
    // - 모든 동물 객체에 대해 순차적으로 소리를 내고 움직이는 동작을 실행합니다.
    // - 입력 매개변수: 없음
    // - 반환값: 없음
    void performActions()
    {
        for (int i = 0; i < 10; i++)
        {
            if (animals[i] != nullptr)
            {
                animals[i]->makeSound();
            }
        }
    }

    // Zoo 소멸자
    // - Zoo 객체가 소멸될 때, 동물 벡터에 저장된 모든 동물 객체의 메모리를 해제합니다.
    // - 메모리 누수를 방지하기 위해 동적 할당된 Animal 객체를 `delete` 합니다.
    // - 입력 매개변수: 없음
    // - 반환값: 없음

    ~Zoo()
    {
        for (int i = 0; i < 10; i++)
        {
            if (animals[i] != nullptr)
            {
                delete animals[i];
                animals[i] = nullptr;
            }

        }

    }
};


// 랜덤 동물을 생성하는 함수
// - 0, 1, 2 중 하나의 난수를 생성하여 각각 Dog, Cat, Cow 객체 중 하나를 동적으로 생성합니다.
// - 생성된 객체는 Animal 타입의 포인터로 반환됩니다.
// - 입력 매개변수: 없음
// - 반환값: Animal* (생성된 동물 객체의 포인터)
Animal* createRandomAnimal()
{
    int a = rand() % 3;

    switch (a)
    {
    case 0:
        return new Dog;
    case 1:
        return new Cat;
    case 2:
        return new Cow;
    default:
        return nullptr;
    }
}




int main() {
    srand(time(NULL));

    cout << "-------------------" << endl;
    cout << "  필수 기능 결과" << endl;
    cout << "-------------------" << endl;
    Animal* ani = new Dog;
    ani->makeSound();
    Animal* ani2 = new Cat;
    ani2->makeSound();
    Animal* ani3 = new Cow;
    ani3->makeSound();


    delete ani;
    delete ani2;
    delete ani3;

    cout << "-------------------" << endl;
    cout << "  도전 기능 결과" << endl;
    cout << "-------------------" << endl;
    Zoo* zoo = new Zoo;
    // 랜덤으로 동물 10마리 추가
    for (int i = 0; i < 10; i++)
    {
        zoo->addAnimal(createRandomAnimal());
    }

    zoo->performActions();
    cout << "-------------------" << endl;

    delete zoo;
}
