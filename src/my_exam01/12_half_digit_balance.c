/*
Exam: my_exam01
Task: 12 - Half Digit Balance

Input:
One non-negative integer with an even number of digits.

Output:
Print digit count, left half sum, right half sum, and whether the number is balanced.
For invalid input, print Invalid input.

Requirements:
Use if / else, loops, accumulators, and at least four functions.
*/

#include <stdio.h>

int count_digits(int n) {
    int count = 0;
    while (n != 0) {
        count++;
        n /= 10;
    }
    return count;
}

int power_of_10(int exponent) {
    int power = 1;
    for (int i = 1; i <= exponent; i++) {
        power *= 10;
    }
    return power;
}

int left_half_sum(int n) {
    n /= power_of_10(count_digits(n) / 2);
    int sum = 0;
    while (n != 0) {
        sum += n % 10;
        n /= 10;
    }
    return sum;
}

int right_half_sum(int n) {
    n %= power_of_10(count_digits(n) / 2);
    int sum = 0;
    while (n != 0) {
        sum += n % 10;
        n /= 10;
    }
    return sum;
}

int is_balanced(int n) {
    if (left_half_sum(n) == right_half_sum(n)) {
        return 1;
    }
    return 0;
}

int main(void) {
    int n = 0;
    if (scanf("%d", &n) != 1 || count_digits(n) % 2 != 0 || n <= 0) {
        printf("Invalid input\n");
        return 0;
    }

    printf("Digits: %d\n", count_digits(n));
    printf("Left sum: %d\n", left_half_sum(n));
    printf("Right sum: %d\n", right_half_sum(n));
    if (is_balanced(n)) {
        printf("Balanced: yes\n");
    } else {
        printf("Balanced: no\n");
    }

    return 0;
}
