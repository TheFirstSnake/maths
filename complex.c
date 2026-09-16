#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Complex{
  int real = 0;
  int complex = 0;
}Complex;

int addition(){
  printf("For addition of complex numbers.\n");
  printf("Each argument must be entered in the format 'a' or 'bi' where a and b are integers.\n Enter end to stop putting arguments\n");
  int a = 0; int b = 0; int n = 0; char input[50] = "Empty"; char *end;
  while(n==0){
    scanf("49%s",input);
    n = strtol(input, &end, 10);
    if (strcmp(end, "i") == 0){
      if(n == 0)
      n = 1;
      b = b + n;
      printf("+");
      n = 0;
     }
    else if (strcmp(end, "") == 0){
      a = a + n;
      printf("+");
      n = 0;
     }
    else if (strcmp(end, "end") == 0)
      n++;
    else{
      printf("Wrong input. Showing results for the rest if you have any.\n");
      n++;
     }
    }
  printf("%d+%di\n", a, b);
  return 0;
}

Complex real(char input[]){
  Complex values; int consumed = 0; int a = 0; int b = 0;
    if (sscanf(input, "%d+%di%n", &a, &b, &consumed) == 2 && input[consumed] == '\0'){
    values.real = a; values.complex = b;
    }else if (sscanf(input, "%d+i%d%n", &a, &b, &consumed) == 2 && input[consumed] == '\0'){
    values.real = a; values.complex = b;
    }else if (sscanf(input, "%d-i%d%n", &a, &b, &consumed) == 2 && input[consumed] == '\0'){
    values.real = a; values.complex = 0-b;
    }else if (sscanf(input, "%d-%di%n", &a, &b, &consumed) == 2 && input[consumed] == '\0'){
    values.real = a; values.complex = 0-b;
    }else if (sscanf(input, "%di%n", &b, &consumed) == 1 && input[consumed] == '\0'){
    values.real = a; values.complex = b;
    }else if (sscanf(input, "i%d%n", &b, &consumed) == 1 && input[consumed] == '\0'){
    values.real = a; values.complex = b;
    }else if (sscanf(input, "%d%n", &a, &consumed) == 1 && input[consumed] == '\0'){
    values.real = a; values.complex = b;
    }else {
    printf("Crashed, not taken. Error, error");
    exit(1);
   }
  return values;
}

int multiplication(){
  printf("For multiplication of complex numbers. \n");
  printf("Arguments must be passed one at a time. And in the format a+bi, a+ib or a or bi.\n Enter end to stop putting arguments.\n");
  char output[50] = "Empty"; char input[50] = "Empty"; char compA[25] = ""; char compB[25] = "";
  int a = 0; int b = 0; int c = 0; int d = 0; int x = 0; int y = 0;
  fgets(output, sizeof(input), stdin);
  output[strcspn(output, "\n")] = '\0';
  while(true){
    fgets(input, sizeof(input), stdin);
    input[strcspn(input, "\n")] = '\0';
    if (strcmp(input, "end") != 0){
      a = real(output);
      b = complex(output);
      c = real(input);
      d = complex(input);
      x = (a*c)-(b*d);
      y = (a*d)+(b*c);
      snprintf(compA, sizeof(compA), "%d", x);
      snprintf(compB, sizeof(compB), "%d", y);
      strcpy(output, "");
      strcat(output, compA);
      strcat(output, "+");
      strcat(output, compB);
      strcat(output, "i");
     }
    else if (strcmp(input, "end") == 0)
      break;
    else
      exit(1);
   }

  printf("%s",output);
  return 0;

}

int output(Complex A){



int main(){
  multiplication();
}
