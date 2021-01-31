#include <sys/syscall.h>
#include <unistd.h>

const char message[] =
	"hello world";

int main() {
	// write(1, message, sizeof(message) - 1);
	syscall(SYS_write, STDOUT_FILENO, "hello world", 12);

	//_exit(0);
	//syscall(SYS_exit, 0);
	return 0;
}