#include <stdio.h>

#include <inttypes.h>

extern unsigned char buf[16];
extern unsigned char buf_perm[16];
extern int dest;
extern int source;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (dest = 0, source = 0; dest < 7; dest++, source = (source + 3) % 17) {
        buf_perm[dest * 2] = buf[source];
        buf_perm[dest * 2 + 1] = buf[(source + 1) % 17];
    }
}
