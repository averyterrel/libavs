#include "_avs.h"
#include "stack.h"

#include <stdlib.h>
#include <stdint.h>
#include <stdbool.h>
#include <errno.h>

avs_stack_t* avs_stack_new() {
	errno = 0;
	avs_stack_t* stack = calloc(1, sizeof(avs_stack_t));
	if (!stack) {
		avs_debug("New stack allocation failed\n");
		return NULL;
	}
	return stack;
}

#if defined(AVS_RELEASE) || defined(AVS_NO_UNUSED_VAR)
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wanalyzer-malloc-leak"
#endif
// realloc is incorrectly marked as a leak
void* avs_stack_push(avs_stack_t* stack, void* ptr) {
	errno = 0;
	void** itms = realloc(stack->itms, sizeof(void*)*(stack->sz+1));
	if (!itms) {
		avs_debug("Stack reallocation during push failed\n");
		return NULL;
	}
	stack->itms = itms;
	stack->itms[stack->sz] = ptr;
	stack->sz++;
	return ptr;
}

void* avs_stack_pop(avs_stack_t* stack) {
	errno = 0;
	if (stack->sz == 0) {
		avs_debug("Stack contains no more items\n");
		errno = EINVAL;
		return NULL;
	}
	void* itm = stack->itms[stack->sz];
	void** itms = realloc(stack->itms, sizeof(void*)*(stack->sz-1));
	if (!itms) {
		avs_debug("Stack reallocation during pop failed\n");
		return NULL;
	}
	stack->itms = itms;
	stack->sz--;
	return itm;
}
#if defined(AVS_RELEASE) || defined(AVS_NO_UNUSED_VAR)
#pragma GCC diagnostic pop
#endif

void* avs_stack_peek(avs_stack_t* stack, size_t index) {
	errno = 0;
	if (index > stack->sz) {
		avs_debug("Peek index during larger than stack size\n");
		errno = EINVAL;
		return NULL;
	}
	return stack->itms[index];
}

int avs_stack_free(avs_stack_t* stack) {
	if (!stack) {
		avs_debug("Tried to free null stack\n");
		return 0;
	}
	if (stack->itms) free(stack->itms);
	else avs_debug("Tried to free manually-freed stack items\n");
	free(stack);
	return 0;
}
