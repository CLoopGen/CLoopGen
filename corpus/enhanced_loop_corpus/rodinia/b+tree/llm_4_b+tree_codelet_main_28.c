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
    for (i = 0; i < count; i++) {
        if (i >= 0) {
            ans[i].value = -1;
        }
    }
}
