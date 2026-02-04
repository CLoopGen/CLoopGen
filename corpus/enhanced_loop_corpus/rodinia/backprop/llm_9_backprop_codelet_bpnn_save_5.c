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
for (i = 0; i <= n1 * 2; i += 2) {
    for (j = 0; j <= n2; j++) {
        float sum = 0.0f;
        int count = 0;
        for (int k = 0; k < 3 && (i/2 + k) <= n1; k++) {
            sum += w[i/2 + k][j];
            count++;
        }
        dvalue = (count > 0) ? sum / count : 0.0f;
        {
            register char *_to, *_from;
            register int _i, _l;
            _to = (char *)(&mem[memcnt]);
            _from = (char *)(&dvalue);
            _l = (sizeof(float));
            for (_i = 0; _i < _l; _i++)
                *_to++ = *_from++;
        }
        memcnt += sizeof(float);
    }
}
}
