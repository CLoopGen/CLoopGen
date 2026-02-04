#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>
#include <string.h>
#include <time.h>

int bd_sequence[8] = {1, 2, 3, 4, 5, 6, 7, 8};
double a_work[8] = {0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0};
int k = 0;

void init_vars() {
    bd_sequence[0] = 10;
    for (int i = 1; i < 8; i++) {
        bd_sequence[i] = bd_sequence[i-1] + i * 5;
    }
    a_work[0] = 1.1;
    for (int i = 1; i < 8; i++) {
        a_work[i] = 0.0;
    }
    k = 0;
}