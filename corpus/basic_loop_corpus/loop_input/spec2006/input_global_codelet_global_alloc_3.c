#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <string.h>

size_t i;
int *reg_allocno;

void init_vars() {
    reg_allocno = (int *)calloc(256 * 1024 * 1024 / sizeof(int), sizeof(int));
    if (!reg_allocno) {
        fprintf(stderr, "Memory allocation failed\n");
        exit(1);
    }
}