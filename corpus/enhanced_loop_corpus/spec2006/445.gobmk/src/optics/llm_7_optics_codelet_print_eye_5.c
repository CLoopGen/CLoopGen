#include <stdio.h>

#include <inttypes.h>

struct eyevalue {
    unsigned char a;
    unsigned char b;
    unsigned char c;
    unsigned char d;
};


struct eye_data {
    int color;
    int esize;
    int msize;
    int origin;
    struct eyevalue value;
    int attack_point;
    int defense_point;
    char marginal;
    char type;
    char neighbors;
    char marginal_neighbors;
    char cut;
};


extern int board_size;
extern struct eye_data eye[400];
extern int m;
extern int n;
extern int mini;
extern int maxi;
extern int minj;
extern int maxj;
extern int origin;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Introduce artificial loop-carried dependency via cumulative index access
    // RAW dependency introduced: each iteration depends on previous write to 'origin'
    int prev_m = -1, prev_n = -1;
    int temp_origin = origin;

    for (m = 0; m < board_size; m++) {
        for (n = 0; n < board_size; n++) {
            int index = (19 + 2) + m * (19 + 1) + n;
            
            // Artificially create a chain: use result of previous valid match
            if (prev_m >= 0 && prev_n >= 0) {
                int prev_index = (19 + 2) + prev_m * (19 + 1) + prev_n;
                // RAW dependency: current temp_origin depends on prior iteration's update
                temp_origin = eye[prev_index].origin;
            }

            if (eye[index].origin != temp_origin) {
                continue;
            }

            // Update bounds with potential WAR hazard avoided by sequential order
            if (m < mini) mini = m;
            if (m > maxi) maxi = m;
            if (n < minj) minj = n;
            if (n > maxj) maxj = n;

            // Update prev only when condition matches — creates data-dependent iteration flow
            prev_m = m;
            prev_n = n;
        }
    }
}
