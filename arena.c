#include <stdlib.h>
#include "arena.h"
#include "_avs.h"

arena_t * arena_create(size_t max) {
  arena_t * arena = calloc(1, sizeof(arena_t));
  if (!arena) {
    _avs_debug("Arena: creation failure\n");
    return NULL;
  }
  arena->max = max;
  return arena;
}

arena_t * arena_resize(arena_t * arena, size_t max) {
  if (!arena) {
    _avs_debug("Arena: null arena\n");
    return NULL;
  }
  if ((arena->head - arena->base) > max) {
    _avs_debug("Arena: tried to resize below size\n");
    return NULL;
  }
  arena->max = max;
  return arena;
}

uintptr_t arena_malloc(arena_t * arena, size_t size) {
  if (!arena) {
    _avs_debug("Arena: null arena\n");
    return (uintptr_t)NULL;
  }
  size_t cursize = arena->head - arena->base;
  size_t newsize = cursize + size + sizeof(size_t);

  if (newsize > arena->max) {
    _avs_debug("Arena: grew too large\n");
    return (uintptr_t)NULL;
  }

  uintptr_t new_base = (uintptr_t)realloc((void*)arena->base, newsize);
  if (!new_base) {
    _avs_debug("Arena: realloc failure\n");
    return (uintptr_t)NULL;
  }
  arena->base = new_base;
  arena->head = new_base + cursize + size;

  *(size_t *)(arena->head) = size;

  return arena->head - size;
}
