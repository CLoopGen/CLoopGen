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
unsigned long temp_quo[4];
int write_index;
for (i = num_hi_sig - den_hi_sig - 1, write_index = 0; i >= 0; i--, write_index++) {
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
    for (j = den_hi_sig; j >= 0; j--) {
        work = quo_est * den[j] + carry;
        carry = ((unsigned long)(work) >> (8 * 8) / 2);
        work = num[i + j] - ((work) & (((unsigned long)1 << ((8 * 8) / 2)) - 1));
        num[i + j] = ((work) & (((unsigned long)1 << ((8 * 8) / 2)) - 1));
        carry += ((unsigned long)(work) >> (8 * 8) / 2) != 0;
    }
    if (num[num_hi_sig] < carry) {
        quo_est--;
        carry = 0;
        for (j = den_hi_sig; j >= 0; j--) {
            work = num[i + j] + den[j] + carry;
            carry = ((unsigned long)(work) >> (8 * 8) / 2);
            num[i + j] = ((work) & (((unsigned long)1 << ((8 * 8) / 2)) - 1));
        }
        num[num_hi_sig] += carry;
    }
    temp_quo[write_index] = quo_est;
}
for (i = 0; i < num_hi_sig - den_hi_sig; i++)
    quo[i] = temp_quo[i];
}
