#include "r1.h"

//Author: Billy Hardy
//Date Created: 8/30
//Last Modified: 8/31 by Billy (changed invalidArgs argument)
//Pre-cond: commhand.c matched on version and argc == 1
//Post-cond: the current version is printed to the screen
int version(int argc, char **argv) {
  if(argc == 1) {
    char buffer[256];
    int bufferSize;
    sprintf(buffer, "\nMPX is at version %i, with that last modification on %i/%i/%i\n\n", VERSION, MONTH, DAY, YEAR);
    bufferSize = strlen(buffer);
    sys_req(WRITE, TERMINAL, buffer, &bufferSize);
  } else {
    invalidArgs(argv[0]);
  }
  return 1;
}
