/* C quickstart main file */
#define _POSIX_C_SOURCE 200809L

#include <stdio.h>

#include <unistd.h>
#include <errno.h>
#include <termios.h>

#include <sys/wait.h>

int
main(int argc, char **argv)
{
	struct termios terms;

	if (argc < 2) {
		fprintf(stderr, "tioPreserve: no program specified");
		return -1;
	}

	tcgetattr(STDIN_FILENO, &terms);

	switch (fork()) {
	case -1:
		perror("tioPreserve: fork failed: ");
		return errno;
	case 0:
		execvp(argv[1], &argv[1]);
	}

	wait(NULL);

	tcsetattr(STDIN_FILENO, TCSAFLUSH, &terms);

	return 0;
}
