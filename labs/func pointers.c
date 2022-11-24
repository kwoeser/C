#include <stdio.h>
#include <stdlib.h>
#include <string.h>


void favoriteFood (char *s) {
    printf("My favorite food is %s\n", s);
}


void favoriteMovie (char *s) {
    printf("My favorite movie is %s\n", s);
}


void favoriteSong (char *s) {
    printf("My favorite song is %s\n", s);
}


void favoriteSport (char *s) {
    printf("My favorite sport is %s\n", s);
}



struct person {
    char *name;		// "name" is the struct member identifier.
    char *answer1;
    char *answer2;
    void (*favorite1) (char *);
    void (*favorite2) (char *);
        
};




void intro(struct person *p) { 
    p->favorite1(p->answer1); 
    p->favorite2(p->answer2);
}

   
   

int main(int argc, char **argv) {
    
    
    struct person *p = (struct person *) malloc(sizeof (struct person));
    
    p->name = strdup("Karma");
    printf("Hello, my name is\n", p->name);
    p->answer1 = "Basketball";
    p->answer2 = "La Haine";
    p->favorite1 = favoriteSport;
    p->favorite2 = favoriteMovie;
    intro(p);
    
    p->name = strdup("Lincoin");
    printf("Hello, my name is\n", p->name);
    p->answer1 = "Pasta";
    p->answer2 = "Marvel";
    p->favorite1 = favoriteFood;
    p->favorite2 = favoriteMovie;
    intro(p);
    
    

    
    
    
    
    // Clean up.
    if (p != NULL) {            // We can't free a NULL pointer, so check if
        if (p->name != NULL) {  // they are NULL before trying to free them.
            free(p->name);      // (The pointers would be NULL if malloc
        };                      // failed, which happens if there is no
        free(p);                // memory available, or some other error).
    };
    
    
    
    
}
