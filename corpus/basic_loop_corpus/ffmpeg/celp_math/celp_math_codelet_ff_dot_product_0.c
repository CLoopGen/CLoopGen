#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  int16_t *a;
extern  int16_t *b;
extern int length;
extern int i;
extern int64_t sum;

// Variable name mappings to avoid conflicts with system symbols

void loop(){
for (i = 0; i < length; i++)
    sum += ((a[i]) * (b[i]));

}
