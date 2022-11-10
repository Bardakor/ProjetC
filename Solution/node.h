#include <stdlib.h>
#include <stdio.h>
#include <string.h>

//define size of 26
#define SIZE 26

typedef struct node {
    char value;
    struct node *children[SIZE];
    char conjugates[50];
} node;

