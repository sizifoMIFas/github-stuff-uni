#include <algorithm>
#include <iostream>
#include <vector>

int main()
{
    std::vector<int> vektorius = {1, 4, 3, 2, 5};

    // Sort vector in ascending order
    sort(vektorius.begin(), vektorius.end());

    for (int i : vektorius){
        std::cout << i << " ";
    }
    return 0;

}