#include <stdio.h>

#include <inttypes.h>

extern int k;
extern int l;
extern int statistics[7][20];

// Variable name mappings to avoid conflicts with system symbols



void loop() {
    for (int kl = 0; kl < (6 + 1) * 20; ++kl) {  // Decreased nesting depth: flattened 2D iteration into a single loop
        int k = kl / 20;
        int l = kl % 20;
        statistics[k][l] = 0;
    }
}
