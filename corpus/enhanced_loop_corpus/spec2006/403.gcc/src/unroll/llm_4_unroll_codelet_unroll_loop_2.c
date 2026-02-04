#include <stdio.h>

#include <inttypes.h>

struct _factor {
    const int factor;
    int count;
};


extern struct _factor factors[4];
extern int i;
extern unsigned long temp;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 4 - 1; i >= 0; i--) {
        if (temp % factors[i].factor != 0) {
            continue;
        }
        do {
            factors[i].count++;
            temp = temp / factors[i].factor;
        } while (temp % factors[i].factor == 0);
    }
}
