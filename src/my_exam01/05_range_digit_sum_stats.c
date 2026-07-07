/*
Exam: my_exam01
Task: 5 - Range Digit Sum Stats

Input:
Two non-negative integers: start and end.

Output:
Print counts by digit-sum parity and the total sum of all digit sums.
For invalid input, print Invalid input.

Requirements:
Use if / else, loops, accumulators, and at least three functions.
*/

#include <stdio.h>

int sum_digits(int n) {
    int sum = 0;
    if (n < 10) {
        sum = n;
    } else {
        while (n != 0) {
            int temp = n % 10;
            sum += temp;
            n /= 10;
        }
    }
    return sum;
}

int is_even(int n) {
    if (n % 2 == 0) {
        return 0;
    }
    return 1;
}

int count_even_digit_sums(int start, int end) {
    int count_even_digit_sums = 0;
    for (int i = start; i <= end; i++) {
        if (is_even(sum_digits(i)) == 0) {
            count_even_digit_sums++;
        }
    }
    return count_even_digit_sums;
}
int count_odd_digit_sums(int start, int end) {
    int count_odd_digit_sums = 0;
    for (int i = start; i <= end; i++) {
        if (is_even(sum_digits(i)) == 1) {
            count_odd_digit_sums++;
        }
    }
    return count_odd_digit_sums;
}
int total_digit_sum_in_range(int start, int end) {
    int total_digit_sum_in_range = 0;
    for (int i = start; i <= end; i++) {
        int temp = sum_digits(i);
        total_digit_sum_in_range += temp;
    }
    return total_digit_sum_in_range;
}

int main(void) {
    int start_n = 0;
    int end_n = 0;

    if (scanf("%d %d", &start_n, &end_n) != 2 || start_n > end_n || start_n < 0) {
        printf("Invalid input\n");
        return 0;
    }

    printf("Even digit sums: %d\n", count_even_digit_sums(start_n, end_n));
    printf("Odd digit sums: %d\n", count_odd_digit_sums(start_n, end_n));
    printf("Total digit sum: %d\n", total_digit_sum_in_range(start_n, end_n));

    return 0;
}
