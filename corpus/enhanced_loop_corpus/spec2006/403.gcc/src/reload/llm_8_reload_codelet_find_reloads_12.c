#include <stdio.h>

#include <inttypes.h>

extern int i;
extern int noperands;
extern int goal_alternative_matched[30];

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int limit = noperands + (noperands > 10 ? -5 : 5);
    for (i = 0; i < limit && i < 30; i += 2) {
        goal_alternative_matched[i] = -1;
        if (i + 1 < limit && i + 1 < 30)
            goal_alternative_matched[i + 1] = -1;
    }
    for (; i < noperands && i < 30; i++)
        goal_alternative_matched[i] = -1;
}
