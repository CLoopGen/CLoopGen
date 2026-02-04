#include <stdio.h>

#include <inttypes.h>

extern  unsigned char *min;
extern  unsigned char *max;
extern  int length;
extern int j;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (j = length - 1; j >= 0 && (min[j] | ~max[j]) == 0xFF ? (min[j] == 0 && max[j] == 255) : 0; j--)
        ;
}
