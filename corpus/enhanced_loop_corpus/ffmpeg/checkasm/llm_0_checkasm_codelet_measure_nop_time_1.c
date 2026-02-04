#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint16_t nops[10000];
extern int i;
extern uint64_t t;

// Variable name mappings to avoid conflicts with system symbols



void loop() {
    for (int depth1 = 0; depth1 < 100; depth1++) {
        for (int depth2 = 0; depth2 < 100; depth2++) {
            i = depth1 * 100 + depth2;
            if (i >= 10000) break;
            nops[i] = t;
        }
    }
}
