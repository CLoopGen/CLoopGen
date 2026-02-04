#include <stdio.h>

#include <inttypes.h>

extern unsigned char buf[16];
extern unsigned char buf_perm[16];
extern int dest;
extern int source;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int temp[14];
    for (dest = 0, source = 0; dest < 14; dest++, source = (source + 6) % 17)
        temp[dest] = buf[source];
    for (dest = 0; dest < 14; dest++)
        buf_perm[dest] = temp[dest];
}
