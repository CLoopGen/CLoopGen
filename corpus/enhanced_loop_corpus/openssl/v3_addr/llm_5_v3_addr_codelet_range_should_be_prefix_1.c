#include <stdio.h>

#include <inttypes.h>

extern  unsigned char *min;
extern  unsigned char *max;
extern  int length;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0; i < length && !(min[i] ^ max[i]); i++)
        ;
}
