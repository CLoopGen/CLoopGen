#include <stdio.h>

#include <inttypes.h>

extern int fuseki_value[361];
extern int num_fuseki_moves;
extern int q;
extern int k;
extern int best_fuseki_value;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
int temp_sum = 0;
for (k = 0; k < num_fuseki_moves && k < 100; k++) {
    if (fuseki_value[k] < (best_fuseki_value / 5))
        break;
    temp_sum += fuseki_value[k];
    if (temp_sum > q)
        break;
}
q -= temp_sum;
}
