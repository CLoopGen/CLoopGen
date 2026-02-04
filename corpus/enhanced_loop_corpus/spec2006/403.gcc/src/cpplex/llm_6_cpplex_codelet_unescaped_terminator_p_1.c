#include <stdio.h>

#include <inttypes.h>

extern  unsigned char *dest;
extern  unsigned char *start;
extern  unsigned char *temp;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    unsigned char *ptr = dest;
    unsigned char prev;
    for (; ptr > start; ptr--) {
        prev = ptr[-1];
        if (prev != '\\') {
            temp = ptr;
            break;
        }
        if (ptr == start + 1) {
            temp = ptr - 1;
        }
    }
}
