#ifndef AVS_PORTABILITY_STDC_H
#define AVS_PORTABILITY_STDC_H 1

#ifndef AVS_STDC
#ifdef __STDC__
#define AVS_STDC (__STDC__ == 1)
#define AVS_KNR 0
#else
#define AVS_STDC 0
#define AVS_KNR 1
#endif /* defined(__STDC__) */
#endif /* !defined(AVS_STDC) */

#define AVS_STDC_VERSION_94 199409L
#define AVS_STDC_VERSION_99 199901L
#define AVS_STDC_VERSION_11 201112L
#define AVS_STDC_VERSION_17 201703L
#define AVS_STDC_VERSION_18 201703L
#define AVS_STDC_VERSION_23 202311L
#define AVS_STDC_VERSION_27 -1L
#if 0
TODO: C27
#endif

#ifndef AVS_STDC_VERSION
#ifdef __STDC_VERSION__
#define AVS_STDC_VERSION __STDC_VERSION__
#define AVS_STDC_89 1
#define AVS_STDC_90 1
#else /* defined(__STDC_VERSION__) */
#if AVS_STDC
#define AVS_STDC_VERSION 0
#define AVS_STDC_89 1
#define AVS_STDC_90 1
#else /* AVS_STDC */
#define AVS_STDC_VERSION 0
#define AVS_STDC_89 0
#define AVS_STDC_90 0
#endif /* AVS_STDC */
#endif /* defined(__STDC_VERSION__) */
#define AVS_STDC_94 (AVS_STDC_VERSION >= AVS_STDC_VERSION_94)
#define AVS_STDC_99 (AVS_STDC_VERSION >= AVS_STDC_VERSION_99)
#define AVS_STDC_11 (AVS_STDC_VERSION >= AVS_STDC_VERSION_11)
#define AVS_STDC_17 (AVS_STDC_VERSION >= AVS_STDC_VERSION_17)
#define AVS_STDC_18 (AVS_STDC_VERSION >= AVS_STDC_VERSION_18)
#define AVS_STDC_23 (AVS_STDC_VERSION >= AVS_STDC_VERSION_23)
#define AVS_STDC_27 (AVS_STDC_VERSION >= AVS_STDC_VERSION_27)
#endif /* !defined(AVS_STDC_VERSION) */

#ifndef AVS_STDC_HOSTED
#ifdef __STDC_HOSTED__
#define AVS_STDC_HOSTED (__STDC_HOSTED__ == 1)
#else
#define AVS_STDC_HOSTED -1
#endif /* defined(__STDC_HOSTED__) */
#endif /* !defined(AVS_STDC_HOSTED) */

#ifndef AVS_STDC_ANALYZABLE
#ifdef __STDC_ANALYZABLE__
#define AVS_STDC_ANALYZABLE (__STDC_ANALYZABLE__ == 1)
#else
#define AVS_STDC_ANALYZABLE -1
#endif /* defined(__STDC_ANALYZABLE__) */
#endif /* !defined(AVS_STDC_ANALYZABLE) */

#ifndef AVS_STDC_BOUNDS
#ifdef __STDC_LIB_EXT1__
#define AVS_STDC_BOUNDS (__STDC_LIB_EXT1__ == AVS_STDC_11)
#else
#define AVS_STDC_BOUNDS -1
#endif /* defined(__STDC_LIB_EXT1__) */
#endif /* !defined(AVS_STDC_BOUNDS) */

#ifndef AVS_STDC_ATOMICS
#ifdef __STDC_NO_ATOMICS__
#define AVS_STDC_ATOMICS (__STDC_NO_ATOMICS__ != 1)
#else
#define AVS_STDC_ATOMICS -1
#endif /* defined(__STDC_NO_ATOMICS__) */
#endif /* !defined(AVS_STDC_ATOMICS) */

#ifndef AVS_STDC_COMPLEX
#ifdef __STDC_NO_COMPLEX__
#define AVS_STDC_COMPLEX (__STDC_NO_COMPLEX__ != 1)
#else
#define AVS_STDC_COMPLEX -1
#endif /* defined(__STDC_NO_COMPLEX__) */
#endif /* !defined(AVS_STDC_COMPLEX) */

#ifndef AVS_STDC_THREADS
#ifdef __STDC_NO_THREADS__
#define AVS_STDC_THREADS (__STDC_NO_THREADS__ != 1)
#else
#define AVS_STDC_THREADS -1
#endif /* defined(__STDC_NO_THREADS__) */
#endif /* !defined(AVS_STDC_THREADS) */

#ifndef AVS_STDC_VLA
#ifdef __STDC_NO_VLA__
#define AVS_STDC_VLA (__STDC_NO_VLA__ != 1)
#else
#define AVS_STDC_THREADS -1
#endif /* defined(__STDC_NO_VLA__) */
#endif /* !defined(AVS_STDC_VLA) */

#endif /* AVS_PORTABILITY_STDC_H */
