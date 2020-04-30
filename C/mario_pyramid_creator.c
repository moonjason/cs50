#include <stdio.h>
#include <cs50.h>

void make_line(int height, int line)
{
    for(int i = 0; i < height + 2 + line + 1; i++)
    {
        if( i < height - line - 1 || i == height || i == height + 1 )
        {
            printf(" ");
        }
        else if (i == height + 2 + line)
        {
            printf("#\n");
        }
        else
        {
            printf("#");
        }
    }
}

int main(void)
{
    int height;
    do
    {
        height = get_int("What is the Height?");
    }
    while(height < 1);

    for(int i = 0; i < height; i++)
    {
        make_line(height, i);
    }
}