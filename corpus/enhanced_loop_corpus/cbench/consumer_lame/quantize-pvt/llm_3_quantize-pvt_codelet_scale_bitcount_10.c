#include <stdio.h>

#include <inttypes.h>

typedef struct {
    int l[22];
    int s[13][3];
} III_scalefac_t;

extern III_scalefac_t *scalefac;
extern int sfb;
extern int max_slen2;

// Variable name mappings to avoid conflicts with system symbols



void loop() {
    // Variant 2: Consecutive access using a pointer to simulate linear traversal
    // Introduce a temporary pointer for linear, consecutive access to relevant array segment
    const int *ptr = &(scalefac->l[11]);
    int i;
    for (i = 0; i < 10; i++) {
        if (ptr[i] > max_slen2)
            max_slen2 = ptr[i];
    }
    // Update sfb as side effect to maintain external state (if used outside)
    sfb = 21;
}
