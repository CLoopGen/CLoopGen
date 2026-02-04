#include <stdio.h>

#include <inttypes.h>

extern  unsigned char *dest;
extern  unsigned char *start;
extern  unsigned char *temp;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    unsigned char *p = dest;
    unsigned char *next_p;
    for (; p > start; p = next_p) {
        next_p = p - 1;
        if (next_p[-1] == '\\') {
            continue;
        } else {
            temp = next_p;
            break;
        }
        if (next_p == start) {
            temp = start;
            break;
        }
    }
    if (p == start && temp != start) {
        temp = dest;
    }
}
