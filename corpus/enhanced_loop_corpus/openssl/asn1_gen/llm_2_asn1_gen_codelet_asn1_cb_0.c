#include <stdio.h>

#include <inttypes.h>

extern  char *elem;
extern int len;
extern int i;
extern int vlen;
extern  char *p;
extern  char *vstart;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Strided memory access with step size of 2 (simulating non-unit stride)
    // This variant processes every second character, still checking for ':'
    for (i = 0, p = elem; i < len; p += 2, i += 2) {
        if (*p == ':') {
            vstart = p + 1;
            vlen = len - (int)(vstart - elem);
            len = (int)(p - elem);
            break;
        }
        // Handle case where next access would exceed bounds
        if (i + 2 >= len && i + 1 < len) {
            p++; i++;
            if (*p == ':') {
                vstart = p + 1;
                vlen = len - (int)(vstart - elem);
                len = (int)(p - elem);
                break;
            }
        }
    }
}
