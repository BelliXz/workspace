#include <unistd.h>
#include <stdio.h>
 
int main()
{
	char *args[3];
	int		i;
 
	args[0] = "war";
	args[1] = "-x";
	args[2] = NULL;
	i = execve("/bin/ls", args, NULL);
	printf("i = %d\n",i);
	printf("This line will not be executed.\n");
 
	return (0);
}
