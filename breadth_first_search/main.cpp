#include <queue>
#include <map>
#include <string>
#include <vector>
#include <list>
#include <iostream>

using namespace std;

class Person
{
public:
    string name;
    string profession;
    list<Person*> friends;
    string toString()
    {
        return name + " " + profession;
    }
};

Person* breadthFirstSearch(Person* person, const string& prof)
{
    if(!person)
    {
        return nullptr;
    }

    queue<Person*> pool;
    pool.push(person);

    while(!pool.empty())
    {
        Person* cur = pool.front();
        pool.pop();
        if(cur->profession == prof)
        {
            return cur;
        }
        else
        {
            for(const auto& fr : cur->friends)
            {
                pool.push(fr);
            }
        }
    }
    return nullptr;
}

int main()
{
    Person* me = new Person{"Me", "programmer", {}};
    Person* p1 = new Person{"Anton", "engeneer", {}};
    Person* p2 = new Person{"Slava", "engeneer", {}};
    Person* p3 = new Person{"Alexander", "engeneer", {}};
    Person* p4 = new Person{"Evgeniy", "front", {}};
    me->friends = {p1,p2,p3,p4};

    Person* p5 = new Person{"Rodion", "yurist", {}};
    Person* p6 = new Person{"Nadya", "rejissyor", {}};
    p1->friends = {p5,p6};

    cout <<breadthFirstSearch(me, "yurist")->toString() <<endl;

    return 0;
}
