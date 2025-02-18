#include <stdio.h>
#include <stdlib.h>
// Creating a dynamic array using only static arrays

int main(void) {
    int cap = 2;
    int num = 0;

    int* arr;
    arr = (int*)malloc(cap * sizeof(int));

    for (int i = 0; i < 10; i++) {
        scanf("%d", &num);
        if (i > cap)
        {
            cap = cap*2;
            int* arr_;
            arr_ = (int*)malloc(cap * sizeof(int));

            for (int j = 0; j < cap; j++)
            {
                arr_[j] = arr[j];
            }
            arr = arr_;
        }
        arr[i] = num;

        printf("Inserted %d\n[", num);
        for (int j = 0; j <= i; j++) {
            printf("%d", arr[j]);
        }
        printf("] cap: %d\n", cap);
    }
    return 0;
}