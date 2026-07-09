/*
Exam: my_exam01
Task: 14 - Number Tool Menu

Input:
One command number and one non-negative integer.

Output:
Print the result of the selected command.
For invalid input, print Invalid input.

Requirements:
Use if / else, switch, loops, and at least four functions.
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

int is_palindrome(int n) {
    if (n == reverse_number(n)) {
        return 1;
    }
    return 0;
}

int main(void) {
    int command = 0;
    int n = 0;

    if (scanf("%d %d", &command, &n) != 2 || command < 1 || command > 4 || n < 0) {
        printf("Invalid input\n");
        return 0;
    }

    switch (command) {
        case 1:
            printf("Digits: %d\n", count_digits(n));
            break;
        case 2:
            printf("Digit sum: %d\n", sum_digits(n));
            break;
        case 3:
            printf("Reversed: %d\n", reverse_number(n));
            break;
        case 4:
            if (is_palindrome(n)) {
                printf("Palindrome: yes\n");
            } else {
                printf("Palindrome: no\n");
            }
            break;
    }

    return 0;
}
