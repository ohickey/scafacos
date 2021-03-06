/*
  Copyright (C) 2011,2012 Olaf Lenz
  
  This file is part of ScaFaCoS.
  
  ScaFaCoS is free software: you can redistribute it and/or modify
  it under the terms of the GNU General Public License as published by
  the Free Software Foundation, either version 3 of the License, or
  (at your option) any later version.
  
  ScaFaCoS is distributed in the hope that it will be useful,
  but WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
  GNU General Public License for more details.
  
  You should have received a copy of the GNU General Public License
  along with this program.  If not, see <http://www.gnu.org/licenses/>. 
*/
#include "caf.h"

#include <stdio.h>
#include <stdlib.h>
#include "utils.h"

/** Computes the charge assignment function of for the \a i'th degree
    at value \a x. */
fcs_float ifcs_p3m_caf(fcs_int i, fcs_float x, fcs_int cao_value) {
  switch (cao_value) {
  case 1 : return 1.0;
  case 2 : {
    switch (i) {
    case 0: return 0.5-x;
    case 1: return 0.5+x;
    default:
      printf("Tried to access charge assignment function of degree %d in scheme of order %d.\n",i,cao_value);
      return 0.0;
    }
  } 
  case 3 : { 
    switch (i) {
    case 0: return 0.5*SQR(0.5 - x);
    case 1: return 0.75 - SQR(x);
    case 2: return 0.5*SQR(0.5 + x);
    default:
      printf("Tried to access charge assignment function of degree %d in scheme of order %d.\n",i,cao_value);
      return 0.0;
    }
  case 4 : { 
    switch (i) {
    case 0: return ( 1.0+x*( -6.0+x*( 12.0-x* 8.0)))/48.0;
    case 1: return (23.0+x*(-30.0+x*(-12.0+x*24.0)))/48.0;
    case 2: return (23.0+x*( 30.0+x*(-12.0-x*24.0)))/48.0;
    case 3: return ( 1.0+x*(  6.0+x*( 12.0+x* 8.0)))/48.0;
    default:
      printf("Tried to access charge assignment function of degree %d in scheme of order %d.\n",i,cao_value);
      return 0.0;
    }
  }
  case 5 : {
    switch (i) {
    case 0: return (  1.0+x*( -8.0+x*(  24.0+x*(-32.0+x*16.0))))/384.0;
    case 1: return ( 19.0+x*(-44.0+x*(  24.0+x*( 16.0-x*16.0))))/ 96.0;
    case 2: return (115.0+x*       x*(-120.0+x*       x*48.0))  /192.0;
    case 3: return ( 19.0+x*( 44.0+x*(  24.0+x*(-16.0-x*16.0))))/ 96.0;
    case 4: return (  1.0+x*(  8.0+x*(  24.0+x*( 32.0+x*16.0))))/384.0;
    default:
      printf("Tried to access charge assignment function of degree %d in scheme of order %d.\n",i,cao_value);
      return 0.0;
    }
  }
  case 6 : {
    switch (i) {
    case 0: return (  1.0+x*( -10.0+x*(  40.0+x*( -80.0+x*(  80.0-x* 32.0)))))/3840.0;
    case 1: return (237.0+x*(-750.0+x*( 840.0+x*(-240.0+x*(-240.0+x*160.0)))))/3840.0;
    case 2: return (841.0+x*(-770.0+x*(-440.0+x*( 560.0+x*(  80.0-x*160.0)))))/1920.0;
    case 3: return (841.0+x*(+770.0+x*(-440.0+x*(-560.0+x*(  80.0+x*160.0)))))/1920.0;
    case 4: return (237.0+x*( 750.0+x*( 840.0+x*( 240.0+x*(-240.0-x*160.0)))))/3840.0;
    case 5: return (  1.0+x*(  10.0+x*(  40.0+x*(  80.0+x*(  80.0+x* 32.0)))))/3840.0;
    default:
      printf("Tried to access charge assignment function of degree %d in scheme of order %d.\n",i,cao_value);
      return 0.0;
    }
  }
  case 7 : {
    switch (i) {
    case 0: return (    1.0+x*(   -12.0+x*(   60.0+x*( -160.0+x*(  240.0+x*(-192.0+x* 64.0))))))/46080.0;
    case 1: return (  361.0+x*( -1416.0+x*( 2220.0+x*(-1600.0+x*(  240.0+x*( 384.0-x*192.0))))))/23040.0;
    case 2: return (10543.0+x*(-17340.0+x*( 4740.0+x*( 6880.0+x*(-4080.0+x*(-960.0+x*960.0))))))/46080.0;
    case 3: return ( 5887.0+x*          x*(-4620.0+x*         x*( 1680.0-x*        x*320.0)))   /11520.0;
    case 4: return (10543.0+x*( 17340.0+x*( 4740.0+x*(-6880.0+x*(-4080.0+x*( 960.0+x*960.0))))))/46080.0;
    case 5: return (  361.0+x*(  1416.0+x*( 2220.0+x*( 1600.0+x*(  240.0+x*(-384.0-x*192.0))))))/23040.0;
    case 6: return (    1.0+x*(    12.0+x*(   60.0+x*(  160.0+x*(  240.0+x*( 192.0+x* 64.0))))))/46080.0;
    default:
      printf("Tried to access charge assignment function of degree %d in scheme of order %d.\n",i,cao_value);
      return 0.0;
    }
  }
  default :{
    printf("Charge assignment order %d unknown.\n",cao_value);
    return 0.0;
  }}}
}

