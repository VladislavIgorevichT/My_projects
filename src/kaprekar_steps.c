// Reads a four-digit number and prints Kaprekar steps until 6174 or an unreachable state.
#include <stdio.h>

int sort(int *n1, int *n2, int *n3, int *n4) {
    for (int i = 0; i < 4; i++) {
        if (*n1 >= *n2) {
            int temp = *n2;
            *n2 = *n1;
            *n1 = temp;
        }
        if (*n2 >= *n3) {
            int temp = *n3;
            *n3 = *n2;
            *n2 = temp;
        }
        if (*n3 >= *n4) {
            int temp = *n4;
            *n4 = *n3;
            *n3 = temp;
        }
    }
    return 0;
}

int digit(int *number, int *n1, int *n2, int *n3, int *n4) {
     if (*number >= 1000) {
        *n1 = *number % 10;
        *number /= 10;
        *n2 = *number % 10;
        *number /= 10;
        *n3 = *number % 10;
        *number /= 10;
        *n4 = *number % 10;
    } else {
        *n1 = *number % 10;
        *number /= 10;
        *n2 = *number % 10;
        *number /= 10;
        *n3 = *number % 10;
        *number /= 10;
        *n4 = 0;
    }
    return 0;
}

int main(void) {
    int number = 0;
    int n1 = 0;
    int n2 = 0;
    int n3 = 0;
    int n4 = 0;
    scanf ("%d", &number);

    digit(&number, &n1, &n2, &n3, &n4);
    sort(&n1, &n2, &n3, &n4);

    int max_number = n4 * 1000 + n3 * 100 + n2 * 10 + n1;
    int min_number = n1 * 1000 + n2 * 100 + n3 * 10 + n4;

    int result = max_number - min_number;

    printf("%04d - %04d = %04d\n", max_number, min_number, result);

    if (result == 0) {
        printf("Kaprekar constant cannot be reached\n");
        return 0;
    }

    while (result != 6174) {
        number = result;
        digit(&number, &n1, &n2, &n3, &n4);
        sort(&n1, &n2, &n3, &n4);
        max_number = n4 * 1000 + n3 * 100 + n2 * 10 + n1;
        min_number = n1 * 1000 + n2 * 100 + n3 * 10 + n4;
        result = max_number - min_number;
        printf("%04d - %04d = %04d\n", max_number, min_number, result);
    }
    return 0;
}
