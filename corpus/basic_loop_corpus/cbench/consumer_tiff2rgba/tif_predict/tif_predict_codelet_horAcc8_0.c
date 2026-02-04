#include <stdio.h>

#include <inttypes.h>

typedef int int32;

typedef int32 tsize_t;

extern tsize_t stride;
extern char *cp;
extern int i;

// Variable name mappings to avoid conflicts with system symbols

void loop(){
for (i = stride - 4; i > 0; i--) {
    cp[stride] += *cp;
    cp++;
}

}
