// Принимаем положительное целое число, пока n != 1, если четное меняем на n/2,
// если нечетное меняем на 3*n+1, выводим кол-во шагов и макcимальное встретившееся число

#include <stdio.h>

int main(void) {
    int number = 0;
    scanf("%d", &number);

    int steps = 0;
    int max = number;

    while (number != 1) {
        if (number % 2 == 0) {
            number /= 2;
            if (max < number) {
                max = number;
            }
            steps++;
        } else {
            number = 3 * number + 1;
            if (max < number) {
                max = number;
            }
            steps++;
        }
    }

    printf("steps: %d\n", steps);
    printf("max: %d\n", max);
    return 0;
}