#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int i;
extern double data[256];

// Variable name mappings to avoid conflicts with system symbols

void loop(){
for (i = 1; i <= 10; i++) {
    ((data)[2 * (i)]) = ((data)[2 * (128 - i)]) = 1.;
}

}
