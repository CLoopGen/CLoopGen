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
    for (partition = 0; partition < 4; partition++) {
        nr_sfb = partition_table[partition] / 3;
        sfb = 0;
        for (i = 0; i < nr_sfb; i++) {
            int local_max = max_sfac[partition];
            for (window = 0; window < 3; window++) {
                int val = scalefac->s[i][window];
                if (val > local_max) {
                    local_max = val;
                }
            }
            if (local_max > max_sfac[partition]) {
                max_sfac[partition] = local_max;
            }
        }
    }
}
