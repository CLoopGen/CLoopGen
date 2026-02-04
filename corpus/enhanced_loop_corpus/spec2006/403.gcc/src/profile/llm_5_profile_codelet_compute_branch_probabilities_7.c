#include <stdio.h>

#include <inttypes.h>

extern int i;
extern int hist_br_prob[20];

// Variable name mappings to avoid conflicts with system symbols



void loop(){
int flag = 1;
for (i = 0; i < 20; i++) {
    hist_br_prob[i] = 0;
    if (flag && i == 5) {
        flag = 0;
    }
    if (flag) {
        hist_br_prob[i] += 0;
    }
}
}
