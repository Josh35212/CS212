#include <stdio.h>
#include <stdlib.h>

int main(int argc, char* argv[])
{
    if (argc != 3)
    {
        fprintf(stderr, "Format: <%s> <input-filename> <output-filename>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    char* in_file = argv[1];
    char* out_file = argv[2];
    
    FILE* read_in_file = NULL;
    FILE* write_out_file = NULL;

    read_in_file = fopen(in_file, "r");
    if (read_in_file == NULL)
    {
        fprintf(stderr, "Error: unable to open %s\n", in_file);
        exit(EXIT_FAILURE);
    }

    write_out_file = fopen(out_file, "w");
    if (write_out_file == NULL)
    {
        fprintf(stderr, "Error: unable to open %s\n", out_file);
        exit(EXIT_FAILURE);
    }

    int buffer[5];

    for (int i = 0; i < 5; i++)
    {
        fseek(read_in_file, sizeof(int) * i * 10, SEEK_SET);
        fread(buffer, sizeof(int), 5, read_in_file);
        for (int j = 0; j < 5; j++)
        {
            fprintf(write_out_file, "%d\n", buffer[j]);
        }
    }

    fclose(read_in_file);
    fclose(write_out_file);

    return 0;
}