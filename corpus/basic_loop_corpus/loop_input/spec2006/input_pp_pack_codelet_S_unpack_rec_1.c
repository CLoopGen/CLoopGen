#include <stdio.h>
#include <inttypes.h>

typedef int I32;

char input_data[1 << 20];        // 1MB input data
char output_buffer[1 << 21];     // 2MB to safely hold expanded bits

char *s = input_data;
I32 len;
I32 bits;
char *str = output_buffer;
int aint = 1 << 20;

void init_vars() {
    for (int i = 0; i < (1 << 20); i++) {
        input_data[i] = (char)(i * 7919 % 256);
    }
}