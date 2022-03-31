#include <bits/stdc++.h>

//its correct, but doesn't pass time limit yet
//probably missing memory optimization as well

int find_new_max_id(int* candies, int n, int mid) {

    int max = candies[mid];
    int id = mid;

    for (int i = 0; i < n ; i++) {
        if (candies[i] == max && i != mid) {
            id = i;
            break;
        }
    }
    
    for (int i = 0; i < n; i++) {
        if (candies[i] > max) {
            id = i;
            max = candies[id];
        }
    }
    return id;
}

int main() {
    int t; std::cin >> t;

    while (t--) {
        int n;
        std::cin>>n;

        bool c = true;

        int candies[n];
        int max = 0, id = 0, mid = 0;

        for (int i = 0; i < n; i++) {
            scanf("%d", &candies[i]);
            if (candies[i] > max) {
                max = candies[i];
                mid = id = i;
            }
        }

        if (n == 1) 
        {
            c = candies[0] == 1;
        } else {
            //printf("%d %d\n", candies[mid], mid);
            while (candies[mid] != 0 ) {
                candies[mid]--;
                //printf("%d\n", candies[mid]);
                id = find_new_max_id(candies, n, mid);
                //printf("%d\n", id);
                if (id == mid) {
                    c = false;
                    break;
                }
                mid = id;
                //printf("%d %d\n", candies[mid], mid);
            }
            
        } 
        if (c) printf("YES\n");
        else printf("NO\n");

    }
}