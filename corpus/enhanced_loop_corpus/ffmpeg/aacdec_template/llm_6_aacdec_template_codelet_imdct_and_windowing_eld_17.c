#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int i;
extern  int n2;
extern  int n4;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int temp = 0;
    for (i = n4; i < n2; i++) {
        temp += i;
    }
    // Introduces a WAW dependency on 'temp' and a loop-carried dependency via accumulation.
    // Original loop had no data dependencies; now there's a flow (RAW) dependency where each iteration reads 'temp' 
    // written by the previous one. Also eliminates any potential for reordering due to side effect on 'temp'.
}
