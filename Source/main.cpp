#include "AlignedVector.h"
#include <vector>
#include <iostream>

int main()
{
    
    AVector<int> MyVec(66);

    MyVec.Add(77);
    MyVec.Add(2);
    MyVec.Add(3);
    MyVec.Add(4);
    for (const auto& v : MyVec)
    {
        std::cout << v << "\n";
    }


    return 0;
}
