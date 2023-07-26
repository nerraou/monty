#ifndef LIB_H
#define LIB_H

#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>

#define BUFFER_SIZE 5

int _getline(int fd, char **linep);
ssize_t _str_index_of(const char *str, char c);
char *_strdup(const char *str);
char *_strcpy(char *dest, const char *src);
char *join_and_free(char *s1, const char *s2);
char *strjoin(const char *s1, const char *s2);
size_t _strlen(const char *str);
char *_strtrim(char const *s1, char const *set);
char *_strncpy(char *dest, const char *src, size_t n);
char **_strtow(const char *str, const char *set);
int _strcmp(char *s1, char *s2);
int _isspace(char c);
int _is_int(const char *str);
unsigned int _atou(const char *str);

#endif