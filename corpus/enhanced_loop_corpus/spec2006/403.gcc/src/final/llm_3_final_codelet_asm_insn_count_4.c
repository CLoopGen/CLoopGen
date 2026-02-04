#include <stdio.h>

#include <inttypes.h>

extern  char *template;
extern int count;

// Variable name mappings to avoid conflicts with system symbols



void loop() {
    const char *access_pattern = template;
    int offset = 0;
    int stride = 1;
    for (; access_pattern[offset]; ) {
        if ((access_pattern[offset] == ';') || access_pattern[offset] == '\n')
            count++;
        offset += stride;
    }
}
