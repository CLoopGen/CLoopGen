#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef long JLONG;

typedef struct {
    int c0min;
    int c0max;
    int c1min;
    int c1max;
    int c2min;
    int c2max;
    JLONG volume;
    long colorcount;
} box;

typedef box *boxptr;

extern boxptr boxlist;
extern int numboxes;
extern boxptr boxp;
extern int i;
extern JLONG maxv;
extern boxptr which;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    JLONG temp_maxv = maxv;
    boxptr temp_which = which;
    for (i = 0; i < numboxes; i++) {
        boxptr current = boxlist + i;
        JLONG vol = current->volume;
        int greater = vol > temp_maxv;
        temp_maxv = greater ? vol : temp_maxv;
        temp_which = greater ? current : temp_which;
    }
    maxv = temp_maxv;
    which = temp_which;
}
