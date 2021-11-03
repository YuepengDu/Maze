
#include "WallFollower.h"


WallFollower::WallFollower() {
   // TODO
   this->path = new Trail();
}

WallFollower::~WallFollower() {
   // TODO delete solution;
   delete path;
}

void WallFollower::setMazeSize(int width,int height){
   this->width = width;
   this->height = height;
}

int WallFollower::getWidth(){
   return this->width;
}


int WallFollower::getHeight(){
   return this->height;
}


void WallFollower::execute(Maze maze) {
   // TODO
   
   int col,row;
   Position* T = nullptr;  //robot start position
   Position* G = nullptr;  //goal position
   for(row = 0; row < this->height; row++){
      for(col = 0; col < this->width; col++){
         char cur = maze[row][col];
         if(isOrien(cur)){ //robot start position
            T = new Position(col,row,getOrien(cur));
         }else if(cur == 'G'){   //goal position
            G = new Position(col,row,getOrien(cur));
         }
      }
   }

   if(T == nullptr || G == nullptr) return;
   col = T->getX();
   row = T->getY();
   Orientation orien = T->getOrientation();
   int gcol = G->getX();
   int grow = G->getY();
   int directs[][2] = {
      {0,1},   //east
      {1,0},   //south
      {0,-1},  //west
      {-1,0},  //north
   };
   int visits[4] = {0};
   while(col != gcol || row != grow){
      int direct_idx = getOrienIdx(orien);
      visits[0] = (direct_idx + 1)%4;  //right
      visits[1] = direct_idx; //front
      visits[2] = (direct_idx + 3)%4;  //left
      visits[3] = (direct_idx + 2) %4; //back
      // char ds[] = ">v<^";
      // std::cout << ds[getOrienIdx(orien)] << std::endl;
      for(int i = 0; i < 4; i++){
         int idx = visits[i];
         int trow = row + directs[idx][0];
         int tcol = col + directs[idx][1];
         char r = maze[trow][tcol];
         // std::cout << "[" << i <<"]:find(" << tcol << "," << trow << ")" << std::endl;
         if(r != '='){   //not wall
            orien = getIdxOrien(idx);
            if(i != 1){ //left/right
               this->path->addCopy(new Position(col,row,orien));   //turn right
            }
            
            if(i != 2){
               col+=directs[idx][1];
               row+=directs[idx][0];
               this->path->addCopy(new Position(col,row,orien));  //move one space forward right
            }
            break;
         }
      }
   }
}

Trail* WallFollower::getFullPath() {
   // TODO
   Trail tmp = *path;
   return new Trail(tmp);
}
