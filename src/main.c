#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <inttypes.h>
#include "../dict/headers/dict.h"

// Making it work with nmake on windows
#ifdef _WIN32
#  ifdef _WIN64
#    define SIZE_T PRIu64
#  else
#    define SIZE_T PRIu32
#  endif
#else
#  define SIZE_T "llu"
#endif

typedef struct {
    char* name;
    char* pass;
    char* email;
    bool active;
} _User, * User;

User new_user(char* name, char* pass, char* email) {
    User user = malloc(sizeof(_User));
    user->active = true;
    user->name = name;
    user->pass = pass;
    user->email = email;
    return user;
}

char* user_return_email(User user) { return user->email; }

void free_user(Element ele) {
    free(ele);
}

int main() {
    Dict dict = new_dict(DEFAULT_SIZE);
    printf("Dict created with size: %" SIZE_T "\n\n", dict->size);

    //? Creating our user objects to be used as values for dict
    User john = new_user("John", "arrgh", "john@hotmail.com");
    User amber = new_user("Amber", "goldilocks", "amber@hotmail.com");
    User steve = new_user("Steve", "Plankton", "steve@hotmail.com");
    User slim = new_user("Slim", "Shovel", "slim@hotmail.com");

    //* Adding key:value pairs to dict
    dict_add(dict, "Amber", amber);
    dict_add(dict, "Steve", steve);
    dict_add(dict, "Slim", slim);
    int john_added = dict_add(dict, "John", john);
    printf("Add elements to dict, returning:\n");
    printf("    Success:              %d\n", john_added);

    // Dictionary supports hash collisions but keys have to be unique
    int jonh_readded = dict_add(dict, "John", john);
    printf("    Failure (key exists): %d\n\n", jonh_readded);

    //* Removing key from dict
    printf("Remove element from dict, returning:\n");
    int john_removed = dict_rem(dict, "John", free_user);
    int nonexistent_removed = dict_rem(dict, "Paulo", free_user);
    printf("    Success:               %d\n", john_removed);
    printf("    Failure (nonexistent): %d\n\n",
        nonexistent_removed);

    //* Searching means finding a node, dict_get will already return
    // node->element (the value from k:v pair)
    User john_user = dict_get(dict, "John");
    User amber_user = dict_get(dict, "Amber");
    printf("Find element in dict from key:\n");
    printf("    Success, returns pointer: %p\n", (void*)amber_user);
    printf("    Failure, returns pointer: %p\n\n", (void*)john_user);

    // Getting the object inside the node
    printf("Printing an object inside node\n");
    printf("    Name:  %s\n", amber_user->name);
    printf("    Pass:  %s\n", amber_user->pass);
    printf("    Email: %s\n\n", amber_user->email);

    //* Printing the dict
    printf("Printing the dict with NULL:\n");
    print_dict(dict, NULL, 4);
    printf("\nPrinting the dict with EMAIL:\n");
    print_dict(dict, (ER)user_return_email, 4);

    //? Freeing allocated memory for the users - not recommended
    // free(slim);
    // free(steve);
    // free(amber);
    // free(john);

    //* Freeing the entire dict from memory - recommended
    free_dict(dict, free_user);

    printf("\nProgram exited successfully\n");
    return 0;
}
