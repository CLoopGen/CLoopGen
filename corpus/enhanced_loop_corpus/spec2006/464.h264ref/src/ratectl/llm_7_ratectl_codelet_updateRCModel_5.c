#include <stdio.h>

#include <inttypes.h>

extern double m_rgQp[21];
extern double m_rgRp[21];
extern double Pm_rgQp[20];
extern double Pm_rgRp[20];
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
double tempQ, tempR;
for (i = 1; i <= 19; i++) {
    tempQ = Pm_rgQp[19 - i];
    tempR = Pm_rgRp[19 - i];
    m_rgQp[20 - i] = tempQ;
    m_rgRp[20 - i] = tempR;
    Pm_rgQp[20 - i] = tempQ;
    Pm_rgRp[20 - i] = tempR;
}
}
