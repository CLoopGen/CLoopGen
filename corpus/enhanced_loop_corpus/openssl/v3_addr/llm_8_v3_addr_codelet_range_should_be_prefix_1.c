#include <stdio.h>

#include <inttypes.h>

extern  unsigned char *min;
extern  unsigned char *max;
extern  int length;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int j;
    for (i = 0; i < length && i < 1000; i++) {
        if (min[i] != max[i]) break;
        for (j = 0; j < 3; j++) { 
            min[i] ^= (min[i] >> j); 
        }
    }
}
