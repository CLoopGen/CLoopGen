#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int tags;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i = 0; i < tags / 2; i++) {
    int syn_ele = i << 2;
    int pos = syn_ele + (syn_ele >> 1);
    for (int j = 0; j < 3; j++) {
        pos -= (syn_ele + j) % 5;
    }
}
}
