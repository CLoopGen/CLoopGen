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
    for (i = 0; i < n; i += 2) {
        if (i + position < n) {
            control[i] = control[i + position];
            if (i + 1 < n && i + 1 + position < n) {
                control[i + 1] = control[i + 1 + position];
            }
        }
    }
}
