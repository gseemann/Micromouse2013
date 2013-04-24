//declare variables

const int SIZE = 16;
const int WALLS = 4;

int arrayWalls[SIZE][SIZE][WALLS];
int arrayFlood[SIZE][SIZE];

int xPosition = 0;
int yPosition = 0;
                                                      
                                          
   
//   0                               
// 0 --------------------->x
//   |
//   |
//   |
//   |  
//   |  
//   y


boolean incrementx = true;
boolean incrementy = false;
boolean decrementx = false;
boolean decrementy = false;

//only one of these is set to true                             
//this indicates the direction the mouse is moving              
//we start at 0x0 the y axis is inverted from how we normally look at it

boolean north = false;      //false indicates that there is no wall
boolean west = false;
boolean east = false;
boolean south = false;


void updatePosition()
{
  if(incrementx)        //this function updates the mouse's position in the maze
    xPosition++;
  if(incrementy)
    yPosition++;
  if(decrementx)
    xPosition--;
  if(decrementy)
    yPosition--; 
}
//       0
//     ----
//  1 |    | 2
//    |    |
//     ----
//      3

//check this function
void updateWalls(boolean north, boolean west, boolean east)     //we may not need to pass these if we make them global
{                                                               //north =0, west=1, east=2, south=3
  if(north)
  {
    arrayWalls[xPosition][yPosition][0] = 1;            //assigns the north as a wall in the array
    
    if(yPosition=!0)                                    //assigns the south wall of the square above
      arrayWalls[xPosition][yPosition-1][3] = 1;
  }
  
  if(west)
  {
    arrayWalls[xPosition][yPosition][1] = 1;            //assigns the west as a wall in the array
    
    if(xPosition=!0)                                    //assigns the east wall of the square west
      arrayWalls[xPosition-1][yPosition][2] = 1;
  }
  
  if(east)
  {
    arrayWalls[xPosition][yPosition][2] = 1;            //assigns the north as a wall in the array
    
    if(xPosition =! 15)                                    //assigns the west wall of the square east
      arrayWalls[xPosition+1][yPosition][1] = 1;
  }
  
  if(south)
  {
    arrayWalls[xPosition][yPosition][3] = 1;            //assigns the north as a wall in the array
    
    if(yPosition =! 15)                                    //assigns the west wall of the square east
      arrayWalls[xPosition+1][yPosition][0] = 1;
  }
  
}

void seeWalls()
{
 //use bool valuse of increment to orient values 
}

void findPath()
{
  int nCell = 300;           //used to store the flood value for the adjacent squares
  int wCell = 300;           //we may potentiallymove declaration to top but we need to keep the 300 value
  int eCell = 300;           //the 300 is to make sure it wont want to go
  int sCell = 300;
  int currentCell = arrayFlood[xPosition][yPosition];        //gets the current cells flood value
  
  if(!north)                //if there is no wall to the north get the flood value
  {
    nCell = arrayFlood[xPosition][yPosition-1];
  }
  
  if(!west)                //if there is no wall to the west get the flood value
  {
    wCell = arrayFlood[xPosition-1][yPosition];
  }
  
  if(!east)                //if there is no wall to the east get the flood value
  {
    eCell = arrayFlood[xPosition+1][yPosition];
  }
  
  if(!south)                //if there is no wall to the south get the flood value
  {
    sCell = arrayFlood[xPosition][yPosition+1];
  }
  
  //sort cells from lowest to highest
  
  
  //check to if there is a lower square to go to, if not call re flood function
  //any adjacent cell that has a wall in between is set to 300 ie much greater than any other cell would be
  if(currentCell<=north && currentCell<=south && currentCell<=east && currentCell<=west)
  {
    reFlood();        //call the function that refloods the maze with updated values
  }
  else                //figure out which path to take
  {
    if(incrementx)
    {
      if(east<=south && east<=north && east<=west)      //checking if current direction is to lowest value
    }
    
  }
  
}

void reFlood()
{
  
}





