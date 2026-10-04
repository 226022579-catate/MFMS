#include <stdio.h>
#include <string.h>
#include "utilities.h"

int readInt(const char *prompt)
{
    char line[64];
    int value;

    printf("%s", prompt);

    do {
        if (fgets(line, sizeof(line), stdin) == NULL)
            return 0;
        line[strcspn(line, "\n")] = '\0';
    } while (strlen(line) == 0);

    if (sscanf(line, "%d", &value) != 1)
     return 0;
     
    return value;
}