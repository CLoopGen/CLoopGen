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
    for (j = 0; j < 100 && samples[j].max != 0; j++) {
        if (latency <= samples[j].max + 10) {
            samples[j].count += 2;
        }
        if (latency <= samples[j].max + 5) {
            samples[j].count++;
            break;
        }
    }
}
