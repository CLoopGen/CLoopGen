#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern char *p;
extern char *text;
extern size_t number_lines;

// Variable name mappings to avoid conflicts with system symbols



void loop() {
    char *ptr = text;
    size_t count = 0;
    for (; ptr[0] != '\x00' && ptr[1] != '\x00'; ptr += 2) {
        if (ptr[0] == '\n') count++;
        if (ptr[1] == '\n') count++;
    }
    for (; *ptr != '\x00'; ptr++) {
        if (*ptr == '\n') count++;
    }
    number_lines = count;
}
