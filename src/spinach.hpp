#pragma once

#include <string>

#include "plot.hpp"

class Spinach : public Plot {
  private:
    int days = 0;
    bool watered = false;
    static const int days_to_sprout = 2;
    static const int days_to_maturity = 3;

  public:
    std::string symbol() override;
    void end_day() override;
    void water() override;
    bool is_harvestable() override;
    int get_days();
};

