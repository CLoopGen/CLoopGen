#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef double R;

typedef ptrdiff_t INT;

typedef struct rader_tls rader_tl;

struct rader_tls {
    INT k1;
    INT k2;
    INT k3;
    R *W;
    int refcnt;
    rader_tl *cdr;
};


extern R *W;
extern rader_tl **tl;
extern rader_tl **tp;
extern rader_tl *t;

// Variable name mappings to avoid conflicts with system symbols



void loop() {
    // Variant 2: Consecutive array traversal using an explicit index and local array copy
    const INT max_elements = 64; // Assume bounded size for tls list
    rader_tl *local_array[max_elements];
    INT count = 0;
    rader_tl **temp = tl;

    // Copy pointers up to a limit to create a consecutive access pattern
    while (count < max_elements && temp[count] != NULL) {
        local_array[count] = temp[count];
        count++;
    }

    for (INT i = 0; i < count; i++) {
        t = local_array[i];
        if (t->W == W) {
            tp = &local_array[i]; // Simulate original tp update
            break;
        }
    }
}
