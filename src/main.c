#include "exec_instruct.h"
#include "types.h"
#include "blue_comm.h"
#include <pthread.h>



int main(int argc, char **argv) {
  pthread blue_listen;
  
  queue_t *queue=create_queue(QUEUE_HEAP_SIZE);

  pthread_create(&blue_listen,attr,function,(void *)queue);
  
  delegate (queue);
  
  
}
