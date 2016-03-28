#ifndef EXEC_INSTRUCT_H
#define EXEC_INSTRUCT_H
#include "types.h"

#define NUM_MOTORS 3
#define M_OUT_PATH /sys/clas/gpio/export/
//define masks here

unsigned char instruct_masks={~0x1,~0x2};//,..

enum {
  Motor_0=0;
  Motor_1=1;
  Motor_2=2;
};


int motor_outs[NUM_MOTORS];

typedef struct {
} motor_coefficients;


void delegate(queue_t *queue);
void init_motor(motor_coefficients *mc);
void execute_action(char c,motor_coeffcients *mc);

void write_motor(int out,char val);



#endif
