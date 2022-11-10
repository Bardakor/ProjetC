#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "parser.c"

//function to return the entire third element of the array returned by **split
char *getType(char *word)
{
    char *type = malloc(sizeof(char) * strlen(word));
    strcpy(type, word);
    return type;
}

//every type for a nom has this form : Type:Mas/Fem:Sing/Plur

//we need a function that let's us choose a genre and a number for a nom and return the first part of the array returned by **split

char *getNom2(char *genre, char *number, char *filename)
{
    int line_number = rand() % Max;
    char *line = getNom(filename);
    int size;
    char **words = split(line, &size);
    char *word = words[0];
    char *base = words[1];
    char *type = words[2];
    
    //now skip the first 3 letters from type and check if the 2 next letter are corresponding to the genre
    //if not, we need to choose another line
    if (type[3] == genre[0] && type[4] == genre[1])
    {
        //now check if the 2 next letters are corresponding to the number
        if (type[6] == number[0] && type[7] == number[1])
        {
            return line;
        }
    }
    return getNom2(genre, number, filename);
}

