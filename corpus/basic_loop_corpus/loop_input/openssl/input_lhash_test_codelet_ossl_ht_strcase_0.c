#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

char *tgt;
char *src;
int len;
int i;
long case_adjust;

static char src_buffer[1024 * 128]; // 128KB
static char tgt_buffer[1024 * 128]; // 128KB

void init_vars() {
    len = sizeof(src_buffer) - 1; // Leave space for null terminator
    case_adjust = 0xDF; // Typical value to convert lowercase to uppercase (e.g., 'a' & 0xDF = 'A')

    // Initialize src with mixed-case printable characters, null-terminated
    for (int j = 0; j < len - 1; j++) {
        src_buffer[j] = 'A' + (j % 52); // Cycle through letters (assuming ASCII)
        if (src_buffer[j] > 'Z') src_buffer[j] = 'a' + (src_buffer[j] - 'Z' - 1);
    }
    src_buffer[len - 1] = '\x00'; // Ensure null terminator

    // Set pointers
    src = src_buffer;
    tgt = tgt_buffer;

    // Initialize loop index
    i = 0;
}