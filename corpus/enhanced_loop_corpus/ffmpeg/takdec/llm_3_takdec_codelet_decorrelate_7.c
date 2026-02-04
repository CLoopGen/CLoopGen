#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int32_t *p1;
extern int32_t *p2;
extern int i;
extern int order_half;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
int32_t *temp_p1 = p1;
int32_t *temp_p2 = p2;
for (i = 0; i < order_half; i++) {
    int32_t a = *(temp_p1++);
    int32_t b = *(temp_p2++);
    *(--temp_p1) = a + b;
    temp_p1++;
    temp_p2++;
}
}
