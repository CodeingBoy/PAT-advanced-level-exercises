// PAT Advanced Level Exercise 1002 A+B for Polynomials
// Language: C++(C++11)

#include <iostream>
#include <map>
#include <cstdio>

using namespace std;

int main(void) {
    while (true) {
        map<int, double> polynomial_info;

        int num_count;
        cin >> num_count;
        if (cin.eof()) {
            break;
        }

        while (num_count--) {
            int exponent;
            double coefficient;
            cin >> exponent >> coefficient;

            if (polynomial_info.count(exponent)) {
                polynomial_info[exponent] += coefficient;
            } else {
                polynomial_info[exponent] = coefficient;
            }

            if (polynomial_info[exponent] == 0) {
                polynomial_info.erase(exponent);
            }
        }

        cin >> num_count;
        while (num_count--) {
            int exponent;
            double coefficient;
            cin >> exponent >> coefficient;

            if (polynomial_info.count(exponent)) {
                polynomial_info[exponent] += coefficient;
            } else {
                polynomial_info[exponent] = coefficient;
            }

            if (polynomial_info[exponent] == 0) {
                polynomial_info.erase(exponent);
            }
        }

        cout << polynomial_info.size();

        auto iter = polynomial_info.rbegin();
        char buffer[10];
        while (iter != polynomial_info.rend()) {
            int exponent = iter->first;
            double coefficient = iter->second;
            sprintf(buffer, "%.1f", coefficient);


            cout << " " << exponent << " " << buffer;

            iter++;
        }
        cout << endl;
    }

    return 0;
}

