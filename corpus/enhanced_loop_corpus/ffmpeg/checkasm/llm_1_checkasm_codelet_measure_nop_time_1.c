#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint16_t nops[10000];
extern int i;
extern uint64_t t;

// Variable name mappings to avoid conflicts with system symbols



void loop() {
    for (i = 0; i < 10000; i += 5) {
        for (int j = 0; j < 5 && (i + j) < 10000; j++) {
            nops[i + j] = t;
        }
    }
}
