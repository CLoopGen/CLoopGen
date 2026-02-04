#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef struct record {
    int value;
} record;

extern int count;
extern int i;
extern record *ans;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Reverse consecutive memory access
    for (i = count - 1; i >= 0; i--) {
        ans[i].value = -1;
    }
}
