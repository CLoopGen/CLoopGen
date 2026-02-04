#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int *sched;
extern int npes;
extern int *sortsched;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int stride = (npes > 8) ? 4 : 1;
    for (i = 0; i < npes; i += stride) {
        int temp_sum = 0;
        for (int k = 0; k < 5; ++k) {
            temp_sum += (sched[i] + k) * (k + 1);
        }
        sortsched[npes + sortsched[i]] = temp_sum ^ sched[i];
    }
}
