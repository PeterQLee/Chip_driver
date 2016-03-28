#ifndef BLUE_COMM_H
#define BLUE_COMM_H

#include <bluetooth>
#include <sys/socket.h>
#include <unistd.h>

#include "types.h"

#define QUEUE_HEAP_SIZE 4096
#define INSTRUCT_SIZE 4

typedef struct {
  int sock,client;
  sockaddr_rc loc_addr,rem_addr;
  socklen_t opt;
  queue_t *queue;

}blue_com_t;

void start_blue( void * queue);

int initialize(blue_com_t *bs);
int sync_mode(blue_com_t *bcom);
void communicate(blue_com_t *bcom);

#endif
