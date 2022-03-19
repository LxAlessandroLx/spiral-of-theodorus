#include "theodorusSpiral.h"

void help()
{
    printf(
    "Usage: \n"
    " TheodorusSpiral [triangless] [antialiasing] [zoom]\n\n"
    "Arguments:\n"
    " - triangles           number of triangles of the spiral (default = 50)\n"
    " - antialiasing        activate antialiasing: 1 to disable, 2 to enable (default = 1)\n"
    " - zoom                zoom scale (default = 60)\n"
    );
}

int main(int argc, char *argv[])
{
    triangles = argc > 1 ? atoi(argv[1]) : 50;
    antialiasing = argc > 2 ? atoi(argv[2]) : 2;
    zoom = argc > 3 ? atoi(argv[3]) : 60;

    if (!triangles || (antialiasing != 1 && antialiasing != 2) || !zoom)
    {
        printf("Invalid arguments\n");
        help();
        exit(EXIT_FAILURE);
    }

    run();

    return 0;
}
