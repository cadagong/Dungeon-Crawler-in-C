#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    //store data package
    char *input =  (getenv("QUERY_STRING"));     

    char *token = strtok(input, "=");
    char *field[2];    
    int i=0;
    while (token != NULL)
    {
        field[i] = token;        
        token = strtok(NULL,"=");
        i++;
    }       

    //store amount of gold in variable
    int gold = atoi(field[1]); 

    //open index.html file and printf all lines to create webpage
    FILE *html = fopen("../index.html", "rt");
    char line[500]; //store next line of html file        

    printf("Content-Type:text/html\n\n");          

    //start printing lines
    fgets(line, 499, html);
    for(int i=1; i<30; i++)
    {
        printf("%s", line);
        fgets(line, 499, html);
    }    

    //printf the hidden field
    printf("<input type='hidden' name='gold' value='%d'>\n", gold);

    //now finish printing index.html file    
    while(!(feof(html)))
    {
        printf("%s", line);
        fgets(line, 499, html);
    }    
    return 0;
}



