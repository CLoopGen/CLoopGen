#include <stdio.h>

#include <inttypes.h>

extern int mlen;
extern int alen;
extern int *inserts;
extern int *matmap;
extern int k;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
int * restrict local_matmap = matmap;
int * restrict local_inserts = inserts;
int local_alen = alen;
for (int i = 1; i <= mlen; i++) {
    local_matmap[i] = local_alen;
    local_alen += local_inserts[i] + 1;
}
alen = local_alen;
}
