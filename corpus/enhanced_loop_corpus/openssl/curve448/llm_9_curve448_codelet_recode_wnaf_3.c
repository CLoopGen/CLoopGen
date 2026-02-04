#include <stdio.h>

#include <inttypes.h>

struct smvt_control {
    int power;
    int addend;
};


extern struct smvt_control *control;
extern int position;
extern unsigned int n;
extern unsigned int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    unsigned int limit = n * 2;
    for (i = 0; i < limit; i++) {
        unsigned int src_idx = (i % n) + position;
        unsigned int dst_idx = i % n;
        if (src_idx < n) {
            control[dst_idx].power += control[src_idx].power;
            control[dst_idx].addend += control[src_idx].addend;
        }
    }
}
