//read the editorial, still didn't understand the problem, but this should be the solution
//TODO: truly understand the editorial

#include <stdio.h>

#define MAX(X, Y) (((X)>(Y)) ? (X) : (Y))

long find_max(long lower, long higher, long a) {

    //number with the biggest mod thats in range
    long x =  MAX(lower, higher - 1 );

    //maximum between doing the function with the biggest number, and number with biggest mod in range
    long maximum = MAX( higher/a + higher % a, x / a + x % a);


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