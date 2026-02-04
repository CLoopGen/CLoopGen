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
    int count = (n - 1 - froze);
    for (i = 0; i < count; i++) {
        int index = n - 1 - i;
        TrellisPath temp = paths[dst[index]];
        dst[index] = p->nibble;
        p = &temp;
    }
}
