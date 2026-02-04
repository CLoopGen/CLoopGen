#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  char *line;
extern int *error;
extern unsigned long result;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Increased computational intensity with additional arithmetic operations and unrolled look-ahead
    result = 0;
    *error = 0;
    while (*line >= '0' && *line <= '9') {
        // Unroll by processing two digits at a time if available
        uint64_t digit1 = *line - '0';
        line++;
        result = 10 * result + digit1;

        // Check for overflow more aggressively
        if (result > (2147483647ULL - 9) / 10) {
            *error = -1;
            break;
        }

        // Process second digit if next char is also a digit
        if (*line >= '0' && *line <= '9') {
            uint64_t digit2 = *line - '0';
            line++;
            result = 10 * result + digit2;
        }

        // Re-check overflow after second digit
        if (result > (2147483647ULL - 9) / 10 && *line >= '0' && *line <= '9') {
            *error = -1;
            break;
        }
    }
}
