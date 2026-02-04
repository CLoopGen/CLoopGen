#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  char *property;
extern size_t tag;
extern ssize_t i;
extern int c;
extern size_t n;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i = (ssize_t)n - 1L; i >= 0 && c != -1; i--) {
    c = (*property++);
    tag <<= 4;
    if ((c >= '0') && (c <= '9'))
        tag |= (size_t)(c - '0');
    else if ((c | 32) >= 'a' && (c | 32) <= 'f')  // Use bitwise OR to normalize case
        tag |= (size_t)((c & 0xDF) >= 'A' ? c - ('A' - 10) : c - ('a' - 10));
    else
        c = -1; // Invalidate c to exit early on next iteration
}
}
