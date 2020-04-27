#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define BUFFER 10
#define WORKINGS if(workings)
#define sqrd(n) (n)*(n)

int is_int(char* str);

/* quadeq: get equation from a quadratic sequence in the form Tn=Xn^2-Xn-X */
int main (int argc, char* argv[]) {
  int i;              /* index variable */
  int terms[BUFFER];  /* list of terms */
  int n = 0;          /* number of terms */
  char workings = 0;  /* show workings */
  float fdiff;        /* first difference */
  float sdiff;        /* second difference */
  float tmp;          /* temporary storage */
  float ddiff;        /* difference between differences */

  for (i=1; i<argc && n<=BUFFER-1; i++) {  /* check arguments */
    if (is_int(argv[i])) { /* add terms to list */
      terms[n] = atoi(argv[i]);
      n++; continue;
    }
    switch (argv[i][1]){  /* check flags */
      case 'w': workings=1;continue;
      default:
        if (strcmp(argv[i], "--help")==0){  /* help option */
          printf("Usage: quadeq [-w show_workings] TERMS\nGet the Nth term for a quadratic sequence in the form Tn=Xn^2-Xn-X\nExample: quadeq -w 1 3 9 19\n"); return 0;
        }
        else {printf("Usage: quadeq [-w show_workings] TERMS\nTry 'quadeq --help' for more information.\n"); return 1;} /* unknown argument */
    }
  }

  if (n < 3) {printf("error: less than three terms entered\n"); return 1;}  /* stops if less than three terms entered */

  WORKINGS{printf("First differences: ");}
  for (i=0; i<n-1; i++){  /* gets second difference */
    if (i%2){ /* every second loop */
      tmp = (terms[i+1]-terms[i])-fdiff;  /* calculates second difference */
      if (sdiff != tmp && i != 1) {/* checks second difference is constant */
        printf("\nerror: second difference not constant\n");return 1;
      }
      else {sdiff = tmp;}
    }
    fdiff = terms[i+1]-terms[i];
    WORKINGS{printf("%g ", fdiff);}
  }
  WORKINGS{printf("\nSecond difference: %i\n", (int)sdiff);}
  sdiff /= 2; /* half second difference */
  WORKINGS{
    printf("Divide by 2: %g\n", sdiff);
    printf("|%gn^2\t\t|Sequence\t|Difference\t|\n", sdiff);
  }

  for (i=0; i<2; i++){  /* compares Xn^2 to sequence */
    if (i){ /* on second loop */
      ddiff = (terms[i]-sdiff*sqrd(i+1))-fdiff; /* difference between differences */
      tmp = fdiff; /* stores first difference */
    }
    if (!i || workings) {fdiff = terms[i]-sdiff*sqrd(i+1);} /* difference between current term and sequence */
    WORKINGS{printf("|%g\t\t|%i\t\t|%.2g\t\t|\n", sdiff*sqrd(i+1), terms[i], fdiff);}
  }
  WORKINGS{
    printf("Difference between differences: %g\n", ddiff);
    printf("Difference as sequence: Tn=%gn", ddiff);  /* difference between differences as sequence */
    if(tmp-ddiff >= 0){putchar('+');} /* adds plus sign if necisary */
    printf("%g\n", tmp-ddiff);
  }
  printf("Tn=%gn^2", sdiff);  /* answer */
  if (ddiff >= 0) {putchar('+');} /* adds plus sign if necisary */
  printf("%gn", ddiff);
  if(tmp-ddiff >= 0){putchar('+');} /* adds plus sign if necisary */
  printf("%g\n", tmp-ddiff);

  return 0;
}

/* is_int: checks if a string is an integer */
int is_int(char* str) {
  if (*str == '-' || *str == '+'){str++;}
  while(*str!='\0') {
    if (!isdigit(*str)){return 0;}  /* not an integer*/
    str++;
  }
  return 1; /* is an integer */
}
