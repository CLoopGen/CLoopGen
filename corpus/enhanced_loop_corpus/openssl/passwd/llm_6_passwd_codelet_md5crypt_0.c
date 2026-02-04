#include <stdio.h>

#include <inttypes.h>

extern unsigned char buf[16];
extern unsigned char buf_perm[16];
extern int dest;
extern int source;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (dest = 0, source = 0; dest < 14; dest++, source = (source + 6) % 17)
        buf_perm[dest] = buf[source] ^ buf[(source + 1) % 17];
}
