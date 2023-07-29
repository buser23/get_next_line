/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsalgado <bsalgado@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/29 15:52:04 by bsalgado          #+#    #+#             */
/*   Updated: 2023/07/29 16:02:00 by bsalgado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

/*

	*************************  ft_strchr()  ***********************
	The provided code defines a function named ft_strchr, which 
	behaves similarly to the standard library function strchr. 
	It searches for the first occurrence of a specific character 
	c in the string s and returns a pointer to the first occurrence 
	of c in s. If c is not found, it returns NULL.

	char *ft_strchr(const char *s, int c)
	This is the function declaration. It defines a function 
	named ft_strchr, which takes two parameters: a pointer 
	to a constant character s and an integer c. The function 
	returns a pointer to a character (char*).

	char *a;
	This declares a character pointer a, which will be 
	used to traverse the string s.

	if (!s) return (0);
	This checks if the pointer s is NULL. If it is, it 
	means an invalid input, so the function returns 0 (NULL) 
	to indicate an error.

	a = (char *)s;
	This sets the character pointer a to point to the 
	same memory address as the input s, effectively 
	converting the input pointer from const char* to 
	char*. This allows the function to return a 
	non-constant pointer, which is a common practice 
	in C when using the strchr function.

	The function then enters a while loop that iterates 
	through the characters of the string pointed to by a.

	if (*a == (char) c) return (a);
	This checks if the current character *a matches 
	the character c. If there's a match, the function 
	returns the pointer a, pointing to the first 
	occurrence of c in the string.

	a++;
	This increments the pointer a to move to the 
	next character in the string.

	The loop continues until it reaches the end of 
	the string, which is denoted by the null-terminator 
	('\0'). If the character c is not found in the 
	string, the loop will terminate naturally when 
	*a becomes the null-terminator.

	After the loop, the code checks again if the 
	character c is found at the end of the string: 
	if (*a == (char) c) return (a);. This is done to 
	handle the case when c is the null-terminator 
	itself. In this case, the function should return 
	a pointer to the null-terminator.

	If the function reaches this point without finding 
	c in the string, it returns NULL to indicate 
	that c is not present in the string.

	The function ft_strchr is a simple implementation 
	of the strchr function and is useful for searching 
	for characters within a given string. It is Worth 
	noting that the standard library function strchr 
	provides the same functionality and is usually 
	preferred over custom implementations like this one.


	***********************  ft_strclen()  ********************
	The provided code defines a function named ft_strclen, 
	which calculates the length of a substring in a given 
	string s until the character c is encountered. The 
	function returns the size (length) of the substring.

	size_t ft_strclen(const char *s, char c)
	This is the function declaration. It defines 
	a function named ft_strclen, which takes two parameters: 
	a pointer to a constant character s (the input string) 
	and a char c (the target character). The function 
	returns a size_t value, which represents the length 
	of the substring until the character c is encountered.

	size_t i;
	This declares a size_t variable i, which will be 
	used to count the length of the substring.

	if (!s) return (0);
	This checks if the pointer s is NULL. If it is, 
	it means an invalid input, so the function 
	returns 0 to indicate an error.

	i = 0;
	This initializes the i variable to 0, which 
	will serve as the index to traverse the input string s.

	The function then enters a while loop that 
	iterates through the characters of the string s.

	while (s[i] && s[i] != c)
	This loop continues as long as s[i] is not 
	the null-terminator ('\0') and not equal to 
	the target character c. This means the loop 
	will stop either when the null-terminator is 
	reached (end of string) or when the target 
	character c is found.

	i++;
	This increments the index i to move to 
	the next character in the string.

	The loop continues until either the 
	null-terminator or the target character c 
	is encountered.

	Once the loop finishes, the value of i will 
	represent the length of the substring in the 
	input string s until the character c is encountered.

	The function returns i, which is the length 
	of the substring.

	The ft_strclen function is useful for 
	determining the length of a substring until a 
	specific character is found in a given string. 
	It is a simple and efficient function for 
	this purpose. Note that this function does 
	not include the character c in the length 
	count; it stops counting when c is encountered. 
	If c is not found in the string, the function 
	will return the length of the entire string 
	(until the null-terminator).


	*******************  ft_memmove_mod()  *****************
	The provided code defines a function named 
	ft_memmove_mod, which moves data within the buff 
	buffer to modify its contents. It is likely intended 
	to remove the first line from the buffer (up to the 
	first occurrence of the newline character '\n') and 
	update the buffer accordingly.

	char *ft_memmove_mod(char *buff)
	This is the function declaration. It defines a 
	function named ft_memmove_mod, which takes a pointer 
	to a character buff (the input buffer). The 
	function returns a char* pointer.

	size_t line_len; size_t buff_len; size_t i;
	These lines declare three size_t variables: 
	line_len to store the length of the first line, 
	buff_len to store the total length of the buffer, 
	and i for iterating through the buffer.

	line_len = ft_strclen(buff, '\n');
	This line calls the ft_strclen function 
	(provided earlier) to calculate the length of 
	the first line in the buffer buff up to the 
	first occurrence of the newline character '\n'. 
	The result is stored in line_len.

	if (!buff[line_len]): This condition checks if 
	the character immediately after the first line 
	is the null-terminator '\0', which would 
	indicate that the first line is the last line 
	in the buffer (no more lines after it). If this 
	condition is true, it means there's no more data 
	in the buffer after the first line.

	If there's no more data in the buffer after the 
	first line, the function frees the memory allocated 
	for buff and returns NULL, indicating an error.

	buff_len = ft_strclen(buff, '\0');
	This line calls the ft_strclen function to 
	calculate the total length of the buffer buff 
	until the null-terminator '\0' is encountered. 
	The result is stored in buff_len.

	i = -1; while (++i < buff_len - line_len) buff[i] = 
	buff[line_len + 1 + i];
	This loop moves the data after the first line 
	to the beginning of the buffer, effectively 
	removing the first line from the buffer.

	The loop starts with i set to -1 and increments 
	i until it reaches buff_len - line_len - 1.
	Inside the loop, it copies the character at index 
	line_len + 1 + i to index i in the buffer. 
	This effectively shifts the data in the buffer to 
	remove the first line.
	buff[i] = '\0';
	After the loop, a null-terminator '\0' is placed 
	at index i in the buffer to properly terminate 
	the modified buffer as it might have shrunk.

	The function returns the modified buffer buff, 
	which now contains the remaining data after 
	removing the first line.

	Overall, the ft_memmove_mod function efficiently 
	removes the first line from the buffer and 
	updates the buffer in place. Note that this 
	function assumes that buff is a dynamically 
	allocated buffer, as it frees the memory if 
	there's no more data in the buffer after 
	removing the first line. If buff is not dynamically 
	allocated, using the free function on it can lead 
	to undefined behavior. Therefore, users of this 
	function should ensure that buff is indeed a 
	dynamically allocated buffer. Additionally, users 
	are responsible for handling the returned modified 
	buffer appropriately and freeing its memory when 
	it is no longer needed to avoid memory leaks.


	*****************  ft_substr_line()  ****************
	The provided code defines a function named 
	ft_substr_line, which extracts the first line from 
	the input buffer buff and creates a new substring 
	containing that line. The function allocates memory 
	for the new substring and returns a pointer to it.

	char *ft_substr_line(char *buff)
	This is the function declaration. It defines a 
	function named ft_substr_line, which takes a pointer 
	to a character buff (the input buffer). The function 
	returns a char* pointer.

	char *line; size_t line_len; size_t i;
	These lines declare three variables: line as a 
	character pointer to store the newly created substring, 
	line_len to store the length of the first line in buff, 
	and i for iterating through the buffer.

	if (!buff[0]) return (NULL);
	This condition checks if the first character of 
	the buffer is the null-terminator '\0', indicating 
	that the buffer is empty (no data). If the 
	buffer is empty, the function returns NULL, 
	indicating an error.

	line_len = ft_strclen(buff, '\n');
	This line calls the ft_strclen function 
	(provided earlier) to calculate the length 
	of the first line in the buffer buff up to the 
	first occurrence of the newline character '\n'. 
	The result is stored in line_len.

	line = (char *)malloc(sizeof(char) * (line_len + 2));
	This line dynamically allocates memory for the 
	line buffer. It allocates line_len + 2 bytes 
	to accommodate the characters of the first 
	line and a null-terminator '\0' at the end. 
	The +2 is for the newline character '\n' 
	(if present) and the null-terminator.

	if (!line) return (NULL);
	This condition checks if the memory allocation 
	for line was successful. If the allocation 
	fails (line is NULL), it means there's not 
	enough memory available, and the function 
	returns NULL to indicate an error.

	i = -1; while (++i <= line_len) line[i] = buff[i];
	This loop copies the characters of the first 
	line from the buffer buff to the newly 
	allocated line buffer.

	The loop starts with i set to -1 and 
	increments i until it reaches line_len.
	Inside the loop, it copies the character 
	at index i from buff to index i in line.
	After copying buff into line, the null-terminator 
	'\0' is placed at index i in the line buffer to 
	properly terminate the substring:

	The function returns the newly created line, 
	which contains the first line from the buffer.

	The ft_substr_line function efficiently extracts 
	the first line from the buffer and allocates 
	memory for the substring containing the line. 
	It is important to note that this function 
	assumes the input buffer buff contains valid 
	data and is properly terminated with a 
	null-terminator ('\0'). Also, the returned 
	substring must be freed by the caller once it 
	is no longer needed to avoid memory leaks.


	*****************  ft_strjoin_mod()  *******************
	The provided code defines a function named ft_strjoin_mod, 
	which concatenates two strings s1 and s2, modifies 
	the memory allocation to create a new concatenated 
	string c, and then frees the memory allocated for 
	the input string s1. The function returns a pointer 
	to the newly created concatenated string c.

	char *ft_strjoin_mod(char *s1, char *s2)
	This is the function declaration. It defines a 
	function named ft_strjoin_mod, which takes two 
	parameters: pointers to characters s1 and s2 
	(the input strings). The function returns a 
	pointer to a character (char*).

	char *c; size_t len; int i; int j;
	These lines declare variables for the new 
	concatenated string c, the length of the 
	concatenated string len, and two iterators 
	i and j for copying characters.

	len = ft_strclen(s1, '\0') + ft_strclen(s2, '\0');
	This line calculates the total length of the 
	concatenated string. It sums up the lengths of 
	both s1 and s2, including the null-terminators 
	in each string.

	c = (char *)malloc(len * sizeof(char) + 1);
	This line dynamically allocates memory for 
	the concatenated string c. It allocates 
	(len * sizeof(char) + 1) bytes, where +1 
	is for the null-terminator '\0' at the end.

	if (!c) return (NULL);
	This condition checks if the memory allocation 
	for c was successful. If the allocation fails 
	(c is NULL), it means there's not enough memory 
	available, and the function returns NULL to 
	indicate an error.

	The function then copies the contents of s1 
	into the concatenated string c:

	The loop continues as long as s1[i] is not the 
	null-terminator ('\0') and s1 is not NULL 
	(to avoid dereferencing a NULL pointer). 
	It copies characters one by one from s1 to c.
	After copying s1 into c, the function proceeds 
	to copy the contents of s2 into c:

	The loop starts with j set to -1, and the loop 
	increments j and copies the characters of s2 
	into c starting from index i + j.
	Finally, the null-terminator '\0' is placed 
	at the end of the concatenated string c 
	to properly terminate it:

	The function then frees the memory allocated 
	for the input string s1, as it is no longer 
	needed:

	The function returns the newly created 
	concatenated string c, which contains 
	the contents of both s1 and s2.

	The ft_strjoin_mod function efficiently 
	concatenates two strings and manages memory 
	allocation and deallocation properly. 
	However, it assumes that s1 is a dynamically 
	allocated string (allocated using malloc or 
	similar) since it frees the memory within the 
	function. If s1 is not dynamically allocated, 
	using the free function on it can lead to 
	undefined behavior. Therefore, users of this 
	function should ensure that s1 is indeed a 
	dynamically allocated string. Additionally, 
	users are responsible for freeing the memory 
	of the returned concatenated string c once it 
	is no longer needed to avoid memory leaks.

*/

