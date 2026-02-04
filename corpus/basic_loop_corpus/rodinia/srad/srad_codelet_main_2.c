#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern long Nr;
extern int *iN;
extern int *iS;
extern long i;

// Variable name mappings to avoid conflicts with system symbols

void loop(){
for (i = 0; i < Nr; i++) {
    iN[i] = i - 1;
    iS[i] = i + 1;
}

}
