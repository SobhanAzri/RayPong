//
// Created by nryxenon on 12/4/25.
//

#ifndef RAYPONG_SCORES_H
#define RAYPONG_SCORES_H

class ScoreSystem {
public:
    ScoreSystem(): playerScore(0), cpuScore(0) {}
    ~ScoreSystem();

    inline void addPlayerScore(){ playerScore++;}
    inline void addCpuScore(){ cpuScore++;}

    [[nodiscard]] int getPlayerScore() const { return playerScore; }
    [[nodiscard]] int getCpuScore() const { return cpuScore; }

    inline void resetScores() {
        playerScore = 0;
        cpuScore = 0;
    }

protected:
    int playerScore;
    int cpuScore;
};

#endif //RAYPONG_SCORES_H