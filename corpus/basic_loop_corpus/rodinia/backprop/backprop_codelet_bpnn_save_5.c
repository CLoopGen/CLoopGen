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
for (i = 0; i <= n1; i++) {
    for (j = 0; j <= n2; j++) {
        dvalue = w[i][j];
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
