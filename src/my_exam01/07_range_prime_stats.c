/*
Exam: my_exam01
Task: 7 - Range Prime Stats

Input:
Two positive integers: start and end.

Output:
Print counts of prime, composite, and neither numbers, plus the sum of primes.
For invalid input, print Invalid input.

Requirements:
Use if / else, loops, counters, an accumulator, and at least three functions.
*/

#include <stdio.h>

int is_prime(int n) {
    int count = 0;
    for (int i = 1; i <= n; i++) {
        if (n % i == 0) {
            count++;
        }
    }
    if (count == 2) {
        return 1;
    }
    return 0;
}

int is_composite(int n) {
    int count = 0;
    for (int i = 1; i <= n; i++) {
        if (n % i == 0) {
            count++;
        }
    }
    if (count > 2) {
        return 1;
    }
    return 0;
}

int count_primes(int start, int end) {
    int count = 0;
    for (int i = start; i <= end; i++) {
        if (is_prime(i)) {
            count++;
        }
    }
    return count;
}

int count_composites(int start, int end) {
    int count = 0;
    for (int i = start; i <= end; i++) {
        if (is_composite(i)) {
            count++;
        }
    }
    return count;
}

int count_neither(int start, int end) {
    int count = 0;
    for (int i = start; i <= end; i++) {
        if (is_prime(i) == 0 && is_composite(i) == 0) {
            count++;
        }
    }
    return count;
}

int sum_primes(int start, int end) {
    int sum = 0;
    for (int i = start; i <= end; i++) {
        if (is_prime(i)) {
            sum += i;
        }
    }
    return sum;
}

int main(void) {
    int start = 0;
    int end = 0;
    if (scanf("%d %d", &start, &end) != 2 || start > end || start <= 0 || end <= 0) {
        printf("Invalid input\n");
        return 0;
    }

    printf("Prime count: %d\n", count_primes(start, end));
    printf("Composite count: %d\n", count_composites(start, end));
    printf("Neither count: %d\n", count_neither(start, end));
    printf("Prime sum: %d\n", sum_primes(start, end));

    return 0;
}
