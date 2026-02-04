#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>
#include <string.h>

unsigned char *p;
unsigned char *utf8;

static unsigned char *utf8_buffer;

void init_vars() {
    size_t data_size = 64 << 20; // 64 MB to target ~0.01 sec runtime on modern CPU
    utf8_buffer = (unsigned char *)malloc(data_size);
    if (!utf8_buffer) {
        exit(1);
    }

    // Fill with printable ASCII (32-126), and some tabs, newlines, carriage returns
    for (size_t i = 0; i < data_size - 1; i++) {
        int r = rand() % 100;
        if (r < 2) utf8_buffer[i] = '\t';     // tab
        else if (r < 4) utf8_buffer[i] = '\n'; // newline
        else if (r < 6) utf8_buffer[i] = '\r'; // carriage return
        else utf8_buffer[i] = (rand() % 95) + 32; // printable ASCII
    }

    // Place a control character (<32, not tab/newline/CR) near the end to trigger break
    utf8_buffer[data_size - 1] = 7; // Bell character

    utf8 = utf8_buffer;
    p = utf8;
}

__attribute__((destructor))
static void cleanup() {
    free(utf8_buffer);
}