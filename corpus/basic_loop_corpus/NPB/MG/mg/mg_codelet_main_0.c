#include <stdio.h>

extern  int debug_vec[8];
extern int i;

void loop(){
for (i = 0; i <= 7; i++) {
    debug_vec[i] = 0;
}

}
