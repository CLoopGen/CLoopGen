#include <stdio.h>

#include <inttypes.h>

typedef struct {
    int l[22];
    int s[13][3];
} III_scalefac_t;

extern int pretab[21];
extern III_scalefac_t *scalefac;
extern int sfb;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
int indices[] = {11, 12, 13, 14, 15, 16, 17, 18, 19, 20};
for (int i = 0; i < 10; i++) {
    int sfb = indices[i];
    if (scalefac->l[sfb] < pretab[sfb])
        break;
}
}
