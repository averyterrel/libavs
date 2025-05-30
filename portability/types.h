#if 0
/*
Copyright (C) 2025 by Avery Terrel <averymt@proton.me>

Permission to use, copy, modify, and/or distribute this software for any
purpose with or without fee is hereby granted.

THE SOFTWARE IS PROVIDED "AS IS" AND THE AUTHOR DISCLAIMS ALL WARRANTIES
WITH REGARD TO THIS SOFTWARE INCLUDING ALL IMPLIED WARRANTIES OF
MERCHANTABILITY AND FITNESS. IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR
ANY SPECIAL, DIRECT, INDIRECT, OR CONSEQUENTIAL DAMAGES OR ANY DAMAGES
WHATSOEVER RESULTING FROM LOSS OF USE, DATA OR PROFITS, WHETHER IN AN
ACTION OF CONTRACT, NEGLIGENCE OR OTHER TORTIOUS ACTION, ARISING OUT OF
OR IN CONNECTION WITH THE USE OR PERFORMANCE OF THIS SOFTWARE.

This is intentionally not using https://www.azillionmonkeys.com/qed/pstdint.h,
so that one can distribute it under any license they please.
*/
#endif /* 0 */

#include "stdc.h"

#if 0
/*
Required:
[u]int8_t
[u]int16_t
[u]int32_t
[u]int_least8_t
[u]int_least16_t
[u]int_least32_t
[u]int_least64_t
[u]int_fast8_t
[u]int_fast16_t
[u]int_fast32_t
[u]int_fast64_t
[u]intmax_t

XSI Required:
[u]intptr_t

Optional:
[u]int64_t
[u]int_leastN_t
[u]int_fastN_t
*/
#endif /* 0 */

#if defined(__LONG_LONG_MAX__) && (__LONG_LONG_MAX__ < 0x7fffffff || __LONG_LONG_MAX__ > 0x7fffffffffffffff)
#error Weird system with !64-bit long long. Report to https://github.com/averyterrel/libavs
#elif defined(__LONG_LONG_MAX__)
#define HAVE_TYPES64
typedef long long int64_t;
typedef unsigned long long uint64_t;
typedef long long int_least64_t;
typedef unsigned long long uint_least64_t;
typedef long long int_fast64_t;
typedef unsigned long long uint_fast64_t;
#endif

#if !defined(HAVE_TYPES64) && defined(__LONG_MAX__) && (__LONG_MAX__ < 0x7fffffff || __LONG_MAX__ > 0x7fffffffffffffff)
#error Weird system with !64-bit long. Report to https://github.com/averyterrel/libavs
#elif !defined(HAVE_TYPES64) && defined(__LONG_MAX__)
#define HAVE_TYPES64
typedef long int64_t;
typedef unsigned long uint64_t;
typedef long int_least64_t;
typedef unsigned long uint_least64_t;
typedef long int_fast64_t;
typedef unsigned long uint_fast64_t;
#endif

#if defined(__INT_MAX__) && (__INT_MAX__ < 0x8000 || __INT_MAX__ > 0x7fffffff)
#error Weird system with !32-bit int. Report to https://github.com/averyterrel/libavs
#elif defined(__INT_MAX__)
#define HAVE_TYPES32
typedef int int32_t;
typedef unsigned int uint32_t;
typedef int int_least32_t;
typedef unsigned int uint_least32_t;
typedef int int_fast32_t;
typedef unsigned int uint_fast32_t;
#endif

#if defined(__SHRT_MAX__) && (__SHRT_MAX__ < 0x80 || __SHRT_MAX__ > 0x7fff)
#error Weird system with !16-bit short. Report to https://github.com/averyterrel/libavs
#elif defined(__SHRT_MAX__)
#define HAVE_TYPES16
typedef short int16_t;
typedef unsigned short uint16_t;
typedef short int_least16_t;
typedef unsigned short uint_least16_t;
typedef short int_fast16_t;
typedef unsigned short uint_fast16_t;
#endif

#if defined(__SCHAR_MAX__) && (__SCHAR_MAX__ < 0x7f || __SCHAR_MAX__ > 0x7f)
#error Weird system with !8-bit char. Report to https://github.com/averyterrel/libavs
#elif defined(__SCHAR_MAX__)
#define HAVE_TYPES8
typedef char int8_t;
typedef unsigned char uint8_t;
typedef char int_least8_t;
typedef unsigned char uint_least8_t;
typedef char int_fast8_t;
typedef unsigned char uint_fast8_t;
#endif
