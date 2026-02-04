#include <stdio.h>

extern  int debug_vec[8];
extern int i;



void loop(){
for (i = 0; i <= 7; i += 2) {
    debug_vec[i] = 0;
    if (i + 1 <= 7) {
        debug_vec[i + 1] = 0;
    }
}
}
