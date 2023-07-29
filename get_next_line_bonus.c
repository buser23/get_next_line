/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsalgado <bsalgado@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/29 15:50:52 by bsalgado          #+#    #+#             */
/*   Updated: 2023/07/29 16:17:02 by bsalgado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

/*

	*************************  get_buffer()  ***********************
		This code defines the get_buffer function, which reads data from 
		a file descriptor fd and stores it in a buffer buff. It uses a 
		temporary buffer temp to read chunks of data from the file and 
		then appends this data to the buff buffer until it encounters a 
		newline character or reaches the end of the file.

		static char *get_buffer(char *buff, int fd): 
		This is the function declaration. It defines a static function 
		named get_buffer, which takes two parameters: a char* buffer buff 
		and an integer fd representing the file descriptor. The function 
		returns a char* pointer.

		temp = malloc(sizeof(char) * (BUFFER_SIZE + 1));
		This allocates memory for the temporary buffer temp. The size 
		allocated is (BUFFER_SIZE + 1) bytes, where BUFFER_SIZE appears 
		to be a constant representing the maximum number of bytes to 
		read at a time.

		if (!temp) return (NULL);
		This checks if the memory allocation for temp was successful. 
		If the allocation failed (temp is NULL), it means there's not 
		enough memory available, and the function returns NULL to indicate 
		an error.

		bytes = 1;
		This initializes the bytes variable to 1. It is set to 1 to 
		ensure that the loop starts executing.

		while (!ft_strchr(buff, '\n') && bytes) { ... }
		This initiates a loop that continues as long as there is data 
		to read (bytes is non-zero) and the newline character '\n' is 
		not found in the buff.

		bytes = read(fd, temp, BUFFER_SIZE);
		This reads up to BUFFER_SIZE bytes of data from the file descriptor 
		fd into the temporary buffer temp. The number of bytes actually 
		read is stored in the bytes variable.

		if (bytes == -1) { ... }
		This checks if an error occurred while reading from the file. If 
		bytes is -1, it means an error occurred, and the function cleans 
		up by freeing the memory allocated for temp and buff, and then 
		it returns NULL to indicate the error.

		temp[bytes] = '\0';
		This adds a null-terminator ('\0') at the end of the data read 
		into the temporary buffer temp, effectively converting it into 
		a null-terminated string.

		buff = ft_strjoin_mod(buff, temp);
		This calls a custom function ft_strjoin_mod (not shown in the 
		provided code) to concatenate the contents of the temp buffer 
		to the buff. The function ft_strjoin_mod likely takes care of 
		allocating memory for the new concatenated string and managing 
		the necessary memory operations.

		The loop continues until a newline character is found in the buff,
		or the end of the file is reached. The function continuously reads 
		data from the file and appends it to the buff until it reaches the 
		end of the line.

		free(temp);
		After the loop finishes, the temporary buffer temp is 
		no longer needed,so its memory is freed to prevent memory leaks.

		return (buff);
		Finally, the function returns the pointer to the buffer buff, which 
		now contains the concatenated data read from the file.

		This get_buffer function is designed to be called by the 
		get_next_line function to read data from a file descriptor and 
		handle concatenation of multiple read chunks into a single buffer. 
		The usage and correctness of this function depend on the proper 
		implementation of the ft_strjoin_mod function (not provided) 
		and the get_next_line function.


		*************************  get_next_line()  ****************
		This code defines the get_next_line function, which 
		reads lines from a file descriptor fd. It uses a 
		static array of character pointers buff 
		to store the data read from each file descriptor 
		separately between successive calls to the function.

		char *get_next_line(int fd)
		This is the function declaration. It defines 
		a functionnamed get_next_line, which takes an integer 
		fd representing the file descriptor. The function 
		returns a char* pointer, which is the 
		line read from the file.

		"static char *buff[MAX_FILES]"
		This declares a static array of character pointers named 
		buff. MAX_FILES appears to be a constant representing 
		the maximum number of file descriptors the program can handle. 
		Each element of this array, buff[fd], will store the data read 
		from the corresponding file descriptor fd.

		char *line;
		This declares a character pointer line, 
		which will be used to store the extracted 
		line read from buff.

		The following if statement checks for potential errors:
			fd < 0
			If fd is negative, it indicates an invalid file 
			descriptor, so the function returns NULL.
			fd > MAX_FILES
			If fd exceeds the maximum allowed value (MAX_FILES), 
			it means the program cannot handle that many file 
			descriptors, so it returns NULL.
			BUFFER_SIZE <= 0
			If BUFFER_SIZE is less than or equal to zero, it means 
			the buffer size for reading is invalid, so the function 
			returns NULL.

		buff[fd] = get_buffer(buff[fd], fd);
		This calls the get_buffer function to read data from 
		the file descriptor fd and store it in the static buffer 
		buff[fd]. The buff[fd] argument is used to ensure each file 
		descriptor's data is stored separately in the array. 
		If get_buffer encounters an error (returns NULL), the 
		function also returns NULL to indicate the error.

		if (!buff[fd]) return (NULL);
		This checks if the memory allocation and reading in 
		get_buffer were successful. If the buffer buff[fd] is 
		NULL, it means there was an error, and the function 
		returns NULL to indicate the error.

		line = ft_substr_line(buff[fd]);
		This calls a custom function ft_substr_line (not shown 
		in the provided code) to extract a line from the buff[fd]. 
		The ft_substr_line function likely searches for a newline 
		character in buff[fd], extracts the line up to that point, 
		and returns it as a new dynamically allocated string 
		stored in line.

		buff[fd] = ft_memmove_mod(buff[fd]);
		This calls a custom function ft_memmove_mod (not shown 
		in the provided code) to move the data after the extracted 
		line (including the newline character) to the beginning 
		of buff[fd]. This step is necessary to update buff[fd] with 
		the remaining data after reading the line.

		The function returns the extracted line stored in 
		the line pointer. The static buffer buff[fd] now contains 
		the remaining data after the extracted line, ready to be 
		used in the next call to get_next_line to read the next 
		line from the file.

		The usage of a static array to store the buffers for 
		different file descriptors allows the function to handle 
		multiple files simultaneously without mixing their contents. 
		However, it's important to note that using a static variable 
		can lead to issues in multi-threaded environments due to 
		potential data race problems. Additionally, the 
		behavior of this code depends on the correct implementation 
		of the ft_substr_line and ft_memmove_mod functions (not provided) 
		and the validity of the get_buffer function.
		
		
		*************************  main()  **************************
		The provided main function is a test code for reading and 
		printing lines from three text files (text0.txt, text1.txt, 
		and text2.txt) using the get_next_line function. It first 
		opens the files, then reads and prints their contents line by 
		line, and finally, it closes the file descriptors.

		char *line; int i; int j; int fd[3];
		These lines declare variables line, i, j, and an array 
		of integers 
		fd to store the file descriptors.

		fd[0] = open("text0.txt", O_RDONLY); 
		fd[1] = open("text1.txt", O_RDONLY); 
		fd[2] = open("text2.txt", O_RDONLY);
		These lines open three text files in read-only mode 
		and store their file descriptors in the fd array. text0.txt, 
		text1.txt, and text2.txt are the filenames. The file descriptors 
		will be used later to read from the 
		corresponding files.

		The first while loop is used to print the file descriptors 
		for verification
		The second while loop is used to read and print the content 
		of each file using the get_next_line function:
		i = line[0]; // Continue reading until the first 
		character of the line is not '\0'.
		free(line); // Free the line as it's no longer needed.
		i = 0; // Set i to 0 to exit the inner loop when 
		get_next_line returns NULL.
		
		The outer loop runs for each file descriptor stored 
		in the fd array.
		The inner loop reads lines from the file descriptor 
		using the get_next_line 
		function until it returns NULL (end of file or error).
		Inside the inner loop, each line is printed, and the 
		loop continues until there are no more lines to read 
		(get_next_line returns NULL).After reading and printing 
		the content of each file, the code closes the file 
		descriptors:

		The main function returns 0 to indicate 
		successful execution.

		When executed, this code should read and print the 
		content of each file (text0.txt, text1.txt, and text2.txt) 
		line by line. The output should 
		show the lines of each file separately, followed 
		by the closing of file descriptors. If the get_next_line 
		function works correctly, the output should match the 
		content of the respective text files.

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
	static char	*buff[MAX_FILES];
	char		*line;

	if (fd < 0 || fd > MAX_FILES || BUFFER_SIZE <= 0)
		return (NULL);
	buff[fd] = get_buffer(buff[fd], fd);
	if (!buff[fd])
		return (NULL);
	line = ft_substr_line(buff[fd]);
	buff[fd] = ft_memmove_mod(buff[fd]);
	return (line);
}

/* int	main(void)
{
	char	*line;
	int		i;
	int		j;
	int		fd[3];

	fd[0] = open("text0.txt", O_RDONLY);
	fd[1] = open("text1.txt", O_RDONLY);
	fd[2] = open("text2.txt", O_RDONLY);
	j = 3;
		while (--j >= 0)
	{
		printf("Fd=%d\n\n", fd[j]);
	}
	j = 3;
	while (--j >= 0)
	{
		printf("\nFd=%d\n", fd[j]);
		i = 1;
		while (i)
			{
				line = get_next_line(fd[j]);
				if (line)
				{
					printf("-%s", line);
					i = line[0];
					free(line);
				}
				else
					i = 0;
			}
		printf("\n");
	}
	j = 3;
	while (--j >= 0)
	{
		close(fd[j]);
	}
	return (0);
} */