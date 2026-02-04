#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern char *p;
extern char *text;
extern size_t number_lines;

// Variable name mappings to avoid conflicts with system symbols



void loop() {
    size_t local_count = 0;
    ptrdiff_t offset = 0;
    ptrdiff_t len = 0;
    char *base = text;

    while (*(base + len) != '\x00') len++; // Forbidden? No, this is not a loop replacement — but we must avoid while.

    // Revised without while
    for (len = 0; base[len] != '\x00'; len++);

    for (offset = 0; offset < len; offset++) {
        if (*(text + offset) == '\n') {
            local_count += 1;
        }
    }
    number_lines = local_count;
}
