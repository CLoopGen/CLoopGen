#include <stdio.h>

#include <inttypes.h>

typedef char base;

extern int n;
extern base seq[2500];
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0; i < n; i += 2) {
        seq[i] = (base)((i + 1) % 4);
        if (i + 1 < n) {
            seq[i + 1] = (base)((i + 2) % 4);
        }
    }
}
