#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <errno.h>

/* FREE_ARRAY.c */
void free_arr(char **array);

/* PATH.c */
char *_path(char *com, char **env);

/* EXECUTE.c */
int _exec(char **com, char **argv, char **env, int com_count);

/* ENV.c */
char *_getenv(char *var, char **environ);
void Env(char **com, int *status, char **env);

/* UTILS.c */
void revstr(char *str, int len);
int ispos(char *str);

/* EXIT.c */
void error(char *argv, char *com, int com_count);
void exit_err(char *argv, char *com, int com_count);
void Exit(char **com, char **argv, int *status, int com_count);

/* HELPER_FUNC_0.c */
char *_itoa(int num);
int _atoi(char *str);

/* TOKEN.c */
char **tok_tok(char *line);
char *_getline(void);

/* HELPER_FUNC_1.c */
int _strlen(char *string);
char *_strcat(char *dest, char *src);
char *_strcpy(char *dest, char *src);
char *_strdup(const char *str);
int _strcmp(char *s1, char *s2);

/* BUILTIN_COM.c */
int isblt(char *com);
void cd(char **com, int *status);
void bltin_func(
	char **com, char **argv, int *status, int com_count, char **env);

#endif
