/* CS 212 Lab - Week 06 - Structs
   Lab leader example.

   Authors: S. Isaac G. Anderson (Fall 2022)
*/

#include <stdio.h>
#include <stdlib.h>

/* These are examples of bad enum values
   so you know what bad ones look like . (: */
enum year
{
  FRESHIE, //0 
  SOPHO,   //1
  JUNI,    //2
  OLD,     //3
  SUPER    //4
};

/* Struct definition will go here. */
struct student 
{
    char *name;
    int id;
    enum year year;
};



/* We're hardcoding everything, so no argc/argv. */
int main()
{
    
    
    
  struct cat 
  {
    int age;
    char *name;
    
  };

  printf("Non-struct versions:\n");

  /* Let's define some student information. */
  char *student_name = "Kara";
  int student_id = 950000003;
  enum year student_year = SUPER;

  /* Print the student information. */
  printf("Name: %s\n", student_name);
  printf("ID: %d\n", student_id);
  printf("Year: %d\n", student_year);
  printf("\n");

  /* What if we wanted several students, together? */
  int n = 3;
  char **names = malloc(n * sizeof (char *));
  int *ids = malloc(n * sizeof (int));
  enum year *years = malloc(n * sizeof (enum year));

  names[0] = "Thea";
  ids[0] = 950000000;
  years[0] = SOPHO;

  names[1] = "Mia";
  ids[1] = 950000001;
  years[1] = FRESHIE;

  names[2] = "Laurel";
  ids[2] = 950000002;
  years[2] = JUNI;

  /* Print everything. */
  for (int i = 0; i < n; i++)
  {
    printf("Index: %d\n", i);
    printf("Name: %s\n", names[i]);
    printf("ID: %d\n", ids[i]);
    printf("Year: %d\n", years[i]);
    printf("\n");
  }

  printf("Struct versions:\n");

  /* Now do the above, but with a student struct,
     defined outside main, and used in a student struct array. */

  struct student studentK;
  studentK.name = "Kara";
  studentK.id = 95000003;
  student.K.year = SUPER;
  
  
  /* Print the student information. */
  printf("Name: %s\n", studentK.name);
  printf("ID: %d\n", studentK.id); 
  printf("Year: %d\n", studentK.year);
  printf("\n");
  
  /* Create a student struct array. */
  struct students *students = malloc(n*sizeof(struct student));
    students[0].name = "Thea";
    students[0].id = 950000000;
    students[0].year = SOPHO;
  
  /* Print everything. */
   for (int i = 0; i < n; i++)
  {
    printf("Index: %d\n", i);
    printf("Name: %s\n", students[i].name);
    printf("ID: %d\n", students[i].id);
    printf("Year: %d\n", students[i].year);
    printf("\n");
  }
  
  

  /* Clean up. */
  if (names) free(names);
  if (ids) free(ids);
  if (years) free(years);
  if (students) free(students);

  return EXIT_SUCCESS;
}
