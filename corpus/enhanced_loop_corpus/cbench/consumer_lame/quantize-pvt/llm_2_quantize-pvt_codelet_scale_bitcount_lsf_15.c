#include <stdio.h>

#include <inttypes.h>

typedef struct {
    int l[22];
    int s[13][3];
} III_scalefac_t;

extern III_scalefac_t *scalefac;
extern int partition;
extern int nr_sfb;
extern int window;
extern int i;
extern int sfb;
extern int max_sfac[4];
extern unsigned int *partition_table;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (sfb = 0, partition = 0; partition < 4; partition++) {
        nr_sfb = partition_table[partition] / 3;
        for (i = 0; i < nr_sfb; i++, sfb++) {
            int base_idx = sfb * 3; // Strided access base
            for (window = 0; window < 3; window++) {
                if (scalefac->s[0][base_idx + window] > max_sfac[partition]) // Indirect-like strided access across flattened dimension
                    max_sfac[partition] = scalefac->s[0][base_idx + window];
            }
        }
    }
}
