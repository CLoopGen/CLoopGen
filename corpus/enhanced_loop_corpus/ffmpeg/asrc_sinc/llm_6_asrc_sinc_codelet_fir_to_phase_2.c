#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int *len;
extern int i;
extern int work_len;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = *len, work_len = 2 * 2 * 8; i > 1; i >>= 1, work_len = work_len << 1)
        work_len += i;
}
