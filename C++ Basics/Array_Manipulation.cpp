#include <iostream>
#include <vector>

/*
int main() {
    unsigned int n, m;  
    std::cin >> n >> m;

    std::map<unsigned int, std::map<unsigned int, unsigned int>> m_storedElements;
    std::vector<unsigned int> v_storedValue(m);
    for(int i = 0; i < m; i++) {
        unsigned int a, b, value;    
        std::cin >> a >> b >> value;

        std::map<unsigned int, unsigned int> m_in_storedElements;   
        m_in_storedElements[a] = b;
        m_storedElements[i] = m_in_storedElements;
    
        v_storedValue[i] = value;
    }

    std::map<unsigned int, unsigned long int> m_kValue;
    unsigned long int max = 0;
    for(int i = 0; i < m; ++i) {
        std::map<unsigned int, unsigned int> m_in_storedElements;  
        m_in_storedElements = m_storedElements[i];

        for(std::map<unsigned int, unsigned int>::iterator it = m_in_storedElements.begin(); it != m_in_storedElements.end(); it++) { 
            for(auto first = it->first, end = it->second, j = first; j <= end; ++j) {
                m_kValue[j] += v_storedValue[i];
                if(m_kValue[j] > max) {
                    max = m_kValue[j];
                }
            }
        }
    }

    std::cout << max;
    return 1;
}
*/

long arrayManipulation(int n, vector<vector<int>> queries) {
   vector<int> temp = vector<int>(n);
   for(vector<int> query : queries) {
        int first = query[0] - 1, end = query[1] - 1, value = query[2];
        temp[first] += value;
        temp[end + 1] -= value;
   }
   
   long max = INT_MIN, curVal = 0;
   for(int val : temp) {
       curVal += val; 
       if(curVal > max) {
           max = curVal;
       }
   }
    
    return max;
}