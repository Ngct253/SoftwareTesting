#include <iostream>
#include <cmath>
#include <vector>
#include <array>
using namespace std;

int solveQuartic(double a, double b, double c, double x[]) {
    if (a == 0 && b == 0 && c == 0) {
        return -1;
    }

    if (a == 0 && b == 0) {
        return 0;
    }
    if (a == 0) {
        double y = -c / b;
        if (y < 0) return 0;
        x[0] = sqrt(y);
        x[1] = -sqrt(y);
        return 2;
    }
    double delta = b * b - 4 * a * c;
    if (delta < 0) return 0;
    double y1 = (-b + sqrt(delta)) / (2 * a);
    double y2 = (-b - sqrt(delta)) / (2 * a);
    int count = 0;
    if (y1 >= 0) {
        x[count++] = sqrt(y1);
        x[count++] = -sqrt(y1);
    }
    if (y2 >= 0 && y2 != y1) {
        x[count++] = sqrt(y2);
        x[count++] = -sqrt(y2);
    }
    return count;
}

int main() {
    double x[4];

    // Danh sách test-case: {a, b, c}
    vector<array<double, 3>> tests = {
        {0,0,0},   // TC1: vô số nghiệm
        {0,0,5},   // TC2: vô nghiệm
        {0,1,0},   // TC3: nghiệm thực 0
        {0,1,-4},  // TC4: ±2
        {0,1,4},   // TC5: vô nghiệm
        {1,0,1},   // TC6: Δ < 0
        {1,-2,1},  // TC7: Δ = 0, y=1
        {1,2,1},   // TC8: Δ = 0, y < 0
        {1,-5,4}   // TC9: 4 nghiệm ±1, ±2
    };

    for (size_t t = 0; t < tests.size(); t++) {
        double a = tests[t][0], b = tests[t][1], c = tests[t][2];
        cout << "Test case " << (t + 1)
            << " (a=" << a << ", b=" << b << ", c=" << c << "): ";
        int n = solveQuartic(a, b, c, x);
        if (n == -1) {
            cout << "Infinite solutions." << endl;
        }
        else if (n == 0) {
            cout << "No solution." << endl;
        }
        else {
            cout << "The equation has " << n << " real solution(s): ";
            for (int i = 0; i < n; i++) {
                cout << x[i] << " ";
            }
            cout << endl;
        }
    }

    return 0;
}
