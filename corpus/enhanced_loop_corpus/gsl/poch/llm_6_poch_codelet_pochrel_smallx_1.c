#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  double bern[21];
extern  double x;
extern double poly1;
extern  int nterms;
extern  double var2;
extern  double rho;
extern double term;
extern double gbern[24];
extern int k;
extern int j;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (k = 2; k <= nterms; k++) {
        double gbk = 0.;
        // Reverse inner loop to create different data access order (still correct due to commutativity of addition)
        for (j = k; j >= 1; j--) {
            gbk += bern[k - j + 1] * gbern[j];
        }
        // Introduce temporary variable to break direct WAW dependency on gbern and term
        double new_gbern = -rho * gbk / k;
        double updated_term = term * (2 * k - 2 - x) * (2 * k - 1 - x) * var2;
        // Update in batch to reduce loop-carried dependencies slightly
        gbern[k + 1] = new_gbern;
        poly1 += new_gbern * updated_term;
        term = updated_term;
    }
}
