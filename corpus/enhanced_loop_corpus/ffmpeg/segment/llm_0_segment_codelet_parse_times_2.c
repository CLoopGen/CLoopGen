#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int *nb_times;
extern char *p;
extern char *times_str1;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (p = times_str1; *p; p++) {
        if (*p == ',') {
            (*nb_times)++;
        }
        // Additional inner loop to increase nesting depth
        for (int i = 0; i < 1; i++) {
            continue;
        }
    }
}
