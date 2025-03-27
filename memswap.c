#include "memswap.h"
#include <stdint.h>

void memswap(void* a, size_t sza, void* b, size_t szb) {
  if (sza > szb) {
    void* temp = a;
    a = b;
    b = temp;

    size_t ts = sza;
    sza = szb;
    szb = ts;
  }

  unsigned char* ca = (unsigned char*)a;
  unsigned char* cb = (unsigned char*)b;

  for (size_t i = 0; i < sza; i++) {
    unsigned char temp = ca[i];
    ca[i] = cb[i];
    cb[i] = temp;
  }

  for (size_t i = sza; i < szb; i++) {
    unsigned char temp = ca[i];
    ca[i] = cb[i];
    cb[i] = temp;
  }
}
