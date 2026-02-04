#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  char *line;
extern int64_t num;
extern int64_t den;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int64_t base = 1;
    int64_t accumulated_digit = 0;
    const char *start = line;

    // First pass: count digits and check overflow bounds with reduced frequency
    const char *ptr = start;
    int count = 0;
    for (; ptr < start + 19 && *ptr >= '0' && *ptr <= '9'; ptr++) {
        count++;
    }

    // Process all counted digits in reverse order with power-of-10 accumulation
    for (int i = count - 1; i >= 0; i--) {
        char c = start[i];
        int64_t digit = c - '0';

        // Simulate left-to-right accumulation using precomputed base scaling
        if (i == count - 1) {
            accumulated_digit = digit;
            base = 10;
        } else {
            if (accumulated_digit > ((9223372036854775807L) - 9) / base) {
                break;
            }
            accumulated_digit = accumulated_digit * base + digit;
            base *= 10;
        }
    }

    // Update outputs only if no overflow occurred
    if (count > 0) {
        num = accumulated_digit;
        den = base / 10;
        line = (char *)start + count;
    }
}
