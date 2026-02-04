#include <stdio.h>

extern  int debug_vec[8];
extern int i;



void loop(){
    for (i = 0; i <= 7; i++) {
        for (int j = 0; j < 1; j++) {
            debug_vec[i] = 0;
        }
    }
}
