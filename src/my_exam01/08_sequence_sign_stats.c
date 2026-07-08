/*
Exam: my_exam01
Task: 8 - Sequence Sign Stats

Input:
Integers one by one, ending with 0.

Output:
Print counts of positive even, positive odd, negative numbers, and sum of positives.
For invalid input, print Invalid input.

Requirements:
Use if / else, a loop, counters, an accumulator, and at least three functions.
*/

#include <stdio.h>

int is_even(int n) {
    if (n % 2 == 0) {
        return 1;
    }
    return 0;
}

int is_positive(int n) {
    if (n > 0) {
        return 1;
    }
    return 0;
}

int is_negative(int n) {
    if (n < 0) {
        return 1;
    }
    return 0;
}

int main(void) {
    int n = 1;
    int positive_even_count = 0;
    int positive_odd_count = 0;
    int negative_count = 0;
    int positive_sum = 0;

    while (n != 0) {
        int result = scanf("%d", &n);
        if (result == 1) {
            if (is_even(n) && is_positive(n)) {
                positive_even_count++;
                positive_sum += n;
            } else if (is_even(n) == 0 && is_positive(n)) {
                positive_odd_count++;
                positive_sum += n;
            } else if (is_negative(n)) {
                negative_count++;
            }
        } else {
            printf("Invalid input\n");
            return 0;
        }
    }

    printf("Positive even count: %d\n", positive_even_count);
    printf("Positive odd count: %d\n", positive_odd_count);
    printf("Negative count: %d\n", negative_count);
    printf("Positive sum: %d\n", positive_sum);

    return 0;
}
