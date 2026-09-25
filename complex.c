#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

typedef struct Complex{
    int real;
    int complex;
}Complex;

int print(Complex A){
    char *x = "+";
    char result[50] = "";
    if (A.complex<0)
        x = "";
    printf("%d%s%di\n",A.real,x,A.complex);
    return 0;
}

Complex extract(char input[]){
    Complex values; int consumed = 0; int a = 0; int b = 0;
    if (sscanf(input, "%d+%di%n", &a, &b, &consumed) == 2 && input[consumed] == '\0'){
        values.real = a; values.complex = b;
    }else if (sscanf(input, "%d+i%d%n", &a, &b, &consumed) == 2 && input[consumed] == '\0'){
        values.real = a; values.complex = b;
    }else if (sscanf(input, "%d-i%d%n", &a, &b, &consumed) == 2 && input[consumed] == '\0'){
        values.real = a; values.complex = 0-b;
    }else if (sscanf(input, "%d-%di%n", &a, &b, &consumed) == 2 && input[consumed] == '\0'){
        values.real = a; values.complex = 0-b;
    }else if (sscanf(input, "%di+%d%n", &b, &a, &consumed) == 2 && input[consumed] == '\0'){
        values.real = a; values.complex = b;
    }else if (sscanf(input, "i%d+%d%n", &b, &a, &consumed) == 2 && input[consumed] == '\0'){
        values.real = a; values.complex = b;
    }else if (sscanf(input, "i%d-%d%n", &b, &a, &consumed) == 2 && input[consumed] == '\0'){
        values.real = 0-a; values.complex = b;
    }else if (sscanf(input, "%di-%d%n", &b, &a, &consumed) == 2 && input[consumed] == '\0'){
        values.real = 0-a; values.complex = b;
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

int addition(){
    printf("For addition of complex numbers.\n");
    printf("Each argument must be entered in the format 'a' or 'bi' where a and b are integers.\n Enter end to stop putting arguments\n");
    Complex compo; Complex output = {0}; char input[50] = "Empty";
    while(true){
        fgets(input, sizeof(input), stdin);
        if (strcmp(input, "end") != 0){
            compo = extract(input);
            output.real = output.real + compo.real;
            output.complex = output.complex + compo.complex;
        }
        else if (strcmp(input, "end") == 0)
            break;
        else{
            printf("Wrong input. Showing results for the rest if you have any.\n");
        }
    }
    print(output);
    return 0;
}

int multiplication(){
    printf("\nFor multiplication of complex numbers. \n");
    printf("Arguments must be passed one at a time. And in the format a+bi, a+ib or a or bi.\nEnter end to stop putting arguments.\n");
    char output[50] = "Empty"; char input[50] = "Empty"; Complex part1; Complex part2; Complex part3;
    fgets(output, sizeof(output), stdin);
    output[strcspn(output, "\n")] = '\0';
    part1 = extract(output);
    while(true){
        fgets(input, sizeof(input), stdin);
        input[strcspn(input, "\n")] = '\0';
        if (strcmp(input, "end") != 0){
            part2 = extract(input);
            part3.real = (part1.real*part2.real)-(part1.complex*part2.complex);
            part3.complex = (part1.real*part2.complex)+(part1.complex*part2.real);
            part1 = part3;
        }
        else if (strcmp(input, "end") == 0)
            break;
        else
            exit(1);
    }
    print(part1);
    return 0;
}

int main(){
    printf("Enter your choice between multiplication and addition\n");
    printf("1. For Addition. \n2. For Multiplication");
    char choice[5];
    fgets(choice, sizeof(choice), stdin);
    multiplication();
}
