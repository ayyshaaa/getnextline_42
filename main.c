#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>
#include "get_next_line.h"

int main()
{
        int     fd;
        char    *res;

        fd = open("linetest.txt", O_RDWR);
        res = get_next_line(fd);
        printf("%s", res);
        free(res);
        res = NULL;
        res = get_next_line(fd);
        printf("%s", res);
        free(res);
        res = NULL;
        res = get_next_line(fd);
        printf("%s", res);
        free(res);
        res = NULL;
        return (0);
}