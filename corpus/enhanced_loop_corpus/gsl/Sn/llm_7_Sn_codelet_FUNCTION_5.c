#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern double medA;
extern double medB;
extern int i;
extern int diff;
extern int half;
extern int Amin;
extern int Amax;
extern int even;
extern int length;
extern int leftA;
extern int leftB;
extern int nA;
extern int nB;
extern int tryA;
extern int tryB;
extern int rightA;
extern int rightB;
extern int np1_2;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i = 2; i <= np1_2; ++i) {
    nA = i - 1;
    diff = nB - nA;
    Amin = diff / 2 + 1;
    Amax = diff / 2 + nA;
    leftA = 1;
    rightA = nB;
    leftB = 1;
    rightB = nB;
    int converged = 0;
    for (int iter = 0; iter < 60 && !converged; ++iter) {
        int length = rightA - leftA + 1;
        int even = 1 - (length % 2);
        int half = (length - 1) / 2;
        int tryA = leftA + half;
        int tryB = leftB + half;
        int new_rightA = rightA;
        int new_leftA = leftA;
        int new_rightB = rightB;
        int new_leftB = leftB;
        if (tryA < Amin) {
            new_rightB = tryB;
            new_leftA = tryA + even;
        } else if (tryA > Amax) {
            new_rightA = tryA;
            new_leftB = tryB + even;
        } else {
            if (medA >= medB) {
                new_rightA = tryA;
                new_leftB = tryB + even;
            } else {
                new_rightB = tryB;
                new_leftA = tryA + even;
            }
        }
        if (new_leftA == leftA && new_rightA == rightA &&
            new_leftB == leftB && new_rightB == rightB) {
            converged = 1;
        }
        leftA = new_leftA;
        rightA = new_rightA;
        leftB = new_leftB;
        rightB = new_rightB;
    }
    if (!(leftA > Amax)) {
        medA += 1e-9;
    }
}
}
