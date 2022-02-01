/*
Link: https://www.hackerrank.com/challenges/minimum-swaps-2/problem
i   arr                         swap (indices)
0   [7, 1, 3, 2, 4, 5, 6]       swap (0,3)
1   [2, 1, 3, 7, 4, 5, 6]       swap (0,1)
2   [1, 2, 3, 7, 4, 5, 6]       swap (3,4)
3   [1, 2, 3, 4, 7, 5, 6]       swap (4,5)
4   [1, 2, 3, 4, 5, 7, 6]       swap (5,6)
5   [1, 2, 3, 4, 5, 6, 7]
*/

#include <iostream>
#include <map>
int main() {
    int n;
    std::cin >> n;

    std::map<unsigned int, unsigned int> m_storedElements; 
    for(int i = 1; i <= n; ++i) {
        int value;
        std::cin >> value;

        m_storedElements[i] = value;
    } 

    int count = 0;
    while(true) {
        bool success = false;
        for(int i = 1; i <= n; i++) {
            if(m_storedElements[i] != i) { 
                std::swap(m_storedElements[i], m_storedElements[m_storedElements[i]]);
                count++;
                success = true;
            }
        }

        if(success == false) {
            break;
        }
    }

    std::cout << count;
    return 0;
}