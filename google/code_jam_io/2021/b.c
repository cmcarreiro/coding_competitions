#include <stdio.h>


//t -> test cases
//n -> num of blocks
//l -> size of each block
void solve(int num_case, int n) {
    int l[n];
    int letters = 0;

    for (int i = 0; i < n; i++) {
        scanf("%d", &l[i]);
        letters += l[i];
    }

    letters++; //accounting for A

    char result[letters + 1];
    for (int i = 0; i < letters + 1; i++) {
        result[i] = '\0';
    }

    result[0] = 'A';

    //result index
    int ri = 0;
    int counter = 1;

    for (int i = 1; i < n+1; i++) {
        //even
        if (i % 2 == 0) {
            char last_char = 'A' - 1;
            int prev_ri = ri;
            
            //loop through all the letters in the block
            for (int j = l[i-1]; j > 0; j--) {
                ri = prev_ri + j;
                result[ri] = ++last_char;
                last_char = result[ri];
            }

            if (result[prev_ri] <= last_char) {
                result[prev_ri] = result[prev_ri] + (last_char - result[prev_ri] + 1);
            }
            ri = prev_ri + l[i-1];
        }

        //odd
        else {
            char last_char = result[ri];
            //loop through all the letters in the block
            for (int j = 0; j < l[i-1]; j++) {
                ri++;
                result[ri] = ++last_char;
                last_char = result[ri];
            }
        }
    }

    printf("Case #%d: ", num_case);
    for (int i = 0; i < letters; i++) {
        printf("%c", result[i]);
    }


}

int main() {

    int t;
    scanf("%d", &t);
    t++;

    for (int i = 1; i < t; i++) {
        if (i != 1) printf("\n");
        int n;
        scanf("%d", &n);
        solve(i, n);
    }

    return 0;
}
