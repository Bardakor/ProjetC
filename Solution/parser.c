#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <time.h>

int Max = 0;

//function to calculate the number of lines in the file

int countLines(char *filename)
{
    FILE *fp = fopen(filename, "r");
    int count = 0;
    char c;
    for (c = getc(fp); c != EOF; c = getc(fp))
        if (c == '\n')
            count = count + 1;
    fclose(fp);
    return count;
}

// function to return an array of strings from a string, it splits the string at each space or tabulation or newline or carriage return and returns an array of strings

char **split(char *str, int *size)
{
    char **array = malloc(sizeof(char *) * Max);
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
    char *line = malloc(sizeof(char) * Max);
    int i = 0;
    while (fgets(line, Max, fp) != NULL)
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
    int line_number = rand() % Max;
    char *line = getLine(filename, line_number);
    char *line2 = getLine(filename, line_number);
    int size;
    char **array = split(line2, &size);
    while (!isNom(array[2]))
    {
        line_number = rand() % Max;
        line = getLine(filename, line_number);
        line2 = getLine(filename, line_number);
        array = split(line2, &size);
    }
    return line;
}

//function to pick a line that type is Ver, if it's not Ver it will pick another line until it finds a line that type is Ver

char *getVer(char *filename)
{
    int line_number = rand() % Max;
    char *line = getLine(filename, line_number);
    char *line2 = getLine(filename, line_number);
    int size;
    char **array = split(line2, &size);
    while (!isVer(array[2]))
    {
        line_number = rand() % Max;
        line = getLine(filename, line_number);
        line2 = getLine(filename, line_number);
        array = split(line2, &size);
    }
    return line;
}


//function to pick a line that type is Adj, if it's not Adj it will pick another line until it finds a line that type is Adj

char *getAdj(char *filename)
{
    int line_number = rand() % Max;
    char *line = getLine(filename, line_number);
    char *line2 = getLine(filename, line_number);
    int size;
    char **array = split(line2, &size);
    while (!isAdj(array[2]))
    {
        line_number = rand() % Max;
        line = getLine(filename, line_number);
        line2 = getLine(filename, line_number);
        array = split(line2, &size);
    }
    return line;
}

//function to pick a line that type is Adv, if it's not Adv it will pick another line until it finds a line that type is Adv

char *getAdv(char *filename)
{
    int line_number = rand() % Max;
    char *line = getLine(filename, line_number);
    char *line2 = getLine(filename, line_number);
    int size;
    char **array = split(line2, &size);
    while (!isAdv(array[2]))
    {
        line_number = rand() % Max;
        line = getLine(filename, line_number);
        line2 = getLine(filename, line_number);
        array = split(line2, &size);
    }
    return line;
}

//function to create a new empty file and store in it all the lines that type is Nom, unlimited memory

void createNom(char *filename)
{
    FILE *fp = fopen(filename, "r");
    FILE *fp2 = fopen("Nom.txt", "w");
    char *line = malloc(sizeof(char) * Max);
    int i = 0;
    while (fgets(line, Max, fp) != NULL)
    {
        char *line2 = getLine(filename, i);
        int size;
        char **array = split(line2, &size);
        if (isNom(array[2]))
        {
            fprintf(fp2, "%s", line);
        }
        i++;
    }
    fclose(fp);
    fclose(fp2);
}

//function to fetch only the base of the word afrer the split

char *getBase(char *filename, int line_number)
{
    char *line = getLine(filename, line_number);
    int size;
    char **array = split(line, &size);
    return array[1];
}

//function to go trough whole file, split the line and get the base of the word, check if it's not the same base as the previous one, and if it's not the same base as the previous one, store it in a new file

void createBase(char *filename)
{
    //go trogh the file line by line, add the word to the file if does not have the same basis as it's previous word in the file, only for word that have type nom

    FILE *fp = fopen(filename, "r");
    FILE *fp2 = fopen("Base.txt", "w");
    char *line = malloc(sizeof(char) * Max);
    int i = 0;
    char *previous = malloc(sizeof(char) * Max);
    while (fgets(line, Max, fp) != NULL)
    {
        char *line2 = getLine(filename, i);
        int size;
        char **array = split(line2, &size);
        if (isNom(array[2]))
        {
            if (strcmp(previous, array[1]) != 0)
            {
                fprintf(fp2, "%s \n", array[1]);
                strcpy(previous, array[1]);
            }
        }
        i++;
    }
    fclose(fp);
    fclose(fp2);
}


char *getPhrasever1()
{
    char *phrase = malloc(100 * sizeof(char));
    char *nom = getNom("dictionnaire.txt");
    char *adj = getAdj("dictionnaire.txt");
    char *ver = getVer("dictionnaire.txt");
    char *nom2 = getNom("dictionnaire.txt");
    
    // split the line to get the base of the word
    
    int size;
    char **words = split(nom, &size);
    char *word = words[1];
    char **words2 = split(adj, &size);
    char *word2 = words2[1];
    char **words3 = split(ver, &size);
    char *word3 = words3[1];
    char **words4 = split(nom2, &size);
    char *word4 = words4[1];
    
    // concatenate the base of the word to the phrase
    
    strcat(phrase, word);
    strcat(phrase, " ");
    strcat(phrase, word2);
    strcat(phrase, " ");
    strcat(phrase, word3);
    strcat(phrase, " ");
    strcat(phrase, word4);
    return phrase;
}

//now we need to generate a phrase that has this order : Nom + "qui" + ver + ver + nom + adj

