/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsalgado <bsalgado@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/29 15:53:19 by bsalgado          #+#    #+#             */
/*   Updated: 2023/07/29 15:57:13 by bsalgado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

/*

	*************************  get_buffer()  ***********************
	This function appears to read data from a file descriptor fd and 
	store it in a buffer buff. The function uses a temporary buffer 
	temp of size BUFFER_SIZE + 1 to read chunks of data from the file 
	and then appends this data to the buff buffer until it encounters 
	a newline character or reaches the end of the file.

	static char *get_buffer(char *buff, int fd)
	This is the function declaration. It defines a function named 
	get_buffer, which takes two parameters: a char* pointer buff 
	and an integer fd. The function returns a char* pointer.

	int bytes;
	This declares an integer variable named bytes, which will be 
	used to store the number of bytes read from the file during 
	each iteration of the loop.

	char *temp;
	This declares a character pointer temp, which will be used 
	as a temporary buffer to read data from the file before 
	appending it to the main buffer buff.

	temp = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	This allocates memory for the temporary buffer temp. 
	The size allocated is (BUFFER_SIZE + 1) bytes, where BUFFER_SIZE 
	appears to be a constant representing the maximum number of bytes 
	to read at a time.

	if (!temp) return (NULL);
	This checks if the memory allocation for temp was successful. 
	If the allocation failed (temp is NULL), it means there's not 
	enough memory available, and the function returns NULL to 
	indicate an error.

	bytes = 1;
	This initializes the bytes variable to 1. It is set to 1 to 
	ensure that the loop starts executing.

	while (!ft_strchr(buff, '\n') && bytes)
	This initiates a loop that will run until either a newline 
	character is found in the buff, or bytes becomes 0 
	(meaning no more data to read).

	bytes = read(fd, temp, BUFFER_SIZE);
	This reads up to BUFFER_SIZE bytes of data from the file descriptor 
	fd into the temporary buffer temp. The number of bytes actually 
	read is stored in the bytes variable.

	if (bytes == -1) { ... }
	This checks if an error occurred while reading from the file. 
	If bytes is -1, it means an error occurred, and the function cleans 
	up by freeing the memory allocated for temp and buff, and then it 
	returns NULL to indicate the error.

	temp[bytes] = '\0';
	This adds a null-terminator ('\0') at the end of the data read 
	into the temporary buffer temp, effectively converting it into a 
	null-terminated string.

	buff = ft_strjoin_mod(buff, temp);
	This calls a custom function ft_strjoin_mod (not shown in the 
	provided code) to concatenate the contents of the temp buffer to 
	the buff. The function ft_strjoin_mod likely takes care of allocating 
	memory for the new concatenated string and managing the 
	necessary memory operations.

	free(temp);
	After the loop finishes, the temporary buffer temp is no longer needed, 
	so its memory is freed to prevent memory leaks.

	return (buff);
	Finally, the function returns the pointer to the buffer buff, 
	which now contains the concatenated data read from the file.


	*************************  get_next_line()  ***********************
	This code seems to implement a function named get_next_line, which 
	is likely intended to read lines from a file descriptor fd one by one. 
	The function uses static variables buff to store the data read from 
	the file between successive calls to the function.

	char *get_next_line(int fd)
	This is the function declaration. It defines a function named get_next_line, 
	which takes an integer fd representing the file descriptor. The function 
	returns a char* pointer, which is the line read from the file.

	static char *buff;
	This declares a static character pointer named buff. A static variable 
	retains its value between function calls. It is used to store the data 
	read from the file between successive calls to get_next_line. This allows 
	the function to continue reading from where it left off.

	char *line;
	This declares a character pointer line, which will be used to store the 
	extracted line read from buff.

	if (fd < 0 || BUFFER_SIZE <= 0) return (NULL);
	This checks if the file descriptor fd is valid (not negative) and if 
	BUFFER_SIZE is greater than zero. If fd is negative or BUFFER_SIZE is 
	less than or equal to zero, it returns NULL to indicate an error.

	buff = get_buffer(buff, fd);
	This calls the get_buffer function to read data from the file descriptor 
	fd and store it in the static buffer buff. If get_buffer encounters 
	an error (returns NULL), the function also returns NULL to 
	indicate the error.

	line = ft_substr_line(buff);
	This calls a custom function ft_substr_line (not shown in the provided 
	code) to extract a line from the buff. The ft_substr_line function 
	likely searches for a newline character in buff, extracts the line 
	up to that point, and returns it as a new dynamically allocated 
	string stored in line.

	buff = ft_memmove_mod(buff);
	This calls a custom function ft_memmove_mod (not shown in the 
	provided code) to move the data after the extracted line 
	(including the newline character) to the beginning of buff. 
	This step is necessary to update buff with the remaining data 
	after reading the line.

	return (line);
	Finally, the function returns the extracted line stored in the 
	line pointer. The static buffer buff now contains the remaining 
	data after the extracted line, ready to be used in the next call 
	to get_next_line to read the next line from the file.


	*************************  main()  ***********************
	The provided code appears to test the get_next_line function by 
	opening and reading from three different text files 
	(text0.txt, text1.txt, and text2.txt). It then prints the 
	content of each file line by line using the get_next_line 
	function. Finally, it closes the file descriptors and returns 0.

	Open three text files and store their file descriptors in fd array
    fd[0]...
	Print the file descriptors for verification
    j = 3; ...
	Read and print the content of each file using get_next_line
		j = 3; ... printf("-%s", line);
	i = line[0]; // Continue reading until the first character of the 
	line is not '\0'.
	free(line); // Free the line as it's no longer needed.
	i = 0; // Set i to 0 to exit the inner loop when get_next_line 
	returns NULL.
	Close the file descriptors
  	j = 3; ... close(fd[j]);
	return (0); // Return 0 to indicate successful execution.

	Please note that the code assumes the get_next_line function is properly 
	implemented and handles reading lines from the provided file descriptors 
	correctly. The behavior of this code depends on the correctness of the 
	get_next_line function and the content of the text0.txt, text1.txt, 
	and text2.txt files.

	When executed, this code should read and print the content of each file 
	(text0.txt, text1.txt, and text2.txt) line by line. The output should 
	show the lines of each file separately, followed by the closing of file 
	descriptors. If the get_next_line function works correctly, the output 
	should match the content of the respective text files.

*/

static char	*get_buffer(char *buff, int fd)
{
	int		bytes;
	char	*temp;

	temp = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!temp)
		return (NULL);
	bytes = 1;
	while (!ft_strchr(buff, '\n') && bytes)
	{
		bytes = read(fd, temp, BUFFER_SIZE);
		if (bytes == -1)
		{
			free(temp);
			free(buff);
			return (NULL);
		}
		temp[bytes] = '\0';
		buff = ft_strjoin_mod(buff, temp);
	}
	free (temp);
	return (buff);
}

char	*get_next_line(int fd)
{
	static char	*buff;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	buff = get_buffer(buff, fd);
	if (!buff)
		return (NULL);
	line = ft_substr_line(buff);
	buff = ft_memmove_mod(buff);
	return (line);
}

/* int	main(void)
{
	char	*line;
	int		i;
	int		fd;

	fd = open("text1.txt", O_RDONLY);
	i = 1;
	printf("Fd=%d\n\n", fd);
	while (i)
	{
		line = get_next_line(fd);
		if (line)
		{
			printf("-%s", line);
			i = line[0];
			free(line);
		}
		else
			i = 0;
	}
	close(fd);
	return (0);
} */