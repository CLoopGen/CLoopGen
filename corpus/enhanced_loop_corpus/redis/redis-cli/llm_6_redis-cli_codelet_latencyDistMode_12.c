#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
struct distsamples {
    long long max;
    long long count;
    int character;
};


extern long long latency;
extern int j;
extern struct distsamples samples[];

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    long long temp_max;
    for (j = 0; ; j++) {
        temp_max = samples[j].max;
        if (temp_max == 0 || latency <= temp_max) {
            samples[j].count += 1;
            break;
        }
    }
}
