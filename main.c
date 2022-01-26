#include "get_next_line.h"
#include <fcntl.h>
#include <stdio.h>

int main(void)
{
	int fd = open("/Users/fobiol-b/project/get_next_line/test.txt", O_RDONLY);
	
	printf("%s\n", get_next_line(fd));
	return (0);
}

