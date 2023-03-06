#include <iostream>

namespace algorithm
{
    class BinarySearch
    {
        public:
        template<typename T>
        static inline const T* Search(const T* sortedData,
                const std::size_t& length,
                const T& key)
        {
            auto low = sortedData;
            auto high = sortedData + length - 1;
            
            //Get number of elements in lower half
            auto numberOfElementsInLower = length/2;
            auto mid = sortedData + numberOfElementsInLower;
            
            if(key > *high || key < *low)
            {
               return nullptr;
            }            
            else if(key == *mid)
            {
                return mid;
            }
            else if(length == 1)
            {
                return nullptr;
            }
            else if(key > *mid)
            {
                //Search from mid to upper limit
                auto upperLength = length - numberOfElementsInLower;
                return Search(mid, upperLength, key);
            }
            else
            {
                //Search from lower limit to mid
                return Search(sortedData, numberOfElementsInLower, key);
            }
        }
    };    
}
