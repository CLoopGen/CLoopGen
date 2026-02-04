#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef struct TrellisPath {
    int nibble;
    int prev;
} TrellisPath;

extern uint8_t *dst;
extern int n;
extern TrellisPath *paths;
extern TrellisPath *p;
extern int froze;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    if (n - 1 > froze) {
        for (i = n - 1; i > froze; i--) {
            for (int unroll_factor = 0; unroll_factor < 1; unroll_factor++) {
                dst[i] = p->nibble;
                p = &paths[p->prev];
            }
        }
    }
}
