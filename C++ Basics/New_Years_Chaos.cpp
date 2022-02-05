// https://www.hackerrank.com/challenges/new-year-chaos/problem?
#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);
vector<string> split(const string &);
map<int, bool> m_storedValue;
 
void minimumBribes(vector<int> q, int n) {
    int count = 0;
    for(map<int, bool>::reverse_iterator it = m_storedValue.rbegin(); it != m_storedValue.rend(); it++) {
        //cout << it->first << " " << it->second << endl;
        
        if(!(it->second)) {
            int index = it->first;
            if(q[index - 1] == index + 2) {
                count += 2;
                std::swap(q[index - 1], q[index]);
                std::swap(q[index], q[index + 1]);
                m_storedValue[index] = false;
            }
            
            if(q[index - 1] == index + 1) {
                count += 1;
                std::swap(q[index - 1], q[index]);
                m_storedValue[index] = false;
            }
        }
    }   
    
    cout << count << endl;
}

int main()
{
    string t_temp;
    getline(cin, t_temp);

    int t = stoi(ltrim(rtrim(t_temp)));

    for (int t_itr = 0; t_itr < t; t_itr++) {
        string n_temp;
        getline(cin, n_temp);

        int n = stoi(ltrim(rtrim(n_temp)));

        string q_temp_temp;
        getline(cin, q_temp_temp);

        vector<string> q_temp = split(rtrim(q_temp_temp));

        vector<int> q(n);

        m_storedValue.clear();
        bool success = false;
        for (int i = 0; i < n; i++) {
            int q_item = stoi(q_temp[i]);

            q[i] = q_item;
            
            bool condition = false;
            if(q[i] == i + 1 || q[i] < i + 1) {
                condition = true;
            }
            
            if(i + 1 - q[i] <= -3) {
                cout << "Too chaotic" << endl;
                success = true;
                break;
            }
            
            m_storedValue[i + 1] = condition;
        }

        if(!success) 
            minimumBribes(q, n);
    }

    return 0;
}

string ltrim(const string &str) {
    string s(str);

    s.erase(
        s.begin(),
        find_if(s.begin(), s.end(), not1(ptr_fun<int, int>(isspace)))
    );

    return s;
}

string rtrim(const string &str) {
    string s(str);

    s.erase(
        find_if(s.rbegin(), s.rend(), not1(ptr_fun<int, int>(isspace))).base(),
        s.end()
    );

    return s;
}

vector<string> split(const string &str) {
    vector<string> tokens;

    string::size_type start = 0;
    string::size_type end = 0;

    while ((end = str.find(" ", start)) != string::npos) {
        tokens.push_back(str.substr(start, end - start));

        start = end + 1;
    }

    tokens.push_back(str.substr(start));

    return tokens;
}
