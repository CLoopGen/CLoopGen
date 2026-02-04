#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int tags;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0; i < tags; i++) {
        int syn_ele;
        int pos;
        for (int k = 0; k < 5; k++) {
            syn_ele += k;
        }
    }
}
