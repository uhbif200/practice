#include <vector>
#include <iostream>
#include <assert.h>

using namespace std;

vector<int> test {0,1,2,3,4,5,6,7,8,9,10};

vector<int> test2 {2,4,6,8,10,12,14,16,18,20};


int binarySearch(const vector<int> src, int target)
{
    if(src.size() == 0 || src[0] > target)
    {
        return -1;
    }

    int low_index = 0;
    int high_index = src.size() - 1;

    while(true)
    {
        if(high_index - low_index == 1)
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

        int middle_index = ( (high_index - low_index) / 2) + low_index;

        if(src[middle_index] == target)
        {
            return middle_index;
        }

        if(src[middle_index] > target)
        {
            high_index = middle_index;
        }
        else //src[middle_index] < target
        {
            low_index = middle_index;
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
    return 0;
}
