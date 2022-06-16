#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "../dict/headers/dict.h"

typedef struct {
    char* name;
    char* pass;
    char* email;
    bool active;

}_User, * User;

User new_user(char* name, char* pass, char* email) {
    User user = malloc(sizeof(_User));
    user->active = true;
    user->name = name;
    user->pass = pass;
    user->email = email;
    return user;
}

char* user_return_email(User user) {
    return user->email;
}

int main() {
    Dict dict = new_dict(DEFAULT_SIZE);
    printf("Dict created with size: %llu\n\n", dict->size);

    //? Creating our user objects to be used as values for dict
    User john = new_user("John", "arrgh", "john@hotmail.com");
    User amber = new_user("Amber", "goldilocks", "amber@hotmail.com");
    User steve = new_user("Steve", "Plankton", "steve@hotmail.com");
    User slim = new_user("Slim", "Shovel", "slim@hotmail.com");

    //* Adding key:value pairs to dict
    int john_added = dict_add(dict, "John", john);
    dict_add(dict, "Amber", amber);
    dict_add(dict, "Steve", steve);
    dict_add(dict, "Slim", slim);
    printf("Add success, code: %d\n", john_added);

    // Dictionary supports hash collisions but keys have to be unique
    int jonh_readded = dict_add(dict, "John", john);
    printf("Add failure (key exists), code: %d\n\n", jonh_readded);

    //* Removing key from dict
    int john_removed = dict_rem(dict, "John");
    int nonexistent_removed = dict_rem(dict, "Paulo");
    printf("Remove success, code: %d\n", john_removed);
    printf("Remove failure (key doesn't exist), code: %d\n\n", nonexistent_removed);

    //* Searching means finding a node, dict_find will already return node->element (the value from k:v pair)
    User john_user = dict_find(dict, "John");
    User amber_user = dict_find(dict, "Amber");
    printf("Find success, returns pointer: %p\n", (void*)amber_user);
    printf("Find failure, returns pointer: %p\n\n", (void*)john_user);

    // Getting the object inside the node
    printf("John details:\n Name: %s\n Pass: %s\n Email: %s\n\n", amber_user->name, amber_user->pass, amber_user->email);
    // free(amber_user);
    // free(john_user);

    //* Printing the dict
    printf("Printing the dict with NULL:\n");
    print_dict(dict, NULL);
    printf("\nPrinting the dict with EMAIL:\n");
    print_dict(dict, (ER)user_return_email);

    //? Freeing allocated memory for the users
    free(slim);
    free(steve);
    free(amber);
    free(john);

    //* Freeing the entire dict from memory
    free_dict(dict);

    printf("\nProgram exited successfully\n");
    return 0;
}