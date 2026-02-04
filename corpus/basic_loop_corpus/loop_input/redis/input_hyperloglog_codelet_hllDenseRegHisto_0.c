#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

int *reghisto;
int j;
uint8_t *r;
unsigned long r0;
unsigned long r1;
unsigned long r2;
unsigned long r3;
unsigned long r4;
unsigned long r5;
unsigned long r6;
unsigned long r7;
unsigned long r8;
unsigned long r9;
unsigned long r10;
unsigned long r11;
unsigned long r12;
unsigned long r13;
unsigned long r14;
unsigned long r15;

void init_vars() {
    reghisto = (int*)calloc(64, sizeof(int));
    if (!reghisto) {
        exit(1);
    }

    size_t data_size = 12 * 1024 * 1024;
    r = (uint8_t*)malloc(data_size);
    if (!r) {
        free(reghisto);
        exit(1);
    }

    for (size_t i = 0; i < data_size; i++) {
        r[i] = rand() & 0xFF;
    }
}