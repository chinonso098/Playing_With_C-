#include <stdio.h>
#include <stdlib.h>


void List_Of_Cities();   // function declaration
void Exit();// function declaration
void Read_File_Into_Array(); // read the file into the array
void Start_Trip(float a[70][70]);// Start the damn trip
void Calculate_Distance(float a[70][70],int *x,int *y,int *s);
void Add_Another_Destination(float a[70][70],float *Dist,int x,int y,int *z,int *s);



int main()
{
	/*Start the program*/
	Read_File_Into_Array();  
	system("Pause");
}// end main


void Read_File_Into_Array()
{
float City_Distances[70][70]; // An Array of array's of 490 elements
int row,coloum;
float num;

	FILE *fp= fopen("Result.txt","r");

if(fp==NULL) // check for the file
{
    printf("Can't open  'Result.txt'\n");
	system("Pause");
    exit(0);
}

// read the data into the array, analyze and prin the array
for ( row= 0; row<70; row++)
{
    for( coloum=0; coloum<70; coloum++)
    {
        fscanf(fp,"%f", &num);
        City_Distances[row][coloum]=num;
    }
} // end for
     // printf(" the value is: %.1f \n",City_Distances[0][3]);
/* Call the Start trip function*/
Start_Trip(City_Distances);
  
}// end read file into Array definition


void Start_Trip(float a[70][70])
{
	int Current_city;                // the current city the user is in
	int Next_city;                  // the next city the user wants to go to
	int First_city;                // Hold the First City
	int Distance;                 // gets destination
	int Userresponse;                // gets usersresponse

	//printf(" the value is: %.1f \n",a[0][3]);
	printf("Do you want to perform a Trip Distance Calculation?.\n");  // ask user if they want to perform a trip calculation
	printf("Press (1) for Yes or (2) for No!.\n");// Get users response
	scanf("%d",&Userresponse);// get users response

	if(Userresponse==1)
	{
	
	printf("\n");
	printf(" What city are you currently in?\n\n");  // ask user
	List_Of_Cities();  // call the List of cities function
	printf("\n");
	printf(" Enter a value!!\n");
	scanf("%d",&Current_city);  // user input
	printf("\n");


	/*$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$
	  Verify input for Current City
	$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$*/

	   while(Current_city< 1 || Current_city>70)
       {
	     printf("Your City Range Must Be Between 1-70\n");
	      printf("\n");
           printf("Pls enter your Current city again?\n");
            scanf("%d",&Current_city);
       }// end while

	    // Adjust current city
	   Current_city= Current_city -1;
	   First_city= Current_city;

	   printf(" \n");// space

        printf(" What city do you want to go to?\n");  // ask user
		printf("\n");
	    List_Of_Cities();  // call the List of cities function
		printf("\n");
	    printf(" Enter a value!!\n");
	    scanf("%d",&Next_city);  // user input
		printf(" \n");// space


		/*@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
		   Verify input for Next City
		@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@ */


		  while(Next_city< 1 || Next_city>70)
		  {
			 printf("Your City Range Must Be Between 1-70\n");
			  printf("\n");
			   printf("Pls enter your Next city again?\n");
				scanf("%d",&Next_city);
		  }// end if

		  // Adjust Next_City
		  Next_city= Next_city-1;
	
	
		  // Call the Calculate Distance fuction and pass the array and function
		  Calculate_Distance(a,&Current_city,&Next_city,&First_city); // pass Current,Next and First City

	} else if( Userresponse==2)
	{
	   /*Call the Exit Function*/
		Exit();
	
	}

}// end start the trip definition



