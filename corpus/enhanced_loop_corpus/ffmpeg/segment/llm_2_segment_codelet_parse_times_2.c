#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int *nb_times;
extern char *p;
extern char *times_str1;

// Variable name mappings to avoid conflicts with system symbols



void loop() {
    // Variant 1: Strided memory access (process every 2nd character)
    for (p = times_str1; *p; p += 2) {
        if (*p == ',') {
            (*nb_times)++;
        }
        // Handle potential odd-length string by checking next char if exists
        if (*(p + 1) && *(p + 1) == ',') {
            (*nb_times)++;
        }
    }
}
