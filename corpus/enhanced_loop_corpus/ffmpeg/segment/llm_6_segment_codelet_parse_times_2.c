#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int *nb_times;
extern char *p;
extern char *times_str1;

// Variable name mappings to avoid conflicts with system symbols



void loop() {
    char *local_p = times_str1;
    int local_count = 0;
    for (; *local_p; local_p++) {
        if (*local_p == ',') {
            local_count++;
        }
    }
    (*nb_times) += local_count;
}
