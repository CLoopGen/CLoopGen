#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int i;
extern int nthreads;
extern int th_count[4];
extern int temp;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int backup_th_count[4];
    int local_temp = temp;
    for (i = 0; i < 4; i++) {
        if (local_temp >= nthreads) {
            local_temp = 0;
        }
        backup_th_count[i] = local_temp;
        local_temp = local_temp + 1;
    }
    for (i = 0; i < 4; i++) {
        th_count[i] = backup_th_count[i];
    }
    temp = local_temp;
}
