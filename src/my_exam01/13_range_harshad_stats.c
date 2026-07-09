/*
Exam: my_exam01
Task: 13 - Range Harshad Stats

Input:
Two positive integers: start and end.

Output:
Print the count and sum of Harshad numbers in the inclusive range.
For invalid input, print Invalid input.

Requirements:
Use if / else, loops, counters, an accumulator, and at least four functions.
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

int is_harshad(int n) {
    if (n % sum_digits(n) == 0) {
        return 1;
    }
    return 0;
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

int sum_harshad(int start, int end) {
    int sum = 0;
    for (int i = start; i <= end; i++) {
        if (is_harshad(i)) {
            sum += i;
        }
    }
    return sum;
}

int main(void) {
    int start = 0;
    int end = 0;

    if (scanf("%d %d", &start, &end) != 2 || start > end || start <= 0 || end <= 0) {
        printf("Invalid input\n");
        return 0;
    }

    printf("Harshad count: %d\n", count_harshad(start, end));
    printf("Harshad sum: %d\n", sum_harshad(start, end));

    return 0;
}
