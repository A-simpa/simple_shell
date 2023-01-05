#ifndef MAIN_H /*MAIN_H*/
#define MAIN_H /*MAIN_H*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stddef.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/stat.h>


int _getline(char **lineptr, size_t *n,  FILE* stream);
int get_count(FILE *stream);
char **split_words(char *str, char del);
int count_words(char *sr, char del);
char *_getenv(const char *name);
char *_which(char *av);
char **parsing(char *lineptr);
void free_array(char **arr);
#endif /*MAIN_H*/
