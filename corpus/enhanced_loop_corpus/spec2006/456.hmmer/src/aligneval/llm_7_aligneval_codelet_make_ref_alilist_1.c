#include <stdio.h>

#include <inttypes.h>

extern int *ref;
extern char *k1;
extern int col;
extern int r1;
extern int *canons1;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int local_col = 0;
    int local_r1 = r1;
    int cache[256];
    int cache_idx = 0;

    for (; local_col < 256 && k1[local_col] != '\x00'; local_col++) {
        if (!((k1[local_col]) == ' ' || (k1[local_col]) == '.' || (k1[local_col]) == '_' || (k1[local_col]) == '-' || (k1[local_col]) == '~')) {
            cache[cache_idx++] = ref[local_col] ? 1 : 0;
        }
    }

    for (int i = 0; i < cache_idx; i++) {
        canons1[local_r1 + i] = cache[i];
    }
    r1 = local_r1 + cache_idx;
}
