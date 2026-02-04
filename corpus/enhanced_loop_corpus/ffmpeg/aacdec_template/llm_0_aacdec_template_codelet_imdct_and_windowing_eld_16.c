#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int i;
extern  int n;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (int j = 0; j < n; j++) {
        for (i = 0; i < n; i += 2) {
        }
    }
}
