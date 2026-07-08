/*
Exam: my_exam01
Task: 11 - Digit Position Balance

Input:
One non-negative integer.

Output:
Print digit count, sums of digits at odd/even positions, and whether they are equal.
For invalid input, print Invalid input.

Requirements:
Use if / else, loops, accumulators, and at least three functions.
*/

#include <stdio.h>

int count_digits(int n) {
    int count = 0;
    if (n == 0) {
        count++;
    }
    while (n != 0) {
        count++;
        n /= 10;
    }
    return count;
}

int sum_odd_position_digits(int n) {
    int sum = 0;
    int count = count_digits(n);
    for (int i = 1; i <= count; i++) {
        if (i % 2 != 0) {
            sum += n % 10;
        }
        n /= 10;
    }
    return sum;
}

int sum_even_position_digits(int n) {
    int sum = 0;
    int count = count_digits(n);
    for (int i = 1; i <= count; i++) {
        if (i % 2 == 0) {
            sum += n % 10;
        }
        n /= 10;
    }
    return sum;
}

int is_balanced(int n) {
    if (sum_even_position_digits(n) == sum_odd_position_digits(n)) {
        return 1;
    }
    return 0;
}

int main(void) {
    int n = 0;
    if (scanf("%d", &n) != 1 || n < 0) {
        printf("Invalid input\n");
        return 0;
    }

    printf("Digits: %d\n", count_digits(n));
    printf("Odd position sum: %d\n", sum_odd_position_digits(n));
    printf("Even position sum: %d\n", sum_even_position_digits(n));
    if (is_balanced(n)) {
        printf("Balanced: yes\n");
    } else {
        printf("Balanced: no\n");
    }

    return 0;
}
