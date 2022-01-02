/*
 * parse.c : use whitespace to tokenise a line
 * Initialise a vector big enough
 */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "shell.h"

/* Parse a commandline string into an argv array. */
char ** parse(char *line) {

  	static char delim[] = " \t\n"; /* SPACE or TAB or NL */
  	int count = 0;
  	char * token;
  	char **newArgv;

  	/* Nothing entered. */
  	if (line == NULL) {
  		return NULL;
  	}

  	//malloc
     newArgv=(char**)malloc(sizeof(char *));

  	/* Init strtok with commandline, then get first token.
     * Return NULL if no tokens in line.
	 *
	 * Fill in code.
     */

     // strtok with delim
     token=strtok(line, delim);

     if(token == NULL){
     	return NULL;
  	}
  	


  	/* Create array with room for first token.
  	 *
	 * Fill in code.
	 */
     newArgv[0]=token;
     
     printf( "[0] : %s\n", token );


  	/* While there are more tokens...
	 *
	 *  - Get next token.
	 *	- Resize array.
	 *  - Give token its own memory, then install it.
	 * 
  	 * Fill in code.
	 */

     int s_re=1;//for realloc
     int index=0;

     while(token != NULL){
     	token = strtok(NULL, delim);
     	s_re++;
     	index++;
     	newArgv=(char**)realloc(newArgv, s_re*sizeof(char *));
     	newArgv[index]=token;
     	//printf( "[%d] : %s\n",index, token );
     }




  	/* Null terminate the array and return it.
	 *
  	 * Fill in code.
	 */


     //free(token);
     return newArgv;
  	
}


/*
 * Free memory associated with argv array passed in.
 * Argv array is assumed created with parse() above.
 */
void free_argv(char **oldArgv) {


	// int i = 0;

	// while(oldArgv[i]){
	// 	free(oldArgv[i]);
	// 	i++;
	// }
	

	/* Free each string hanging off the array.
	 * Free the oldArgv array itself.
	 *
	 * Fill in code.
	 */

	free(oldArgv);
}
