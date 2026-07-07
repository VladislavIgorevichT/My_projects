/*
Exam: my_exam01
Task: 4 - Digit Parity Stats

Input:
One non-negative integer.

Output:
Print the count of even digits, the count of odd digits, and the dominant type.
For invalid input, print Invalid input.

Requirements:
Use if / else, a loop, and at least three functions.
*/

#include <stdio.h>

int count_even_digits(int n) {
    int even = 0;
    if (n == 0) {
        even++;
        return even;
    }
    while (n != 0) {
        int temp = n % 10;
        if (temp % 2 == 0) {
            even++;
        }
        n /= 10;
    }
    return even;
}
int count_odd_digits(int n) {
    int odd = 0;
    while (n != 0) {
        int temp = n % 10;
        if (temp % 2 != 0) {
            odd++;
        }
        n /= 10;
    }
    return odd;
}

int get_dominant_type(int n) {
    if (count_even_digits(n) > count_odd_digits(n)) {
        return 0;
    } else if (count_even_digits(n) < count_odd_digits(n)) {
        return 1;
    }
    return 2;
}

int main(void) {
    int n = 0;
    if (scanf("%d", &n) != 1 || n < 0) {
        printf("Invalid input\n");
        return 0;
    }

    printf("Even digits: %d\n", count_even_digits(n));
    printf("Odd digits: %d\n", count_odd_digits(n));

    if (get_dominant_type(n) == 0) {
        printf("Dominant: even\n");
    } else if (get_dominant_type(n) == 1) {
        printf("Dominant: odd\n");
    } else {
        printf("Dominant: equal\n");
    }

    return 0;
}
