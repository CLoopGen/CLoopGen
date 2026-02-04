#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef ptrdiff_t INT;

extern INT n;
extern INT s;
extern int i;
extern INT *p;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    INT *indices = (INT*)malloc(n * sizeof(INT));
    for (INT j = 0; j < n; ++j)
        indices[j] = n - 1 - j;
    for (i = 0; i < n; ++i)
        p[indices[i]] = s * indices[i];
    free(indices);
}
