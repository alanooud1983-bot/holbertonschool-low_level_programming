#include "main.h"
#include <stdio.h>

/**
 * error_exit - Prints an error message and exits with a given code.
 * @code: Exit code.
 * @message: Error message format.
 * @arg: Argument to print in message.
 */
void error_exit(int code, const char *message, const char *arg)
{
	dprintf(STDERR_FILENO, message, arg);
	exit(code);
}

/**
 * main - Copies the content of one file to another.
 * @argc: Argument count.
 * @argv: Argument vector.
 *
 * Return: 0 on success.
 */
int main(int argc, char *argv[])
{
	int fd_from, fd_to, rd_bytes, wr_bytes;
	char buffer[1024];

	if (argc != 3)
		error_exit(97, "Usage: cp file_from file_to\n", "");

	fd_from = open(argv[1], O_RDONLY);
	if (fd_from == -1)
		error_exit(98, "Error: Can't read from file %s\n", argv[1]);

	fd_to = open(argv[2], O_CREAT | O_WRONLY | O_TRUNC, 0664);
	if (fd_to == -1)
		error_exit(99, "Error: Can't write to %s\n", argv[2]);

	while ((rd_bytes = read(fd_from, buffer, 1024)) > 0)
	{
		wr_bytes = write(fd_to, buffer, rd_bytes);
		if (wr_bytes != rd_bytes)
			error_exit(99, "Error: Can't write to %s\n", argv[2]);
	}

	if (rd_bytes == -1)
		error_exit(98, "Error: Can't read from file %s\n", argv[1]);

	if (close(fd_from) == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't close fd %d\n", fd_from);
		exit(100);
	}

	if (close(fd_to) == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't close fd %d\n", fd_to);
		exit(100);
	}

	return (0);
}
