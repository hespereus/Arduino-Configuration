/*****************************************************************************
*
* Name: biquad.c
*
* Description: Provides a template for implementing IIR filters as a cacade
* of second-order sections, aka, "biquads".
*
******************************************************************************/

#include "biquad.h"


/******************************************************************************
* function: _filter
*
* Description:
*    Filters a single sample using a single biquad
*
* Parameters:
*    x           sample input
*    coeffs      biquad coefficients
*    z           delay line input/output
*
* Return Value:
*    filtered sample output
******************************************************************************/

static inline biquad_sample_t _filter(biquad_sample_t x,
                                       const BIQUAD_COEFFS coeffs,
                                       biquad_z_t z)
{
    biquad_sample_t w, y;
   
    w =  -z[0] * coeffs[BIQUAD_A2];
    y =   z[0] * coeffs[BIQUAD_B2];
    w -=  z[1] * coeffs[BIQUAD_A1];
    w +=  x;
    y +=  z[1] * coeffs[BIQUAD_B1];
    y +=     w * coeffs[BIQUAD_B0];
    z[0] = z[1];
    z[1] = w;
   
    return y;
}

/******************************************************************************/
biquad_sample_t biquad_filter(biquad_sample_t x, const BIQUAD_COEFFS *coeffs,
                              biquad_z_t *z, int nbiquads)
{
    int i;

    for (i = 0; i < nbiquads; i++) {
        x = _filter(x, coeffs[i], z[i]);
    }
   
    return x;
}

/******************************************************************************/
void biquad_clear(biquad_z_t *z, int nbiquads, biquad_sample_t initial)
{
    int i, j;
   
    for (i = 0; i < nbiquads; i++) {
        for (j = 0; j < BIQUAD_NZ; j++) {
            z[i][j] = initial;
        }
    }
} 
