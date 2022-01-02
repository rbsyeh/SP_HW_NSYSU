#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main( int argc, char* argv[]){

        char input[80];

        int i=0;

        while(fgets(input, 80, stdin)){

            fputs(input, stdout);

            if(argc==2){

                char filename[10];
                strcpy (filename, argv[1]);

                if(i==0){
                    i++;
                    FILE* output_file = fopen(filename, "w+");
                    if (!output_file) {
                        perror("fopen");
                        exit(EXIT_FAILURE);
                    }

                    fwrite(input, 1, strlen(input), output_file);
                    fclose(output_file);
                }
                else{

                    FILE* output_file = fopen(filename, "a");
                    if (!output_file) {
                        perror("fopen");
                        exit(EXIT_FAILURE);
                    }

                    fwrite(input, 1, strlen(input), output_file);
                    fclose(output_file);
                }
            }

            if(argc==3){

                char cmd[2];
                strcpy (cmd, argv[1]);

                if(cmd[1]=='a'){

                    char filename[10];
                    strcpy (filename, argv[2]);

                    FILE* output_file = fopen(filename, "a");
                    if (!output_file){
                        perror("fopen");
                        exit(EXIT_FAILURE);
                    }
                    fwrite(input, 1, strlen(input), output_file);
                    fclose(output_file);
                }
            }
        }
	return 0;

}
