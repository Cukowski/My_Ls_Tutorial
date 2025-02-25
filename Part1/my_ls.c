/*
1. Parse arguments -> -a -t 
2. for directoies ls . > ls dir1
3. sort  alphabetically or by time
4. print
5. free
*/

#include "my_ls.h"

options_t parse_options(int argc, char** argv)
{
    options_t opts;
    opts.show_all = false;
    opts.sort_time = false;

    // Scan all arguments for flags
    for (int i = 0; i < argc; i++)
    {
        if (argv[i][0] == '-')
        {
            // It's an option arg
            for (int j = 1; argv[i][j] != '\0'; j++)
            {
                if (argv[i][j] == 'a') {
                    opts.show_all = true;
                } else if (argv[i][j] == 't') {
                    opts.sort_time = true;
                } else {
                    // Invalid option
                    printf("my_ls: invalid option -- %c\n", argv[i][j]);
                }
            }
        }
        
    }
    return opts;
}

/*
- Collect the non-option arguments (file, dir names)
- separate them
- return total num of dirs
- if no paths, "."
*/
int gather_paths(int argc, char** argv, 
                char** non_dirs, int *non_dir_count, 
                char** dirs, int *dir_count)
{
    int total = 0;
    *dir_count = 0;
    *non_dir_count = 0;

    // skip the argv[0] -> ./my_ls
    for (int i = 1; i < argc; i++)
    {
        // Skip the options
        if (argv[i][0] == '-') {
            continue;
        }

        // Try opening it as a dir
        DIR *temp_dir = opendir(argv[i]);
        if (temp_dir) {
            // it's a valid dir
            closedir(temp_dir);
            dirs[*dir_count] = argv[i];
            (*dir_count)++;
            total++;
        } else {
            // not a dir (file or invalid)
            struct stat st;
            if (lstat(argv[i], &st) == 0) {
                // It's existing
                non_dirs[*non_dir_count] = argv[i];
                (*non_dir_count)++;
                total++;
            } else {
                // Invalid path
                printf("my_ls: cannot access '%s'\n", argv[i]);
            }
        }
    }

    // if no valid, non-option args are provided, default "."
    if (total == 0) {
        dirs[0] = ".";
        *dir_count = 1;
        total = 1;
    }
    
    return total;
}

int main(int argc, char** argv)
{
    // 1) Parse options
    options_t opts = parse_options(argc, argv);

    printf("Options: %d, %d\n", opts.sort_time, opts.show_all);

    // Arrays to store dirs and paths
    char* dirs[argc];
    char* non_dirs[argc];
    memset(dirs, 0, sizeof(dirs)); // Init to NULL
    memset(non_dirs, 0, sizeof(non_dirs)); // Init to NULL
    int dir_count = 0;
    int non_dir_count = 0;

    // 2) Gather Paths
    int total = gather_paths(argc, argv, 
        non_dirs, &non_dir_count, 
        dirs, &dir_count);
    
    printf("Total: %d\n", total);
    printf("dirs: %s\n", dirs[0]);
    printf("Non dirs: %s\n", non_dirs[0]);

    // Sort non_dirs alpahabetically
    if (non_dir_count > 1) {
        // Bubble sort fo non dir array
        for (int i = 0; i < non_dir_count - 1; i++) {
            for (int j = 0; j < non_dir_count - i - 1; j++) {
                if (strcmp(non_dirs[j], non_dirs[j + 1]) > 0) {
                    char* temp = non_dirs[j];
                    non_dirs[j] = non_dirs[j+1];
                    non_dirs[j+1] = temp;
                }
            }
        }
    }
    // Sort dirs alpahabetically
    if (dir_count > 1) {
        // Bubble sort fo non dir array
        for (int i = 0; i < dir_count - 1; i++) {
            for (int j = 0; j < dir_count - i - 1; j++) {
                if (strcmp(dirs[j], dirs[j + 1]) > 0) {
                    char* temp = dirs[j];
                    dirs[j] = dirs[j+1];
                    dirs[j+1] = temp;
                }
            }
        }
    }

    // 3) Print non_dirs first
    // then a blank line and list dirs after
    for (int i = 0; i < non_dir_count; i++) {
        // Just prin the file name (ls -1)
        printf("%s\n", non_dirs[i]);
    }
    if (non_dir_count > 0 && dir_count > 0) {
        printf("\n");
    }

    // 4) For ech dir, read, sort, print!

    return 0;
}