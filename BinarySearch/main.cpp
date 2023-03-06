#include <iostream>
#include <vector>

#include "BinarySearch.hpp"

using namespace algorithm;
int main()
{
    int sortedInts[] {1, 2, 3, 4, 5, 6};
    int searchForKeys [] {4,2,9,0,3};

    for(auto key : searchForKeys)
    {
        std::cout << "search for: " << key << std::endl;
        auto val = BinarySearch::Search<int>(sortedInts, sizeof(sortedInts)/sizeof(int), key);
        if(val != nullptr)
        {
            std::cout << "found value: " << *val << std::endl;
        }    
        else
        {
            std::cout << "value not found" << std::endl;
        }
    }
    return 0;
}
