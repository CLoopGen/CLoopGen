#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int16_t (*temp);
extern int sum;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i = 0; i < 8; i++) {
    int base = i * 8;
    for (int k = 0; k < 8; k++) {
        int idx = base + k;
        sum = ((sum) > (((temp[idx]) >= 0 ? (temp[idx]) : (-(temp[idx])))) ? (sum) : (((temp[idx]) >= 0 ? (temp[idx]) : (-(temp[idx])))));
    }
}
}
