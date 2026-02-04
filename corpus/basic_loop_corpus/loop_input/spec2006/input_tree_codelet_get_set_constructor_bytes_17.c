#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <inttypes.h>

int i;
int set_word_size = 8;
int bit_size;
int bit_pos;
unsigned char *bytep;
char *bit_buffer;

#define DATA_SIZE (128 << 20)  // 128 MB

static unsigned char *internal_byte_buffer;
static char *internal_bit_buffer;

void init_vars() {
    internal_byte_buffer = (unsigned char *)calloc(DATA_SIZE, sizeof(unsigned char));
    internal_bit_buffer = (char *)malloc(DATA_SIZE * sizeof(char));

    if (!internal_byte_buffer || !internal_bit_buffer) {
        fprintf(stderr, "Memory allocation failed\n");
        exit(1);
    }

    for (size_t idx = 0; idx < DATA_SIZE; idx++) {
        internal_bit_buffer[idx] = (char)(rand() % 2);  // Random 0 or 1
    }

    bytep = internal_byte_buffer;
    bit_buffer = internal_bit_buffer;
    bit_size = DATA_SIZE;
    bit_pos = 0;
}