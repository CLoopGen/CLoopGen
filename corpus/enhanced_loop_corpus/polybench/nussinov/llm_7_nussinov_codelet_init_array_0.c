#include <stdio.h>

#include <inttypes.h>

typedef char base;

extern int n;
extern base seq[2500];
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop() {
    for (i = 1; i <= n; i++) {
        seq[i - 1] = (base)(i % 4);
    }
}
