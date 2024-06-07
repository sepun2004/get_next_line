#include "get_next_line.h"


int     main(void)
{
    int fd;
    char *line; 

    fd = open("prueba.txt",O_RDONLY);
    line = get_next_line(fd); 
     printf("line es : %s\n", line);
     free(line);
    // while ((line = get_next_line(fd)) != NULL) 
    // {
    //     printf("line es : %s\n", line);
    //     free(line);
    // }
    close(fd);
    // return NULL;
}
