#include "get_next_line.h"


int     main(int argc, char **argv)
{
    int fd;
    int i;
    char *line; 

    i = atoi(argv[2]);
    fd = open(argv[1],O_RDONLY);
    while (i--)
    {
        line = get_next_line(fd); 
        printf("%s", line);
        free(line);
    }



    // while ((line = get_next_line(fd)) != NULL) 
    // {
    //     printf("line es : %s\n", line);
    //     free(line);
    // }
    close(fd);
    // return NULL;
}
