/*
Exam: my_exam01
Task: 15 - Range Property Menu

Input:
One command number and two non-negative integers: start and end.

Output:
Print the result of the selected range command.
For invalid input, print Invalid input.

Requirements:
Use if / else, switch, loops, counters, accumulators, and at least five functions.
*/

#include <stdio.h>

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

int is_prime(int n) {
    int count = 0;
    for (int i = 1; i <= n; i++) {
        if (n % i == 0) {
            count++;
        }
    }
    if (count == 2) {
        return 1;
    } else {
        return 0;
    }
}

int is_harshad(int n) {
    if (n == 0) {
        return 0;
    } else if (n % sum_digits(n) == 0) {
        return 1;
    } else {
        return 0;
    }
}

int count_even_digit_sums(int start, int end) {
    int count = 0;
    for (int i = start; i <= end; i++) {
        if (sum_digits(i) % 2 == 0) {
            count++;
        }
    }
    return count;
}

int count_palindromes(int start, int end) {
    int count = 0;
    for (int i = start; i <= end; i++) {
        if (is_palindrome(i)) {
            count++;
        }
    }
    return count;
}

int count_harshad(int start, int end) {
    int count = 0;
    for (int i = start; i <= end; i++) {
        if (is_harshad(i)) {
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
    int command = 0;
    int start = 0;
    int end = 0;

    if (scanf("%d %d %d", &command, &start, &end) != 3 || command < 1 || command > 4 || start < 0 ||
        end < 0 || start > end) {
        printf("Invalid input\n");
        return 0;
    }

    switch (command) {
        case 1:
            printf("Even digit sums count: %d\n", count_even_digit_sums(start, end));
            break;
        case 2:
            printf("Palindrome count: %d\n", count_palindromes(start, end));
            break;
        case 3:
            printf("Harshad count: %d\n", count_harshad(start, end));
            break;
        case 4:
            printf("Prime sum: %d\n", sum_primes(start, end));
            break;
    }

    return 0;
}
