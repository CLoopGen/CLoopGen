#include <stdio.h>

#include <inttypes.h>

typedef char base;

extern int n;
extern base seq[2500];
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int j;
    for (i = 0; i < n; i++) {
        for (j = 0; j < 3; j++) {
            seq[i] = (base)((i + 1 + j) % 4);
        }
    }
}
