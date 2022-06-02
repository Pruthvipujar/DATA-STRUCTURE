#include<stdio.h>
#include<string.h>

int checkMatches(char string[], char pattern[])
{
    int stringl, patternl, i, j, flag=0;
    stringl = strlen(string);
    patternl = strlen(pattern);
    if (stringl==patternl)
        {
        if (strcmp(string, pattern)==0)
        {
            printf("They both are the same string!\n");
            return 0;
        }
        }

    for (i=0; i<stringl-patternl+1; i++)
        {
        j=0;
        while (j<patternl && pattern[j]==string[j+i])
        {
            j++;
        }

        if (j==patternl)
        {
            flag = 1;
            printf("Pattern Matches!\n");
        }
    }
    if (flag==0) {
        printf("Pattern doesn't match!\n");
    }
    return 0;
}

int main()
{
    char str[50], pattern[50];
    printf("Enter the string: ");
    scanf("%s", str);
    //gets(str);
    printf("Enter the pattern: ");
    scanf("%s", pattern);
    //gets(pattern);
    checkMatches(str, pattern);

}
