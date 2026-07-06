// Число армстронга (да/нет), принимает на вход положительное целое число,
// если сумма его цифр возведенных в степень кол-ва числе равна самому числу.

#include <stdio.h>

int main(void) {
    int number = 0;
    scanf("%d", &number);

    int degree = number;
    int sum = 0;
    int power = 1;
    int step = 0;
    int digit = number;

    while (degree != 0) {
        degree /= 10;
        step++;
    }

    while (digit != 0) {
        for (int i = 0; i < step; i++) {
            power *= digit % 10;
        }
        sum += power;
        digit /= 10;
        power = 1;
    }

    if (sum == number) {
        printf("YES");
    } else {
        printf("NO");
    }
}