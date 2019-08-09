#include <iostream>
#include <iomanip>
#include <queue>
#include <map>
#include <algorithm>

// resource here: https://stackoverflow.com/questions/35401523/searching-for-multiple-elements-using-stdfind

using namespace std;

struct per_product_spoilage
{
    per_product_spoilage(int prod, int a, int b): prod(prod), a(a), b(b) {};
    int prod, a, b;
};

//overload << operator for debugging
ostream& operator<< (ostream &out, vector<per_product_spoilage> &pps)
{
    for(auto it = pps.begin(); it != pps.end(); ++it) {
        out << "pps = (" << it->prod << "," << it->a << "," << it->b << ")" << " ";
    }
    return out;
}

//greatest common divisor
int gcd(int a, int b) {
    if (b == 0)
        return a;
    return gcd(b, a % b);
}

int main() {
    int product_total;
    cin >> product_total;

    //create a map: the key is the spoilage ratio m, the value is the per_product_storage struct
    map<float, vector<per_product_spoilage>> ratio_map;
    int a[product_total];
    int b[product_total];

    //total product sum
    int a_sum = 0;
    int b_sum = 0;

    //total spoilage ratio numerator and denominator
    int m_t_num = 0;
    int m_t_den = 0;

    for (int i = 0; i < product_total; i++) {
        cin >> a[i];
        a_sum += a[i];
    }

    for (int i = 0; i < product_total; i++) {
        cin >> b[i];
        b_sum += b[i];
    }

//    cout << "total number of products: " << product_total << endl;
    for (int i = 0; i < product_total; i++) {
//        cout << "A" << "[" << i << "] = " << a[i] << '\n'
//             << "B" << "[" << i << "] = " << b[i] << '\n';
    }
//    cout << "A sum = " << a_sum << '\t'
//         << "B sum = " << b_sum << '\n';

    //for each product
    for (int i = 0; i < product_total; i++) {
        //cycle through company A
        for (int j = 1; j <= a[i]; j++) {
            //cycle through company B
            for (int k = 1; k <= b[i]; k++) {
                auto a_s = (float) j;
                auto b_s = (float) k;
                float b_pp_spoilage = b_s / (float) b[i];
                float a_pp_spoilage = a_s / (float) a[i];
                float m = b_pp_spoilage / a_pp_spoilage;
//                cout << "m = " << m << endl;

                //define struct that holds product total, company A total and company B total, respectively
                per_product_spoilage pps(i, j, k);

                //problem description defines m > 1
                if (m > 1) {
                    //count method returns number of matches for a given key
                    if (ratio_map.count(m) > 0) {
                        //create map iterator that searches for the key m
                        //it->first is the key iterator, it->second is the value iterator
                        auto it = ratio_map.find(m);
                        if (it != ratio_map.end())
                            //add new indices to the value vector of the map when m is already in ratio_map
                            it->second.push_back(pps);
                    }
                    //if m doesn't exist in ratio_map yet, populate the map with new m(key) and v_pps(value)
                    else {
//                        cout<<"first product added to map when i = " << i << endl;
                            vector<per_product_spoilage> v_pps;
                            v_pps.push_back(pps);
                            //populate map
                            ratio_map.insert(pair<float, vector<per_product_spoilage>>(m, v_pps));
                    }

                }
            }
        }
    }

    map<float, vector<per_product_spoilage>>::iterator it;
    for (it = ratio_map.begin(); it != ratio_map.end(); ++it) {
        cout << "m = " << it->first << ":" << '\t'
             << it->second
             << "with size " << it->second.size()
             << endl;
    }

    for (it = ratio_map.begin(); it != ratio_map.end(); ++it) {
        if (it->second.size() >= product_total) {
            //check that we have a spoilage number for each product

            vector<per_product_spoilage>:: iterator check;
            check = find_if(it->second.begin(), it->second.end(), [](per_product_spoilage x) {
                return x.prod == 0;
            });

            cout << "p = " << check->prod <<endl;

            int a_sum_s = it->second[0].a + it->second[1].a + it->second[2].a;
            int b_sum_s = it->second[0].b + it->second[1].b + it->second[2].b;
            m_t_num = a_sum_s*b_sum / gcd(a_sum_s*b_sum,b_sum_s*a_sum);
            m_t_den = b_sum_s*a_sum / gcd(a_sum_s*b_sum,b_sum_s*a_sum);

            break;

        }
    }

    cout << m_t_num << "/" << m_t_den << endl;
    return 0;
}