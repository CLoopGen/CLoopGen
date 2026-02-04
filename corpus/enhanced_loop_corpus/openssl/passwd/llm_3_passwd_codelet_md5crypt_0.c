#include <stdio.h>

#include <inttypes.h>

extern unsigned char buf[16];
extern unsigned char buf_perm[16];
extern int dest;
extern int source;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Strided write pattern with reversed read progression
    for (dest = 0, source = 0; dest < 14; dest++, source = (source + 15) % 17) { // backward step equivalent to -2 mod 17
        buf_perm[dest * 2] = buf[source]; // writing with stride 2
    }
}
