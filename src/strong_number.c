// Сильное число, число называется сильным если сумма факториалов его цифр равна этому числу

#include <stdio.h>

int main(void) {
    int number = 0;
    scanf("%d", &number);

    int sum = 0;
    int temp = number;

    while (temp != 0) {
        int current = temp % 10;
        int factorial = 1;
        for (int i = 1; i <= current; i++) {
            factorial *= i;
        }
        temp /= 10;
        sum += factorial;
    }

    if (sum == number) {
        printf("YES");
    } else {
        printf("NO");
    }
}