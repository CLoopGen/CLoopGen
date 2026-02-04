#include <stdio.h>

#include <inttypes.h>

typedef int int32;

typedef int32 tsize_t;

extern tsize_t stride;
extern char *cp;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    tsize_t j;
    char temp = 0;
    for (j = stride - 4; j > 0; j--) {
        temp += cp[0];        
        cp++;
    }
    cp[stride] += temp;       
}
