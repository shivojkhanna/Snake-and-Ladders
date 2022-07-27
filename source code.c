//	Hi, My name is Shivoj Khanna.												//mail - shivojkhanna@gmail.com
//	Here is the source code of snake and ladders game in C language by me.		//Whatsapp - 7497052589
//I have written this code in Visual Studio Ultimate IDE


#include<stdio.h>
#include<conio.h>
#include<time.h>			//time library,it was used to get the random number of dice. I've further explained  it in the dice function
#include<stdlib.h>
int dice();					//dice function for getting the dice
int snake(int);				//Snake function 
int ladder(int);			//Ladder function
int arr[10][10],i,j,p1=0,p2=0;	//	Array function to get the 1 to 100 counting
void counting()
{
	printf("\n\n");
	int k=100;		// K will print in back form from 100 to 1 in a specific way of the game
	for(i=0;i<10;i++)
	{
		for(j=0;j<10;j++)
		{
			arr[i][j]=k;	//	arr[0][0]	-	arr[0][9]	=	100-91,80-71,60-51,40-31,20-11
			k--;
		}
		i++;	
		k=k-9;		//	k=90-9=	81
		for(j=0;j<10;j++)
		{
			arr[i][j]=k;	//	arr[1][0]	-	arr[1][9]	=	81-90,61-70,41-50,21-30,1-10
			k++;
		}
		k=k-11;
	}
	printf("\n____________________________________________________________________________\n\n");
	for(i=0;i<10;i++)
	{
		for(j=0;j<10;j++)
		{
			if(arr[i][j]==p1)
			{
				printf("\033[0;33m");
				printf("P1\t");
				printf("\033[0m");
			}
			else if(arr[i][j]==p2)
			{
				printf("\033[0;33m");
				printf("P2\t");
				printf("\033[0m");
			}
			else
			{
				printf("%d\t",arr[i][j]);
			}
		}
		printf("\n");
	}
	printf("\n____________________________________________________________________________\n");
}

int ladder(int a)
{
	if(a==80)
	{
		a=99;
		printf("\033[0;32m");		//To print in green, where"\033[0:m" means color function and "32" before m is a color Code for GReen Color
		printf("\nLadder-	80	to	99\n");
		printf("\033[0m");			//end of prinnt green function
	}
	else if(a==2)
	{
		a=38;
		printf("\033[0;32m");
		printf("\nLadder-	2	to	38\n");
		printf("\033[0m");
	}
	else if(a==28)
	{
		a=76;
		printf("\033[0;32m");
		printf("\nLadder-	28	to	76\n");
		printf("\033[0m");
	}
	else
	{
		a=a;
	}
	return (a);
}
int snake(int a)
{
	if(a==97)
	{
		a=78;
		printf("\033[0;31m");		//To print in Red, where"\033[0:m" means color function and "31" before m is a color Code for Red Color
		printf("\nSnake	-	97	to	78\n");
		printf("\033[0m");			//End of print Red function
	}
	else if(a==88)
	{
		a=24;
		printf("\033[0;31m");
		printf("\nSnake	-	88 to 24\n");
				printf("\033[0m");
	}
	else if(a==62)
	{
		a=18;
		printf("\033[0;31m");
		printf("\nSnake	-	62	to	18\n");
				printf("\033[0m");
	}
	else if(a==34)
	{
		a=6;
		printf("\033[0;31m");
		printf("\nSnake	-	34	-	6\n");
				printf("\033[0m");
	}
	else
	{
		a=a;
	}
	return(a);
}
void main()
{  		system("cls");		//to clear the screen. this "system" function is in <stdlib.h> lib
		int ch,t;
	printf("\t\t\tSnake and Ladders Game:\nRules:\n1. There will be 2 players.\n2. Dice values from 1-6.\n3.Players have to reach 100 to win.\n4.There are snakes to bring you down and Ladders to take you up.\n");
	start: //	label start, to use goto function to print counting with updated player position
	counting();		//calling the counting function
	 printf("\nSnake:	97-78	88-24	62-18	34-6\nLadder:	80-99	2-38	28-76\n\n");
	printf("Press 1 for 1st player, 2 for 2nd and 8 for exit:\t");
	scanf("%d",&ch);
	switch(ch)
	{
	case 1:
		printf("Player 1.\n");
		t=p1;		//t = temporary, in case number exceeds 100, then to agin make it come back at its last position
		p1=p1+dice();	//player position after every dice
		if(p1==100)
		{
		 system("cls");
		printf("\nPosition of P1=%d\n",p1);
		printf("\nDice= %d\n",dice());
		printf("Player 1 win\n");
		}
		else if(p1>100)
		{
		 p1=t;
		 system("cls");
		printf("\n\tDice= %d\n",dice());
		 printf("\nPosition of P1=%d\n",p1);
		 goto start;
		}
		else
		{
		 system("cls");
		 p1=snake(p1);
		p1=ladder(p1);
		 printf("\n\t\tDice= %d\n",dice());
		printf("\nPosition of P1=%d\n",p1);
		goto start; }
		break;
	case 2:
		printf("Player 2.\n");
		t=p2;	//t = temporary, in case number exceeds 100, then to agin make it come back at its last position
		p2=p2+dice();
		if(p2==100)
		{
		 system("cls");
			printf("\nDice= %d\n",dice());
		printf("\nPosition of P2=%d\n",p2);
		printf("Player 2 win\n");
		}
		else if(p2>100)
		{
		 p2=t;
		 system("cls");
		 		printf("\nDice= %d\n",dice());
		 printf("\nPosition of P2=%d\n",p2);
		 goto start;
		}
		else
		{
		 system("cls");
		 p2=snake(p2);
		p2=ladder(p2);
		 		printf("\nDice= %d\n",dice());
		printf("\nPosition of P2=%d\n",p2);
		goto start; }
		break;
	case 8:
		exit(0);
	default:
		 system("cls");
		 		printf("Error,	Press Again:");
		goto start;
	}

	getch();
}
int dice()
 {
	int i;	//the number which dice will show
	srand(time(NULL));		//srand function is used here fix the algorithm to call the get the random value as per the seconds running
	i=rand()%(6-1+1)+1;		//formulae for getting random number between 1 to 6. //Formulae=rand%(highest-lowest+1)+lowest,	highest=6,lowest=1
	return i;
}
