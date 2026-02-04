#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int *nb_times;
extern char *p;
extern char *times_str1;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Outer loop controlling a single iteration, reducing effective depth via split logic
    for (int i = 0; i < 1; i++) {
        for (p = times_str1; *p; p++) {
            if (*p == ',') {
                (*nb_times)++;
            }
        }
    }
}
