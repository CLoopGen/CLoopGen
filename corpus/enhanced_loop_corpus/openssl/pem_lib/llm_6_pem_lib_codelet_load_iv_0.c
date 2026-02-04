#include <stdio.h>

#include <inttypes.h>

extern unsigned char *to;
extern int num;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    unsigned char temp = 0;
    for (i = 0; i < num; i++) {
        temp = to[i];     // Introduce RAW dependency: read before write
        to[i] = temp;     // WAW with previous iteration removed; now each iteration writes independently
        temp = 0;         // Break potential loop-carried dependency on 'temp'
    }
}
