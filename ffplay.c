#include <stdlib.h>
#include <ffplay_entrypoint.h>

const char program_name[] = "ffplay";
const int program_birth_year = 2003;

int main(int argc, char **argv)
{
    int returnCode = entryPoint(argc, argv, /*is_leon=*/0, 0);
    if (returnCode < 0)
        exit(1);
    return 0;
}
