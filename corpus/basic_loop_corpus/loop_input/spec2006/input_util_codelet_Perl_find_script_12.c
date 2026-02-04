#include <stdio.h>
#include <inttypes.h>

typedef int I32;

char tmpbuf[4096];
char input_data[1 << 20]; // 1MB of input data
char *s = input_data;
I32 len;

void init_vars() {
    // Initialize input_data with printable chars, ending with ';' after ~1MB
    for (int i = 0; i < sizeof(input_data) - 1; i++) {
        input_data[i] = 'a' + (i % 26);
    }
    input_data[sizeof(input_data) - 1] = ';';

    // Initialize s to point to the start of input_data
    s = input_data;

    // Initialize len to 0 before loop
    len = 0;
}