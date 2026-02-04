#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int *nb_times;
extern char *p;
extern char *times_str1;

// Variable name mappings to avoid conflicts with system symbols



void loop() {
    char *temp_p = times_str1;
    int count = *nb_times;
    for (size_t i = 0; temp_p[i] != '\0'; i++) {
        if (temp_p[i] == ',') {
            count++;
        }
    }
    *nb_times = count;
}
