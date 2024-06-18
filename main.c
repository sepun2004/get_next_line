#include <stdio.h>
#include "get_next_line.h" // Asegúrate de que esta declaración coincida con la ubicación de tu archivo header

int main(void) {
    int fd;
    char *line;
    int i;

    i = 0;
    fd = open ("Prueba.txt", O_RDONLY);
    if(fd == -1)
    {
        printf("Error");
        return 0;
    }
    
    while(line = get_next_line(fd))
    {
        printf("line es: %s", line);
        i++;
        free(line);
    }
    close(fd);
}
