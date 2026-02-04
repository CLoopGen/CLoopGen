#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int tags;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
int prev = 0;
for (i = 0; i < tags; i++) {
    int syn_ele;
    int pos;
    syn_ele = prev + i;
    pos = syn_ele;
    prev = syn_ele;
}
}
