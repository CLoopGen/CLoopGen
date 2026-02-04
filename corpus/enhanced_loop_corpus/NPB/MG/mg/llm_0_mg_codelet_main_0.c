#include <stdio.h>

extern  int debug_vec[8];
extern int i;



void loop(){
    for (i = 0; i <= 3; i++) {
        for (int j = 0; j <= 1; j++) {
            int idx = 2 * i + j;
            if (idx <= 7) {
                debug_vec[idx] = 0;
            }
        }
    }
}
