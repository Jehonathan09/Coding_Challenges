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
        //output an error meaasge if file can not be opened
        printf("Unable to open file %s\n", filename);
        return;
    }
    
    int ch;
    //Loop through the file and print each character until 
    //EOF is reached
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
    //check if the program is called with the correct 
    //number of arguments
    if (argc < 2){
        // Print usage information if no filenames are provided
        printf("Usage: %s filename1 [filename2 ...]\n", argv[0]);
        return (1);
    }

    //Loop through the provided filenames and print their content
    for (int i = 1; i < argc; ++i){
        //print the current filename
        printf(argv[1]);
        //Call the function to print the contents of the file
        print_file(argv[i]);
        //print a newline character to separate the filenames
        printf("\n");
        
    }
    
    return (0);
}