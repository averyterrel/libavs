#include "test.h"
#include "../stack.h"

int main(void) {
	int ret = 0;
	stack_t stack = stack_new();
	int y = 3;
	void* z = &y;
	stack_push(&stack, z);
	PASS(*(int*)stack_peek(&stack, 0) == 3);
	PASS(*(int*)stack_pop(&stack) == 3);
	return ret;
}
