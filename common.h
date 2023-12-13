/*
common.h - заголовочный файл со стандартными определениями
*/

#ifndef COMMON_H
#define COMMON_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/msg.h>

#define MAXBUF 80
#define PERM0666

/* 
Определение структуры сообщения. Первым элементом структуры
должен быть элемент типа long, указывающий на тип сообщения.
Другие элементы могут быть определены дополнительно.
*/

typedef struct my_msgbuf
{
long mtype;
char buff[MAXBUF];
} my_message_t;

#endif /* COMMON_H */

