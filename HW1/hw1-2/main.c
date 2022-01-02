#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main( int argc, char* argv[]){
        
	if(argc==3){

		char filename1[20];
		strcpy (filename1, argv[1]);
		char filename2[20];
		strcpy (filename2, argv[2]);

		FILE* input_file  = fopen(filename1, "rb");

		if (!input_file){
			perror("fopen");
			exit(EXIT_FAILURE);
		}

		int a=0;

		fseek(input_file,0,SEEK_END);
		long int size=ftell(input_file); // get size of file in bytes
		fseek(input_file,0,SEEK_SET);

		FILE* output_file  = fopen(filename2, "wb+");


		if (!output_file){
		    perror("fopen");
		    exit(EXIT_FAILURE);
		}
		    
		for(int i=0; i<size; i++){
			fread(&a, sizeof(int), 1, input_file); //read one int (sizeof(int)!=1 byte)
			fwrite(&a, sizeof(int), 1, output_file);
		}

        	fclose(input_file);
		fclose(output_file);
	} 
	return 0;
}
