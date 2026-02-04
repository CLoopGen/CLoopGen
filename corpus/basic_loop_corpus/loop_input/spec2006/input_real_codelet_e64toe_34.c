#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <string.h>

#define DATA_SIZE (128 * 1024 * 1024) // 128 MB for ~0.01 sec on modern CPU

static unsigned short *e_ptr;
static unsigned short *p_ptr;
static unsigned short *e_data;
static unsigned short *p_data;
static int i_val;

unsigned short *e = NULL;
unsigned short *p = NULL;
int i = 0;

void init_vars() {
    if (e_data == NULL) {
        e_data = (unsigned short *)aligned_alloc(32, DATA_SIZE);
        p_data = (unsigned short *)aligned_alloc(32, DATA_SIZE);
    }

    if (!e_data || !p_data) {
        fprintf(stderr, "Allocation failed\n");
        exit(1);
    }

    for (size_t j = 0; j < DATA_SIZE / sizeof(unsigned short); j++) {
        e_data[j] = (unsigned short)(j & 0xFFFF);
    }

    e_ptr = e_data;
    p_ptr = p_data;

    e = e_ptr;
    p = p_ptr;
    i = 0;
}