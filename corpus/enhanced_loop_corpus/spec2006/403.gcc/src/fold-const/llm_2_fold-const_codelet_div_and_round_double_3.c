#include <stdio.h>

#include <inttypes.h>

extern long num[5];
extern long den[4];
extern long quo[4];
extern int i;
extern int j;
extern unsigned long work;
extern unsigned long carry;
extern int num_hi_sig;
extern int den_hi_sig;
extern unsigned long quo_est;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i = num_hi_sig - den_hi_sig - 1; i >= 0; i--) {
    unsigned long tmp;
    num_hi_sig = i + den_hi_sig + 1;
    work = num[num_hi_sig] * ((unsigned long)1 << (8 * 8) / 2) + num[num_hi_sig - 1];
    if (num[num_hi_sig] != den[den_hi_sig])
        quo_est = work / den[den_hi_sig];
    else
        quo_est = ((unsigned long)1 << (8 * 8) / 2) - 1;
    tmp = work - quo_est * den[den_hi_sig];
    if (tmp < ((unsigned long)1 << (8 * 8) / 2) && (den[den_hi_sig - 1] * quo_est > (tmp * ((unsigned long)1 << (8 * 8) / 2) + num[num_hi_sig - 2])))
        quo_est--;
    carry = 0;
    for (j = 0; j <= den_hi_sig; j++) {
        int idx = i + j; // Consecutive memory access with explicit index variable
        work = quo_est * den[j] + carry;
        carry = ((unsigned long)(work) >> (8 * 8) / 2);
        work = num[idx] - ((work) & (((unsigned long)1 << ((8 * 8) / 2)) - 1));
        num[idx] = ((work) & (((unsigned long)1 << ((8 * 8) / 2)) - 1));
        carry += ((unsigned long)(work) >> (8 * 8) / 2) != 0;
    }
    if (num[num_hi_sig] < carry) {
        quo_est--;
        carry = 0;
        for (j = 0; j <= den_hi_sig; j++) {
            int idx = i + j;
            work = num[idx] + den[j] + carry;
            carry = ((unsigned long)(work) >> (8 * 8) / 2);
            num[idx] = ((work) & (((unsigned long)1 << ((8 * 8) / 2)) - 1));
        }
        num[num_hi_sig] += carry;
    }
    quo[i] = quo_est;
}
}
