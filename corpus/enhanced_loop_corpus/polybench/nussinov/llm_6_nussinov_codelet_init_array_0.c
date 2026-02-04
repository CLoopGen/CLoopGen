#include <stdio.h>

#include <inttypes.h>

typedef char base;

extern int n;
extern base seq[2500];
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop() {
    base temp;
    for (i = 0; i < n; i++) {
        temp = (base)((i + 1) % 4);
        seq[i] = temp;
    }
}
