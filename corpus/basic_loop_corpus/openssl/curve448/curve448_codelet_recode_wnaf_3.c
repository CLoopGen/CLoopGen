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
for (i = 0; i < n; i++)
    control[i] = control[i + position];

}
