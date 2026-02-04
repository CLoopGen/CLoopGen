#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int16_t (*temp);
extern int16_t * bak;
extern int sum;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i = 0; i < 8; i++) {
    int offset = i * 8;
    for (int j = 0; j < 8; j++) {
        int idx = offset + j;
        sum += (temp[idx] - bak[idx]) * (temp[idx] - bak[idx]);
    }
}
}
