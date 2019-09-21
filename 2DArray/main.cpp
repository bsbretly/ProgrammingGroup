#include <bits/stdc++.h>

using namespace std;

int findMax(vector<vector<int>> vec) {
    int max(-10000);
    for (auto & i : vec) {
        for (int j : i) {
            if (j > max){
                max = j;
            }
        }
    }
    return max;
}

// Complete the hourglassSum function below.
int hourglassSum(vector<vector<int>> arr) {
    vector<vector<int>> sum(4);
    for (int i=0; i<arr.size(); i++) {
        for (int j=0; j<arr[i].size(); j++) {
            if (i < 4 && 0 <= j && j < 4) {
                int tot = arr[i][j] + arr[i][j + 1] + arr[i][j + 2]
                          + arr[i + 1][j + 1]
                          + arr[i + 2][j] + arr[i + 2][j + 1] + arr[i + 2][j + 2];
                sum[i].push_back(tot);
//                cout<<"i = "<<i<<"\n"<<"j = "<<j<<endl;
//                cout<<"tot = "<<tot<<endl;
                }
        }
    }
    return findMax(sum);
}

int main() {
    int result(0);
    vector<vector<int>> queries{ { 1, 1, 1, 0, 0, 0 },
                                 { 0, 1, 0, 0, 0, 0 },
                                 { 1, 1, 1, 0, 0, 0 },
                                 { 0, 9, 2,-4,-4, 0 },
                                 { 0, 0, 0,-2, 0, 0 },
                                 { 0, 0, 1,-2,-4, 0 } };
    result = hourglassSum(queries);
    cout<<result<<endl;
}