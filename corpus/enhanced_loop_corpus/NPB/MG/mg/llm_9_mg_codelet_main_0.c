#include <stdio.h>

extern  int debug_vec[8];
extern int i;



void loop(){
for (i = 0; i <= 15; i++) {
    if (i < 8) {
        debug_vec[i] = 0;
    }
}
}
