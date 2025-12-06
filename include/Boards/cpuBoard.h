//
// Created by nryxenon on 12/4/25.
//

#ifndef RAYPONG_CPUBOARD_H
#define RAYPONG_CPUBOARD_H

#include "board.h"

class CPUBoard : public Board {
public :
    using Board::Board;
    ~CPUBoard() override = default;

    void updatePosition() override;
    void drawBoard() override;
    void trackPosition();

    void setTargetPosition(const float &target);
    inline void setFollowTarget(const bool &canFollow) {followTargetPosition = canFollow;}
    [[nodiscard]] inline bool canFollowTarget() const { return followTargetPosition; }

protected :

    bool followTargetPosition = true;
    float targetPositionY = 0;
};

#endif //RAYPONG_CPUBOARD_H