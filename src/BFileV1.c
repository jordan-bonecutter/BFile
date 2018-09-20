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
	// If the arg count is too low
    if(argc < 2)
    {
        printf("\n%sUsage: ./BFile <filepath>%s\n\n", "\x1B[31m", "\x1B[0m");
        return 1;
    }

    FILE *fp = fopen(argv[1], "r");
    unsigned long long fl, n;
    char c = 'A', ct = 0; 

	// If the file doesn't exist
    if(!fp)
    {
       printf("\n%sError, file not found\n\n%s", "\x1B[31m", "\x1B[0m");
        return 1;
   	}

	while(c != EOF)
	{
		c = fgetc(fp);
		printf("%c", itochar(c & 0x0F));
		printf("%c", itochar(c>>4 & 0x0F));
		ct += 2;
		if(ct%4 == 0)
		{
			printf(" ");
			if(ct % 32 == 0)
			{
				printf("\n");
				ct = 0;
			}
		}
	}
    
    fclose(fp);
}
