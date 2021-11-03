
#include <iostream>
#include <string>

#include "Types.h"
#include "WallFollower.h"

#ifdef MILESTONE4
// if in milestone4
#include "milestone4.h"
#endif

// Helper test functions
void testPosition();
void testTrail();
void milestone2(Maze maze,Trail* solution,int width,int height,bool output_the_result = true); 
void milestone3(Maze maze,Trail* solution,int width,int height,Position* start);

// Read a maze from standard input.
void readMazeStdin(Maze maze);

// Print out a Maze to standard output.
void printMazeStdout(Maze maze, Trail* solution);

Position* readMazeStdin2(Maze& maze,int& width,int& height);

int main(int argc, char** argv) {
    // THESE ARE SOME EXAMPLE FUNCTIONS TO HELP TEST YOUR CODE
    // AS YOU WORK ON MILESTONE 2. YOU CAN UPDATE THEM YOURSELF
    // AS YOU GO ALONG.
    // COMMENT THESE OUT BEFORE YOU SUBMIT!!!
    // std::cout << "TESTING - COMMENT THE OUT TESTING BEFORE YOU SUBMIT!!!" << std::endl;
    // testPosition();
    // testTrail();
    // std::cout << "DONE TESTING" << std::endl << std::endl;

    // Load Maze from stdin
    Maze maze;
    int width;  //maze width
    int height; //maze height

    Position* start_point = readMazeStdin2(maze,width,height);   //read maze stdin and return start point position

    // Solve using WallFollower
    // THIS WILL ONLY WORK IF YOU'VE FINISHED MILESTONE 2
    WallFollower* follower = new WallFollower();
    follower->setMazeSize(width,height);

    Trail* fullPath = nullptr;
    follower->execute(maze);
    fullPath = follower->getFullPath();

    // Print Maze to stdout
    // printMazeStdout(maze, fullPath);
    
    // milestone2(maze,fullPath,width,height);

    milestone3(maze,fullPath,width,height,start_point);

    //free the maze
    delete_maze(maze,height,width);
    delete follower;

    delete start_point;
    return EXIT_SUCCESS;
}

//milestone4
Position* readMazeStdin2(Maze& maze,int& width,int& height){
    int row = 0;
    int col = 0;
    //max maze size
    char buf[1024];
    //read a line
    std::cin >> buf;
    // one line's length
    int length = strlen(buf);
    maze = make_maze(1024,length);

    Orientation orien = ORIEN_EAST;
    int start_row = -1;
    int start_col = -1;
    do{
        for(col = 0; col < length; col++){
            maze[row][col] = buf[col];
            if(isOrien(buf[col])){
                orien = getOrien(buf[col]);
                start_row = row;
                start_col = col;
            }
        }
        row++;
    }while(std::cin >> buf);
    width = length;
    height = row;

    // return start point position
    return new Position(start_col,start_row,orien);
}

//milestone2 by milestone4
void milestone2(Maze maze,Trail* solution,int width,int height,bool output_the_result){
    // TODO
    // std::cout << "TODO" << std::endl;
    int row,col;
    char direct = 0;
    for(int i = 0; i < solution->size() - 1; i++){
        Position* item = solution->getPosition(i);
        col = item->getX();
        row = item->getY();
        switch(item->getOrientation()){ //obtain current orientation
            case ORIEN_EAST:
                direct = '>';
            break;
            case ORIEN_SOUTH:
                direct = 'v';
            break;
            case ORIEN_WEST:
                direct = '<';
            break;
            case ORIEN_NORTH:
                direct = '^';
            break;
            default:
                direct = '.';
        }
        maze[row][col] = direct;
    }

    // output the maze result after execute miestone2 logic
    if(output_the_result == true){
        //output the maze
        for(row = 0; row < height; row++){
            for(col = 0; col < width; col++){
                std::cout << maze[row][col];
            }
            std::cout << std::endl;
        }
    }
}

//milestone3
void milestone3(Maze maze,Trail* solution,int width,int height,Position* start_point){
    int col,row;

    //call milestone2's logic
    milestone2(maze,solution,width,height);

    col = start_point->getX();
    row = start_point->getY();
    //(col,row) is not goal point
    while(maze[row][col] != 'G'){
        switch(maze[row][col]){
            case '>':
                std::cout << "east" << std::endl;
                col++;
            break;
            case '<':
                std::cout << "west" << std::endl;
                col--;
            break;
            case '^':
                std::cout << "north" << std::endl;
                row--;
            break;
            case 'v':
                std::cout << "south" << std::endl;
                row++;
            break;
        }
    }
}

void readMazeStdin(Maze maze) {
    // ASSUME THE MAZE IS A FIXED SIZE (20X20).
    // TODO
    char cur;
    int row = 0;
    int col = 0;
    while(std::cin >> std::noskipws >> cur){
        if(cur == '\n'){    //newline
            col = 0;
            row++;
        }else{
            maze[row][col++] = cur;
        }
    }
}


void printMazeStdout(Maze maze, Trail* solution) {
    // TODO
    // std::cout << "TODO" << std::endl;
    int row,col;
    char direct = 0;
    for(int i = 0; i < solution->size() - 1; i++){
        Position* item = solution->getPosition(i);
        col = item->getX();
        row = item->getY();
        switch(item->getOrientation()){ //obtain current orientation
            case ORIEN_EAST:
                direct = '>';
            break;
            case ORIEN_SOUTH:
                direct = 'v';
            break;
            case ORIEN_WEST:
                direct = '<';
            break;
            case ORIEN_NORTH:
                direct = '^';
            break;
            default:
                direct = '.';
        }
        maze[row][col] = direct;
    }

    //output the maze
    for(row = 0; row < 20; row++){
        for(col = 0; col < 20; col++){
            std::cout << maze[row][col];
        }
        std::cout << std::endl;
    }
}

void testPosition() {
    std::cout << "TESTING Position" << std::endl;

    // Make a Position and print out the contents
    Position* position = new Position(1, 1, ORIEN_WEST);
    std::cout << position->getX() << ",";
    std::cout << position->getY() << ",";
    std::cout << position->getOrientation() << std::endl;
    delete position;

    // Change Position stale-ness and print again
    position = new Position(4, 2, ORIEN_SOUTH);
    std::cout << position->getX() << ",";
    std::cout << position->getY() << ",";
    std::cout << position->getOrientation() << std::endl;
    delete position;
}

void testTrail() {
    std::cout << "TESTING TRAIL" << std::endl;

    // Make a simple trail, should be empty size
    Trail* trail = new Trail();
    std::cout << "Trail size: " << trail->size() << std::endl;

    // Add a Position to the trail, print size
    Position* b1 = new Position(1, 1, ORIEN_NORTH);
    trail->addCopy(b1);
    std::cout << "Trail size: " << trail->size() << std::endl;

    // Add second Position
    Position* b2 = new Position(0, 0, ORIEN_EAST);
    trail->addCopy(b2);
    std::cout << "Trail size: " << trail->size() << std::endl;

    return ;
    // Test Get-ith - should be 0,0,true
    Position* getB = trail->getPosition(1);
    std::cout << getB->getX() << ",";
    std::cout << getB->getY() << ",";
    std::cout << getB->getOrientation() << std::endl;

    // Print out the trail
    std::cout << "PRINTING OUT A TRAIL IS AN EXERCISE FOR YOU TO DO" << std::endl;
}