char	*ft_strchr(const char *s, int c)
{
	char	*a;

	if (!s)
		return (0);
	a = (char *)s;
	while (*a)
	{
		if (*a == (char) c)
			return (a);
		a++;
	}
	if (*a == (char) c)
		return (a);
	return (NULL);
}

size_t	ft_strclen(const char *s, char c)
{
	size_t	i;

	if (!s)
		return (0);
	i = 0;
	while (s[i] && s[i] != c)
		i++;
	return (i);
}

char	*ft_memmove_mod(char *buff)
{
	size_t	line_len;
	size_t	buff_len;
	size_t	i;

	line_len = ft_strclen(buff, '\n');
	if (!buff[line_len])
	{
		free (buff);
		return (NULL);
	}
	buff_len = ft_strclen(buff, '\0');
	i = -1;
	while (++i < buff_len - line_len)
		buff[i] = buff[line_len + 1 + i];
	buff[i] = '\0';
	return (buff);
}

char	*ft_substr_line(char *buff)
{
	char	*line;
	size_t	line_len;
	size_t	i;

	if (!buff[0])
		return (NULL);
	line_len = ft_strclen(buff, '\n');
	line = (char *)malloc(sizeof(char) * (line_len + 2));
	if (!line)
		return (NULL);
	i = -1;
	while (++i <= line_len)
		line[i] = buff[i];
	line[i] = '\0';
	return (line);
}

char	*ft_strjoin_mod(char *s1, char *s2)
{
	char	*c;
	size_t	len;
	int		i;
	int		j;

	len = ft_strclen(s1, '\0') + ft_strclen(s2, '\0');
	c = (char *) malloc(len * sizeof(char) + 1);
	if (!c)
		return (NULL);
	i = 0;
	while (s1 && s1[i])
	{
		c[i] = s1[i];
		i++;
	}
	j = -1;
	while (s2[++j])
		c[i + j] = s2[j];
	c[i + j] = '\0';
	free (s1);
	return (c);
}
