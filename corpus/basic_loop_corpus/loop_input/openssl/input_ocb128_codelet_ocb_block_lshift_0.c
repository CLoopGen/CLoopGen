#include <stdio.h>
#include <stdlib.h>
#include <string.h>

unsigned char *in;
size_t shift;
unsigned char *out;
int i;
unsigned char carry;
unsigned char carry_next;

#define DATA_SIZE 262144

static unsigned char in_buffer[DATA_SIZE];
static unsigned char out_buffer[DATA_SIZE];

void init_vars() {
    in = in_buffer;
    out = out_buffer;
    shift = 3;
    carry = 0;
    carry_next = 0;
    
    for (int j = 0; j < DATA_SIZE; j++) {
        in[j] = (unsigned char)(j * 71 % 251);
    }
    
    memset(out, 0, DATA_SIZE);
}