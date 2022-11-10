// in file ProjetC/dictionnaire.txt where each line has the following format: word base-of-the-word Type:Gender:Plural
// create program that randomly chooses a word from the dictionary and returns it with it's associated type

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "parser.h"
#include "parser.c"



int display()
{
    // choose a random line from the file dictionnaire.txt
    srand(time(NULL));
    int line_number = rand() % Max;
    char *line = getLine("dictionnaire.txt", line_number);
    int size;
    char **words = split(line, &size);
    char *word = words[0];
    char *base = words[1];
    char *type = getType(words[2]);
    printf("word: %s\nbase: %s\ntype: %s\n", word, base, type);
    return 0;
}

//display Nom

int displayNom()
{
    char *line = getNom("dictionnaire.txt");
    int size;
    char **words = split(line, &size);
    char *word = words[0];
    char *base = words[1];
    char *type = getType(words[2]);
    printf("word: %s\nbase: %s\ntype: %s\n", word, base, type);
    return 0;
}

//display Ver

int displayVer()
{
    char *line = getVer("dictionnaire.txt");
    int size;
    char **words = split(line, &size);
    char *word = words[0];
    char *base = words[1];
    char *type = getType(words[2]);
    printf("word: %s\nbase: %s\ntype: %s\n", word, base, type);
    return 0;
}

//display Adj

int displayAdj()
{
    char *line = getAdj("dictionnaire.txt");
    int size;
    char **words = split(line, &size);
    char *word = words[0];
    char *base = words[1];
    char *type = getType(words[2]);
    printf("word: %s\nbase: %s\ntype: %s\n", word, base, type);
    return 0;
}

//display Adv

int displayAdv()
{
    char *line = getAdv("dictionnaire.txt");
    int size;
    char **words = split(line, &size);
    char *word = words[0];
    char *base = words[1];
    char *type = getType(words[2]);
    printf("word: %s\nbase: %s\ntype: %s\n", word, base, type);
    return 0;
}


int main()
{
    //print number of lines in file
    printf("Number of lines in file: %d\n", countLines("dictionnaire.txt"));
    Max = countLines("dictionnaire.txt");
    display();
    displayNom();
    displayVer();
    displayAdj();
    displayAdv();
}
