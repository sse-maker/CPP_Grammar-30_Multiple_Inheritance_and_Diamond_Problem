//
//  main.cpp
//  30_Multiple_Inheritance_and_Diamond_Problem
//
//  Created by 세광 on 2021/07/23.
//

// 다중 상속과 다이아몬드 문제 (객체 지향 프로그래밍의 문제점)
// 다중 상속의 경우 웬만하면 쓰지 않는 것이 좋음

// 다중 상속은 인터페이스로부터만 받는다.
// 인터페이스: 모든 메서드가 순수 가상 함수이고 비정적 멤버 변수는 없는 class
// 추상 class: 순수 가상 함수가 하나 이상 들어 있는 class
// 다형적 class: 가상 함수가 하나 이상 들어 있는 class

#include <iostream>

using namespace std;

struct IPerson {
    virtual ~IPerson() {}
    virtual void Eat() = 0;
    virtual int GetAge() = 0;
};

struct IStudent : virtual IPerson {
    virtual void Study() = 0;
};

struct Student : IStudent {
    void Eat() { cout << "Eat!" << endl; }
    void Study() { cout << "Study!" << endl; }
    int GetAge() { return age; }
    int age;
};

struct IWorker : virtual IPerson {
    virtual void Work() = 0;
};

struct Researcher : IStudent, IWorker {
    void Eat() { cout << "Eat!" << endl; }
    void Study() { cout << "Study!" << endl; }
    void Work() { cout << "Work!" << endl; }
    int GetAge() { return age; }
    int age;
};

int main() {
    Student s;
    s.Study();
    Researcher r;
    r.Study();
    r.Work();
    
    IPerson *p = new Researcher;
    p->GetAge();
    delete p;
    p = new Student;
    p->GetAge();
}
