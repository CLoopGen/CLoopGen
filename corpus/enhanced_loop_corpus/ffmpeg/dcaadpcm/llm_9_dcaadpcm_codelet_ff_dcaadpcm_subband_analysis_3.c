#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  int32_t *in;
extern int len;
extern int i;
extern int32_t max;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 1; i < len + 2; i++) {
        int32_t prev = (in[i-1] >= 0) ? in[i-1] : -in[i-1];
        int32_t curr = (in[i]   >= 0) ? in[i]   : -in[i];
        int32_t next = (i+1 < len) ? ((in[i+1] >= 0) ? in[i+1] : -in[i+1]) : curr;
        int32_t combined = (prev + curr + next) / 3;
        max |= combined;
    }
}
