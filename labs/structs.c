#include <stdio.h>
#include <stdlib.h>
#include <string.h>





struct cat 
{
    int age;
    char *name;
};

// prototype
struct cat *CreateCat (char *name, int age);



int main() {
    
    struct cat t;
    
    t.age = 13;
    t.name = "Tiramisu";
    
    
    printf("%d %s\n", t.age, t.name);
    
    /*struct cat *cPtr, c;
    // Points to address of k
    cPtr = &c;
    
    c.age = 12;
    c.name = "Kita";
    
    printf("%d %s\n", cPtr -> age, cPtr -> name);*/

    
    struct cat *k;
    
    k = (struct cat *) malloc(sizeof(struct cat));
    
    // k -> age means (*k).age
    k -> age = 12;
    
    k -> name = "Kita";
    
    printf("%d %s\n", k->age, k->name);
    
    
    
 
    
    struct cat *h = CreateCat("Hannah", 3);
    
    printf("%s\n", h -> name);
    
    free(k);
    free(h);
    
}


struct cat *CreateCat (char *name, int n)
{
    
    struct cat *h1;
    h1 = malloc(n * sizeof(struct cat ));
    
    h1 -> name = name;
   
    
    return h1;
    
};

