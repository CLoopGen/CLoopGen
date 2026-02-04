#include <stdio.h>

#include <inttypes.h>

extern  char *str;
extern size_t maxlen;
extern  char *p;

// Variable name mappings to avoid conflicts with system symbols



void loop() {
    // Variant 1: Strided memory access (stride of 2)
    // Skips every other character, still respects maxlen and null terminator
    for (p = str; maxlen >= 2 && *p != '\x00' && *(p+1) != '\x00'; p += 2, maxlen -= 2)
        ;
}
