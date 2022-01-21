#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

/* Um Banco de Dados simples para notas de alunos */

//constantes
#define CLASSES 2
#define GRADES 2

//Matriz - DB
int grade[CLASSES][GRADES];

//prototipos
void enter_grades(void);
int get_grade(int num);
void disp_grades(int g[][GRADES]);

//funcao principal
int main()
{
    char ch, str[80];

    for(;;)
    {
        do
        {
            printf("(D)igitar notas\n");
            printf("(M)ostrar notas\n");
            printf("(S)air\n");
            gets(str);
            ch = toupper(*str);
        }
        while(ch!='D' && ch!='M' && ch!='S');

        switch(ch) {
          case 'D':
            enter_grades();
            break;
          case 'M':
            disp_grades(grade);
            break;
          case 'S':
            exit(0); //return 0;
        }
    }
}

/* Saida da nota dos alunos */
void enter_grades(void)
{
    int t, i;
    for(t=0;t<CLASSES; t++){
        printf("Turma # %d:\n",t+1);
        for(i=0; i<GRADES; i++)
            grade[t][i] = get_grade(i);
    }
}

/* Entrada de uma nota de aluno */
get_grade(int num)
{
    char s[80];

    printf("Digite a nota do aluno # %d:\n",num+1);
    gets(s);
    return(atoi(s));
}

/* Mostra as notas */
void disp_grades(int g[][GRADES])
{
    int t, i;
    for(t=0; t<CLASSES; ++t){
        printf("Turma # %d:\n", t+1);
        for(i=0; i<GRADES; ++i)
            printf("Aluno #%d e %d\n", i+1, g[t][i]);
    }
}
