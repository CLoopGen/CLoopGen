#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>
#include <string.h>
#include <time.h>

char *s;
size_t i;
size_t length;

static char data[1 << 20]; // 1MB buffer

void init_vars() {
    // Initialize the data array with non-null characters
    for (size_t idx = 0; idx < sizeof(data) - 1; idx++) {
        data[idx] = 'a' + (idx % 26);
    }
    data[sizeof(data) - 1] = '\0';
    
    // Place a ';' near the middle to trigger the break condition
    size_t semicolon_pos = (1 << 19); // 512KB position
    data[semicolon_pos] = ';';
    
    // Initialize pointers and variables
    s = data;
    i = 0;
    length = 0;
}