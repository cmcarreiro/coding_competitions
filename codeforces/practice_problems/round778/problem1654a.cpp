#include <iostream>

void solve(int n) {
    int vals[n];
    int maxa = 0;
    int ia = -1;

    for (int i = 0; i < n; i++) {
        std::cin >> vals[i];
        if (vals[i] > maxa) {
                maxa = vals[i];
                ia = i;
        }
    }
    
    int maxb = 0;
    
    for (int i = 0; i < n; i++) {
        if (i == ia ) continue;
        if (vals[i] > maxb) {
            maxb = vals[i];
        }
    }

    int total = maxa + maxb;
    printf("%d\n", total);
}

int main() {
    int t;
    std::cin >> t;

    for (int i = 0; i < t; i++) {
        int n;
        std::cin >> n;
        solve(n);
    }

    return 0;
}