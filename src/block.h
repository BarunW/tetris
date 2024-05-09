#ifndef BLOCK_HEADER
#define BLOCK_HEADER 

#include <cstdint>
#include <unordered_map>
#include <vector>
#include <raylib.h>

typedef std::uint8_t BLOCK_ID ;

const BLOCK_ID ID_ORANGE_RICKY   = 1;
const BLOCK_ID ID_BLUE_RICKY     = 2;
const BLOCK_ID ID_CLEVELAND_Z    = 3;
const BLOCK_ID ID_RHODEISLAND_Z  = 4;
const BLOCK_ID ID_HERO           = 5;
const BLOCK_ID ID_TEWEE          = 6;
const BLOCK_ID ID_SMASH_BOY      = 7;


typedef struct{
    BLOCK_ID block_id;
    Color block_color;
    int NoOfRotation;
    std::unordered_map<int, std::vector<std::vector<int>>> blocks;
}Block;

std::vector<std::vector<int>> NewBlock(int numOfRows , int numOfCols);
Block NewBlockOrangeRicky();
Block NewBlock_Hero();
Block NewBlock_SmashBoy();

#endif



