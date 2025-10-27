#pragma once

#include <string>
#include <vector>

#include "plot.hpp"

class Soil : public Plot {
  public:
    std::string symbol() override;
    void end_day() override;
    int get_age() override;
};
