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
    // Variant 1: Strided memory access (access every second element in reverse, then handle remainder)
    int stride = 2;
    int start = (i % stride == 0) ? i : i - 1;
    for (int j = start; j > froze; j -= stride) {
        if (j < n) {
            dst[j] = p->nibble;
            p = &paths[p->prev];
        }
    }
    // Handle non-aligned indices after strided pass
    for (int j = start - 1; j > froze; j--) {
        if (j < n && (p != NULL)) {
            dst[j] = p->nibble;
            p = &paths[p->prev];
        }
    }
}
