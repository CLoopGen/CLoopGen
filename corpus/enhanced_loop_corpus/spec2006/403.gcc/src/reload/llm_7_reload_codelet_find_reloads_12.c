#include <stdio.h>

#include <inttypes.h>

extern int i;
extern int noperands;
extern int goal_alternative_matched[30];

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = noperands - 1; i >= 0; i--)
        goal_alternative_matched[i] = -1;
}
