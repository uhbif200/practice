#ifndef QUICK_SORT_H
#define QUICK_SORT_H

#include <vector>
#include <random>
#include <time.h>

std::vector<int> quickSort(const std::vector<int>& src)
{
    using namespace std;
    if(src.empty() || src.size() == 1)
    {
        return src;
    }

    vector<int> result;
    result.reserve(src.size());
    if(src.size() == 2)
    {
        if(src[0] < src[1])
        {
            result.push_back(src[0]);
            result.push_back(src[1]);
        }
        else
        {
            result.push_back(src[1]);
            result.push_back(src[0]);
        }
        return result;
    }
    else
    {
        vector<int> lower, higher;
        lower.reserve(src.size());
        higher.reserve(src.size());

        int random_index = rand() % src.size();
        for(int i = 0; i < src.size(); i++)
        {
            if(i == random_index)
            {
                continue;
            }
            if(src[i] <= src[random_index])
            {
                lower.push_back(src[i]);
            }
            else
            {
                higher.push_back(src[i]);
            }
        }
        vector<int> lower_sort = quickSort(lower);
        vector<int> higher_sort = quickSort(higher);
        for(const auto& elem : lower_sort)
        {
            result.push_back(elem);
        }
        result.push_back(src[random_index]);
        for(const auto& elem : higher_sort)
        {
            result.push_back(elem);
        }
        return result;
    }

}


#endif // QUICK_SORT_H
