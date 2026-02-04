#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int n1;
extern int n2;
extern int i;
extern int j;
extern int memcnt;
extern float dvalue;
extern float **w;
extern char *mem;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (j = 0; j <= n2; j++) {
    for (i = 0; i <= n1; i++) {
        float temp = w[i][j];
        register char *dst = (char *)(mem + memcnt);
        register char *src = (char *)(&temp);
        register int size = sizeof(float);
        for (register int idx = 0; idx < size; idx++) {
            dst[idx] = src[idx];
        }
        memcnt += sizeof(float);
    }
}
}
