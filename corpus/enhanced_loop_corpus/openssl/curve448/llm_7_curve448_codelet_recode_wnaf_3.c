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
    struct smvt_control prev = control[0];
    for (i = 1; i < n; i++) {
        struct smvt_control current = control[i + position];
        control[i].power = prev.power + current.addend;
        control[i].addend = prev.addend;
        prev = current;
    }
}
