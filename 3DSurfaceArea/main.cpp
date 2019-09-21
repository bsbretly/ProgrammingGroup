#include <bits/stdc++.h>

using namespace std;

vector<vector<int>> transpose(vector<vector<int> > &b) {
    vector<vector<int> > trans_vec(b[0].size(), vector<int>());
    for (auto & i : b) {
        for (int j = 0; j < i.size(); j++) trans_vec[j].push_back(i[j]);
    }
    return trans_vec;
}

// Complete the surfaceArea function below.
int surfaceArea(vector<vector<int>> A) {
    int sum_base(2*A.size()*A[0].size()); //add top and bottom scales to start
    int sum_left_right(0);
    int sum_front_back(0);
    //left and right
    for(int i=0;i<A.size();i++) {
        //iterate up
        sum_left_right += A[i][0]; //first element in vector
        for(int j=1;j<A[0].size();j++) {
            int diff = A[i][j] - A[i][j-1];
            if (diff < 0) {
                sum_left_right += abs(diff);
            }
        }
        //iterate back
        sum_left_right += A[i][A[0].size()-1]; //last element in vector
        for(int j=A[0].size()-1;j--;) {
            int diff = A[i][j] - A[i][j+1];
            if (diff < 0) {
                sum_left_right += abs(diff);
            }
        }
    }
    //front and back
    auto A_T = transpose(A);
    for(int i=0;i<A_T.size();i++) {
        //iterate up
        sum_front_back += A_T[i][0]; //first element in vector
        for(int j=1;j<A_T[0].size();j++) {
            int diff = A_T[i][j] - A_T[i][j-1];
            if (diff < 0) {
                sum_front_back += abs(diff);
            }
        }
        //iterate back
        sum_front_back += A_T[i][A_T[0].size()-1]; //last element in vector
        for(int j=A_T[0].size()-1;j--;) {
            int diff = A_T[i][j] - A_T[i][j+1];
            if (diff < 0) {
                sum_front_back += abs(diff);
            }
        }
    }
    return sum_front_back + sum_left_right + sum_base;
}


int main() {
    vector<vector<int>> queries{ { 1, 3, 4 },
                                 { 2, 2, 3 },
                                 { 1, 2, 4 } };
//    vector<vector<int>> queries{ { 51 },
//                                 { 32 },
//                                 { 28 },
//                                 { 49 },
//                                 { 28 },
//                                 { 21 },
//                                 { 98 },
//                                 { 56 },
//                                 { 99 },
//                                 { 77 },};
//    vector<vector<int>> queries{ { 4 },
//                                 { 3 },
//                                 { 2 },
//                                 { 4 },
//                                 { 3 },
//                                 { 1 },
//                                 { 2 },
//                                 { 3 },};
    int sum = surfaceArea(queries);
    cout<<"sum = "<<sum<<endl;
}
