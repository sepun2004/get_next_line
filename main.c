#include "get_next_line.h"

    // #include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdlib.h>
#include <stdio.h>

int     main(void)
{
    int fd;
    char *line; 

    fd = open("prueba.txt",O_RDONLY);
    if(fd == -1)
        printf("ERROR OPEN");
    while ((line = get_next_line(fd)) != NULL) 
    {
        printf("%s\n", line);
        free(line);
    }
    close(fd);
    // return NULL;
    
}
