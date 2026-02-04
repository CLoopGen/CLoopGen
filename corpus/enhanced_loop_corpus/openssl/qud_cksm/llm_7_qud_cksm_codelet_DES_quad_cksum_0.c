#include <stdio.h>

#include <inttypes.h>

typedef unsigned int DES_LONG;

extern  unsigned char *input;
extern long length;
extern int out_count;
extern DES_LONG z0;
extern DES_LONG z1;
extern DES_LONG t0;
extern DES_LONG t1;
extern int i;
extern long l;
extern  unsigned char *cp;
extern DES_LONG *lp;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
DES_LONG local_z0 = z0;
DES_LONG local_z1 = z1;
for (i = 0; ((i < 4) && (i < out_count)); i++) {
    cp = input;
    l = length;
    for (; l > 0; l--) {
        DES_LONG temp_t0 = 0;
        if (l > 1) {
            temp_t0 = (DES_LONG)(*(cp++));
            temp_t0 |= (DES_LONG)(((DES_LONG)(*(cp++))) << 8);
            l--;
        } else {
            temp_t0 = (DES_LONG)(*(cp++));
        }
        temp_t0 += local_z0;
        temp_t0 &= 4294967295L;
        DES_LONG temp_t1 = local_z1;
        local_z0 = ((((temp_t0 * temp_t0) & 4294967295L) + ((temp_t1 * temp_t1) & 4294967295L)) & 4294967295L) % 2147483647L;
        local_z1 = ((temp_t0 * ((temp_t1 + ((DES_LONG)83653421L)) & 4294967295L)) & 4294967295L) % 2147483647L;
    }
    z0 = local_z0;
    z1 = local_z1;
    if (lp != ((void *)0)) {
        *lp++ = z0;
        *lp++ = z1;
    }
}
}
