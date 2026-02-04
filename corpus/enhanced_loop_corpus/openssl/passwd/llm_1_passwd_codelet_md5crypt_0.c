#include <stdio.h>

#include <inttypes.h>

extern unsigned char buf[16];
extern unsigned char buf_perm[16];
extern int dest;
extern int source;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (dest = 0; dest < 2; dest++) {
        for (int offset = 0; offset < 7; offset++) {
            int index = dest * 7 + offset;
            if (index < 14) {
                source = (offset * 6) % 17;
                buf_perm[index] = buf[source];
            }
        }
    }
}
