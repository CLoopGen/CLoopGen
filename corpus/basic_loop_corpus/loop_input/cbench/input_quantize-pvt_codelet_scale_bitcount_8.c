#include <stdio.h>
#include <stdlib.h>
#include <inttypes.h>

typedef struct {
    int l[22];
    int s[13][3];
} III_scalefac_t;

III_scalefac_t *scalefac;
int i;
int sfb;
int max_slen1;
int max_slen2;

void init_vars() {
    scalefac = (III_scalefac_t*)calloc(1, sizeof(III_scalefac_t));
    if (!scalefac) {
        fprintf(stderr, "Allocation failed\n");
        exit(1);
    }
    i = 0;
    sfb = 0;
    max_slen1 = 0;
    max_slen2 = 0;
}