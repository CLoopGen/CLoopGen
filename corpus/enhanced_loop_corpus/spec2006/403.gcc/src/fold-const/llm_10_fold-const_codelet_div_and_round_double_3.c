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
    if (num[num_hi_sig] != den[den_hi_sig]) {
        quo_est = work / den[den_hi_sig];
        tmp = work - quo_est * den[den_hi_sig];
        if (tmp < ((unsigned long)1 << (8 * 8) / 2)) {
            unsigned long correction_term = den[den_hi_sig - 1] * quo_est;
            unsigned long dividend_part = tmp * ((unsigned long)1 << (8 * 8) / 2) + num[num_hi_sig - 2];
            if (correction_term > dividend_part) {
                quo_est--;
                tmp = work - quo_est * den[den_hi_sig];
            }
        }
    } else {
        quo_est = ((unsigned long)1 << (8 * 8) / 2) - 1;
        tmp = work - quo_est * den[den_hi_sig];
    }
    carry = 0;
    for (j = 0; j <= den_hi_sig; j++) {
        unsigned long product = quo_est * den[j];
        work = product + carry;
        carry = work >> ((8 * 8) / 2);
        unsigned long low_word = work & (((unsigned long)1 << ((8 * 8) / 2)) - 1);
        long diff = (long)num[i + j] - (long)low_word;
        carry += (diff < 0) ? 1 : 0;
        num[i + j] = diff & (((unsigned long)1 << ((8 * 8) / 2)) - 1);
    }
    if (num[num_hi_sig] < carry) {
        quo_est--;
        carry = 0;
        for (j = 0; j <= den_hi_sig; j++) {
            work = num[i + j] + den[j] + carry;
            carry = work >> ((8 * 8) / 2);
            num[i + j] = work & (((unsigned long)1 << ((8 * 8) / 2)) - 1);
        }
        num[num_hi_sig] += carry;
    }
    quo[i] = quo_est;
}
}
