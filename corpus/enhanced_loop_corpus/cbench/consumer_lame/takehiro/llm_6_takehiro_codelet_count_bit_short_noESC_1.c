#include <stdio.h>

#include <inttypes.h>

extern int *ix;
extern int sum;
extern int sign;
extern unsigned char *hlen;
extern int *p;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int temp_sum = 0;
    int temp_sign = sign;
    int local_p[3];
    unsigned char local_hlen_values[3];

    for (i = 0; i < 3; i++) {
        int y = ix[3];
        int x = ix[i];
        if (x != 0) {
            temp_sign++;
            x *= 16;
        }
        if (y != 0) {
            temp_sign++;
            x += y;
        }
        local_p[i] = x;
        local_hlen_values[i] = hlen[x];
    }

    for (i = 0; i < 3; i++) {
        p[i] = local_p[i];
        sum += local_hlen_values[i];
    }

    sign = temp_sign;
}
