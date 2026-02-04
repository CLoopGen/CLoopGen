#include <stdio.h>

#include <inttypes.h>

extern  unsigned short *x;
extern unsigned short *y;
extern unsigned int a;
extern int i;
extern unsigned int carry;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    unsigned short *local_x = x;
    unsigned short *local_y = y;
    unsigned int local_carry = carry;
    int local_i;

    for (local_i = 2; local_i < (6 + 3); local_i++) {
        unsigned int a = (unsigned int)(*local_x) + (unsigned int)(*local_y);
        if (a & 65536) {
            a &= 65535;
            *(local_y - 1) += 1; // Introduce WAR dependency via earlier memory update
        }
        *local_y = (unsigned short)a;
        local_x--;
        local_y--;
    }
    carry = local_carry; // Eliminate loop-carried carry update (WAW removed)
}
