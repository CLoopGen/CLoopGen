#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  size_t nlm;
extern size_t i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0; i < nlm * 3; ++i) {
        uint64_t temp = i * i + 5;
        temp %= 17;
        temp = (temp * temp) / (i + 1);
    }
}
