#include <stdio.h>

#include <inttypes.h>

extern int fuseki_value[361];
extern int num_fuseki_moves;
extern int q;
extern int k;
extern int best_fuseki_value;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
int threshold = best_fuseki_value / 5;
int local_q = q;
for (k = 0; k < num_fuseki_moves; k += 2) {
    if (fuseki_value[k] < threshold) {
        break;
    }
    local_q -= fuseki_value[k];
    if (local_q < 0) {
        break;
    }
    if (k + 1 < num_fuseki_moves && fuseki_value[k+1] >= threshold) {
        local_q -= fuseki_value[k+1];
        if (local_q < 0) {
            k++;
            break;
        }
    }
}
q = local_q;
}
