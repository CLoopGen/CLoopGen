#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>
#include <string.h>
#include <time.h>

char *source;
char *q;
char *p;

static char *buffer_source;
static char *buffer_q;

void init_vars() {
    size_t data_size = 64 << 20; // 64 MB for ~0.01 sec runtime on modern CPU

    buffer_source = (char*)malloc(data_size);
    buffer_q = (char*)malloc(data_size * 2); // worst case: every char escaped

    if (!buffer_source || !buffer_q) {
        exit(1);
    }

    // Initialize source with mixed content to trigger conditional logic
    for (size_t i = 0; i < data_size - 1; i++) {
        int r = rand() % 100;
        if (r < 3) buffer_source[i] = '\\';
        else if (r < 6) buffer_source[i] = '(';
        else if (r < 9) buffer_source[i] = ')';
        else buffer_source[i] = 'a' + (r % 26);
    }
    buffer_source[data_size - 1] = '\x00'; // null terminate

    source = buffer_source;
    q = buffer_q;
}