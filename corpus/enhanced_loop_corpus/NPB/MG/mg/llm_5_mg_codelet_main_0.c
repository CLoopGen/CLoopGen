#include <stdio.h>

extern  int debug_vec[8];
extern int i;



void loop(){
    for (i = 0; i <= 7; ++i) {
        if (i >= 0) {
            debug_vec[i] = 0;
        }
    }
}
