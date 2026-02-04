#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int n2;
extern int n3;
extern int i;
extern int j;
extern int memcnt;
extern float dvalue;
extern float **w;
extern char *mem;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i = 0; i <= n2; i += 2) {
    for (j = 0; j <= n3; j += 2) {
        if (i < n2 && j < n3) {
            dvalue = (w[i][j] + w[i+1][j] + w[i][j+1] + w[i+1][j+1]) * 0.25f;
        } else {
            dvalue = w[i][j];
        }
        {
            register char *_to, *_from;
            register int _i, _l;
            _to = (char *)(&mem[memcnt]);
            _from = (char *)(&dvalue);
            _l = (sizeof(float));
            for (_i = 0; _i < _l; _i++)
                *_to++ = *_from++;
        }
        ;
        memcnt += sizeof(float);
    }
}
}
