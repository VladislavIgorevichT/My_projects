/*
Exam: my_exam01
Task: 16 - Sequence Property Menu

Input:
A command number, then a sequence of integers ending with 0.

Output:
Print the result of the selected sequence command.
For invalid input, print Invalid input.
*/

#include <stdio.h>

int abs_number(int n) {
    if (n < 0) {
        n = -n;
    }
    return n;
}

int sum_digits(int n) {
    int sum = 0;
    while (n != 0) {
        sum += n % 10;
        n /= 10;
    }
    return sum;
}

int reverse_number(int n) {
    int reverse = 0;
    while (n != 0) {
        reverse += n % 10;
        n /= 10;
        if (n != 0) {
            reverse *= 10;
        }
    }
    return reverse;
}

int is_palindrome_abs(int n) {
    if (abs_number(n) == reverse_number(abs_number(n))) {
        return 1;
    } else {
        return 0;
    }
}

int is_prime_abs(int n) {
    int count = 0;
    for (int i = 1; i <= abs_number(n); i++) {
        if (abs_number(n) % i == 0) {
            count++;
        }
    }
    if (count == 2) {
        return 1;
    } else {
        return 0;
    }
}

int is_harshad_abs(int n) {
    if (abs_number(n) % sum_digits(abs_number(n)) == 0) {
        return 1;
    } else {
        return 0;
    }
}

int main(void) {
    int command = 0;
    int n = 1;
    int scan_result = 0;

    if (scanf("%d", &command) != 1 || command < 1 || command > 4) {
        printf("Invalid input\n");
        return 0;
    }

    int result = 0;
    while ((scan_result = scanf("%d", &n)) == 1 && n != 0) {
        switch (command) {
            case 1:
                if (n > 0 && sum_digits(n) % 2 == 0) {
                    result++;
                }
                break;
            case 2:
                if (n < 0 && is_palindrome_abs(abs_number(n))) {
                    result++;
                }
                break;
            case 3:
                if (is_prime_abs(abs_number(n))) {
                    result += abs_number(n);
                }
                break;
            case 4:
                if (is_harshad_abs(n)) {
                    result++;
                }
        }
    }

    if (scan_result != 1) {
        printf("Invalid input\n");
        return 0;
    }

    switch (command) {
        case 1:
            printf("Positive even digit sums count: %d\n", result);
            break;
        case 2:
            printf("Negative palindromes count: %d\n", result);
            break;
        case 3:
            printf("Prime absolute sum: %d\n", result);
            break;
        case 4:
            printf("Harshad absolute count: %d\n", result);
            break;
    }

    return 0;
}
