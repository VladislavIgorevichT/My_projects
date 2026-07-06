// Reads one integer and prints digit sum, even digit count, max digit, and reversed number.
#include <stdio.h>

int main(void) {
    int number = 0;
    int sum = 0;
    int even = 0;
    int max_number = 0;
    int reversed = 0;

    scanf("%d", &number);

    if (number < 0) {
        number = -number;
    }

    if (number == 0) {
        even = even + 1;
    }

    while (number != 0) {
        // sum
        int digit = number % 10;
        sum = sum + digit;
        // even digit
        if (digit % 2 == 0) {
            even = even + 1;
        }
        // max
        if (max_number < digit) {
            max_number = digit;
        }
        // reversed
        reversed = reversed * 10 + digit;

        number = number / 10;
    }

    printf("sum: %d\n", sum);
    printf("even digits: %d\n", even);
    printf("max digit: %d\n", max_number);
    printf("reversed: %d\n", reversed);
    return 0;
}
