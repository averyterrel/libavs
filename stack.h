#pragma once
#include <stdint.h>

typedef struct avs_stack_t avs_stack_t;
struct avs_stack_t {
	size_t sz;
	void** itms;
};

#ifndef AVS_STACK
#define stack_t avs_stack_t
#define stack_new avs_stack_new
#define stack_push avs_stack_push
#define stack_pop avs_stack_pop
#define stack_peek avs_stack_peek
#endif /* AVS_STACK */

#ifdef AVS_DEBUG
#define avs_stack_new avs_stack_debug_new
#define avs_stack_push avs_stack_debug_push
#define avs_stack_pop avs_stack_debug_pop
#define avs_stack_peek avs_stack_debug_peek
#endif /* AVS_DEBUG */

avs_stack_t* avs_stack_new();
int avs_stack_free(avs_stack_t* stack);
void* avs_stack_push(avs_stack_t* stack, void* ptr);
void* avs_stack_pop(avs_stack_t* stack);
void* avs_stack_peek(avs_stack_t* stack, size_t index);
