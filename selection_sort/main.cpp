#include <vector>
#include <iostream>
#include <random>
#include <time.h>

using namespace std;

template<typename T>
vector<T> selectionSort(vector<T> src)
{
    vector<T> result;
    result.reserve(src.size());

    int operations = 0;
    while(!src.empty())
    {
        int min_index = 0;
        for(int i = 1; i < src.size(); i++)
        {
            operations++;
            if(src[min_index] > src[i])
            {
                min_index = i;
            }
        }
        result.push_back(src[min_index]);
        src.erase(src.begin() + min_index);
    }
    cout <<"Arr size: " <<result.size() <<" operations " <<operations <<endl;
    return result;
}

int main()
{
    srand(time(NULL));

    vector<int> test1{0,4,2,6,3,10,5,2,2,2,3,4,7,12};

    for(auto num : selectionSort(test1))
    {
        cout <<num <<" ";
    }
    cout <<endl;


    {
        vector<int> testBig;
        testBig.reserve(10000);
        for(int i = 0; i < 10000; i++)
        {
            testBig.push_back(rand() % 10000);
        }

        for(auto num : selectionSort(testBig))
        {
            cout <<num <<" ";
        }
        cout <<endl;
    }

    {
        vector<float> testBigFloat;
        testBigFloat.reserve(10000);
        for(int i = 0; i < 10000; i++)
        {
            testBigFloat.push_back((float)(rand() % 10000) / 10.0);
        }

        for(auto num : selectionSort(testBigFloat))
        {
            cout <<num <<" ";
        }
        cout <<endl;
    }
    return 0;
}
