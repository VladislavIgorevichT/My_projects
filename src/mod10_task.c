// Reads one integer and prints its largest digit.
#include <stdio.h>

int main() {
    int number = 0;
    int max_digit = 0;
    if (scanf("%d", &number) == 1) {
        while (number != 0) {
            if (number % 10 > max_digit) {
                max_digit = number % 10;
            }
            number = number / 10;
        }
        printf("%d", max_digit);
    }
    return 0;
}
