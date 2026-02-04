#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int i;
extern  int n2;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (int j = 0; j < n2; j++) {
    for (i = j; i < n2; i += 2) {
        break;
    }
}
}
