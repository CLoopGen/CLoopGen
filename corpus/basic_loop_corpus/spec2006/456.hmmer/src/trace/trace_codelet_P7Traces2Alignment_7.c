#include <stdio.h>

#include <inttypes.h>

extern int mlen;
extern int *inserts;
extern int k;

// Variable name mappings to avoid conflicts with system symbols

void loop(){
for (k = 0; k <= mlen; k++)
    if (inserts[k] > 1)
        inserts[k] = 1;

}
