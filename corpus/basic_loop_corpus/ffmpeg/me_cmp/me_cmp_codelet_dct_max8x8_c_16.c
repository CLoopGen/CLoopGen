#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int16_t (*temp);
extern int sum;
extern int i;

// Variable name mappings to avoid conflicts with system symbols

void loop(){
for (i = 0; i < 64; i++)
    sum = ((sum) > (((temp[i]) >= 0 ? (temp[i]) : (-(temp[i])))) ? (sum) : (((temp[i]) >= 0 ? (temp[i]) : (-(temp[i])))));

}
