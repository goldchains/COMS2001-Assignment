#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>
#include <errno.h>
#include <unistd.h>
#include <termios.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <stdbool.h>

#define INPUT_STRING_SIZE 80

#include "io.h"
#include "parse.h"
#include "process.h"
#include "shell.h"

int cmd_quit(tok_t arg[]) {
  printf("Bye\n");
  exit(0);
  return 1;
}

int cmd_help(tok_t arg[]);

int cmd_pwd(tok_t arg[]){
   char pwd[1024];
   if (getcwd(pwd, sizeof(pwd)) != NULL)
       fprintf(stdout, "Current working dir: %s\n", pwd);
   else
       perror("getcwd() error");
   return 0; 
  
};

/* Command Lookup Table Structures */
typedef int cmd_fun_t (tok_t args[]); // cmd functions take token array and return int
typedef struct fun_desc {
  cmd_fun_t *fun;
  char *cmd;
  char *doc;
} fun_desc_t;
// add more commands to this lookup table!
fun_desc_t cmd_table[] = {
  {cmd_help, "?", "show this help menu"},
  {cmd_pwd, "pwd", "show working directory"},
  {cmd_quit, "quit", "quit the command shell"},
};

int lookup(char cmd[]) {
  int i;
  for (i=0; i < (sizeof(cmd_table)/sizeof(fun_desc_t)); i++) {
    if (cmd && (strcmp(cmd_table[i].cmd, cmd) == 0)) return i;
  }
  return -1;
}

int cmd_help(tok_t arg[]) {
  int i;
  for (i=0; i < (sizeof(cmd_table)/sizeof(fun_desc_t)); i++) {
    printf("%s - %s\n",cmd_table[i].cmd, cmd_table[i].doc);
  }
  return 1;
}

void init_shell()
{
  // Check if we are running interactively
  shell_terminal = STDIN_FILENO;

  // Note that we cannot take control of the terminal if the shell is not interactive
  shell_is_interactive = isatty(shell_terminal);

  if(shell_is_interactive){

    // force into foreground
    while(tcgetpgrp (shell_terminal) != (shell_pgid = getpgrp()))
      kill( - shell_pgid, SIGTTIN);

    shell_pgid = getpid();
    // Put shell in its own process group
    if(setpgid(shell_pgid, shell_pgid) < 0){
      perror("Couldn't put the shell in its own process group");
      exit(1);
    }

    // Take control of the terminal
    tcsetpgrp(shell_terminal, shell_pgid);
    tcgetattr(shell_terminal, &shell_tmodes);
  }
  
  /** YOUR CODE HERE */
  // ignore signals
}

/**
 * Add a process to our process list
 */
void add_process(process* p)
{
  /** YOUR CODE HERE */
}

/**
 * Creates a process given the tokens parsed from stdin
 *
 */
process* create_process(tok_t* tokens)
{
  /** YOUR CODE HERE */
  return NULL;
}



int shell (int argc, char *argv[]) {
  pid_t pid = getpid();		 // get current process's PID
  pid_t ppid = getppid();	 // get parent's PID
  pid_t cpid;                // use this to store a child PID

  char *s = malloc(INPUT_STRING_SIZE+1); // user input string
  tok_t *t;			                     // tokens parsed from input
  // if you look in parse.h, you'll see that tokens are just c-style strings
  
  int lineNum = 0;
  int fundex = -1;
  
  // perform some initialisation
  init_shell();

  printf("%s running as PID %d under %d\n",argv[0],pid,ppid);

  lineNum=0;
  // change this to print the current working directory before each line as well as the line number.
  fprintf(stdout, "%d: ", lineNum);
  while ((s = freadln(stdin))){ 
    t = getToks(s); // break the line into tokens
    fundex = lookup(t[0]); // Is first token a shell literal
    if(fundex >= 0){
cmd_table[fundex].fun(&t[1]);
   lineNum++;
}   
    else {
       // replace this statement to call a function that runs executables
      fprintf(stdout, "This shell only supports built-ins. Replace this to run programs as commands.\n");
    }
    // change this to print the current working directory before each line as well as the line number.
    fprintf(stdout, "%d: ", lineNum);
  }
  return 0;
}
