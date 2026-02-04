#include <stdio.h>

#include <inttypes.h>

extern int length;
extern int j;
extern int bdig[6];
extern int old;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int local_old = old;
    for (int i = 0; i <= length - 2; i++) {
        local_old = local_old * 10 + bdig[i];
    }
    old = local_old;
}
