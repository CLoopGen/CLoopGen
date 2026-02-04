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
for (partition = 0; partition < 2; partition++) {
    nr_sfb = partition_table[partition] + partition_table[partition + 2];
    sfb = 0;
    for (i = 0; i < nr_sfb; i++) {
        int idx = (i < partition_table[partition]) ? i : i + 22 - partition_table[partition + 2];
        if (idx < 22 && scalefac->l[idx] > max_sfac[partition])
            max_sfac[partition] = scalefac->l[idx];
        if (idx < 22 && scalefac->l[idx] > max_sfac[partition + 2])
            max_sfac[partition + 2] = scalefac->l[idx];
    }
}
}
