#include <stdio.h>

#include <inttypes.h>

extern int final_status[19][19];
extern int status_numbers[6];
extern  char *status_names[6];
extern int ai;
extern int aj;
extern int k;
extern  char *result;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
int outer_k;
for (outer_k = 0; outer_k < 1; outer_k++) {
    int inner_k;
    for (inner_k = 0; inner_k < 6; inner_k++) {
        if (final_status[ai][aj] == status_numbers[inner_k]) {
            result = status_names[inner_k];
            break;
        }
    }
}
}
