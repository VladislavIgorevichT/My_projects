/*
Exam: my_exam01
Task: 10 - Digit Extreme Analyzer

Input:
One non-negative integer.

Output:
Print the maximum digit, minimum digit, their difference, and whether all digits are equal.
For invalid input, print Invalid input.

Requirements:
Use if / else, loops, and at least three functions.
*/

#include <stdio.h>

int max_digit(int n) {
    int max = n % 10;
    while (n != 0) {
        int temp = n % 10;
        if (temp > max) {
            max = temp;
        }
        n /= 10;
    }
    return max;
}

int min_digit(int n) {
    int min = n % 10;
    while (n != 0) {
        int temp = n % 10;
        if (temp < min) {
            min = temp;
        }
        n /= 10;
    }
    return min;
}

int digit_difference(int n) {
    int diff = max_digit(n) - min_digit(n);
    return diff;
}

int all_digits_equal(int n) {
    int first_digit = n % 10;
    n /= 10;
    while (n != 0) {
        int temp = n % 10;
        if (temp != first_digit) {
            return 0;
        }
        n /= 10;
    }
    return 1;
}

int main(void) {
    int n = 0;
    if (scanf("%d", &n) != 1 || n < 0) {
        printf("Invalid input\n");
        return 0;
    }

    printf("Max digit: %d\n", max_digit(n));
    printf("Min digit: %d\n", min_digit(n));
    printf("Difference: %d\n", digit_difference(n));
    if (all_digits_equal(n)) {
        printf("All digits equal: yes\n");
    } else {
        printf("All digits equal: no\n");
    }

    return 0;
}
