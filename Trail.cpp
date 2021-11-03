
#include "Trail.h"


Trail::Trail() {
   // TODO
   this->length = 0;
   #ifdef MILESTONE4
   //initial capacity is 16
   this->capacity = 16;
   this->path = new Position*[this->capacity];
   #endif
}

Trail::Trail(Trail& other){
   this->length = 0;
   this->capacity = other.capacity;
   this->path = new Position*[this->capacity];
   for(int i = 0; i < other.length; i++){
      this->addCopy(other.getPosition(i));
   }
}

Trail::~Trail() {
   // TODO
   #ifdef MILESTONE4
      delete[] this->path;
   #endif
}

int Trail::size() {
   // TODO
   return this->length;
}

Position* Trail::getPosition(int i) {
   // TODO
   // not in Milestone4
   #ifndef MILESTONE4
      if(i < 0 || i >= TRAIL_ARRAY_MAX_SIZE || i >= this->length) return nullptr; 
      return this->positions[i];
   #else
      if(i < 0 || i >= this->length) return nullptr;
      return this->path[i];
   #endif
}

void Trail::addCopy(Position* t) {
   // TODO
   if(t == nullptr || this->length >= 1600) return;
   int x = t->getX();
   int y = t->getY();
   Orientation o = t->getOrientation();
   // std::cout << "length: " << this->length << std::endl;
   #ifndef MILESTONE4
      this->positions[this->length++] = new Position(x,y,o);
   #else
      if(this->length >= this->capacity){
         this->resizePath();
      }
      this->path[this->length++] = new Position(x,y,o);
   #endif
}

void Trail::resizePath() {
   if(this->length < this->capacity) return;
   //capacity resize to 2 times
   int capacity = this->capacity * 2;
   Position** path = new Position*[capacity];

   for(int i = 0; i < this->length; i++)
      path[i] = this->path[i];
   delete this->path;   //delete old path space
   this->path = path;   //assign new path to this->path
   this->capacity = capacity; //change capacity
}
