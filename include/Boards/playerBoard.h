//
// Created by nryxenon on 12/4/25.
//

#ifndef RAYPONG_PLAYERBOARD_H
#define RAYPONG_PLAYERBOARD_H
#include "board.h"

class PlayerBoard final : public Board {

public:
    using Board::Board ;

    ~PlayerBoard() override = default;

    void updatePosition() override;
    void drawBoard() override;
};

#endif //RAYPONG_PLAYERBOARD_H