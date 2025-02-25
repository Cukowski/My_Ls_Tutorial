#ifndef MY_LS_H
#define MY_LS_H

#include <stdio.h>
#include <stdbool.h>
#include <dirent.h>
#include <sys/stat.h>
#include <string.h>


// Strucuture to hold command-line opritons (-a, -t)
typedef struct s_options {
    bool show_all; // -a
    bool sort_time; // -t
} options_t;


// Function declerations
options_t parse_options(int argc, char** argv);
int gather_paths(int argc, char** argv, 
                char** non_dirs, int *non_dir_count, 
                char** dirs, int *dir_count);


#endif