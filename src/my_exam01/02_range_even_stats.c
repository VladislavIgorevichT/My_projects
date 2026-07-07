/*
Exam: my_exam01
Task: 2 - Range Even Stats

Input:
Two integers: start and end.

Output:
Print the count and sum of even numbers in the inclusive range.
For invalid input or invalid range, print Invalid input.

Requirements:
Use if / else, a loop, and at least two functions.
*/

#include <stdio.h>

int is_even(int n) {
    if (n % 2 == 0) {
        return 1;
    } else {
        return 0;
    }
}
int count_even_in_range(int start, int end) {
    int even_count = 0;
    for (int i = start; i <= end; i++) {
        if (is_even(i)) {
            even_count++;
        }
    }
    return even_count;
}
int sum_even_in_range(int start, int end) {
    int sum = 0;
    for (int i = start; i <= end; i++) {
        if (is_even(i)) {
            sum += i;
        }
    }
    return sum;
}

int main(void) {
    int start_number = 0;
    int end_number = 0;

    if (scanf("%d %d", &start_number, &end_number) != 2 || start_number > end_number) {
        printf("Invalid input\n");
        return 0;
    }

    int even_count = count_even_in_range(start_number, end_number);
    int sum = sum_even_in_range(start_number, end_number);

    printf("Even count: %d\n", even_count);
    printf("Even sum: %d\n", sum);

    return 0;
}
