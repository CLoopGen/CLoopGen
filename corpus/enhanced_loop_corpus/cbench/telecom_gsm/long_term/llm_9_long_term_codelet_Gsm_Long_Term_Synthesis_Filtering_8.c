#include <stdio.h>

#include <inttypes.h>

typedef short word;

typedef long longword;

typedef unsigned long ulongword;

extern word *erp;
extern word *drp;
extern longword ltmp;
extern int k;
extern word brp;
extern word drpp;
extern word Nr;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (k = 0; k <= 59; k += 3) {
        word temp1 = drp[(k - Nr) % 40];
        word temp2 = drp[(k - Nr + 1) % 40];
        word temp3 = drp[(k - Nr + 2) % 40];
        
        longword product1 = (longword)(brp) * (longword)(temp1);
        longword product2 = (longword)(brp + 1) * (longword)(temp2);
        longword product3 = (longword)(brp - 1) * (longword)(temp3);

        longword sum1 = (product1 + 16384) >> 15;
        longword sum2 = (product2 + 16384) >> 15;
        longword sum3 = (product3 + 16384) >> 15;

        longword avg = (sum1 + sum2 + sum3) / 3;

        ltmp = (longword)(erp[k % 40]) + avg;

        drp[k % 40] = (ulongword)(ltmp - (-32768)) > 65535 ? 
                      (ltmp > 0 ? 32767 : -32768) : 
                      (word)ltmp;
    }
}
