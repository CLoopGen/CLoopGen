#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>
#include <string.h>
#include <time.h>

#define DATA_SIZE 40
#define WORK_SIZE 50

int16_t *sblock_data;
float data[40];
float work[50];
float zero[40];
int i;

void init_vars() {
    sblock_data = (int16_t*)malloc(sizeof(int16_t) * DATA_SIZE);
    if (!sblock_data) {
        fprintf(stderr, "Memory allocation failed\n");
        exit(1);
    }

    for (int j = 0; j < DATA_SIZE; j++) {
        sblock_data[j] = (int16_t)(j % 32768);
    }

    for (int j = 0; j < WORK_SIZE; j++) {
        work[j] = (float)(j + 1) * 0.5f;
    }

    for (int j = 0; j < DATA_SIZE; j++) {
        zero[j] = 0.0f;
        data[j] = 0.0f;
    }

    i = 0;
}