#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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

    FILE *fp = NULL; 
    unsigned long long n;
    unsigned char print_this, bflag;
    char content = 0;

    if(argc > 2)
    {
        if(!strcmp(argv[1], "-b"))
        {
            fp = fopen(argv[2], "r");
            bflag = 1;
        }
        else
        {
            fp = fopen(argv[1], "r");
            if(!strcmp(argv[2], "-b"))
                bflag = 1;
        }
    }
    else
    {
        fp = fopen(argv[1], "r");
    }

    if(!fp)
    {
       printf("\n%sError, file not found\n\n%s", "\x1B[31m", "\x1B[0m");
        return 1;
    }

    if(bflag)
    {
        printf("\n\n");
        for(n = 0; content != EOF || n%8 != 7; n++)
        {
            if(n%8 == 0)
            {
                if(n != 0)
                    printf(" ");
                content = fgetc(fp);
                print_this = content & 0x80;
                print_this = print_this>>7;
                print_this = itochar(print_this);
            }
            else if(n%8 == 1)
            {
                print_this = content & 0x40;
                print_this = print_this>>6;
                print_this = itochar(print_this);
            }
            else if(n%8 == 2)
            {
                print_this = content & 0x20;
                print_this = print_this>>5;
                print_this = itochar(print_this); 
            }
            else if(n%8 == 3)
            {
                print_this = content & 0x10;
                print_this = print_this>>4;
                print_this = itochar(print_this); 
            }
            else if(n%8 == 4)
            {
                print_this = content & 0x8;
                print_this = print_this>>3;
                print_this = itochar(print_this); 
            }
            else if(n%8 == 5)
            {
                print_this = content & 0x4;
                print_this = print_this>>2;
                print_this = itochar(print_this); 
            }
            else if(n%8 == 6)
            {
                print_this = content & 0x2;
                print_this = print_this>>1;
                print_this = itochar(print_this); 
            }
            else if(n%8 == 7)
            {
                print_this = content & 0x1;
                print_this = itochar(print_this); 
            }
            if(n%64 == 0 && n != 0)
                printf("\n");
            printf("%c", print_this);
        }

        print_this = content & 0x1;
        print_this = itochar(print_this); 
        printf("%c", print_this);
        printf("\n\n");
        fclose(fp);
        return 0;
    }

    for(n = 0; content != EOF; n++)
    {
        if(n%2 == 0)
        {
            content = fgetc(fp);
            print_this = content & 0xF0;
            print_this = print_this>>4;
            print_this = itochar(print_this);
        }
        else
        {
            print_this = content & 0xF;
            print_this = itochar(print_this);
        }

        if(n%4 == 0)
        {
            printf(" ");
            if(n%32 == 0)
            {
                printf("\n");
            }
        }
        printf("%c", print_this);
    }
    
    print_this = content &0xF;
    print_this = itochar(print_this);
    printf("%c", print_this);
    printf("\n\n");

    fclose(fp);
}
