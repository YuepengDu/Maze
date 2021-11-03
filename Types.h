
#ifndef COSC_ASSIGN_ONE_TYPES
#define COSC_ASSIGN_ONE_TYPES

// We can change Milestone state in here
#define MILESTONE4

//if character is a direction character,then true,else false
#define isOrien(ch) ((ch) == '<' || (ch) == '>' || (ch) == '^' || (ch) == 'v')
//get the orientation character's orientation value
#define getOrien(ch) ((ch) == '<' ? ORIEN_WEST : (ch) == '^' ? ORIEN_NORTH : (ch) == '>' ? ORIEN_EAST : ORIEN_SOUTH)
//get orientation idx
#define getOrienIdx(orien) ((orien) == ORIEN_EAST ? 0 : (orien) == ORIEN_SOUTH ? 1 : (orien) == ORIEN_WEST ? 2 : 3)
//get idx orientation
#define getIdxOrien(idx) ((idx) == 0 ? ORIEN_EAST : (idx) == 1 ? ORIEN_SOUTH : (idx) == 2 ? ORIEN_WEST : ORIEN_NORTH)


// Orientation codes
enum Orientation {
   ORIEN_NORTH,
   ORIEN_EAST,
   ORIEN_SOUTH,
   ORIEN_WEST,
};

#define MAZE_DIM                20
#define TRAIL_ARRAY_MAX_SIZE    (4 * MAZE_DIM * MAZE_DIM)

// A 2D array to represent the maze or observations
// REMEMBER: in a maze, the location (x,y) is found by maze[y][x]!
#ifndef MILESTONE4
typedef char Maze[MAZE_DIM][MAZE_DIM];
#else
typedef char** Maze; //Milestone4's Maze
#endif

#endif // COSC_ASSIGN_ONE_TYPES
