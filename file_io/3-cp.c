#include "main.h"
#include <stdio.h>
#include <stdlib.h>

#define BUFFER_SIZE 1024

/**
 * error_exit - prints an error message to STDERR and exits with code
 * @code: exit code
 * @format: error message format
 * @arg: argument (file name or fd)
 */
void error_exit(int code, const char *format, const char *arg)
{
	dprintf(STDERR_FILENO, format, arg);
	exit(code);
}

/**
 * main - copies the content of a file to another file
 * @argc: argument count
 * @argv: argument vector
 * Return: 0 on success
 */
int main(int argc, char *argv[])
{
	int fd_from, fd_to;
	ssize_t rd_bytes, wr_bytes;
	char buffer[BUFFER_SIZE];

	if (argc != 3)
	{
		dprintf(STDERR_FILENO, "Usage: cp file_from file_to\n");
		exit(97);
	}

	fd_from = open(argv[1], O_RDONLY);
	if (fd_from == -1)
		error_exit(98, "Error: Can't read from file %s\n", argv[1]);

	fd_to = open(argv[2], O_WRONLY | O_CREAT | O_TRUNC, 0664);
	if (fd_to == -1)
	{
		close(fd_from);
		error_exit(99, "Error: Can't write to %s\n", argv[2]);
	}

	while ((rd_bytes = read(fd_from, buffer, BUFFER_SIZE)) > 0)
	{
		wr_bytes = write(fd_to, buffer, rd_bytes);
		if (wr_bytes == -1 || wr_bytes != rd_bytes)
		{
			close(fd_from);
			close(fd_to);
			error_exit(99, "Error: Can't write to %s\n", argv[2]);
		}
	}

	if (rd_bytes == -1)
	{
		close(fd_from);
		close(fd_to);
		error_exit(98, "Error: Can't read from file %s\n", argv[1]);
	}

	if (close(fd_from) == -1)
		error_exit(100, "Error: Can't close fd %d\n", argv[1]);

	if (close(fd_to) == -1)
		error_exit(100, "Error: Can't close fd %d\n", argv[2]);

	return (0);
}
