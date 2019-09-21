#include <iostream>
#include <iomanip>
#include <cmath>
#include <queue>
#include <sstream>

using namespace std;
// compute s(r) according to problem statement

double s(double r, int n, int a, int d) {
    double x = 0;
    double r_k_minus_one = 1; // r^0 is always 0
    for (int k = 1; k <= n; k++) {
        x += (a - d * k) * r_k_minus_one;
        r_k_minus_one *= r;
    }
    return x;
}

int main() {
    int q,a,d,n,x;

    cin>>q;
    stringstream f;
    for(int i = 0; i < q; i++) {
        cin>>a>>d>>n>>x;

        double r_lower = -10000;
        double r_upper = 10000;

        // until the range is small enough
        while (r_upper - r_lower > 0.0000000000001) {
            double r_mid = (r_upper + r_lower) / 2;
            // find result at r_midpoint
            double x_guess = s(r_mid,n,a,d);

            // adjust borders
            if (x_guess < -x)
                r_upper = r_mid;
            else
                r_lower = r_mid;
        }

        if (i < q-1)
            cout<<fixed<<setprecision(12)<<(r_upper + r_lower) / 2<<endl;
        else
            cout<<fixed<<setprecision(12)<<(r_upper + r_lower) / 2;
    }

    cout<<f.str();

    return 0;
}
