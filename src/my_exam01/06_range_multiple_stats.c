/*
Exam: my_exam01
Task: 6 - Range Multiple Stats

Input:
Two integers: start and end.

Output:
Print counts for multiples of 3 only, 5 only, both 3 and 5, and the sum of both.
For invalid input, print Invalid input.

Requirements:
Use if / else, loops, counters, an accumulator, and at least three functions.
*/

#include <stdio.h>

int is_divisible_by(int n, int divisor) {
    if (n % divisor == 0) {
        return 1;
    }
    return 0;
}

int count_multiples_of_3_only(int start, int end) {
    int count = 0;
    for (int i = start; i <= end; i++) {
        if (is_divisible_by(i, 3) == 1) {
            if (is_divisible_by(i, 5) == 0) {
                count++;
            }
        }
    }
    return count;
}

int count_multiples_of_5_only(int start, int end) {
    int count = 0;
    for (int i = start; i <= end; i++) {
        if (is_divisible_by(i, 5) == 1) {
            if (is_divisible_by(i, 3) == 0) {
                count++;
            }
        }
    }
    return count;
}

int count_multiples_of_both(int start, int end) {
    int count = 0;
    for (int i = start; i <= end; i++) {
        if (is_divisible_by(i, 3) == 1) {
            if (is_divisible_by(i, 5) == 1) {
                count++;
            }
        }
    }
    return count;
}

int sum_multiples_of_both(int start, int end) {
    int sum = 0;
    for (int i = start; i <= end; i++) {
        if (is_divisible_by(i, 3) == 1) {
            if (is_divisible_by(i, 5) == 1) {
                sum += i;
            }
        }
    }
    return sum;
}

int main(void) {
    int start = 0;
    int end = 0;
    if (scanf("%d %d", &start, &end) != 2 || start > end) {
        printf("Invalid input\n");
        return 0;
    }

    printf("Multiples of 3 only: %d\n", count_multiples_of_3_only(start, end));
    printf("Multiples of 5 only: %d\n", count_multiples_of_5_only(start, end));
    printf("Multiples of both: %d\n", count_multiples_of_both(start, end));
    printf("Sum of both: %d\n", sum_multiples_of_both(start, end));

    return 0;
}
