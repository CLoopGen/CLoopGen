#include <stdio.h>

extern  int debug_vec[8];
extern int i;



void loop(){
    int prev = 0;
    for (i = 0; i <= 7; i++) {
        debug_vec[i] = prev;
        prev = debug_vec[i] + 1;
    }
}
