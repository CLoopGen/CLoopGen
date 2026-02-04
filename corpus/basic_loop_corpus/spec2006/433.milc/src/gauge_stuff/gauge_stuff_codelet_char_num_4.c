#include <stdio.h>

#include <inttypes.h>

extern int *dig;
extern int length;
extern int j;
extern int bdig[6];

// Variable name mappings to avoid conflicts with system symbols

void loop(){
for (j = 0; j < length; j++)
    bdig[j] = 7 - dig[length - j - 1];

}
