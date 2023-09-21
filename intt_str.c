#include <stdlib.h>
#include <stdio.h>

char *get_int(int num);
unsigned int _abs(int);
int getn_len(unsigned int num, unsigned int base);
void fin_buff(unsigned int num, unsigned int base,
		char *buff, int buff_size);
/**
 * fin_buff - custon function to fill buffer with correct numbers
 * @num: number to be converted to string
 * @base: base value of the number
 * @buff: the buffer that will be filled
 * @buff_size: the size of the buffer
 *
 * Return: returns nothing
 */
void fin_buff(unsigned int num, unsigned int base,
		char *buff, int buff_size)
{
	int rem, i = buff_size - 1;

	buff[buff_size] = '\0';
	while (i >= 0)
	{
		rem = num % base;
		if (rem > 9)
			buff[i] = rem + 87;
		else
			buff[i] = rem + '0';
		num /= base;
		i--;
	}
}
/**
 * get_int - custom function that points to a string containing int
 * @num: number to be converted to string
 *
 * Return: returns pointer to a string
 */
char *get_int(int num)
{
	unsigned int tmp;
	int len = 0;
	long numl = 0;
	char *ret;

	tmp = _abs(num);
	len = getn_len(tmp, 10);

	if (num < 0 || numl < 0)
		len++;
	ret = malloc(len + 1);
	if (!ret)
		return (NULL);
	fin_buff(tmp, 10, ret, len);
	if (num < 0 || numl < 0)
		ret[0] = '-';

	return (ret);
}
/**
 * _abs - custom function to determine absolute value of an integer
 * @i: the integer to get abs
 *
 * Return: returns an integer
 */
unsigned int _abs(int i)
{
	if (i < 0)
		return (-(unsigned int)i);
	return ((unsigned int)i);
}
/**
 * getn_len - custom function to determine length of buffer
 * @num: number needed to get length
 * @base: the base of the number represented in buffer
 *
 * Return: returns an integer
 */
int getn_len(unsigned int num, unsigned int base)
{
	int len = 1;

	while (num > base - 1)
	{
		len++;
		num /= base;
	}
	return (len);
}
