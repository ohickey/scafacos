#include "fmm_c.h"

#if FMM_MAXNMULTIPOLES > 38
const fmm_float_t fmmec_0d_p39[] = {
#include "include/fmmec_0d_p39.h"
};

const fmm_float_t *get_fmmec_0d_p39()
{
  return fmmec_0d_p39;
}
#endif

