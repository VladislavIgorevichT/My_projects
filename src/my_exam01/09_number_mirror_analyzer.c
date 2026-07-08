/*
Exam: my_exam01
Task: 9 - Number Mirror Analyzer

Input:
One non-negative integer.

Output:
Print digit count, reversed number, and whether the number is a palindrome.
For invalid input, print Invalid input.

Requirements:
Use if / else, loops, and at least three functions.
*/

#include <stdio.h>

int count_digits(int n) {
    int count = 0;
    if (n == 0) {
        count++;
        return count;
    }
    while (n != 0) {
        count++;
        n /= 10;
    }
    return count;
}

int reverse_number(int n) {
    int reverse_number = 0;
    while (n != 0) {
        reverse_number *= 10;
        reverse_number += n % 10;
        n /= 10;
    }
    return reverse_number;
}

int is_palindrome(int n) {
    if (n == reverse_number(n)) {
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
    printf("Reversed: %d\n", reverse_number(n));
    if (is_palindrome(n)) {
        printf("Palindrome: yes\n");
    } else {
        printf("Palindrome: no\n");
    }

    return 0;
}
