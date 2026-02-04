#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int32_t *p1;
extern int32_t *p2;
extern int length;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int32_t *temp_p1 = p1;
    int32_t *temp_p2 = p2;
    for (i = 0; i < length; i++) {
        uint32_t a = *(temp_p1 + i * 2);      // Strided access with stride 2
        uint32_t b = *(temp_p2 + i * 2);
        if (i * 2 < length) {
            p2[i * 2] = a + b;
        }
    }
}
