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
    std::cout << MyVec[0] << "\n";
    std::cout << MyVec[1] << "\n";
    std::cout << MyVec[2] << "\n";
    std::cout << MyVec[3] << "\n";



    std::vector<int> Vec(0);
    Vec.push_back(1);
    Vec.push_back(2);
    Vec.push_back(3);
    Vec.push_back(4);


    return 0;
}
