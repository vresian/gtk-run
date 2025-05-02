#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdbool.h>
#include <sys/inotify.h>
#include <string.h>

int
main (int argc, 
      char *args[])
{
    char* cwd = getcwd(NULL, 0);
    char buf[1024];
    bool watch = false;

    for (int i = argc - 1; i > 0; i--) 
    {
        if (strcmp(args[i], "--watch") == 0)
        {
            watch = true;
        }
        else if (strcmp(args[i], "--directory") == 0)
        {
            free(cwd);
            cwd = args[i + 1];
        }
    }

    int fd = inotify_init();
    int wd = inotify_add_watch(fd, cwd, IN_MODIFY);

    while (true)
    {
        ////////////// 

        if (!watch) {
            free(cwd);
            break;
        }
        
        read(fd, buf, sizeof(buf));
    }
    
    return 0;
}
