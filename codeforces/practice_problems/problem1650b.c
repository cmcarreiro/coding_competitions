//exceeds time limit
//TODO: make this pass the time limit

#include <stdio.h>
#include <math.h>

long find_max(long lower, long higher, long a) {
    long x;
    long maximum = 1;
    long val;

    for (x = lower; x <= higher; x++ ){
        val = floor(x / a) + x % a;
        if (val > maximum) maximum = val;
    }

    return maximum;
}

//problem 1650B
void main() {
    int num_test_cases;
    long lower_limit, higher_limit, a;
    int i;

    scanf("%d", &num_test_cases);

    for (i = 0; i < num_test_cases; i++) {
        scanf("%ld %ld %ld", &lower_limit, &higher_limit, &a);
        long value = find_max(lower_limit, higher_limit, a);
        printf("%ld\n", value);
    }

}