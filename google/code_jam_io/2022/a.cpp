#include <bits/stdc++.h>
#include <iostream>
#include <stdio.h>

int main() {

    int t;
    scanf("%d\n", &t);


    for (int i = 1; i <= t; i++) {
        int n;
        scanf("%d\n", &n);

        int q1 = 0, q2 = 0, q3 = 0, q4 = 0;
        for (int y = 0; y < 2*n; y++) {
            for (int x = 0; x < 2*n; x++) {
                char c;
                scanf("%c", &c);
                if (y < n && x < n &&  c == 'I') q1++; 
                if (y < n && x >= n &&  c == 'I') q2++; 
                if (y >= n && x < n &&  c == 'I') q3++; 
                if (y >= n && x >= n &&  c == 'I') q4++;
            }
            getchar();
        }
        
        int result = std::abs(q1-q4) + std::abs(q2-q3);

        printf("Case #%d: %d\n", i, result);

    }

    return 0;
}