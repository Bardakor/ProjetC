// in file ProjetC/dictionnaire.txt where each line has the following format: word base-of-the-word Type:Gender:Plural
// create program that randomly chooses a word from the dictionary and returns it with it's associated type

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "functions.h"

#define MAX 100

// function to return an array of strings from a string, it splits the string at each space or tabulation or newline or carriage return and returns an array of strings

char **split(char *str, int *size)
{
    char **array = malloc(sizeof(char *) * MAX);
    char *token = strtok(str, " \t \r \n");
    int i = 0;
    while (token != NULL)
    {
        array[i] = malloc(sizeof(char) * strlen(token));
        strcpy(array[i], token);
        token = strtok(NULL, " \t \r \n");
        i++;
    }
    *size = i;
    return array;
}

// function that checks if the third element of the array returned by **split is Nom or Ver or Adj or Adv by reading the first 3 letters of the word

int isNom(char *word)
{
    if (word[0] == 'N' && word[1] == 'o' && word[2] == 'm')
    {
        return 1;
    }
    return 0;
}

int isVer(char *word)
{
    if (word[0] == 'V' && word[1] == 'e' && word[2] == 'r')
    {
        return 1;
    }
    return 0;
}

int isAdj(char *word)
{
    if (word[0] == 'A' && word[1] == 'd' && word[2] == 'j')
    {
        return 1;
    }
    return 0;
}

int isAdv(char *word)
{
    if (word[0] == 'A' && word[1] == 'd' && word[2] == 'v')
    {
        return 1;
    }
    return 0;
}

// functions that returns as char the type of the word

char *getType(char *word)
{
    if (isNom(word))
    {
        return "Nom";
    }
    else if (isVer(word))
    {
        return "Ver";
    }
    else if (isAdj(word))
    {
        return "Adj";
    }
    else if (isAdv(word))
    {
        return "Adv";
    }
    else
        return "nothing";
}

// return a string that is an entire line from the file dictionnaire.txt

char *getLine(char *filename, int line_number)
{
    FILE *fp = fopen(filename, "r");
    char *line = malloc(sizeof(char) * MAX);
    int i = 0;
    while (fgets(line, MAX, fp) != NULL)
    {
        if (i == line_number)
        {
            return line;
        }
        i++;
    }
    return NULL;
}

//function to pick a line that type is Nom, if it's not Nom it will pick another line until it finds a line that type is Nom

char *getNom(char *filename)
{
    char *line = malloc(sizeof(char) * MAX);
    int line_number = rand() % 1000;
    line = getLine(filename, line_number);
    int size = 0;
    char **array = split(line, &size);
    while (!isNom(array[2]))
    {
        line_number = rand() % 1000;
        line = getLine(filename, line_number);
        array = split(line, &size);
    }
    return line;
}

//function to pick a line that type is Ver, if it's not Ver it will pick another line until it finds a line that type is Ver

char *getVer(char *filename)
{
    char *line = malloc(sizeof(char) * MAX);
    int line_number = rand() % 1000;
    line = getLine(filename, line_number);
    int size = 0;
    char **array = split(line, &size);
    while (!isVer(array[2]))
    {
        line_number = rand() % 1000;
        line = getLine(filename, line_number);
        array = split(line, &size);
    }
    return line;
}


//function to pick a line that type is Adj, if it's not Adj it will pick another line until it finds a line that type is Adj

char *getAdj(char *filename)
{
    char *line = malloc(sizeof(char) * MAX);
    int line_number = rand() % 1000;
    line = getLine(filename, line_number);
    int size = 0;
    char **array = split(line, &size);
    while (!isAdj(array[2]))
    {
        line_number = rand() % 1000;
        line = getLine(filename, line_number);
        array = split(line, &size);
    }
    return line;
}

//function to pick a line that type is Adv, if it's not Adv it will pick another line until it finds a line that type is Adv

char *getAdv(char *filename)
{
    char *line = malloc(sizeof(char) * MAX);
    int line_number = rand() % 1000;
    line = getLine(filename, line_number);
    int size = 0;
    char **array = split(line, &size);
    while (!isAdv(array[2]))
    {
        line_number = rand() % 1000;
        line = getLine(filename, line_number);
        array = split(line, &size);
    }
    return line;
}



int main()
{

    // choose a random line from the file dictionnaire.txt
    srand(time(NULL));
    int line_number = rand() % 300000;
    char *line = getLine("dictionnaire.txt", line_number);
    int size;
    char **words = split(line, &size);
    char *word = words[0];
    char *base = words[1];
    char *type = getType(words[2]);
    printf("word: %s\nbase: %s\ntype: %s\n", word, base, type);
    return 0;
}
