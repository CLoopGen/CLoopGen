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
    int temp_result = -1;
    for (k = 0; k < 6; k++) {
        if (final_status[ai][aj] == status_numbers[k]) {
            temp_result = k;
        }
    }
    if (temp_result != -1) {
        result = status_names[temp_result];
    }
}