#ifdef P3M_AD
/** Computes the gradient of the charge assignment function of for the \a i'th degree
    at value \a x. */
fcs_float ifcs_p3m_caf_d(fcs_int i, fcs_float x, fcs_int cao_value) {
  fcs_int ip = cao_value - 1;
  switch (ip) 
    {
    case 1:
	    switch(i) {
	    case 0: return -1.0;
	    case 1: return 1.0;
	    }
      break;
    case 2:
	    switch(i) {
	    case 0: return x-0.5;
	    case 1: return -2.0*x;
	    case 2: return x+0.5;
	    }
      break;
    case 3:
	    switch(i) {
	    case 0: return (-1.0+x*(  4.0+x*( -4.0)))/8.0;
	    case 1: return (-5.0+x*( -4.0+x*( 12.0)))/8.0;
	    case 2: return ( 5.0+x*( -4.0+x*(-12.0)))/8.0;
	    case 3: return ( 1.0+x*(  4.0+x*(  4.0)))/8.0;
	    }
      break;
    case 4:
	    switch(i) {
	    case 0: return ( -1.0+x*(  6.0+x*( -12.0+x*( 8.0))))/48.0;
	    case 1: return (-11.0+x*( 12.0+x*(  12.0+x*(-16.0))))/24.0;
	    case 2: return (      x*(-5.0+x*x*4.0))/4.0;
	    case 3: return ( 11.0+x*( 12.0+x*( -12.0+x*(-16.0))))/ 24.0;
	    case 4: return (  1.0+x*(  6.0+x*(  12.0+x*(  8.0))))/48.0;
	    }
        break;
    case 5:
	    switch(i) {
	    case 0: return ( -1.0+x*(  8.0+x*( -24.0+x*(  32.0+x*(-16)))))/384.0;
	    case 1: return (-75.0+x*( 168.0+x*( -72.0+x*( -96.0+x*(80.0)))))/384.0;
	    case 2: return (-77.0+x*( -88.0+x*( 168.0+x*(  32.0+x*(-80.0)))))/192.0;
	    case 3: return ( 77.0+x*( -88.0+x*(-168.0+x*(  32.0+x*(80.0)))))/192.0;
	    case 4: return ( 75.0+x*( 168.0+x*(  72.0+x*( -96.0+x*(-80)))))/384.0;
	    case 5: return (  1.0+x*(   8.0+x*(  24.0+x*(  32.0+x*(16.0)))))/384.0;
	    }
       break;
    case 6 : 
	    switch(i) {
	    case 0: return (  -1.0+x*( 10.0+x*( -40.0+x*(  80.0+x*(-80.0+x*32.0)))))/3840.0;
	    case 1: return ( -59.0+x*(185.0+x*(-200.0+x*(  40.0+x*( 80.0-x*48.0)))))/960.0;
	    case 2: return (-289.0+x*(158.0+x*( 344.0+x*(-272.0+x*(-80.0+x*96.0)))))/768.0;
	    case 3: return (       x*(-77.0+        x*x*(  56.0       -x*x*16.0) ) )/96.0;
	    case 4: return ( 289.0+x*(158.0+x*(-344.0+x*(-272.0+x*( 80.0+x*96.0)))))/768.0;
	    case 5: return (  59.0+x*(185.0+x*( 200.0+x*(  40.0+x*(-80.0-x*48.0)))))/960.0;
	    case 6: return (   1.0+x*( 10.0+x*(  40.0+x*(  80.0+x*( 80.0+x*32.0)))))/3840.0;
	    }
       break;
    default :
      fprintf(stderr,"Charge assignment order %d unknown.\n",cao_value);
      return 0.0;
  }
  return 0.0;
}

#endif

/** Interpolates the P-th order charge assignment function from
 * Hockney/Eastwood 5-189 (or 8-61). The following charge fractions
 * are also tabulated in Deserno/Holm. */
void ifcs_p3m_interpolate_charge_assignment_function(ifcs_p3m_data_struct *d) {
  const fcs_int N = d->n_interpol;
  const fcs_float dInterpol = 0.5 / N;
  const fcs_int cao = d->cao;
  fcs_int i;
  long j;


  P3M_TRACE(printf("    ifcs_p3m_caf: interpolating caf of order %d with %d points\n", \
                   cao,N));

  if (N > 0) {
    d->int_caf = (fcs_float*)realloc(d->int_caf, sizeof(fcs_float)*(2*N+1)*d->cao);
#ifdef P3M_AD
    d->int_caf_d = (fcs_float*)realloc(d->int_caf_d, sizeof(fcs_float)*(2*N+1)*d->cao);
#endif

    /* loop over all interpolation points */
    for (i = -N; i <= N; i++) {
      /* loop over all cao */
      for (j = 0; j < cao; j++) {
        d->int_caf[(i+N)*cao + j] = ifcs_p3m_caf(j, i*dInterpol, cao);
#ifdef P3M_AD
        d->int_caf_d[(i+N)*cao + j] = ifcs_p3m_caf_d(j, i*dInterpol, cao);
#endif
      }
    }
  } else {
    /* otherwise just allocate the memory to store the precomputed values */
    d->int_caf = (fcs_float*)realloc(d->int_caf, sizeof(fcs_float)*3*d->cao);
#ifdef P3M_AD
    d->int_caf_d = (fcs_float*)realloc(d->int_caf_d, sizeof(fcs_float)*3*d->cao);
#endif
  }
}


