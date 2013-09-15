#ifndef R2_H
#define R2_H

#include <stdio.h>

//constants
#define SYS 0 //system process
#define APP 1 //application process

typedef struct {
  char name[11];
  int class;
  int priority;
  int state;      //running, ready or blocked
  int suspended;  //suspended or not
  /*
  //stack
  unsigned char *top; //TODO: this is eff-ed up.
  //memory information
  int memory_size;
  unsigned char *load_address;
  unsigned char *exec_address;
  */
} pcb;

typedef struct {
  int count;
  pcb *head, *tail;
} pcb_queue;

//modes
#define FIFO 1
#define PRIORITY -1

//error codes
#define SUCCESS 0
#define NO_SUCH_MODE -1
#define PCB_NOT_FOUND -2

//function prototypes
//definePCB.c
int createPCB(int argc, char **argv);
int deletePCB(int argc, char **argv);
//alterPCB.c
int blockPCB(int argc, char **argv);
int unblockPCB(int argc, char **argv);
int suspendPCB(int argc, char **argv);
int resumePCB(int argc, char **argv);
int setPCBPriority(int argc, char **argv);
//dispPCB.c
int showPCB(int argc, char **argv);
int showReady(int argc, char **argv);
int showBlocked(int argc, char **argv);
int showAll(int argc, char **argv);
//PCBProcedures.c
pcb *allocatePCB();
int freePCB(pcb *toFree);
pcb *setupPCB(char name[], int class, int priority);
pcb *findPCB(char *name);
pcb *find(char *name, pcb_queue *queue);
int insertPCB(pcb *toInsert);
int removePCB(pcb *toRemove);

#endif