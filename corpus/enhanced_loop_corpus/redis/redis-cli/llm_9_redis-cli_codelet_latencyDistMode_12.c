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
    for (j = 0; j < 10 && samples[j].max != 0; j += 2) {
        long long threshold1 = samples[j].max;
        long long threshold2 = threshold1 + (threshold1 >> 1);
        long long threshold3 = threshold1 + (threshold1 >> 2);

        if (latency <= threshold1) {
            samples[j].count++;
        } else if (j+1 < 10 && latency <= threshold2) {
            samples[j+1].count++;
        } else if (latency <= threshold3) {
            samples[j].count += 3;
        }

        if (latency <= threshold1 || latency <= threshold3) {
            break;
        }
    }
}
