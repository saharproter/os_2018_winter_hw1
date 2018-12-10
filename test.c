#include "hw2_syscalls.h"
#include <iostream>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <errno.h>
#include <sched.h>


int main(){
	printf("policy: %d\n" , get_policy(getpid()));
	printf("is: %d\n" , is_changeable(getpid()));
	printf("make: %d\n" , make_changeable(getpid()));
	printf("policy2: %d\n" , get_policy(getpid()));
	printf("is2: %d\n" , is_changeable(getpid()));
	printf("change: %d\n" , change(1));
	printf("policy2: %d\n" , get_policy(getpid()));
	printf("change: %d\n" , change(0));
	printf("policy2: %d\n" , get_policy(getpid()));
	return 0;
}
