#include "exec_instruct.h"

void delegate(queue_t *queue) {
  motor_coefficients mc;
  char c;
  int res=1;
  while () {
    while (res) {
      c=queue->popQ(&res);
    }
    execute_action(c,&mc);
		   
  }
}

void init_motor(motor_coefficients *mc) {
  int fd,i;
  char bufs*[]= {"12"};
  //set mc to specific things
  //init motors
  fd=open(M_OUT_PATH,O_WRONLY);
  for (i=0;i<1;i++) {
  
    write(fd,bufs[i],strlen(bufs[i]));
  }
  
  close (fd);

  //Set directions
	  
  
  
}
		  
void execute_action(char c, motor_coeffecients *mc) {
  
}

void write_motor (int out, char *val) {
  write(out,val,1);
}
