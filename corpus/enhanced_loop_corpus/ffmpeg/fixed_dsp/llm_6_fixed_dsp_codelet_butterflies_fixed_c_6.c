#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int *v2;
extern int len;
extern int i;
extern unsigned int *v1;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0; i < len; i++) {
        int temp1 = v1[i];
        int temp2 = v2[i];
        int t = temp1 - temp2;
        v1[i] = temp1 + temp2;
        v2[i] = t;
    }
}
