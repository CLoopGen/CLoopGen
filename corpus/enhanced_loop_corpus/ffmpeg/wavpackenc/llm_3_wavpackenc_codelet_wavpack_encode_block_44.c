#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int32_t *samples_l;
extern int32_t *samples_r;
extern int i;
extern int nb_samples;

// Variable name mappings to avoid conflicts with system symbols



void loop() {
    int *index_map = (int*)malloc(nb_samples * sizeof(int));
    for (int j = 0; j < nb_samples; j++) {
        index_map[j] = nb_samples - 1 - j;
    }
    for (i = 0; i < nb_samples; i++) {
        int idx = index_map[i];
        samples_r[idx] += ((samples_l[idx] -= samples_r[idx]) >> 1);
    }
    free(index_map);
}
