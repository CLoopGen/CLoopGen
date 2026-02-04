#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

int16_t **chrUSrcPtr;
int16_t **tmpU;
int neg;
int i;

static int16_t *allocated_memory = NULL;
static int16_t **ptr_array_chrU = NULL;
static int16_t **ptr_array_tmpU = NULL;

void init_vars() {
    const size_t total_elements = 1 << 20; 
    const size_t ptr_array_size = 1 << 12; 

    neg = ptr_array_size;

    allocated_memory = calloc(total_elements, sizeof(int16_t));
    ptr_array_chrU = calloc(ptr_array_size, sizeof(int16_t*));
    ptr_array_tmpU = calloc(ptr_array_size, sizeof(int16_t*));

    if (!allocated_memory || !ptr_array_chrU || !ptr_array_tmpU) {
        exit(1);
    }

    for (size_t idx = 0; idx < ptr_array_size; idx++) {
        ptr_array_chrU[idx] = allocated_memory + (idx * 64 % total_elements);
        ptr_array_tmpU[idx] = NULL;
    }

    chrUSrcPtr = ptr_array_chrU;
    tmpU = ptr_array_tmpU;
}