void Calculate_Distance(float a[70][70],int *x,int *y,int *s) // get Current,Next and First City
{
	int Current_city= *x;
	int Next_city=*y;
	int First_city= *s;
	float Distance;
	int Total_Cities=0;// initialize total cities

	char *Cities[70]={"Akron,OH","Albany,NY","Albion,WA","Alexan,CA","Anson,TX","Andrew,IN","Angola,TN","Arcae,ND","Argos,NV","Attica,DC","Auburn,KY","Aurora,PA","Austin,TX","Avilla,UT","Avon,OR","Barile,MT","Balake,SC","Batvoil,GA","Bagran,CO","Beord,MN","Becrove,WI","Berne,ME","Bicknel,VA","Blokel,AZ","Blumin,NM","Blfton,NJ","Bonville,OK","Bourbon,KS","Brazil,SD","Bremen,IL","Bright,WA","Bristol,WI","Brookly,MA","Bikston,MO","Bokvile,WY","Brosbur,MD","Broton,NH","Butler,IN","Cambel,VT","Canelt,DC","Carmel,IN","Cayuga,OH","Cedlake,AL","Centers,FL","Chandle,AR,","Charles,NE","Chester,IA","Cheston,LA","Churow,MN","Cicero,OR","Clakson,NV","Clayes,WA","Clermon,SC","Clinton,DC","Clover,NC","Cumbia,IN","Coluus,IL","Coervil,NY","Converse,CA","Corydon,UT","Coton,TX","Crawft,RI","Crosvil,WY","Croint,HI","Culver,AL","Cumland","Dale,IA","Daleon,FL","Davile,GA","Dridon,MA"};
 

	Distance=a[Current_city][Next_city]; // get the distance of current and next city

	printf("The Distance from %2s to %2s is %.1f(Miles)\n\n",Cities[Current_city],Cities[Next_city],Distance);

	//Update Number of Cities
	Total_Cities=1;

	/*Call the Add Another City Function*/
	Add_Another_Destination(a,&Distance,Current_city,Next_city,&Total_Cities,&First_city); // pass Array,Current,Next city and Total cities

}// end definition of calculate distance


//566666666668555555555555555555555555555555555555555555555555555555555555555555555555555555555555555555555555555555555555555555555555555555555555555555555555555555555555555555555


void Add_Another_Destination(float a[70][70],float *Dist,int x,int y,int *z,int *s) // get Array,Current,Next city,Total cities and First city
{
	int Userresponse; // get user response
	int Current_city=x;  // get current city from user
	int Next_city=y;    // get Next city from user
	int Total_Cities = *z; // intialize total cities with z
	int First_city= *s;    // get the first city from the begining
	float Distance;     // f
	float Total_Distance= *Dist; // initialize Total_Distance with *Dist
	char *Cities[70]={"Akron,OH","Albany,NY","Albion,WA","Alexan,CA","Anson,TX","Andrew,IN","Angola,TN","Arcae,ND","Argos,NV","Attica,DC","Auburn,KY","Aurora,PA","Austin,TX","Avilla,UT","Avon,OR","Barile,MT","Balake,SC","Batvoil,GA","Bagran,CO","Beord,MN","Becrove,WI","Berne,ME","Bicknel,VA","Blokel,AZ","Blumin,NM","Blfton,NJ","Bonville,OK","Bourbon,KS","Brazil,SD","Bremen,IL","Bright,WA","Bristol,WI","Brookly,MA","Bikston,MO","Bokvile,WY","Brosbur,MD","Broton,NH","Butler,IN","Cambel,VT","Canelt,DC","Carmel,IN","Cayuga,OH","Cedlake,AL","Centers,FL","Chandle,AR,","Charles,NE","Chester,IA","Cheston,LA","Churow,MN","Cicero,OR","Clakson,NV","Clayes,WA","Clermon,SC","Clinton,DC","Clover,NC","Cumbia,IN","Coluus,IL","Coervil,NY","Converse,CA","Corydon,UT","Coton,TX","Crawft,RI","Crosvil,WY","Croint,HI","Culver,AL","Cumland","Dale,IA","Daleon,FL","Davile,GA","Dridon,MA"};	
	Total_Distance += Total_Distance;  // aggregate total distance
	Total_Cities += Total_Cities;      // aggragate total cities


	printf("Would you like to add another city for your next destination?\n\n");
	printf("Press (1) for Yes and (2) for No\n");
	scanf_s("%d",&Userresponse);
	if(Userresponse==1)
	{
		Distance= *Dist;
		Current_city=y; // Set the previous City to the current city

        printf(" \n");// space
		printf(" What city do you want to go to next?\n");  // ask user
		printf(" \n");// space
	    List_Of_Cities();  // call the List of cities function
		printf(" \n");// space
	    printf(" Enter a value!!\n");
	    scanf("%d",&Next_city);  // user input
		printf(" \n");// space

		/*@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
		   Verify input for Next City
		@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@ */

		  while(Next_city< 1 || Next_city>70)
		  {
			 printf("Your City Range Must Be Between 1-70\n");
			  printf("\n");
			   printf("Pls enter your Next city again?\n");
				scanf("%d",&Next_city);
		  }// end if

		  // Adjust Next_City
		  Next_city= Next_city-1;

		  while(Next_city==Current_city)
		    {
		     printf("You're Already in this City!!!!\n\n");
			 printf("Please Enter your Next Destination of choice!!!!\n\n");
			 scanf("%d",&Next_city);

			 // Adjust Next_City
		     Next_city= Next_city-1;
	
		  }// end while
		  Calculate_Distance(a,&Current_city,&Next_city,&First_city); // pass array, Current,Next and First City
	}else if(Userresponse== 2)
	{
		printf(" \n");// space
		printf("Total Cities Visited: %d\n\n",Total_Cities);
		printf("The Total Distance from %2s to %2s is %.1f(Miles)\n",Cities[First_city],Cities[Next_city],Total_Distance);
	  /*Call The Exit Funtion*/
		Exit();
	} else if(Userresponse != 1 || Userresponse !=2)
	 {
	    printf("That is not a recognized input\n\n");
		Add_Another_Destination(a,&Distance,Current_city,Next_city,&Total_Cities,&First_city);
	}//
}// end the Add another city definition
//3333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333 



