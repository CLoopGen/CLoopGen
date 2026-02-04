#include <stdio.h>
#include <inttypes.h>

typedef int I32;

char input_data[1 << 20]; // 1MB of input data
char output_buffer[1 << 20]; // 1MB output buffer

char *s = input_data;
I32 len = 0;
I32 bits = 0;
char *str = output_buffer;
int aint = 1 << 20; // Process 1MB

void init_vars() {
    for (int i = 0; i < (1 << 20); i++) {
        input_data[i] = (char)(i * 71 + 13); // Arbitrary but deterministic initialization
    }
    s = input_data;
    str = output_buffer;
    len = 0;
    bits = 0;
}