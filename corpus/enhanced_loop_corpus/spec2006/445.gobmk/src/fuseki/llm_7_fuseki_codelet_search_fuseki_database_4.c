#include <stdio.h>

#include <inttypes.h>

extern int fuseki_value[361];
extern int num_fuseki_moves;
extern int q;
extern int k;
extern int best_fuseki_value;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int local_best = best_fuseki_value / 5;
    int i;
    for (i = 0; i < num_fuseki_moves; i++) {
        int val = fuseki_value[i];
        if (val < local_best) {
            k = i;
            break;
        }
        q -= val;
        k = i;
        if (q < 0)
            break;
    }
}
