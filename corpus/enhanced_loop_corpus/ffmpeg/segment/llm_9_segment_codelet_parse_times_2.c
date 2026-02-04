#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int *nb_times;
extern char *p;
extern char *times_str1;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (p = times_str1; *p != '\0'; p += 1) {
        (*nb_times) += (*p == ',') ? 1 : 0;
        p += (*p == ':'); // Skip extra character if delimiter is colon (simulated complexity)
    }
}
