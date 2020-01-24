#include <stdio.h>
#include <stdlib.h>

int main (int argc, char* argv[]) {
  //Stops if less than three terms are entered
  if (argc < 4) {
    printf("You must enter at least THREE terms!\n");
    return 0;
  }

  //Gets all terms in a list
  short int term = 0; //current term
  short int i; //index variable for loop
  int terms[argc-1]; //terms of the sequence
  for (i = 1; i < argc; i++) {
    term = atoi(argv[i]); //gets value as integer
    printf("%d ", term); //print integer
    terms[i-1] = term; //add to list
  }

  //Gets second difference
  int fdiff[argc-2]; //first difference
  int sdiff; //second difference
  for (i = 0; i < argc-2; i++) {
    fdiff[i] = terms[i+1] - terms[i];
  }
  sdiff = fdiff[1] - fdiff[0];
  for (i = 0; i < argc-3; i++) {
    if (fdiff[i+1] - fdiff[i] != sdiff) {
      printf("\nThis is not a quadratic sequence as the second difference is NOT constant!\n");
      return 0;
    }
  }
  float hsdiff = (float)sdiff / 2; //half the second difference
  printf("\nThe second difference is: %i\n", sdiff);
  printf("%i divided by 2 = %.2g\n", sdiff, hsdiff);
  printf("Thus %.2gn(squared)\n", hsdiff);

  //Prints terms of Xn squared
  float nsqrd; //Xn squared
  float diff[argc-1]; //quadratic minus Xn squared
  printf("|%.2gn(squared)\t|Sequence\t|Difference\t|\n", hsdiff);
  for (i = 0; i < argc-1; i++) {
    nsqrd = (float)hsdiff * (((float)i+1)*((float)i+1));
    printf("|%.2g\t\t|%i\t\t|%.2g\t\t|\n", nsqrd, terms[i], terms[i]-nsqrd);
    diff[i] = terms[i] - nsqrd;
  }

  //Prints the differences as a sequence
  printf("Thus: ");
  for (i = 0; i < argc-1; i++) {
    printf("%.2g, ", diff[i]);
  }

  //Gets the difference between the differences
  float ddiff = diff[1] - diff[0];
  printf("\nDifference: %.2g\n", ddiff);

  //Prints Tn
  for (i = 0; i <= 1; i++) {
    if (i == 0) {printf("Tn=%.2gn", ddiff);} //prints differences as a linear equation
    else { //prints the linear equation with Xn squared at the begining
      printf("\nTn=%.2gn(squared)", hsdiff);
      if (ddiff >= 0) {printf("+");}
      printf("%.2gn", ddiff);
    }
    if (diff[0]-ddiff >= 0){printf("+");}
    printf("%.2g", diff[0]-ddiff);
  }

  //Goes to a new line
  printf("\n");

  return 0;
}
