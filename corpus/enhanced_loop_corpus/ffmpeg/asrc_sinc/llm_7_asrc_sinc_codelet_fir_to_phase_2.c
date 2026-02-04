#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int *len;
extern int i;
extern int work_len;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int temp = work_len;
    for (i = *len, temp = 8; i > 1; i >>= 1)
        temp = temp * 2;
    work_len = temp;
}
