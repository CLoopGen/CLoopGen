#include <stdio.h>

#include <inttypes.h>

typedef struct {
    int from;
    int target;
    int captured;
    int promoted;
    int castled;
    int ep;
} move_s;

extern int killer_scores[300];
extern int killer_scores2[300];
extern int killer_scores3[300];
extern move_s dummy;
extern move_s killer1[300];
extern move_s killer2[300];
extern move_s killer3[300];
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Strided memory access with reverse traversal and stride of 10
    for (i = 299; i >= 0; i -= 10) {
        // Reset elements in strided manner, ensuring bounds
        for (int stride = 0; stride < 10 && (i - stride) >= 0; stride++) {
            int idx = i - stride;
            killer_scores[idx] = 0;
            killer_scores2[idx] = 0;
            killer_scores3[idx] = 0;
            killer1[idx] = dummy;
            killer2[idx] = dummy;
            killer3[idx] = dummy;
        }
    }
}
