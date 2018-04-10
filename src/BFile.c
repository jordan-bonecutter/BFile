#include <stdio.h>
#include <stdlib.h>

char itochar(char i)
{
    switch (i)
    {
        case 0:
        {
            return '0';
        }
        case 1:
        {
            return '1';
        }
        case 2:
        {
            return '2';
        }
        case 3:
        {
            return '3';
        }
        case 4:
        {
            return '4';
        }
        case 5:
        {
            return '5';
        }
        case 6:
        {
            return '6';
        }
        case 7:
        {
            return '7';
        }
        case 8:
        {
            return '8';
        }
        case 9:
        {
            return '9';
        }
        case 10:
        {
            return 'A';
        }
        case 11:
        {
            return 'B';
        }
        case 12:
        {
            return 'C';
        }
        case 13:
        {
            return 'D';
        }
        case 14:
        {
            return 'E';
        }
        case 15:
        {
            return 'F';
        }
        default:
        {
            return '?';
        }
    }
}

int main(int argc, char *argv[])
{
    if(argc < 2)
    {
        printf("\n%sUsage: ./BFile <filepath>%s\n\n", "\x1B[31m", "\x1B[0m");
        return 1;
    }

    FILE *fp = fopen(argv[1], "r");
    unsigned long long fl, n;
    char *contents = NULL;
    unsigned char *converted_contents = NULL;

    if(!fp)
    {
       printf("\n%sError, file not found\n\n%s", "\x1B[31m", "\x1B[0m");
        return 1;
    }

    fseek(fp, 0, SEEK_END);
    fl = ftell(fp);
    fseek(fp, 0, SEEK_SET);

    contents = malloc(fl);
    converted_contents = calloc(fl<<1, 1);

    for(n = 0; n < fl; n++)
    {
        contents[n] = fgetc(fp);
    }
    
    fclose(fp);

    for(n = 0; n < fl<<1; n++)
    {
        if(n%2 == 0)
        {
            converted_contents[n] = contents[n>>1] & 0xF0;
            converted_contents[n] = converted_contents[n]>>4;

            converted_contents[n] = itochar(converted_contents[n]);
        }
        else
        {
            converted_contents[n] = contents[n>>1] & 0xF;
            
            converted_contents[n] = itochar(converted_contents[n]);
        }
    }

    free(contents);

    for(n = 0; n < fl<<1; n++)
    {
        printf("%c", converted_contents[n]);
        if(n % 16 == 0)
        {
            printf("\n");
        }

        if(n % 4 == 0)
        {
            printf(" ");
        }
    }

    printf("\n\n");
   
    free(converted_contents);
}
