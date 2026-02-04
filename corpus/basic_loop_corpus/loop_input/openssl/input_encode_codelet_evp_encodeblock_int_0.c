#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <inttypes.h>

unsigned char *t;
unsigned char *f;
int dlen;
int i;
int ret;
unsigned long l;
unsigned char *table;

static unsigned char *f_buffer;
static unsigned char *t_buffer;
static unsigned char table_data[64];

void init_vars() {
    // Allocate f buffer: choose size to get ~0.01s runtime
    // The loop processes 3 bytes per iteration, outputs 4 bytes
    // Use ~768KB input to ensure sufficient runtime without being too large
    const int input_size = 768 * 1024;
    f_buffer = (unsigned char*)calloc(input_size, 1);
    if (!f_buffer) exit(1);

    // t needs to hold up to (4/3)*dlen + some extra, so allocate generously
    const int output_capacity = (input_size / 3 + 1) * 4;
    t_buffer = (unsigned char*)malloc(output_capacity);
    if (!t_buffer) {
        free(f_buffer);
        exit(1);
    }

    // Initialize table with printable base64-like characters
    for (int idx = 0; idx < 26; ++idx) table_data[idx] = 'A' + idx;
    for (int idx = 26; idx < 52; ++idx) table_data[idx] = 'a' + (idx - 26);
    for (int idx = 52; idx < 62; ++idx) table_data[idx] = '0' + (idx - 52);
    table_data[62] = '+';
    table_data[63] = '/';

    // Set global pointers and variables
    f = f_buffer;
    t = t_buffer;
    table = table_data;
    dlen = input_size;
    ret = 0;
    l = 0;
}