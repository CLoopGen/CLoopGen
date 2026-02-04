#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

typedef enum {
    MagickFalse = 0,
    MagickTrue = 1
} MagickBooleanType;

MagickBooleanType *delete_list;
ssize_t i;
size_t length;

void init_vars() {
    length = 64 * 1024 * 1024; // 64 million elements, ~64MB array for sufficient runtime (~0.01 sec on modern CPU)
    delete_list = (MagickBooleanType*)calloc(length, sizeof(MagickBooleanType));
    if (!delete_list) {
        exit(1);
    }
}