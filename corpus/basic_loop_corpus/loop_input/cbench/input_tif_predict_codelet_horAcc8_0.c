#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <inttypes.h>

typedef int int32;
typedef int32 tsize_t;

tsize_t stride;
char *cp;
int i;

static char *buffer;
static tsize_t buffer_size = 64 * 1024 * 1024; // 64 MB for sufficient runtime (~0.01 sec)

void init_vars() {
    // Allocate large enough buffer to ensure valid access throughout loop
    buffer = (char *)calloc(buffer_size, sizeof(char));
    if (!buffer) {
        exit(1);
    }

    // Initialize buffer with non-zero values to make computation observable
    for (size_t idx = 0; idx < buffer_size; idx++) {
        buffer[idx] = (char)(idx & 0xFF);
    }

    // Set stride to a reasonable fraction of buffer size to allow cp[stride] access
    stride = 16 * 1024; // 16 KB stride, well within buffer bounds

    // Initialize cp to point inside the buffer such that cp + stride is valid
    cp = buffer + 1024; // Start cp at offset 1024 to allow both pre-increment and cp[stride] access

    // Ensure initial loop condition: i = stride - 4 > 0 => stride > 4 (satisfied)
}