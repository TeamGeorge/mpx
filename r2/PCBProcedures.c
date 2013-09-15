#include "r2.h"

//globals
pcb *running;
pcb_queue ready, blocked;

pcb *allocatePCB() {
  //TODO: stuff
}

//believe it works
int freePCB(pcb *toFree) {
  int returnVal;
  if(toFree != find(toFree->name)) {
    returnVal = PCB_NOT_FOUND;
  } else {
    sys_free_mem(toFree->stack);
    sys_free_mem(toFree);
    returnVal = SUCCESS;
  }
  return returnVal;
}

pcb *setupPCB(char name[], int class, int priority) {
  //TODO: stuff
}

//believe it works
pcb *findPCB(char *name) {
  pcb *returnVal = NULL;
  returnVal = (strcmp(name, running->name) == 0) ? running : find(name, ready); //if not running, check ready queue
  returnVal = (returnVal != NULL) ? returnVal : find(name, blocked);   //if NULL, check blocked queue
  return returnVal;
}

//believe it works
pcb *find(char *name, pcb_queue *queue) {
  int i;
  pcb *curr = queue->head, *returnVal = NULL;
  for(i=0; i<queue->count; i++) {
    if(strcmp(curr->name, name) == 0) {  //found it
      returnVal = curr;
      break;
    } else {
      curr = curr->next;  //didn't, go to next
    }
  }
  return returnVal;
}

//believe it works
//TODO: helper function for insertion?
int insertPCB(pcb *toInsert, pcb_queue *queue, int mode) {
  int returnVal;
  pcb *curr;
  if(mode == FIFO) {
    queue->tail->prev = toInsert;
    toInsert->next = queue->tail;
    queue->tail = toInsert;
    toInsert->prev = NULL:
    queue->count++;
    returnVal = SUCCESS;
  } else if(mode == PRIORITY) {
    curr = queue->tail;
    while(curr->priority < toInsert->priority) {
      curr = curr->next;
    }
    if(curr == NULL) {
      queue->head->next = toInsert;
      toInsert->prev = queue->head;
      queue->head = toInsert;
      toInsert->next = NULL;
    } else {
      curr->prev->next = toInsert;
      toInsert->prev = curr->prev;
      curr->prev = toInsert;
      toInsert->next = curr;
    }
    returnVal = SUCCESS;
  } else {
    returnVal = NO_SUCH_MODE;
  }
  return returnVal;
}

//return error code?
int removePCB(pcb *toRemove) {
  //TODO: stuff
}