void List_Of_Cities()
{
	int i;
	char *Cities[70]={"Akron,OH","Albany,NY","Albion,WA","Alexan,CA","Anson,TX","Andrew,IN","Angola,TN","Arcae,ND","Argos,NV","Attica,DC","Auburn,KY","Aurora,PA","Austin,TX","Avilla,UT","Avon,OR","Barile,MT","Balake,SC","Batvoil,GA","Bagran,CO","Beord,MN","Becrove,WI","Berne,ME","Bicknel,VA","Blokel,AZ","Blumin,NM","Blfton,NJ","Bonville,OK","Bourbon,KS","Brazil,SD","Bremen,IL","Bright,WA","Bristol,WI","Brookly,MA","Bikston,MO","Bokvile,WY","Brosbur,MD","Broton,NH","Butler,IN","Cambel,VT","Canelt,DC","Carmel,IN","Cayuga,OH","Cedlake,AL","Centers,FL","Chandle,AR,","Charles,NE","Chester,IA","Cheston,LA","Churow,MN","Cicero,OR","Clakson,NV","Clayes,WA","Clermon,SC","Clinton,DC","Clover,NC","Cumbia,IN","Coluus,IL","Coervil,NY","Converse,CA","Corydon,UT","Coton,TX","Crawft,RI","Crosvil,WY","Croint,HI","Culver,AL","Cumland","Dale,IA","Daleon,FL","Davile,GA","Dridon,MA"};
	for(i=0; i<10; i++)
	{
        printf("%1d.%-12s  %1d.%-12s  %1d.%-12s  %1d.%-12s  %1d.%-12s  %1d.%-12s  %1d.%-12s ", i+1,Cities[i],i+11 ,Cities[i+10],i+21,Cities[i+20],i+31,Cities[i+30],i+41,Cities[i+40],i+51,Cities[i+50],i+61,Cities[i+60]);
        printf("\n");
	}// for loop
	    //printf("11. To Exit\n");
}// end list of cities definition


void Exit()
{
	printf("Good-Bye\n");
	system("Pause");
	exit(0);
}// end exit definition

