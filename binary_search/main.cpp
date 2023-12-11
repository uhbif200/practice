#include <vector>
#include <iostream>
#include <assert.h>
#include <random>
#include <algorithm>

using namespace std;

vector<int> test {0,1,2,3,4,5,6,7,8,9,10};
vector<int> test2 {2,4,6,8,10,12,14,16,18,20};

template <typename T>
int binarySearch(const vector<T>& src, int target)
{
    if(src.size() == 0 || src[0] > target)
    {
        return -1;
    }

    int low_index = 0;
    int high_index = src.size() - 1;
    int step = 1;

    while(true)
    {
        cout <<"Step " <<step <<endl;
        step++;

        if(low_index >= high_index)
        {
            if(src[high_index] <= target)
            {
                return high_index;
            }
            else
            {
                return low_index;
            }
        }

        int middle_index = (high_index + low_index) / 2;

        if(src[middle_index] == target)
        {
            return middle_index;
        }

        if(src[middle_index] > target)
        {
            high_index = middle_index - 1;
        }
        else //src[middle_index] < target
        {
            low_index = middle_index + 1;
        }

    }
    return 0;
}

int main()
{
    for(int i = 0; i < test.size(); i++)
    {
        int scope = test[i] - 1;
        int search_result = binarySearch(test, scope);
        cout <<"Scope: " <<scope <<" result: " <<(search_result < 0 ? "nan" : to_string(test[search_result])) <<endl;
    }

    cout <<"Test2" <<endl;

    for(int i = 0; i < test2.size(); i++)
    {
        int scope = test2[i] - 1;
        int search_result = binarySearch(test2, scope);
        cout <<"Scope: " <<scope <<" result: " <<(search_result < 0 ? "nan" : to_string(test2[search_result])) <<endl;
    }

    cout <<"Test3" <<endl;

    for(int i = 0; i < test.size(); i++)
    {
        int scope = test[i] * 2;
        int search_result = binarySearch(test, scope);
        cout <<"Scope: " <<scope <<" result: " <<(search_result < 0 ? "nan" : to_string(test[search_result])) <<endl;
    }

    cout <<"Random test int" <<endl;
    {
        std::random_device dev;
        std::mt19937 rng(dev());
        std::uniform_int_distribution<std::mt19937::result_type> dist(0, 1000); // distribution in range [1, 6]
        vector<int> rand_int_vec;
        rand_int_vec.reserve(1000);
        for(int i = 0 ; i < 1000; i++)
        {
            rand_int_vec.push_back(dist(rng));
        }
        std::sort(rand_int_vec.begin(), rand_int_vec.end());

        for(int i = 0 ; i < 10 ; i++)
        {
            int scope = dist(rng);
            int result = binarySearch(rand_int_vec, scope);
            cout <<"Scope: " <<scope <<" result: " <<(result < 0 ? "nan" : to_string(rand_int_vec[result])) <<endl;

        }

    }

    cout <<"Random test float" <<endl;
    {
        std::random_device dev;
        std::mt19937 rng(dev());
        std::uniform_int_distribution<std::mt19937::result_type> dist(0, 1000); // distribution in range [1, 6]
        vector<float> rand_float_vec;
        rand_float_vec.reserve(1000);
        for(int i = 0 ; i < 1000; i++)
        {
            rand_float_vec.push_back(((float)dist(rng)) / 10.0);
        }
        std::sort(rand_float_vec.begin(), rand_float_vec.end());

        for(int i = 0 ; i < 10 ; i++)
        {
            float scope = ((float) dist(rng)) / 10.0;
            int result = binarySearch(rand_float_vec, scope);
            cout <<"Scope: " <<scope <<" result: " <<(result < 0 ? "nan" : to_string(rand_float_vec[result])) <<endl;

        }

    }

    return 0;
}
