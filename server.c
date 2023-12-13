#include "common.h"

int main() {
key_t key;
int msgid;
my_message_t message;

printf("Message Queue Server...\n");

// Получение ключа для очереди сообщений
if ((key = ftok("server", 'A')) < 0) {
fprintf(stderr, "Невозможно получить ключ (%s)\n", strerror(errno));
exit(-1);
}

// Создание или получение доступа к очереди сообщений
if ((msgid = msgget(key, IPC_CREAT | 0666)) < 0) {
fprintf(stderr, "Невозможно создать очередь (%s)\n", strerror(errno));
exit(-1);
} 
// Бесконечный цикл приема сообщений
while (1) {
// Получение сообщения из очереди
if (msgrcv(msgid, &message, sizeof(message), 0, 0) < 0) {
fprintf(stderr, "Ошибка чтения сообщения (%s)\n", strerror(errno));
exit(-1);
}

// Вывод сообщения и PID отправителя
printf("Received from client PID %ld: %s\n", message.mtype, message.buff);
}

exit(0);
}


dsg
