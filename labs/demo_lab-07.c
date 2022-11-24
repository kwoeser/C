/* CIS 212 Lab - Week 07 - Function Pointers
 * Author: S. Isaac Geronimo Anderson
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* Given */

void hello(char *name) {
    printf("Hello, %s!\n", name);
};

void ciao(char *name) {
    printf("Ciao, %s!\n", name);
};

void greeting(void (*f)(char *), char *name) {  // greeting takes a function
    f(name);                                    // pointer as an argument
};                                              // (which is f) and uses call
                                                // syntax () on it, passing in
                                                // the name argument.

                                                /* Challenge */
struct person {
    char *name;		            // "name" is the struct member identifier.
    void (*preferred) (char *); // "preferred" is the struct member identifier
                                // which is a function pointer for a function
                                // which takes a char * and has void return
                                // (which is perfect for hello and ciao, which
                                // each take a char * and have void return).
};



void greet(struct person *p) {  // This function takes a struct person pointer
    p->preferred(p->name);      // and accesses its "preferred" member, which
};                              // is a function pointer, meaning we can use
                                // call syntax () on it and pass in its own
                                // "name" member.

int main(int argc, char **argv) {
    
    
    
    printf("main is at 0x%p\n", main);  // This illustrates how main itself
                                        // (without using call syntax, ())
                                        // is a function pointer, with its own
                                        // memory address, which we could pass
                                        // or store as a value, (even though
                                        // I can't imagine right now how that
                                        // would be useful).
    printf("hello is at 0x%p\n", hello);// hello and ciao are also technically 
    printf("ciao is at 0x%p\n", ciao);  // function pointers, which we can
                                        // pass as values (such as to the
                                        // greeting function).

    hello("CIS 212");           // Fairly normal function call.
    ciao("Universe");           // Same here.

    greeting(hello, "Hank");    // Calling greeting with the hello function,
    greeting(ciao, "Boyana");   // and with the ciao function. This is not the
                                // same as calling hello or ciao, because we
                                // are not using call syntax () and so we are
                                // just passing pointers to these functions to
                                // greeting.

    void (*burrito)(char *) = hello;  // Creating a function pointer variable
    burrito("Birt");                  // named "burrito" with the same type as
                                      // the functions hello and ciao. Thus we
                                      // can call "burrito" as if it were a
                                      // function.

    struct person *p = (struct person *) malloc(sizeof (struct person));
    p->name = strdup("Dillinger");
    p->preferred = ciao;
    greet(p);

    // Clean up.
    if (p != NULL) {            // We can't free a NULL pointer, so check if
        if (p->name != NULL) {  // they are NULL before trying to free them.
            free(p->name);      // (The pointers would be NULL if malloc
        };                      // failed, which happens if there is no
        free(p);                // memory available, or some other error).
    };

    return 0;
};
