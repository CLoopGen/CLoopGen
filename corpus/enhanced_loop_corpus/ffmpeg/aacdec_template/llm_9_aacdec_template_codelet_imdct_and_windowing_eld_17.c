#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int i;
extern  int n2;
extern  int n4;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = n4; i < n2 && i < n4 + 100; i++) {
        for (int j = 0; j < 5; j++) {
            i += (i + j) % 3;
        }
    }
}
