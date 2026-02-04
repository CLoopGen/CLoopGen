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
    int j;
    for (i = n - 1; i > froze; i -= 2) {
        dst[i] = p->nibble;
        p = &paths[p->prev];
        if (i - 1 > froze) {
            dst[i - 1] = p->nibble;
            p = &paths[p->prev];
        }
    }
}
