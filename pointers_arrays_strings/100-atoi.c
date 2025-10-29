#include "main.h"

/**
 * _atoi - converts a string to an integer
 * @s: string to convert
 * Return: integer value
 */
int _atoi(char *s)
{
    unsigned int num = 0;
    int sign = 1;
    int i = 0;

    while (s[i] && (s[i] < '0' || s[i] > '9'))
    {
        if (s[i] == '-')
            sign *= -1;
        i++;
    }

    while (s[i] >= '0' && s[i] <= '9')
    {
        if (num > (unsigned int)(2147483647 / 10))
            return (sign == 1 ? 2147483647 : -2147483648);

        num = num * 10 + (s[i] - '0');
        i++;
    }

    if (sign == -1 && num > 2147483648)
        return (-2147483648);

    return (sign * num);
}
