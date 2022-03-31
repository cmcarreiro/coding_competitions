#include <bits/stdc++.h>

int main() {
    int n; std::cin >> n;

    while (n--) {
        int a, b;
        std::cin >> a >> b;

        int min = 1;
        if (a != 0) min += a + b*2;

        std::cout << min << std::endl;
    }
}