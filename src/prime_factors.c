// Считываем положительное число и выводим его разложение на простые множители

#include <stdio.h>

// Простое ли число?
int is_prime(int number) {
    if (number >= 2) {
        for (int i = 2; i < number; i++) {
            if (number % i == 0) {
                return 0;
            }
        }
    }
    return 1;
}

int main(void) {
    int number = 0;
    int step = 0;
    scanf("%d", &number);

    if (is_prime(number)) {
        printf("%d\n", number);
        return 0;
    }

    for (int i = 2; i <= number; i++) {
        int degree = 0;

        while (number % i == 0) {
            degree++;
            number /= i;
        }
        if (degree == 1) {
            if (step > 0) {
                printf(" * ");
            }
            printf("%d", i);
            step++;
        }
        if (degree > 1) {
            if (step > 0) {
                printf(" * ");
            }
            printf("%d^%d", i, degree);
            step++;
        }
    }

    printf("\n");

    return 0;
}
