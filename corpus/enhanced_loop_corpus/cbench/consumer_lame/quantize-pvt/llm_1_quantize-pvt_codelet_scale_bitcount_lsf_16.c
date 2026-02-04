#include <stdio.h>

#include <inttypes.h>

typedef struct {
    int l[22];
    int s[13][3];
} III_scalefac_t;

extern III_scalefac_t *scalefac;
extern int partition;
extern int nr_sfb;
extern int i;
extern int sfb;
extern int max_sfac[4];
extern unsigned int *partition_table;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    sfb = 0;
    partition = 0;
    for (; partition < 4 && sfb < 22;) {
        nr_sfb = partition_table[partition];
        for (i = 0; i < nr_sfb && sfb < 22; i++, sfb++)
            if (scalefac->l[sfb] > max_sfac[partition])
                max_sfac[partition] = scalefac->l[sfb];
        partition++;
    }
}
