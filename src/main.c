#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

typedef struct {
	unsigned short L0[16];
	unsigned short L1[16];
	unsigned short L2[16];
}LFSR;
/*
 * f0 f1 f2 f3 f4 f5 f6 f7 
 */
typedef struct{
	unsigned short F[8];
}Filtre;


LFSR* initialiserLFSR(const char* path,LFSR* gen, Filtre* fitlre){
	FILE* file = fopen(path,"r");
	assert(file);
	char buffer[256];
	fscanf(file, "%s", buffer);
	for (int i = 0; i < 16; ++i)
	{
		gen->L0[i] = buffer[i];
	}

	fscanf(file, "%s", buffer);
	for (int i = 0; i < 16; ++i)
	{
		gen->L1[i] = buffer[i];
	}
	fscanf(file, "%s", buffer);
	for (int i = 0; i < 16; ++i)
	{
		gen->L2[i] = buffer[i];
	}

}

/**
 *	Usage  : ./Flow fichier n
 */

int main(int argc, char const *argv[])
{
	//if(argc != 2){ fprintf(stderr, "Usage: Usage  : ./Flow fichier n\n"); exit(0);}
	//Ouvir le fichier et initialiser le LFSR
	FILE * fp;
    char * line = NULL;
    size_t len = 0;
    ssize_t read;

    fp = fopen("./config.txt", "r");
    if (fp == NULL){
    	fprintf(stderr, "Fichier introuvable \n");
        exit(0);
    }

    while ((read = getline(&line, &len, fp)) != -1) {
    	read = getline(&line, &len, fp);
        printf("%s", line);
    }
    printf("\n");

    fclose(fp);
    if (line)
        free(line);
    exit(EXIT_SUCCESS);
	return 0;
}
