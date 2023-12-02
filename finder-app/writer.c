#include <stdio.h>
#include <syslog.h>
#include <sys/stat.h>

int main(int argc, char *argv[])
{
    openlog("AELD - ASSIGNMENT 2", LOG_PID, LOG_USER);
    syslog(LOG_DEBUG, "Writing %s to %s", argv[2], argv[1]);

    // Ensuring that the file takes exactly three arguments
    if (argc != 3)
    {
        syslog(LOG_ERR, "Wrong number of arguments");
        closelog();
        return 1;
    }
    char *writeFile = argv[1];
    char *writeStr = argv[2];

    FILE *filePointer;

    // Open file in write mode
    filePointer = fopen(writeFile, "w");

    printf("%s", writeFile);
    printf("%s", writeStr);

    if (filePointer == NULL)
    {
        syslog(LOG_ERR, "An error occurred while trying to write to file");
        closelog();
        return 1;
    }

    // Writing to the file
    fputs(writeStr, filePointer);

    closelog();
    return 0;
}