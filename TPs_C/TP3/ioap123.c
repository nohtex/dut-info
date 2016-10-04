#include "ioap123.h"

text define_size( int taille) {
 return malloc(taille+1);
}

//une fonction  qui ne d�borde pas et ne m�morise pas le '\n'
text read_line() {
  text txt;
  int lg;
  char phrase[256];
  fgets(phrase,256,stdin);
  lg=strlen(phrase);
  txt = define_size(lg);
  //�liminer le '\n' m�moris� par fgets si n�cessaire
  if (phrase[lg-1]=='\n') phrase[lg-1]=0;
  strcpy(txt,phrase);
  return txt;
}

int read_int() {
  text input_tmp;
  int entier;
  input_tmp=read_line();
  entier=atoi(input_tmp);
  return entier;
}

double read_double() {
  text input_tmp;
  double v;
  input_tmp=read_line();
  v=atof(input_tmp);
  return v;
}

void print_int(int entier) {
 printf("%i", entier);
}

void print_double(double dec) {
 printf("%lf",dec);
}

void print_char(char c) {
 printf("%c",c);
}

void print_text(text txt) {
  printf("%s",txt);
}

void print_newline() {
 printf("\n");
}

void print_addr(void * p){
  printf("%p",p);
}
