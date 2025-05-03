#include <stdlib.h>
#include <unistd.h>
#include <stdbool.h>
#include <sys/inotify.h>
#include <string.h>

int
main (int argc, 
      char *argv[])
{
    bool watch = false;
    char *build_directory_name, *directory;
    char buf[1024];
    
    directory = getcwd(NULL, 0);

    for (int i = argc - 1; i > 0; i--) 
    {
        if (strcmp(argv[i], "--watch") == 0)
        {
            watch = true;
        }
        else if (strcmp(argv[i], "--directory") == 0)
        {
            free(directory);
            directory = argv[i + 1];
        }
    }

    int fd = inotify_init();
    int wd = inotify_add_watch(fd, directory, IN_MODIFY);
    
    char *setup_command = strcat();

    while (true)
    {
        chdir(directory);
        
        ////////////// 

        if (!watch) {
            free(directory);
            break;
        }
        
        read(fd, buf, sizeof(buf));
    }
    
    return 0;
}
