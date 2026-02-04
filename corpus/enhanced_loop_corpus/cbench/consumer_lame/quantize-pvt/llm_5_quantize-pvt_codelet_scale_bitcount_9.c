#include <stdio.h>

#include <inttypes.h>

typedef struct {
    int l[22];
    int s[13][3];
} III_scalefac_t;

extern III_scalefac_t *scalefac;
extern int sfb;
extern int max_slen1;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (sfb = 0; sfb < 11; sfb++) {
        int current = scalefac->l[sfb];
        if (current > max_slen1) {
            max_slen1 = current;
        } else {
            if (current == max_slen1) {
                max_slen1 = current; // Redundant but creates alternate control path
            }
        }
    }
}
