#include <iostream>
#include <fstream>
#include <unordered_map>
#include <unordered_set>
#include <vector>
using namespace std;
int main() {
    fstream file("twitter.csv");
    unordered_map<string, int> mp;
    vector<pair<int, string>> inf;
    unordered_set<string> st; //use hash table and push not repeated value
    string word; //read from file
    vector<string> vc; //store file value
    while (getline(file, word)) {
        st.insert(word); //push each row in set
    } // n
    for (auto &it: st) { //push elements in the vector
        vc.push_back(it);
    }//n
    for (int i = 0; i < vc.size(); ++i) { // loop for each record in file
        int indx = 0; // position of ","
        string id2;
       for (int j = 0; j < vc[i].length(); ++j) { //loop for each  and search for ',' then
            if (vc[i][j] == ',') {
                indx = j + 1;
                break;
            }
        }
        for (int j = indx; j < vc[i].length(); ++j) {
            id2 += vc[i][j];
        }
        mp[id2]++;
    }//n
    for (auto &it: mp) {
        inf.push_back(make_pair(it.second, it.first));
    }//n
    sort(inf.begin(), inf.end()); // nlogn
    for (int i = inf.size() - 1; i >=inf.size()-10 ; --i) {
        cout << inf[i].second << " has " << inf[i].first << endl;
    }//n


    return 0; // total 5n + nlogn
}