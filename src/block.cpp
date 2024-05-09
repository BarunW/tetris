#include "block.h"
#include <raylib.h>
#include <unordered_map>

std::vector<std::vector<int>> NewBlock(int numOfRows , int numOfCols){
    std::vector<std::vector<int>> block(numOfRows, std::vector<int>(numOfCols));
    for (int row = 0; row < numOfRows; row++){
        for (int col = 0; col < numOfCols; col++){
           if(col != 1) block[row][col] = - 1; 
           if(row == 0 && col == 0) block[row][col] = 0; 
        }
    }
    return  block;
}

Block NewBlockOrangeRicky(){
    Block b;
    b.block_id = ID_ORANGE_RICKY;
    b.block_color = ORANGE;
    b.NoOfRotation = 3;
    
    std::unordered_map<int, std::vector<std::vector<int>>> blocks;

    blocks[0] = std::vector<std::vector<int>>{{-1, -1, -1}, {-1, -1, 0}, {0, 0, 0}}; 
    blocks[1] = std::vector<std::vector<int>>{{-1, 0, 0}, {-1, -1, 0}, {-1, -1, 0}}; 
    blocks[2] = std::vector<std::vector<int>>{{-1, -1, -1}, {0, 0, 0}, {0, -1, -1}}; 
    blocks[3] = std::vector<std::vector<int>>{{0, -1, -1}, {0, -1, -1}, {0, 0, -1}}; 
    
    b.blocks = blocks;

    return  b;
}

Block NewBlock_SmashBoy() {
    Block b;
    b.block_id = ID_SMASH_BOY;
    b.block_color = WHITE;
    b.NoOfRotation = 0;
    
    std::unordered_map<int, std::vector<std::vector<int>>> blocks;

    blocks[0] = std::vector<std::vector<int>>{{-1, -1, -1}, {-1, 0, 0}, {-1, 0, 0}}; 

    b.blocks = blocks;

    return b;

}

Block NewBlock_Hero(){
    Block b;
    b.block_id = ID_HERO;
    b.block_color = {21, 204, 209, 255} ;
    b.NoOfRotation = 1;
    
    std::unordered_map<int, std::vector<std::vector<int>>> blocks;

    blocks[0] = std::vector<std::vector<int>>{{0, 0, 0, 0}};
    blocks[1] = std::vector<std::vector<int>>{{0}, {0}, {0}, {0}}; 

    b.blocks = blocks;

    return b;

}






