#include "common.h"
#include <unistd.h>

#define MESSAGE "Hello from client %ld\n"

int main() {
key_t key;
int msgid;
my_message_t message;

printf("Message Queue Client...\n");

// Получение ключа для очереди сообщений
if ((key = ftok("server", 'A')) < 0) {
fprintf(stderr, "Невозможно получить ключ (%s)\n", strerror(errno));
exit(-1);
}

// Получение доступа к очереди сообщений
if ((msgid = msgget(key, 0)) < 0) {
fprintf(stderr, "Невозможно получить доступ к очереди (%s)\n", strerror(errno));
exit(-2);
}
// Использование PID как типа сообщения
message.mtype = getpid();

// Подготовка сообщения
int length = sprintf(message.buff, MESSAGE, (long) getpid());
if (length < 0) {
fprintf(stderr, "Ошибка копирования в буфер (%s)\n", strerror(errno));
exit(-3);
}

// Отправка сообщения в очередь
if (msgsnd(msgid, (void *) &message, length, 0) < 0) {
fprintf(stderr, "Ошибка записи сообщения в очередь (%s)\n", strerror(errno));
exit(-4);
}

exit(0);
}

