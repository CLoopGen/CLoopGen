#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern double count[100];
extern double edge[100];
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    double temp_count = 0;
    double temp_edge = 0;
    for (i = 0; i < 100; i++) {
        temp_count += count[i];
        temp_edge += edge[i];
        count[i] = temp_count;
        edge[i] = temp_edge;
    }
}
