#pragma once
#include "level.h"
#include <array>

const std::array<LevelDescription, 3> LEVELS = {
    {{// Level 1
      .grid = {10, 10, {}},
      .startingPosition = {1, 1},
      .speed = 0.1f,
      .targetScore = 5},
     {// Level 2
      .grid = {10, 10, {{5, 5}}},
      .startingPosition = {1, 1},
      .speed = 0.08f,
      .targetScore = 10},
     {// Level 3
      .grid = {10, 10, {{1, 1}, {2, 2}, {3, 3}, {4, 4}}},
      .startingPosition = {5, 1},
      .speed = 0.08f,
      .targetScore = 10}}};