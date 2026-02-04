#include <stdio.h>

#include <inttypes.h>

extern  unsigned short *p;
extern unsigned short *q;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop() {
    int j;
    unsigned short temp;
    for (j = 0; j < 6; j++) {
        temp = p[3 - j];     // Introduce temporary to break direct WAW/WAR with q
        q[j] = temp;         // Eliminate pointer post-increment to remove loop-carried flow dependency
    }
}
