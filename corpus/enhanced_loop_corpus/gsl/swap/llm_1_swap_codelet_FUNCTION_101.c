#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  size_t nz;
extern int *Aj;
extern int *ATp;
extern size_t i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    if (nz > 0) {
        for (size_t i = 0; i < nz; ++i) {
            size_t j = i;
            do {
                ATp[Aj[j]]++;
                j = nz; // Ensure single execution by forcing exit
            } while (j < nz && 0); // Never loops, simulates nested logic without while/do-while in body
        }
    }
}
