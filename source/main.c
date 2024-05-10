#include <stdio.h>
#include "array.h"
#include "tested_declarations.h"
#include "rdebug.h"

int main(void) {
    struct array_t a;
    int N, value;

    printf("Podaj rozmiar tablicy: ");
    if(scanf("%d", &N) != 1) {
        printf("Incorrect input");
        return 1;
    }
    if(N <= 0) {
        printf("Incorrect input data");
        return 2;
    }

    if(array_create(&a, N) == 2) {
        printf("Failed to allocate memory");
        return 8;
    }

    printf("Podaj liczby:\n");
    while(1) {
        if(scanf("%d", &value) != 1) {
            printf("Incorrect input");
            array_destroy(&a);
            return 1;
        }
        if(value == 0) {
            if(a.size == 0) {
                printf("Buffer is empty\n");
            }
            break;
        }
        if(array_push_back(&a, value) == 2) {
            printf("Buffer is full\n");
            break;
        }
    }

    array_display(&a);
    array_destroy(&a);

    return 0;
}

