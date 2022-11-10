#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "node.h"


node *createnode(char value) {

    // Allocating memory space for the node
    node *out = malloc(sizeof(node));

    // Checking if the node is null
    if (out != NULL) {

        // Assigning its char value
        out->value = value;

        // Nulling nodes to the children array
        for (int i=0; i<SIZE; i++) {

            out->children[i] = NULL;

        }
    }

    return out;
}