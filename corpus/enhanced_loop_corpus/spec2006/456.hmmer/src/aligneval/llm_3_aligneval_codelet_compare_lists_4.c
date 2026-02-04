#include <stdio.h>

#include <inttypes.h>

extern int *k2;
extern int *t2;
extern int len2;
extern float id;
extern float tot;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Indirect array access using an index map (simulated with alternating forward and reverse indexing)
    int *index_map = (int*)__builtin_alloca(len2 * sizeof(int));
    for (int j = 0; j < len2; j++) {
        index_map[j] = (j % 2 == 0) ? j : (len2 - 1 - j);
    }
    for (i = 0; i < len2; i++) {
        int idx = index_map[i];
        tot += 1.;
        if (k2[idx] == t2[idx])
            id += 1.;
    }
}
