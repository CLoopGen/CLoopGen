#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  char *line;
extern int *error;
extern unsigned long result;

// Variable name mappings to avoid conflicts with system symbols



void loop() {
    // Variant 1: Strided memory access with step of 2 (simulating non-consecutive access)
    // This variant processes every second digit character, still using for-loop structure
    ptrdiff_t stride = 2;
    char *current = line;
    for (; current >= line && *current >= '0' && *current <= '9'; current += stride) {
        if (result > (2147483647 - 9) / 10)
            *error = -1;
        result = 10 * result + *current - '0';
        // Ensure we don't skip past the end by checking next access
        if (*(current + 1) < '0' || *(current + 1) > '9')
            break;
    }
}
