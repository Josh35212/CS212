#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Determine if a found word matches an input word by length and characters
int SearchForWord(char* word, int word_length, char* search_word)
{
    if (strlen(search_word) != word_length)
    {
        return 0;
    }
    for (int k = 0; k < word_length; k++)
    {
        if (word[k] != search_word[k])
        {
            return 0;
        }
    }
    return 1;
}

// Determine if character is a separator
int SeperatorFlag(char c)
{
    if (c == ' ' || c == ',' || c == '.' || c == '\n')
    {
        return 1;
    }
    return 0;
}

int main(int argc, char* argv[])
{
    if (argc < 3)
    {
        fprintf(stderr, "Format: \"%s\" \"filename\" \"word(s)\"\n", argv[0]);
        exit(1);
    }

    int counts[argc];
    for (int i = 0; i < argc; i++)
    {
        counts[i] = 0;
    }

    FILE* read_file = NULL;
    read_file = fopen(argv[1], "r");
    if (read_file == NULL)
    {
        fprintf(stderr, "\"%s\" is not a valid file.\n", argv[1]);
        exit(1);
    }

    fseek(read_file, 0, SEEK_END);
    int size = ftell(read_file);
    fseek(read_file, 0, SEEK_SET);

    char* buffer = malloc(sizeof(char) * (size + 1));
    fread(buffer, sizeof(char), size, read_file);

    int in_word = 0;
    int word_start = 0;
    for (int i = 0; i < size; i++)
    {
        if (SeperatorFlag(buffer[i]))
        {
            if (in_word == 1)
            {
                for (int j = 2; j < argc; j++)
                {
                    if (SearchForWord(&buffer[word_start], (i - word_start), argv[j]))
                    {
                        counts[j]++;
                    }
                }
            }
            in_word = 0;
        }
        else
        {
            if (in_word == 0)
            {
                word_start = i;
            }
            in_word = 1;
        }
    }
    
    // Final check
    if (in_word == 1)
    {
        for (int i = 2; i < argc; i++)
        {
            if (SearchForWord(&buffer[word_start], (size - word_start), argv[i]))
            {
                counts[i]++;
            }
        }
    }

    fclose(read_file);
    free(buffer);

    for (int i = 2; i < argc; i++)
    {
        fprintf(stdout, "The word \"%s\" occurs %d times.\n", argv[i], counts[i]);
    }
    
    return 0;
}