#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  char *line;
extern int *error;
extern unsigned long result;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Reduced arithmetic operations with trip count estimation and simplified logic
    result = 0;
    *error = 0;
    int digit_count = 0;

    // First pass: estimate digit count to pre-check potential overflow
    const char* temp_line = line;
    while (*temp_line >= '0' && *temp_line <= '9') {
        digit_count++;
        temp_line++;
    }

    // If too many digits, likely overflow (more than 10 digits can't fit in int)
    if (digit_count > 10) {
        *error = -1;
        return;
    }

    // Single-pass conversion without repeated overflow checks per iteration
    for (; *line >= '0' && *line <= '9'; line++) {
        result = 10 * result + (*line - '0');
    }

    // Final overflow check after full computation
    if (result > 2147483647) {
        *error = -1;
        result = 0;
    }
}
