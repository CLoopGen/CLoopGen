#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  char *line;
extern int64_t num;
extern int64_t den;

// Variable name mappings to avoid conflicts with system symbols



void loop() {
    // Variant 1: Strided memory access with step size of 2 (simulating non-consecutive access)
    // This variant processes every second digit, creating a strided access pattern.
    // It still respects overflow conditions but advances the pointer by 2 each time.
    for (; *line >= '0' && *line <= '9'; line += 2) {
        if (num > ((9223372036854775807L) - 9) / 10ULL || den > (9223372036854775807L) / 10ULL)
            break;
        num = 10 * num + (*line - '0');
        den *= 10;
        // Ensure we don't go past the null terminator after increment
        if (*(line + 1) == '\0') break;
    }
}
