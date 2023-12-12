#include <QCoreApplication>
#include <quick_sort.h>
#include <vector>
#include <iostream>

int main()
{
    using namespace std;
    srand(time(NULL));

    //simple
    {
        vector<int> test({2,5,7,21,64,3,23,4,35,67,53});
        vector<int> result = quickSort(test);
        for(const auto& val : result)
        {
            cout <<val <<" ";
        }
        cout <<endl;
    }

    //big
    {
        vector<int> test;
        test.reserve(100000);
        for(int i = 0; i < 100000; i++)
        {
            test.push_back(rand() % 100000);
        }
        vector<int> result = quickSort(test);
        for(const auto& val : result)
        {
            cout <<val <<" ";
        }
        cout <<endl;
    }
    return 0;
}
