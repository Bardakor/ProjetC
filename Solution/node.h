#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Name
{
    char *noun;
    char *type;
    char *genre;
    char *number;
} Name;

typedef struct Verb
{
    char *verb;
    char *type;
    char *tense;
    char *number;
    char *person;
} Verb;

typedef struct Adj
{
    char *adj;
    char *type;
    char *genre;
    char *number;
} Adj;

typedef struct Adv
{
    char *adv;
    char *type;
} Adv;

typedef struct multipleverb
{
    char *verb;
    char *type;
    
    //revenir dessus plus tard
} multipleverb;

