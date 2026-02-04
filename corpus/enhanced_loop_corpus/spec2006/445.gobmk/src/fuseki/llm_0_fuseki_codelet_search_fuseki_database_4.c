#include <stdio.h>

#include <inttypes.h>

extern int fuseki_value[361];
extern int num_fuseki_moves;
extern int q;
extern int k;
extern int best_fuseki_value;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
int k1;
for (k1 = 0; k1 < num_fuseki_moves; k1++) {
    for (k = k1; k < num_fuseki_moves; k++) {
        if (fuseki_value[k] < (best_fuseki_value / 5))
            break;
        q -= fuseki_value[k];
        if (q < 0)
            break;
    }
    if (q < 0) break;
}
}
