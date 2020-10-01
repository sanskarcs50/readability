#include<stdio.h>
#include<cs50.h>
#include<string.h>
#include<math.h>

int get_letters(string tex);
int get_words(string tex);
int get_sentences(string tex);
int get_index(string tex);


int main(void)
{
    // takes input form user
    string text = get_string("Text:");
    int index = get_index(text);
    //prints suitable utput
    if (index < 1)
    {
        printf("Before Grade 1\n"); // if index is smaller than 1
    }
    else if (index > 16)
    {
        printf("Grade 16+\n"); // if index is greater than 16
    }
    else
    {
        printf("Grade %i\n", index);
    }
    
}
//for counting letters
int get_letters(string tex)
{
    int length = strlen(tex);
    int letters = 0;
    for (int i = 0; i < length; i++)
    {
        if ((tex[i] >= (int)'a' && tex[i] <= (int)'z') || (tex[i] >= (int)'A' && tex[i] <= (int)'Z'))
        {
            letters++;
        }
       
    }
    return letters;
}
// for counting words
int get_words(string tex)
{
    int length = strlen(tex);
    int words = 0;
    for (int i = 0; i < length; i++)
    {
        if (tex[i] == ' ')
        {
            words++;
        }
    }
    return words + 1;
}
// for counting sentences
int get_sentences(string tex)
{
    int length = strlen(tex);
    int sentences = 0;
    for (int i = 0; i < length; i++)
    {
        if (tex[i] == '!' || tex[i] == '.' || tex[i] == '?')
        {
            sentences++;
        }
    }
    return sentences;
}
// for calculating index
int get_index(string tex)
{
    float L = (float) get_letters(tex) / get_words(tex) * 100;
    float S = (float) get_sentences(tex) / get_words(tex) * 100; 
    int index = round((0.0588 * L) - (0.296 * S) - 15.8);
    
    return index;
}
