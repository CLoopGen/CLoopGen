#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int *len;
extern int i;
extern int work_len;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i = *len , work_len = 2 * 2 * 8; i > 5; work_len = work_len * 3 + 1, i--)
    for (int j = 0; j < (work_len % 4) + 1; j++)
        work_len += j;
}
