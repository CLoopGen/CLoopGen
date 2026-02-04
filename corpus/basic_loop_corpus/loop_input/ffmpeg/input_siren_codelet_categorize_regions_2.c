#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

int *category_balance;
int i;
int num_rate_control_possibilities;
int *max_rate_ptr;

void init_vars() {
    num_rate_control_possibilities = 64 * 1024 * 1024 / sizeof(int);
    category_balance = (int*)calloc(num_rate_control_possibilities, sizeof(int));
    int *temp_array = (int*)malloc((num_rate_control_possibilities) * sizeof(int));
    for (int j = 0; j < num_rate_control_possibilities; j++) {
        temp_array[j] = j;
    }
    max_rate_ptr = temp_array;
}