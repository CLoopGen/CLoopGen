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
    const int *l_ptr = &(scalefac->l[0]);
    for (sfb = 0, partition = 0; partition < 4; partition++) {
        nr_sfb = partition_table[partition];
        for (i = 0; i < nr_sfb; i++, sfb++) {
            int value = *(l_ptr + sfb);
            if (value > max_sfac[partition])
                max_sfac[partition] = value;
        }
    }
}
