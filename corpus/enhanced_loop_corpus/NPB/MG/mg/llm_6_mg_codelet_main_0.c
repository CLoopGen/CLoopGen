#include <stdio.h>

extern  int debug_vec[8];
extern int i;



void loop(){
    int temp = 0;
    for (i = 0; i <= 7; i++) {
        temp = debug_vec[i];
        debug_vec[i] = temp + 1;
        temp = debug_vec[i];
    }
}
