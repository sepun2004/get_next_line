#include <stdio.h>
#include "get_next_line.h" // Asegúrate de que esta declaración coincida con la ubicación de tu archivo header
// #include "get_next_line_bonus.h" // Asegúrate de que esta declaración coincida con la ubicación de tu archivo header

int main(void) {
    // int fd;
    int fd1;
    char *line;
    int i;

    i = 0;
    line = NULL;
    // printf("%s", line);
    // fd = open("Prueba.txt", O_RDONLY);
    fd1 = open("prueba1.txt", O_RDONLY);
    if (fd1 < 0)
        return (0);
    while (i < 9)
    {
        
        // line = get_next_line(fd);
        // printf("Fichero 1 =>> line [%02d]: %s\n", i, line);
        // free(line);

        line = get_next_line(fd1);
        printf("Fichero 2 =>> line [%02d]: %s\n", i, line);
        free(line);

        i++;
    }
    // close(fd);
    close(fd1);
    return(0);
}*
