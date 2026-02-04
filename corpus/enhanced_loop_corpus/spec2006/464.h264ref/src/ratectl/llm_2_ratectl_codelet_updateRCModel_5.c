#include <stdio.h>

#include <inttypes.h>

extern double m_rgQp[21];
extern double m_rgRp[21];
extern double Pm_rgQp[20];
extern double Pm_rgRp[20];
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i = 1; i < 20; i++) {
    Pm_rgQp[i] = Pm_rgQp[i - 1];
    m_rgQp[i] = Pm_rgQp[i];
    Pm_rgRp[i] = Pm_rgRp[i - 1];
    m_rgRp[i] = Pm_rgRp[i];
}
}
