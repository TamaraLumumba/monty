/*
 * File: stringtoken1.c
 * Auth; Tamara Lumumba
 */

#include <stdlib.h>

/**
 * tokenizeString - Tokenizes a given input string into individual words
 *                  using provided delimiters.
 * @input: The input string to be tokenized.
 * @delimiters: The delimiters used to separate words within the input string.
 * Return: A dynamically allocated array of pointers to extracted words.
 *         The last element of the array is set to NULL.
 *         Returns NULL in case of errors or when no words are found.
 */
char **tokenizeString(char *input, char *delimiters)
{
	char **wordArray = NULL;
	int wordCount, wordLength, n;
	int index = 0;

	if (input == NULL || !*input)
		return (NULL);
	wordCount = countWords(input, delimiters);
	if (wordCount == 0)
		return (NULL);
	wordArray = malloc((wordCount + 1) * sizeof(char *));
	if (wordArray == NULL)
		return (NULL);

	for (index = 0; index < wordCount; index++)
	{
		wordLength = getWordLength(input, delimiters);
		if (isDelimiter(*input, delimiters))
		{
			input = getNextWord(input, delimiters);
		}
		wordArray[index] = malloc((wordLength + 1) * sizeof(char));
		if (wordArray[index] == NULL)
		{
			while (index > 0)
			{
				index--;
				free(wordArray[index]);
			}
			free(wordArray);
			return (NULL);
		}
		for (n = 0; n < wordLength; n++)
		{
			wordArray[index][n] = *(input + n);
		}
		wordArray[index][n] = '\0';
		input = getNextWord(input, delimiters);
	}
	wordArray[index] = NULL;
	return (wordArray);
}

/**
 * isDelimiter - Checks if a character is a delimiter.
 * @character: The character to be checked.
 * @delimiters: The array of delimiters to compare against.
 * Return: 1 if the character is a delimiter, 0 otherwise.
 */

int isDelimiter(char character, char *delimiters)
{
	for (int i = 0; delimiters[i] != '\0'; i++)
	{
		if (delimiters[i] == character)
			return (1);
	}
	return (0);
}

/**
 * getWordLength - Calculates the length of the next word in the input string.
 * @input: The input string containing words.
 * @delimiters: The array of delimiters used to identify word boundaries.
 * Return: The length of the next word in characters.
 */

int getWordLength(char *input, char *delimiters)
{
	int length = 0, pending = 1;

    /* Iterate through the input string */
	for (int i = 0; input[i] != '\0'; i++)
	{
		if (isDelimiter(input[i], delimiters))
		{
			pending = 1;
		} else if (pending)
		{
			length++;
		}

		/* Stop counting if a delimiter is encountered after a word */
		if (length > 0 && isDelimiter(input[i], delimiters))
		{
			break;
		}
	}

	return (length);
}

/**
 * countWords - Counts the number of words in the input string.
 * @input: The input string containing words.
 * @delimiters: The array of delimiters used to identify word boundaries.
 * Return: The number of words in the input string.
 */

int countWords(char *input, char *delimiters)
{
	int count = 0, pending = 1;
	int i = 0;

    /* Iterate through the input string */
	while (input[i] != '\0')
	{
		if (isDelimiter(input[i], delimiters))
			pending = 1;
		else if (pending)
		{
			pending = 0;
			count++;
		}
		i++;
	}

	return (count);
}

/**
 * getNextWord - Returns a pointer to the start of the next
 *               word in the input string.
 * @input: The input string containing words.
 * @delimiters: The array of delimiters used to identify word boundaries.
 * Return: A pointer to the start of the next word in the input string.
 */
char *getNextWord(char *input, char *delimiters)
{
	int pending = 0;

    /* Iterate through the input string */
	for (int i = 0; input[i] != '\0'; i++)
	{
		if (isDelimiter(input[i], delimiters))
		{
			pending = 1;
		} else if (pending)
		{
			break;
		}
	}
	return (input + i);
}
