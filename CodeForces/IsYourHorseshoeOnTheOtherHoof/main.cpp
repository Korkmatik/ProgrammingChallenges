#include <iostream>
#include <vector>

void InsertIfNotContains(std::vector<int>& vec, int value)
{
    bool contains = false;
    for (int i = 0; i < vec.size(); i++)
    {
        if (vec[i] == value)
        {
            contains = true;
            break;
        }
    }

    if(!contains)
    {
        vec.push_back(value);
    }
}

int main()
{
    int s1, s2, s3, s4;
    std::cin >> s1 >> s2 >> s3 >> s4;

    std::vector<int> uniqueValues;
    InsertIfNotContains(uniqueValues, s1);
    InsertIfNotContains(uniqueValues, s2);
    InsertIfNotContains(uniqueValues, s3);
    InsertIfNotContains(uniqueValues, s4);

    std::cout << 4 - uniqueValues.size() << std::endl;

    return 0;
}