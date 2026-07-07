/*
Exam: my_exam01
Task: 1 - Number Classifier

Input:
One integer.

Output:
Print the number sign, parity, and digit count.
For invalid input, print Invalid input.

Requirements:
Use if / else, one loop, and at least two functions.
*/

#include <stdio.h>

void print_is_sign(int n) {
    if (n > 0) {
        printf("Sign: positive\n");
    } else if (n < 0) {
        printf("Sign: negative\n");
    } else {
        printf("Sign: zero\n");
    }
}
void print_is_even(int n) {
    if (n % 2 == 0) {
        printf("Parity: even\n");
    } else {
        printf("Parity: odd\n");
    }
}
void print_count_digits(int n) {
    int digits = 0;
    if (n == 0) {
        digits++;
    }
    while (n != 0) {
        n /= 10;
        digits++;
    }
    printf("Digits: %d\n", digits);
}

int main(void) {
    int n = 0;
    if (scanf("%d", &n) != 1) {
        printf("Invalid input\n");
        return 0;
    }

    print_is_sign(n);
    print_is_even(n);
    print_count_digits(n);

    return 0;
}
