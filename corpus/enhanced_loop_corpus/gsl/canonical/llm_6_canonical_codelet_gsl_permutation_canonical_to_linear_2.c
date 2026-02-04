#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern size_t i;
extern size_t k;
extern size_t kk;
extern size_t first;
extern  size_t n;
extern size_t * pp;
extern  size_t * qq;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    size_t temp;
    for (i = 1; i < n; i++) {
        kk = qq[i];
        temp = pp[kk]; // Introduce temporary to modify RAW dependency
        if (kk > first) {
            pp[k] = temp;
            k = kk;
        } else {
            pp[k] = first;
            k = kk;
            first = temp; // Use temp instead of direct access to break WAW on pp[kk]
        }
    }
}
