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
#include <errno.h>

extern char **environ;

int _getline(char **lineptr, size_t *n,  FILE* stream);
int get_count(FILE *stream);
char **split_words(char *str, char del);
int count_words(char *sr, char del);
char *_getenv(const char *name);
char *_which(char *av);
char **parsing(char *lineptr, char *name, int count, int *flag);
void free_array(char **arr);
int builtin_check(const char *name);
int digit_count(char *s);
int pow_10(int n);
int sign(char *s);
int _atoi(char *s);
void printenv(void);
#endif /*MAIN_H*/
