#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//variable to check if question has already been answered
//hasBeenAnswered is initialized to -1 once question is answered
//user can only answer question if hasBeenAnswered != -1
int hasBeenAnswered;

int main()
{

    //variables hold values of possible valid inputs
    char *north = "NORTH";
    char *south = "SOUTH";
    char *east = "EAST";
    char *west = "WEST";
    char *balance = "GOLD";
    char *answer = "printf%28%22Give+me+the+Campbell+life%21%22%29%3B";

    //variable to store amount of gold
    int gold;

    //store input from user
    char *input =  (getenv("QUERY_STRING")); 

    //parse input from user
    char *token = strtok(input, "=&");
    char *field[4];        
    field[1] = " ";
    int i=0;
    while (token != NULL)
    {
        field[i] = token;        
        token = strtok(NULL,"=&");
        i++;
    }    

    if(strcmp(field[2], "gold")==0)
    {
        gold = atoi(field[3]); //user came from another room
    }
    else if(strcmp(field[1], "gold")==0)
    {
        gold = atoi(field[2]); //there was no input
    }
    else
    {
        gold = 10; //user came directly to this room
    }
    
    printf("Content-Type:text/html\n\n");
    printf("<html>");
    printf("<body><center>");
    
    //after determining user input, make correct response
    if(strcmp(field[1], north) == 0) //input is "NORTH"
    {
        printf("<a href='https://www.cs.mcgill.ca/~akermo/cgi-bin/addgold.cgi?gold=%d'>Click HERE to go NORTH</a>", gold); 
    }
    else if(strcmp(field[1], south) == 0) //input is "SOUTH"
    {       

        printf("<a href='https://www.cs.mcgill.ca/~eaugus2/cgi-bin/addgold.cgi?gold=%d'>Click HERE to go SOUTH</a>", gold);
    }
    else if(strcmp(field[1], east) == 0) //input is "EAST"
    {
        printf("<a href='https://www.cs.mcgill.ca/~mstron1/cgi-bin/addgold.cgi?gold=%d'>Click HERE to go EAST</a>", gold);
    }
    else if(strcmp(field[1], west) == 0) //input is "WEST"
    {
        printf("<a href='https://www.cs.mcgill.ca/~cmulle8/cgi-bin/addgold.cgi?gold=%d'>Click HERE to go WEST</a>", gold);
    }
    else if(strcmp(field[1], balance) == 0) //input is "GOLD"
    {
        printf("<h1>You have %d gold</h1><br>", gold);
        printf("<img src='../chest.jpg' alt='chest' height='200' width='200'><br>");
        printf("<br/><a href='https://cs.mcgill.ca/~dpeter19/cgi-bin/addgold.cgi?gold=%d'>Click Here to go back</a>", gold);
    }
    else if(strcmp(field[1], answer) == 0) //input was correct answer
    {	
    	gold+=10; //correct answer, gain 10 gold
	if(gold>=100)
      	{	    	
       	    printf("Correct answer!<br>");
	    printf("You now have %d gold and you have won the game!", gold);    
       	}
        else
        {		
    	    printf("<h1>Correct answer!</h1>");
            printf("<h3>You now have %d gold!</h3>", gold);
	    printf("<br><img src='../coins.jpg' alt='coins' heigt='200' width='200'>");
            printf("<br/><a href='https://cs.mcgill.ca/~dpeter19/cgi-bin/addgold.cgi?gold=%d'>Click Here to go back</a>", gold);
        }         
    }    
    else
    {        
        if(gold<=0)
        {       	    
            printf("<h1>Wrong asnwer!</h1>");    
            printf("<h3>You don't have enough gold to pay! You have lost the game!</h3>");
	    printf("<br><img src='../skull.jpg' alt='skull' height='300' width='200'>");
        }
        else
        {            
	    gold-=5; //wrong answer, lose 5 gold
            printf("<h1>Wrong answer! You lose 5 gold!</h1>");
	    printf("<h3>You now have %d gold.</h3>", gold);
	    printf("<img src='../x.jpg' alt='x' height='200' width='200'>");
            printf("<br/><a href='https://cs.mcgill.ca/~dpeter19/cgi-bin/addgold.cgi?gold=%d'>Click Here to go back</a>", gold);
        }     	
    }
    
    printf("</center></body>");
    printf("</html>");
    return 0;
}



