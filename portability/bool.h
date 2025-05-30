#ifndef AVS_PORTABILITY_BOOL_H
#define AVS_PORTABILITY_BOOL_H

#if AVS_STDC_VERSION < AVS_STDC_23 && AVS_STDC_VERSION >= AVS_STDC_99
#include <stdbool.h>
#else
#ifndef bool
#define bool unsigned int
#endif /* bool */
#ifndef true
#define true 1
#endif /* true */
#ifndef false
#define false 0
#endif /* false */
#endif /* STDC_V < C99 */

#endif /* AVS_PORTABILITY_BOOL_H */
