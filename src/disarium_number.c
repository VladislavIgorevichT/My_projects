// Число Disarium, если сумма его цифр, возведенных в степень их позиции
// слева направо равна самому числу

#include <stdio.h>

int main(void) {
    int number = 0;
    scanf("%d", &number);

    int sum = 0;
    int temp = number;
    int degree = 0;

    while (temp != 0) {
        temp /= 10;
        degree++;
    }

    temp = number;

    while (temp != 0) {
        int current = 1;
        for (int i = 1; i <= degree; i++) {
            current *= temp % 10;
        }
        temp /= 10;
        degree--;
        sum += current;
    }

    if (sum == number) {
        printf("YES");
    } else {
        printf("NO");
    }

    return 0;
}