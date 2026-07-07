/*
Exam: my_exam01
Task: 3 - Divisor Analyzer

Input:
One positive integer.

Output:
Print the divisor count, proper divisor sum, and number type.
For invalid input, print Invalid input.

Requirements:
Use if / else, a loop, and at least three functions.
*/

#include <stdio.h>

int count_divisors(int n) {
    int divisors = 0;
    for (int i = 1; i <= n; i++) {
        if (n % i == 0) {
            divisors++;
        }
    }
    return divisors;
}
int sum_proper_divisors(int n) {
    int sum = 0;
    for (int i = 1; i < n; i++) {
        if (n % i == 0) {
            sum += i;
        }
    }
    return sum;
}
int is_prime(int n) {
    int step = 0;
    for (int i = 1; i <= n; i++) {
        if (n % i == 0) {
            step++;
        }
    }
    if (step == 2) {
        return 1;
    } else {
        return 0;
    }
}

int main(void) {
    int n = 0;
    if (scanf("%d", &n) != 1 || n <= 0) {
        printf("Invalid input\n");
        return 0;
    }

    printf("Divisors count: %d\n", count_divisors(n));
    printf("Proper divisors sum: %d\n", sum_proper_divisors(n));

    if (n == 1) {
        printf("Type: neither\n");
    } else if (is_prime(n) == 1) {
        printf("Type: prime\n");
    } else {
        printf("Type: composite\n");
    }

    return 0;
}
