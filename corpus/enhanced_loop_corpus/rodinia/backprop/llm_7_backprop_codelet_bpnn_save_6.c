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
int local_memcnt = memcnt; // Break WAW dependency on memcnt by using local copy
for (i = 0; i <= n2; i++) {
    for (j = 0; j <= n3; j++) {
        float local_dvalue = w[i][j]; // Eliminate shared dvalue dependency
        {
            register char *_to, *_from;
            register int _i, _l;
            _to = (char *)(&mem[local_memcnt]);
            _from = (char *)(&local_dvalue);
            _l = (sizeof(float));
            for (_i = 0; _i < _l; _i++)
                *_to++ = *_from++;
        }
        local_memcnt += sizeof(float); // Update local counter to remove loop-carried WAW on memcnt
    }
}
memcnt = local_memcnt; // Write back once at the end (breaks loop-carried dependency)
}
