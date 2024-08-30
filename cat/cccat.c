//step1: open a file specified on the command line and write its contents to the standard output
#include <stdio.h>
#include <string.h>

/**
* print_file: function to print the contest of the file
* @filename: the name of the file to be printed
* Return: None
 */

void print_file(const char* filename)
{
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        printf("Unable to open file %s\n", filename);
        return;
    }
    //Read and print the file content
    char ch;
    while ((ch = fgetc(file)) != EOF) {
        putchar(ch);
    }
    //close file 
    fclose(file);
}

/**
* main: main entry point
* @argc: the number of command line arguments
* @argv: the array of command line arguments
* Return: 0 if successful, non-zero otherwise
*/
int main(int argc, char *argv[])
{
    FILE *file;
    char ch;
    //check if the user has provided a filename
    if (argc != 2){
        printf("Usage: %s filename\n", argv[0]);
        return (1);
    }
    //open the file specified on the command line
    print_file(argv[1]);
    return (0);
}