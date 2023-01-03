#ifndef MAIN_H /*MAIN_H*/
#define MAIN_H /*MAIN_H*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stddef.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <unistd.h>

int __getline(char **lineptr, FILE* stream);
char **split_words(char *str, char del);
int count_words(char *sr, char del);
#endif /*MAIN_H*/
