#include "_avs.h"
#include "stack.h"

#include <stdlib.h>
#include <stdint.h>
#include <stdbool.h>
#include <errno.h>

avs_stack_t* avs_stack_new() {
	errno = 0;
	avs_stack_t* stack = malloc(sizeof(avs_stack_t));
	if (!stack) {
		if (errno == 0) errno = ENOMEM;
		return NULL;
	}
	stack->sz = 0;
	stack->itms = NULL;
	return stack;
}

void* avs_stack_push(avs_stack_t* stack, void* ptr) {
	errno = 0;
	if (!stack) {
		errno = EINVAL;
		return NULL;
	}
	void** itms = realloc(stack->itms, sizeof(void*) * (stack->sz+1));
	if (!itms) {
		if (errno == 0) errno = ENOMEM;
		return NULL;
	}
	stack->sz++;
	stack->itms = itms;
	return ptr;
}

void* avs_stack_pop(avs_stack_t* stack) {
	errno = 0;
	if (!stack) {
		errno = EINVAL;
		return NULL;
	}
	if (stack->sz == 0) {
		errno = ERANGE;
		return NULL;
	}
	void* ptr = stack->itms[stack->sz-1];
	void** itms = realloc(stack->itms, sizeof(void*) * (stack->sz-1));
	if (!itms) {
		if (errno == 0) errno = ENOMEM;
		return NULL;
	}
	stack->sz--;
	stack->itms = itms;
	return ptr;
}

void* avs_stack_peek(avs_stack_t* stack, size_t index) {
	errno = 0;
	if (!stack) {
		errno = EINVAL;
		return NULL;
	}
	if (stack->sz < index+1) {
		errno = EINVAL;
		return NULL;
	}
	return stack->itms[index];
}

int avs_stack_free(avs_stack_t* stack) {
	errno = 0;
	if (!stack) {
		errno = EINVAL;
		return -1;
	}
	free(stack);
	return 0;
}
