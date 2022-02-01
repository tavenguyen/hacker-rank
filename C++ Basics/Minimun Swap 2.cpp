// https://www.hackerrank.com/challenges/minimum-swaps-2/

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