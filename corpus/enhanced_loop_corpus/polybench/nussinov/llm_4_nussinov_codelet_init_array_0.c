#include <stdio.h>

#include <inttypes.h>

typedef char base;

extern int n;
extern base seq[2500];
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i = 0; i < n; i++) {
    if ((i + 1) % 4 == 0) {
        seq[i] = (base)0;
        continue;
    }
    seq[i] = (base)((i + 1) % 4);
}
}
