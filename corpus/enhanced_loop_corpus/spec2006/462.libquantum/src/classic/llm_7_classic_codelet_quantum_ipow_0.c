#include <stdio.h>

#include <inttypes.h>

extern int a;
extern int b;
extern int i;
extern int r;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int local_r = r;
    for (i = 0; i < b; i += 2) {
        if (i + 1 < b) {
            local_r = local_r * a * a;
        } else {
            local_r = local_r * a;
        }
    }
    r = local_r;
}
