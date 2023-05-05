#include <stdio.h>
#include <string.h>

#define d 256
#define q 101

int rabin_karp(char *text, char *pattern)
{
    int text_length = strlen(text);
    int pattern_length = strlen(pattern);
    int i, j;
    int pattern_hash = 0;
    int text_hash = 0;
    int h = 1;   
    for (i = 0; i < pattern_length - 1; i++)
    h = (h * d) % q;
    for (i = 0; i < pattern_length; i++)
    {
        pattern_hash = (d * pattern_hash + pattern[i]) % q;
        text_hash = (d * text_hash + text[i]) % q;
    }
    for (i = 0; i <= text_length - pattern_length; i++)
    {
        if (text_hash == pattern_hash)
        {
            for (j = 0; j < pattern_length; j++)
            {
                if (text[i + j] != pattern[j])
                break;                
            }
            if (j == pattern_length)
            return i;
        }

        if (i < text_length - pattern_length)
        {
            text_hash = (d * (text_hash - text[i] * h) + text[i + pattern_length]) % q;
            if (text_hash < 0)
            text_hash += q;
        }
    }
    return -1;
}

int main()
{
    char text[1000], pattern[1000];

    printf("Enter the text: ");
    fgets(text, 1000, stdin);
    printf("Enter the pattern to search for: ");
    fgets(pattern, 1000, stdin);
    text[strcspn(text, "\n")] = 0;
    pattern[strcspn(pattern, "\n")] = 0;
    int result = rabin_karp(text, pattern);
    if (result == -1)
    printf("Pattern not found in text.\n");
    else
    printf("Pattern found in text starting at index %d.\n", result);
    return 0;
}