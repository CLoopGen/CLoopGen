#include <stdio.h>

#include <inttypes.h>

extern char PL_tokenbuf[256];
extern char *d;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    char *index = PL_tokenbuf;
    size_t offset = 0;
    // Eliminate pointer increment as primary carrier; use index arithmetic instead
    for (; index[offset] && (index[offset] >= 'a' && index[offset] <= 'z'); offset++)
        ; // Empty body
    d = index + offset; // Final assignment outside loop
}
