#include <errno.h>
#include <stdlib.h>
#include <fcntl.h>
#include <sys/syslog.h>
#include <stdio.h>
#include <sys/types.h>
#include <syslog.h>
#include <unistd.h>
#include <string.h>

int main(int argc, char **argv)
{

    openlog(NULL, 0, LOG_USER);
    if (argc < 3) {
        syslog(LOG_ERR, "Invalid number of arguments! Expected - 3, found - %d\n", argc);
        exit(1);
    }

    int fd = creat(argv[1], 0664);
    if (fd == -1) {
       syslog(LOG_ERR, "Error: %s", strerror(errno));
       perror("creat"); 
       exit(1);
    }

    ssize_t bytesWritten = write(fd, argv[2], strlen(argv[2]));
    if (bytesWritten == -1) {
       syslog(LOG_ERR, "Error: %s", strerror(errno));
       perror("write"); 
       exit(1);
    } else if (bytesWritten != strlen(argv[2])) {
       syslog(LOG_ERR, "Something went wrong :(");
       exit(1);
    } else {
        syslog(LOG_DEBUG, "Writing %s to %s", argv[2], argv[1]);
    }


    close(fd);
}
