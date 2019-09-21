#include <bits/stdc++.h>

using namespace std;

vector<int> dynamicArray(int n, vector<vector<int>> queries) {
    int lastAnswer(0);
    vector<vector<int>> seqList(n);
    for (auto & querie : queries) {
        int x = querie[1];
        int y = querie[2];
        //type 1 query
        if (querie[0] == 1) {
            seqList[(x^lastAnswer)%n].push_back(y);
        }
            //type 2 query
        else {
            vector<int> seq = seqList[(x^lastAnswer)%n];
            lastAnswer = seq[y%seq.size()];
            cout << lastAnswer << endl;
        }
    }
}

int main() {
//    std::vector<int> v(5,99);
//    for(int i : v) {
//        std::cout << i << std::endl;
//    }
    int n = 2;
    vector<vector<int>> queries{ { 1, 0, 5 },
                             { 1, 1, 7 },
                             { 1, 0, 3 },
                             { 2, 1, 0 },
                             { 2, 1, 1 } };
    dynamicArray(n,queries);
}