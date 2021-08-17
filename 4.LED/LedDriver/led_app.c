/******************firstdrvtest.c*************/
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>
 
/* firstdrvtest on
  * firstdrvtest off
  */
int main(int argc, char **argv)
{
	int fd;
	int val = 33;
	fd = open("/dev/xyz", O_RDWR);//可通过ls /dev/xyz命令查看
	if (fd < 0)
	{
		printf("can't open!\n");
	}
	if (argc != 2)
	{
		printf("Usage :\n");
		printf("%s <on|off>\n", argv[0]);
		return 0;
	}
 
	if (strcmp(argv[1], "on1") == 0)
	{
		val  = 1;
	}
	if (strcmp(argv[1], "on2") == 0)
	{
		val  = 2;
	}	
        if (strcmp(argv[1], "on3") == 0)
	{
		val  = 3;
	}	
        if (strcmp(argv[1], "on4") == 0)
	{
		val  = 4;
	}
        if (strcmp(argv[1], "on5") == 0)
	{
		val  = 5;
	}	
	write(fd, &val, 4);
	return 0;
}
