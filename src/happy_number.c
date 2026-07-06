// принимает число и проверяет что процесс замены числа на сумму квадратов его цифр равен 1

#include <stdio.h>

int main(void) {
    int number = 0;
    int sum = 0;
    int digit = 0;
    int step = 0;
    int temp = 0;
    scanf("%d", &number);

    while (number != 0 && number != 1 && step < 101) {
        temp = number;
        sum = 0;
        while (temp != 0) {
            digit = temp % 10;
            temp /= 10;
            sum += (digit * digit);
        }
        number = sum;
        step++;
    }

    if (number != 1) {
        printf("NO");
    } else {
        printf("YES");
    }
}
