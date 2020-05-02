#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <math.h>

int main(void)
{
    float letters = 0;
    float sentences = 0;
    float words = 0;
    bool last_inc = false;

    string text = get_string("Text: ");
    for (int i = 0; i < strlen(text); i++)
    {
        if (text[i] == 46 || text[i] == 63 || text[i] == 33)
        {
            last_inc = false;
            words++;
            sentences++;
        }
        else if ((text[i] >= 65 && text[i] <= 90) || (text[i] >= 97 && text[i] <= 122))
        {
            letters++;
            last_inc = true;
        }
        else
        {
            if(last_inc == true) {
                words++;
                last_inc = false;
            }
        }
    }
    letters = letters / words * 100;
    sentences = sentences / words * 100;

    float grade = 0.0588 * letters - 0.296 * sentences - 15.8;

    if (grade < 1)
    {
        printf("Before Grade 1\n");
    } else if (grade > 16)
    {
        printf("Grade 16+\n");
    } else
    {
        int final_grade = roundf(grade);
        printf("Grade %i\n", final_grade);
    }
}


// Could use a lot of refining ~