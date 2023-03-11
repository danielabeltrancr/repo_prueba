#include <stdio.h>
#include <stdlib.h>

int askNumbers() {
    int numbers;
    char entrada;

    do {
        printf("Ingrese la cantidad de numeros a capturar (minimo 5, maximo 10, o x para salir): ");
        if (scanf("%d", &numbers) == 1) {
            if (numbers >= 5 && numbers <= 10) {
                break;
            } else {
                printf("La cantidad de numeros debe estar entre 5 y 10.\n");
            }
        } else {
            scanf("%c", &entrada);
            if (entrada == 'x') {
                printf("Saliendo de la aplicacion.\n");
                return -1;
            } else {
                printf("La entrada no es valida.\n");
            }
        }
    } while (1);

    return numbers;
}

int captureNumbers(int n[], int numbers) {
    int i;
    char entrada;

    printf("Ingrese los numeros:\n");
    for (i = 0; i < numbers; i++) {
        do {
            printf("Numero %d: ", i+1);
            if (scanf("%d", &n[i]) == 1) {
                if (n[i] >= 0 && n[i] <= 99) {
                    break;
                } else {
                    printf("El numero debe estar entre 0 y 99.\n");
                }
            } else {
                scanf("%c", &entrada);
                if (entrada == 'x') {
                    printf("Saliendo de la aplicacion.\n");
                    return -1;
                } else {
                    printf("La entrada no es valida.\n");
                }
            }
        } while (1);
    }

    return 0;
}

int max(int n[], int numbers) {
    int  max = n[0];
    for (int i = 1; i < numbers; i++) {
        if (n[i] > max) {
            max = n[i];
        }
    }
    return max;
}

int min(int n[], int numbers) {
    int min = n[0];
    for (int i = 1; i < numbers; i++) {
        if (n[i] < min) {
            min = n[i];
        }
    }
    return min;
}

float mean(int n[], int numbers) {
    int sum = 0;
    for (int i = 0; i < numbers; i++) {
        sum += n[i];
    }
    return (float)sum / numbers;
}

int compare(const void *a, const void *b) {
    return (*(int *)a - *(int *)b);
}

float median(int n[], int numbers) {
    qsort(n, numbers, sizeof(int), compare);
    if (numbers % 2 == 0) {
        return (float)(n[numbers / 2] + n[numbers / 2 - 1]) / 2;
    } else {
        return (float)n[numbers / 2];
    }
}

int mode(int n[], int numbers) {
    int mode, count, max_count = 0;
    for (int i = 0; i < numbers; i++) {
        count = 0;
        for (int j = 0; j < numbers; j++) {
            if (n[j] == n[i]) {
                count++;
            }
        }
        if (count > max_count) {
            max_count = count;
            mode = n[i];
        }
    }
    return mode;
}

int main() {
    int numbers;
    int n[10];
    int result;

    numbers = askNumbers();
    if (numbers == -1) {
        return 0;
    }

    result = captureNumbers(n, numbers);
    if (result == -1) {
        return 0;
    }

    printf("Maximo: %d\n", max(n, numbers));
    printf("Minimo: %d\n", min(n, numbers));
    printf("Media: %f\n", mean(n, numbers));
    printf("Mediana: %f\n", median(n, numbers));
    printf("Moda: %d\n", mode(n, numbers));

    return 0;
}
