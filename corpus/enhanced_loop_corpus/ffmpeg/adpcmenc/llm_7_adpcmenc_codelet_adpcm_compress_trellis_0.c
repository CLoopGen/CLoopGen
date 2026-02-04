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
    int idx = n - 1;
    TrellisPath* current = &paths[p->prev];
    for (i = n - 1; i > froze; i--) {
        dst[i] = p->nibble;
        p = current;
        current = &paths[current->prev];
        idx--;
    }
}
