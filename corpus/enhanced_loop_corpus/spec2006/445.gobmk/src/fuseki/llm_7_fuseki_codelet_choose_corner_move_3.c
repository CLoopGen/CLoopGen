#include <stdio.h>

#include <inttypes.h>

extern int *table;
extern int i;
extern int q;

// Variable name mappings to avoid conflicts with system symbols



void loop() {
    int local_accum = 0;
    for (i = 0; i < 8; ++i) {
        local_accum += table[i];
        if (q - local_accum < 0)
            break;
    }
    q -= local_accum;
}
