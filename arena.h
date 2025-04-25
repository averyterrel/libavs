#include <stddef.h>
#include <stdint.h>
#include <stdio.h>

#ifdef AVS_DEBUG
#define arena_create arena_create_debug
#define arena_resize arena_resize_debug
#define arena_malloc arena_malloc_debug
#define arena_realloc arena_realloc_debug
#define arena_destroy arena_destroy_debug
#endif

typedef struct {
  uintptr_t base;
  uintptr_t head;
  size_t max;
} arena_t;

arena_t * arena_create(size_t max);
arena_t * arena_resize(arena_t * arena, size_t max);
uintptr_t arena_malloc(arena_t * arena, size_t size);
uintptr_t arena_realloc(arena_t * arena, void * obj, size_t size);
void arena_destroy(arena_t * arena);
