#include <stdio.h>
#include <inttypes.h>
#include <string.h>
#include <stdlib.h>

char *suitestr;
char *st;
int delim_count;

static char data_buffer[1024 * 128]; // 128KB buffer

void init_vars() {
    size_t i;
    size_t len = sizeof(data_buffer) - 1; // Leave space for null terminator

    // Initialize with a repeating pattern containing commas
    for (i = 0; i < len; i++) {
        if ((i % 64) == 63) {
            data_buffer[i] = ',';
        } else {
            data_buffer[i] = 'x';
        }
    }
    data_buffer[len] = '\x00';

    // Initialize external pointers
    suitestr = data_buffer;
    st = NULL;
    delim_count = 0;
}