#include "main.h"

/**
 * _atoi - converts a string to an integer
 * @s: string to convert
 *
 * Return: the integer value, or 0 if none found
 */
int _atoi(char *s)
{
	int i = 0, sign = 1;
	unsigned int num = 0;

	while (s[i] && (s[i] < '0' || s[i] > '9'))
	{
		if (s[i] == '-')
			sign *= -1;
		i++;
	}

	while (s[i] >= '0' && s[i] <= '9')
	{
		if (num > 214748364)
		{
			if (sign == 1)
				return (2147483647);
			else
				return (-2147483648);
		}
		num = (num * 10) + (s[i] - '0');
		i++;
	}

	if (sign == -1 && num > 2147483648)
		return (-2147483648);

	return (num * sign);
}
