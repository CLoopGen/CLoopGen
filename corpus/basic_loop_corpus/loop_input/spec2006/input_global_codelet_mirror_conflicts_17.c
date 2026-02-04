#include <stdio.h>
#include <stdlib.h>
#include <inttypes.h>
#include <string.h>

int max_allocno;
int allocno_row_words;
int i;
int j;
int rw;
int rwb;
long *p;
long *q0;
long *q1;
long *q2;
unsigned long mask;

static long *p_data;
static long *q_buffer;

void init_vars() {
    max_allocno = 4096;
    allocno_row_words = 64;
    rw = 1;
    rwb = 256;
    
    size_t p_size = (size_t)max_allocno * allocno_row_words;
    size_t q_size = (size_t)max_allocno * rwb * allocno_row_words + 1024;
    
    p_data = (long*)aligned_alloc(sizeof(long), p_size * sizeof(long));
    q_buffer = (long*)aligned_alloc(sizeof(long), q_size * sizeof(long));
    
    if (!p_data || !q_buffer) {
        fprintf(stderr, "Allocation failed\n");
        exit(1);
    }
    
    for (size_t idx = 0; idx < p_size; idx++) {
        p_data[idx] = (long)(idx % 1000);
    }
    
    memset(q_buffer, 0, q_size * sizeof(long));
    
    p = p_data;
    q0 = q_buffer;
    q1 = NULL;
    q2 = NULL;
    mask = 0;
    i = 0;
    j = 0;
}