#include <stdlib.h>
char **strtow(char *str, char *delims);
int isdelim(char ch, char *delims);
int get_wl(char *str, char *delims);
int get_wc(char *str, char *delims);
char *get_nw(char *str, char *delims);
/**
 * strtow - function that splits a string into words
 * @str: the string to split
 * @delims: delimitors
 *
 * Return: returns a 2d array
 */
char **strtow(char *str, char *delims)
{
	char **words = NULL;
	int wc, wordlen, n, i = 0;

	if (str == NULL || !*str)
		return (NULL);
	wc = get_wc(str, delims);

	if (wc == 0)
		return (NULL);
	words = malloc((wc + 1) * sizeof(char *));

	if (words == NULL)
		return (NULL);
	while (i < wc)
	{
		wordlen = get_wl(str, delims);
		if (isdelim(*str, delims))
		{
			str = get_nw(str, delims);
		}
		words[i] = malloc((wordlen + 1) * sizeof(char));
		if (words[i] == NULL)
		{
			while (i >= 0)
			{
				i--;
				free(words[i]);
			}
			free(words);
			return (NULL);
		}
		n = 0;
		while (n < wordlen)
		{
			words[i][n] = *(str + n);
			n++;
		}
		words[i][n] = '\0'; /*sets eostr*/
		str = get_nw(str, delims);
		i++;
	}
	words[i] = NULL;
	return (words);
}
/**
 * isdelim - function to check if str has delims
 * @ch: character in str
 * @delims: pointer to the delims array
 * Return: returns 0 or 1
 */
int isdelim(char ch, char *delims)
{
	int i = 0;

	while (delims[i])
	{
		if (delims[i] == ch)
			return (1);
		i++;
	}
	return (0);
}
/**
 * get_wl - function to determine length of word
 * @str: the string
 * @delims: delimeters
 *
 * Return: returns word length
 */
int get_wl(char *str, char *delims)
{
	int wlen = 0, pending = 1, i = 0;

	while (*(str + i))
	{
		if (isdelim(str[i], delims))
			pending = 1;
		else if (pending)
		{
			wlen++;
		}
		if (wlen > 0 && isdelim(str[i], delims))
			break;
		i++;
	}
	return (wlen);
}
/**
 * get_wc - function to get word count in str
 * @str: the string
 * @delims: delimitors
 *
 * Return: returns the word count
 */
int get_wc(char *str, char *delims)
{
	int wc = 0, pending = 1, i = 0;

	while (*(str + i))
	{
		if (isdelim(str[i], delims))
			pending = 1;
		else if (pending)
		{
			pending = 0;
			wc++;
		}
		i++;
	}
	return (wc);
}
/**
 * get_nw - function that gets next word in string
 *
 * @str: the string
 * @delims: delimitors
 *
 * Return: returns the next word
 */
char *get_nw(char *str, char *delims)
{
	int pending = 0;
	int i = 0;

	while (*(str + i))
	{
		if (isdelim(str[i], delims))
			pending = 1;
		else if (pending)
			break;
		i++;
	}
	return (str + i);
}
