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
    for (sfb = 0; sfb < nr_sfb; sfb++) {
        window = 0;
        if (scalefac->s[sfb][window] > max_sfac[partition])
            max_sfac[partition] = scalefac->s[sfb][window];
        window = 1;
        if (scalefac->s[sfb][window] > max_sfac[partition])
            max_sfac[partition] = scalefac->s[sfb][window];
        window = 2;
        if (scalefac->s[sfb][window] > max_sfac[partition])
            max_sfac[partition] = scalefac->s[sfb][window];
    }
}
}
