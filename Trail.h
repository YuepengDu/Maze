
#ifndef COSC_ASSIGN_ONE_TRAIL
#define COSC_ASSIGN_ONE_TRAIL

#include <cstring>
#include <cstdlib>
#include "Position.h"
#include "Types.h"

class Trail {
public:

   /*                                           */
   /* DO NOT MOFIFY ANY CODE IN THIS SECTION    */
   /*                                           */


   // Constructor/Desctructor.
   Trail();
   ~Trail();

   // Copy Constructor
   // Produces a DEEP COPY of the Trail
   Trail(Trail& other);

   // Number of elements in the Trail
   int size();

   // Get a pointer to the i-th trail element in the array - useful for making Positions stale.
   Position* getPosition(int i);

   // Add a COPY trail element to the BACK of the trail.
   void addCopy(Position* trail);

   /*                                           */
   /* YOU MAY ADD YOUR MODIFICATIONS HERE       */
   /*                                           */
   // Resize path to double time capacity
   void resizePath();

private:
   /*                                           */
   /* DO NOT MOFIFY ANY CODE IN THIS SECTION    */
   /*                                           */

   // Trail of Position objects
   // You may assume a fixed size for M1 & M2
   Position* positions[TRAIL_ARRAY_MAX_SIZE];

   // Number of Positions currently in the trail
   int length;


   /*                                           */
   /* YOU MAY ADD YOUR MODIFICATIONS HERE       */
   /*                                           */
   // Milestone4's path variable
   Position** path;
   // path's max capacity
   int capacity;
};

#endif // COSC_ASSIGN_ONE_TRAIL
