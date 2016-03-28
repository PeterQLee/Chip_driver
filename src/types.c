#include "types.h"

queue_t *create_queue(size_t stack_lim){
  queue_t *queue=malloc(sizeof(queue_t));
  char *mem=malloc(stack_lim*sizeof(char));
  queue->top=mem;
  queue->bottom=mem;
  queue->start_addr=mem;
  queue->end_addr=mem+((stack_lim-1)*sizeof(char));//check this
  queue->cursize=0;
  queue->maxsize=stack_lim;
  return queue;
}
void clear_queue(queue_t *queue) {
  //clean up memory
  free(queue->start_addr);
  free(queue);
}


int push_Q(queue_t *queue,char c) {
  //Access function, ensures queue is circular and pushes.
  _ensure_circular(queue);
  if (NQUEUE_FULL(queue)) {
    _push_queue(queue, c);
    return 0;
  } 
  return 1;
}
char pop_Q(queue_t *queue, int *ret) {
  //Access function, ensures queue is circular and pops
  while (queue->lock) {}
  
  queue->lock=true;
  _ensure_circular(queue);
  char d;
  if (NQUEUE_EMPTY(queue)) {
    return _pop_queue(queue);

  }
  *ret=1;
  
  queue->lock=false;
  return 0;
  
  
}

void _ensure_circular(queue_t *queue) {
  //make sure pointers are in range
  if (queue->top>queue->end_addr) 
    queue->top=queue->start_addr;
  
  if (queue->bottom>queue->end_addr)
    queue->bottom=queue->start_addr;
  
}

void _push_queue(queue_t *queue,char c) {
  //pushes a single char
  *((char*)queue->bottom)=c;
  (queue->bottom)++; //increment pointer
  (queue->cursize)++;
  queue->lock=false;
}

char _pop_queue(queue_t *queue) {
  //Trusts that something is in the queue already
  (queue->top)++;
  (queue->cursize)--;
  char d= *((char *)(queue->top-1));
  queue->lock=false;
  return d;

}
