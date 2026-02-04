#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef struct {
    uint_fast16_t ind;
    uint_fast32_t len;
    unsigned char *data;
} jpc_ppxstabent_t;

typedef struct {
    int numents;
    int maxents;
    jpc_ppxstabent_t **ents;
} jpc_ppxstab_t;

extern jpc_ppxstab_t *tab;
extern int inspt;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Indirect memory access using an index remapping array (simulated via pointer arithmetic)
    // Create a virtual "remap" of indices by traversing in reverse and using offset-based access
    // We simulate indirect access by precomputing effective source indices in a temporary fashion
    // Since we cannot declare large arrays on stack without knowing size, we use relative indirection via arithmetic

    // Simulate indirect access pattern: traverse from high to low, but access source via calculated offset
    // Instead of direct [i-1], we maintain a separate logical index stream
    ptrdiff_t diff = tab->numents - inspt;
    for (i = tab->numents; i > inspt; --i) {
        ptrdiff_t src_idx = (i - 1) - inspt; // normalized offset
        tab->ents[i] = tab->ents[inspt + src_idx]; // reconstruct original data via offset (logically same, but pattern changed)
    }
}
