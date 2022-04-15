#include "theodorusSpiral.h"
#include <string.h>

void help()
{
    printf(
    "Usage: \n"
    " TheodorusSpiral [options]\n\n"
    "Options:\n"
    " -t, --triangles           number of triangles of the spiral (default = 50)\n"
    " -a, --antialiasing        activate antialiasing: 1 to disable, 2 to enable (default = 1)\n"
    " -z, --zoom                zoom scale (default = 60)\n"
    );
}

int main(int argc, char *argv[])
{
    triangles = 50;
    antialiasing = 1;
    zoom = 60;

    for (int i = 1; i < argc; i += 2)
    {
        if (!strcmp(argv[i], "-h") || !strcmp(argv[i], "--help"))
        {
            help();
            return EXIT_SUCCESS;
        }
        else if (argv[i+1])
        {
            if (!strcmp(argv[i], "-t") || !strcmp(argv[i], "--triangles"))
            {
                triangles = atoi(argv[i+1]);
            }
            else if (!strcmp(argv[i], "-a") || !strcmp(argv[i], "--antialiasing"))
            {
                antialiasing = atoi(argv[i+1]);
            }
            else if (!strcmp(argv[i], "-z") || !strcmp(argv[i], "--zoom"))
            {
                zoom = atoi(argv[i+1]);
            }
            else
            {
                fprintf(stderr, "ERROR: '%s' invalid argument\n", argv[i+1]);
                return EXIT_FAILURE;
            }
        }
        else
        {
            fprintf(stderr, "ERROR: %s requires an argument!\nUse --help for more information\n", argv[i]);
            return EXIT_FAILURE;
        }
    }

    if (!triangles || (antialiasing != 1 && antialiasing != 2) || !zoom)
    {
        printf("Invalid arguments\n");
        help();
        exit(EXIT_FAILURE);
    }

    run();

    return 0;
}
